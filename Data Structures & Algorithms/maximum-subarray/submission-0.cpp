class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int temp=nums[0],maxm=nums[0];
        for(int i=1;i<n;i++){
            temp=max(nums[i],temp+nums[i]);
            maxm=max(maxm,temp);
        }
        return maxm;

    }
};
