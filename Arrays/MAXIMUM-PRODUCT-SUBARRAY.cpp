/*
we will make three cases : when               1)arr[i] > 0                          2) arr[i] < 0                   3) arr[i]==0

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxvalue = 1;
        int minvalue = 1;
        int ans=INT_MIN;
        int prevmax;
        for (int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                maxvalue = maxvalue * nums[i];
                minvalue = min(minvalue *nums[i],1);
            }
            else if (nums[i] == 0) {
                maxvalue = 0;
                minvalue = 1;
            }
            else {
                prevmax = maxvalue;
                maxvalue = minvalue * nums[i];
                minvalue = prevmax * nums[i];
            }
            ans = max(ans, maxvalue);
            if(maxvalue <= 0) {
                maxvalue = 1;
            }
        }
        return ans;
    }
};
