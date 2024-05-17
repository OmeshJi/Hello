#include <bits/stdc++.h>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
        	if(i==0||w==0){
				dp[i][w]=0;
			}
           else if (weight[i-1] <= w) {
                dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weight(n), value(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    int maxValue = knapsack(W, weight, value, n);
    cout << "The maximum value that can be achieved is: " << maxValue << endl;
    return 0;
}
