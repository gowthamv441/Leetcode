/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<int> max_arr(n);
        vector<int> min_arr(n);
        max_arr[n-1]=prices[n-1];
        min_arr[0]=prices[0];
        for(int i=1;i<n;i++)
            min_arr[i]=min(min_arr[i-1],prices[i]);
        for(int i=n-2;i>=0;i--)
            max_arr[i]=max(max_arr[i+1],prices[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
           // cout<<max_arr[i]<<" "<<min_arr[i]<<endl;
            ans=max(ans,max_arr[i]-min_arr[i]);
        }
        return ans;
    }
};