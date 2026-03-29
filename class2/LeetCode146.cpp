#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getsum(const vector<int>& nums){
        int res=0;
        for(int n:nums){
            res+=n;
        }
        return res;
    }

    bool canPartition(vector<int>& nums) {
        int sum=getsum(nums);
        if(sum%2==1)return false;
        int l=sum/2;
        vector<bool> dp(l+1,false);
        dp[0]=true;
        for(int n:nums){    
            for(int i=l;i>=n;i--){
                if(dp[i-n])dp[i]=true;
            }
            if(dp[l])return true;
        }
        return false;
    }

    bool canPartition2(vector<int>& nums){
        int sum=getsum(nums);
        if(sum%2==1)return false;
        int l=sum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(l+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=l;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1]&&dp[i-1][j-nums[i-1]])dp[i][j]=true;
            }
            if(dp[i][l])return true;
        }
        return false;
    }
    
};

