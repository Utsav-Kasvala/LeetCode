class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = s.find(part);
        while(i!=-1){
            s = s.substr(0,i) + s.substr(i+part.size());
            i = s.find(part);
        }
        return s;
    }
};