
#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int k, vector<int> &heights,vector<int> &dp) {
    // recursion + memoization
	if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
	int minSteps = INT_MAX;

	for(int j=1; j<=k; j++) {
		int jumps = INT_MAX;
		if(ind-j >= 0)
			jumps = solve(ind-j,k,heights,dp) + abs(heights[ind]-heights[ind-j]);
		minSteps = min(minSteps, jumps);
	}

	return dp[ind] = minSteps;
}

int frogKJump(int n, int k, vector<int> &heights) {
    vector<int>dp(n,-1);
	// tabulation
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            int jumps = INT_MAX;
            if(i-j>=0){
                jumps = dp[i-j] + abs(heights[i]-heights[i-j]);
            }
            minSteps = min(jumps,minSteps);
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main(){
	vector<int> heights;
	heights = {10, 20, 30, 10};
	cout << frogKJump(4, 2, heights);
	cout << endl;
	heights = {10, 50, 10};
	cout << frogKJump(3, 2, heights)<<endl;
}