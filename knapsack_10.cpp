#include <iostream>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
  // Create a DP table to store maximum value achievable for each weight capacity
  int dp[n + 1][W + 1];

  // Initialize first row and column of DP table (base cases)
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0; // Knapsack with 0 capacity can hold value 0
  }
  for (int j = 0; j <= W; j++) {
    dp[0][j] = 0; // Cannot hold any item with 0 items
  }

  // Fill the DP table using the knapsack logic
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      // If current item's weight is less than or equal to the capacity
      if (wt[i - 1] <= j) {
        // Consider two options: include or exclude the current item
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);  // Include or exclude
      } else {
        // If current item's weight is greater than capacity, exclude it
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // The maximum value achievable is in the bottom right corner of the DP table
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

  // Call the scaling and knapsack functions (if needed)
  int result = knapsack(W, wt, val, n);

  cout << "Maximum value: " << result << endl;

  return 0;
}
