class TaskManager {
public:
    set<vector<int>> st;
    map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &val:tasks){
            st.insert({val[2],val[1],val[0]});
            mp[val[1]]={val[0],val[2]};
        }

    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId,userId});
        mp[taskId]={userId,priority};
    }
    
    void edit(int taskId, int newPriority) {
        int cu=mp[taskId].first,cp=mp[taskId].second;
        st.erase(st.find({cp,taskId,cu}));
        st.insert({newPriority,taskId,cu});
        mp[taskId]={cu,newPriority};
    }
    
    void rmv(int taskId) {
        int cu=mp[taskId].first,cp=mp[taskId].second;
        st.erase(st.find({cp,taskId,cu}));
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.size()==0){
            return -1;
        }
        else{
            auto it =*(--st.end());
            st.erase(--st.end());
            mp.erase(it[1]);
            return it[2];
        }
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */