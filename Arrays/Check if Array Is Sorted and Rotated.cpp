class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            // to check all the elements form start to end except --> end to start 
            if(nums[i-1] > nums[i]){
                count++;
            }
        }
        // to check the last and first elements of an array 
        if(nums[n-1] > nums[0]){
            count++;
        }
        return count <= 1;
    }
};
