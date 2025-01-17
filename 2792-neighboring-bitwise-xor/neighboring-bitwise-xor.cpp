class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int> ans1(n),ans2(n);
        if(n==1 && derived[0]==0){
           return true;
        }
        else if(n==1){
        return false;
        }
        if(derived[0]==1){
            ans1[0]=0;
            ans1[1]=1;
            ans2[0]=1;
            ans2[1]=0;
        }
        else{
            ans1[0]=1;
            ans1[1]=1;
            ans2[0]=0;
            ans2[1]=0;
        }
        for(int i=2;i<n;i++){
            ans1[i]=ans1[i-1]^derived[i-1];
            ans2[i]=ans2[i-1]^derived[i-1];
        }
        
        if(derived[n-1]==ans1[0]^ans1[n-1] || derived[n-1]==ans2[0]^ans2[n-1])return 1;
        
        return 0;
    }
};