#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // implemented lower bound using binary search
        // arr[ind] >= target smallest index holding this condition
        // and for upper bound condition arr[ind] > target
        // rest code same
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
// shortcut in stl
// int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
// int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();