class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int prefix=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(mp.find(prefix-goal)!=mp.end()){
                cnt+=mp[prefix-goal];
            }
            mp[prefix]++;
        }
        return cnt;
    }
};