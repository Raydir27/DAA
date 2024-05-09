#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
  float value;
  float weight;
  float ratio; // value-to-weight ratio
};

bool compareRatio(const Item& a, const Item& b) {
  return a.ratio > b.ratio;
}

float fractionalKnapsack(Item items[], int n, int W) {
  float totalValue = 0.0f;
  int remainingWeight = W;

  // Sort items by value-to-weight ratio in descending order
  sort(items, items + n, compareRatio);

  // Iterate through items
  for (int i = 0; i < n; i++) {
    // If remaining weight allows taking the entire item
    if (remainingWeight >= items[i].weight) {
      totalValue += items[i].value;
      remainingWeight -= items[i].weight;
    // Otherwise, take a fraction of the item
    } else {
      float fraction = remainingWeight / items[i].weight;
      totalValue += items[i].value * fraction;
      remainingWeight = 0;
      break; // Stop after using remaining weight
    }
  }

  return totalValue;
}

int main() {
  int n, W;
  cout << "Enter the number of items: ";
  cin >> n;

  cout << "Enter the weight of the knapsack: ";
  cin >> W;

  Item items[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter value and weight for item " << i + 1 << ": ";
    cin >> items[i].value >> items[i].weight;
    items[i].ratio = items[i].value / items[i].weight;
  }

  float maxValue = fractionalKnapsack(items, n, W);
  cout << "Maximum value: " << maxValue << endl;

  return 0;
}
