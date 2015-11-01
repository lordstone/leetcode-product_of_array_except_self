class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        if(nums.size() == 1){
            vector<int> tmp(1,0);
            return tmp;
        }
        if(nums.size() == 2) {
            int tmp = nums[0];
            nums[0] = nums[1];
            nums[1] = tmp;
            return nums;
        }//end if size = 2
        vector<int> output(nums.size(), 1);
        output[0] = 1;
        
        for(int i = 1; i < nums.size(); i++){
            output[i] = output[i-1] * nums[i-1]; 
        }//end for i
        int multiplier = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            multiplier *= nums[i+1];
            output[i] *= multiplier;
        }
        return output;
    }
};
