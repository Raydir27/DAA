#include <iostream>
#include <algorithm> 

using namespace std;

int printMaxActivities(int start[], int finish[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minFinishIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (finish[j] < finish[minFinishIndex]) {
        minFinishIndex = j;
      }
    }
    swap(start[i], start[minFinishIndex]);
    swap(finish[i], finish[minFinishIndex]);
  }

  int count = 0;
  int lastFinish = 0;

  cout << "Selected activities: ";
  for (int i = 0; i < n; i++) {
    if (start[i] >= lastFinish) {
      cout << "(" << start[i] << ", " << finish[i] << ") ";
      count++;
      lastFinish = finish[i];
    }
  }
  cout << endl;

  return count;
}

int main() {
  int n;
  cout << "Enter the number of activities: ";
  cin >> n;

  int start[n], finish[n];
  cout << "Enter start and finish times for each activity:\n";
  for (int i = 0; i < n; i++) {
    cin >> start[i] >> finish[i];
  }

  int maxActivities = printMaxActivities(start, finish, n);

  cout << "Maximum number of activities that can be performed: " << maxActivities << endl;

  return 0;
}
