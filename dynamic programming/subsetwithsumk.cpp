#include<bits/stdc++.h>
using namespace std;

int count_zeros_till_index(int arr[],int i)//returns the numberof zeros in array till index i
	{
	    int count=0;
	    for(int j=0;j<=i;j++)
       {
           if(arr[j]==0)
            count++;
       }
       return count;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    long long mod=1e9+7;
	    long long dp[n+1][sum+1];
	    
        for(int j=0;j<sum+1;j++)
            dp[0][j]=0;
            
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=pow(2,count_zeros_till_index(arr,i));
            //A little modification that is needed from Aditya verma's Code
        }                                         
            
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j]=((dp[i-1][j-arr[i-1]])%mod+(dp[i-1][j])%mod)%mod;
                }
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return dp[n][sum];
	}
	int main(){
        int arr[3] = {0,0,1};
        int sum = 1;
        cout<<perfectSum(arr,3,sum)<<endl;
    }

// another way
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int zero = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) zero++;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0 || (sum-target)%2) return 0;
        int targetsum = (sum-target)/2;
        vector<vector<int>>dp(n+1,vector<int>(targetsum+1,-1));
        for(int j=0;j<targetsum+1;j++) dp[0][j] = 0;
        for(int i=0;i<n+1;i++) dp[i][0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<targetsum+1;j++){
                if(nums[i-1]>j || nums[i-1]==0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        return pow(2,zero)*dp[n][targetsum];
    }
};
// another way
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0 || (sum-target)%2) return 0;
        int targetsum = (sum-target)/2;
        vector<vector<int>>dp(n+1,vector<int>(targetsum+1,-1));
        for(int j=0;j<targetsum+1;j++) dp[0][j] = 0;
        for(int i=0;i<n+1;i++) dp[i][0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<targetsum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][targetsum];
    }
};