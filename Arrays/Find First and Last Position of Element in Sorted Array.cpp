class Solution {
public:

    // code for first occurrence of an element 
    int firstocc(vector<int>&nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            //if target is found 
            if(nums[mid] == target){
                ans = mid; // store the current position[index] of a target 
                end = mid-1; // checking if our target still exist in left portion of an array  
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return ans;
    }
    // code for last occurrence of an element 
    int lastocc(vector<int>&nums, int target){
        int start = 0, end = nums.size()-1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            // if target is found
            if(nums[mid] == target){
                ans = mid; // store the current position[index] of a target 
                start = mid+1; // checking if our target still exist in right portion of an array
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstocc(nums, target);
        int last = lastocc(nums, target);
        return {first, last}; 
    }
};
