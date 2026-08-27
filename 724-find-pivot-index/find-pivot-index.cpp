class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        int leftsum=0;
        for(int i = 0; i < nums.size(); i++) {
            totalsum+=nums[i];
        }
         int leftSum = 0;
        // Find pivot index
        for(int i = 0; i < nums.size(); i++) {

            int rightSum = totalsum - leftSum - nums[i];

            if(leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }
        return -1;
    }
};

        