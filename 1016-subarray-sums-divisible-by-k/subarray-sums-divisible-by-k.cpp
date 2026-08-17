class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        int prefix=0;
        mp[0]=1;
        for(int x:nums){
            prefix+=x;
            int rem=prefix%k;
            if(rem<0){
                rem+=k;
            }

            if(mp.find(rem)!=mp.end()){
                cnt+=mp[rem];
            }

            mp[rem]++;
        }
        return cnt;
    }
};