class Solution {
public:
    bool ispossible(vector<int>& nums, int k, int mid){
        int Subarraycount = 1;
        int subarraysum = 0;

        for(int i=0;i<nums.size();i++){
            // Check if current element is smaller than sub-array limit 
            if(subarraysum + nums[i] <= mid){
                subarraysum += nums[i];
            }
            else{
                // Move to the next sub-array when mid limit exceeds
                Subarraycount++;
                // Return false if subarray count exceeds 'k' or element itself is greater than 'mid'
                if(Subarraycount > k || nums[i] > mid){
                    return false;
                }
                subarraysum = nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
      int start = 0;
      int sum = 0;
        int ans = -1;
      for(int i=0;i<nums.size();i++){
        sum += nums[i]; // with the help of sum we are creating the search space of an array 
      }  
      int end = sum; // end contains the sum of all elements of an array

       while(start <= end){
            int mid = start + (end - start)/2;

            // If mid is a possible maximum sum, save it and search for a smaller maximum on the left
            if(ispossible(nums,k,mid)){
            end = mid - 1;
            ans = mid;
            }
            else{
            // If mid is too small to fit elements within 'k' subarrays, increase the limit
            start = mid + 1;
            }
        }
        return ans;
    }
};
