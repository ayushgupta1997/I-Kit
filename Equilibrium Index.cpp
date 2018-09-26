class Solution {
public:
    int pivotIndex(vector<int>& nums) {                // this is index such that leftsum == rightsum
        int sum = 0, leftsum = 0;
        for (auto x: nums) {
            sum += x;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];                            // here we get the right sum 
            if(leftsum == sum)                         
                return i;
            leftsum += nums[i];
        }
        return -1;
        
    }
};
