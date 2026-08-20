class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // remainder 0 occurs before the array starts
        mp[0] = -1;

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if (mp.count(rem)) {
                // Need at least 2 elements
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};