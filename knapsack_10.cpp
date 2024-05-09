#include <iostream>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
  // ... (rest of the knapsack function remains the same)
  // Find a scaling factor to convert floats to integers
  int max_val = 0, max_wt = 0;
  for (int i = 0; i < n; i++) {
    max_val = max(max_val, val[i]);
    max_wt = max(max_wt, (int)wt[i]);
  }
  int scale = 1;
  while (max_val * scale <= INT_MAX && max_wt * scale <= INT_MAX) {
    scale *= 10;
  }

  // Scale weights and values to integers
  for (int i = 0; i < n; i++) {
    wt[i] *= scale;
    val[i] *= scale;
  }

  // Solve knapsack with integer weights and values
  int result = knapsack(W * scale, wt, val, n);

  // Convert result back to original units
  return result / scale;
}
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

  // Scale weights and values to integers if needed (as discussed previously)

  int result = knapsack(W, wt, val, n);

  cout << "Maximum value: " << result << endl;

  return 0;
}
