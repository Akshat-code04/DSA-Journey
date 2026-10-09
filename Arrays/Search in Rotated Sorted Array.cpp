class Solution {
public:

    int pivotelement(vector<int>& nums){
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end-start)/2;
            // finding the pivot[index] in the first postion of an array 
            if(nums[mid] >= nums[0]){
                start = mid+1;
            }
            // finding the pivot[index] in the second postion of an array 
            else{
                end = mid;
            }
        }
        return start;
    }
    int binarysearch(vector<int>& nums,int s,int e,int target){
        int start = s, end = e;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = pivotelement(nums);

        if(nums[pivot] <= target && target  <= nums[n-1]){
            return binarysearch(nums,pivot,n-1,target);
        }
        else{
            return binarysearch(nums,0,pivot-1,target);
        }
    }
};
