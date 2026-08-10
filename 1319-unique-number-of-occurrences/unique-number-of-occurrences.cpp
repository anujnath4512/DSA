class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[x]++;
        }
        unordered_set<int>s1;
        
        for(auto x : mp){
            if(s1.count(x.second)){
                return false;
            }
            s1.insert(x.second);
        }

        return true;
    }
};