#include <iostream>

using namespace std;

int bsearch(vector<int> &arr, int low, int high, int num) {
  if (high >= low) {
    int mid = low + (high - low) / 2; // evita overflow

    if (arr[mid] == num)
      return mid;

    if (arr[mid] > num)
      return bsearch(arr, low, mid - 1, num);

    return bsearch(arr, mid + 1, high, num);
  }
  return -1; // indica erro
}

int main(int argc, char *argv[]) {
  vector<int> arr;
  int num = 10;
  int size = arr.size();
  int low = 0;
  int high = size - 1;
  return 0;
}
