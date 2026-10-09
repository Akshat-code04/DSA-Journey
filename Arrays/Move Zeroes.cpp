class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int nonZeros = 0;

        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[nonZeros],nums[j]);
                nonZeros++;
            }
        }
        
    }
};
