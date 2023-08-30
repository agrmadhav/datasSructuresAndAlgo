#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = 1e9;
        int index = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            // if whole part is sorted 
            if(nums[low] <= nums[high]){
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                break;
            }
            // take the minimum from the sorted part and eliminate it
            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid+1;
            }
            else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        return ans;
    }
};