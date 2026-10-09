class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size()-1;

        while(start < end){
            int mid = start + (end - start)/2;

            // On the uphill slope [left part before peak element], peak is in the right half
            if(arr[mid] < arr[mid+1]){
                start = mid+1; 
            }
            // On the downhill slope [right part after peak elemnet] or at the peak, search left
            else {
                end = mid;
            }
        }
        return start;
    }
};
