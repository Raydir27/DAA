#include <iostream>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
  int dp[n + 1][W + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= W; j++) {
    dp[0][j] = 0; 
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      
      if (wt[i - 1] <= j) {
      
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]); 
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][W];
}

int main() {
  int n;
  cout << "Enter the number of items: ";
  cin >> n;

  float val[n];
  float wt[n];

  cout << "Enter the values of the items:\n";
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  cout << "Enter the weights of the items:\n";
  for (int i = 0; i < n; i++) {
    cin >> wt[i];
  }

  int W;
  cout << "Enter the maximum weight capacity of the knapsack: ";
  cin >> W;

  int result = knapsack(W, wt, val, n);

  cout << "Maximum value: " << result << endl;

  return 0;
}
