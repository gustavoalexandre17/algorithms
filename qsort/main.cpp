#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// particiona o vetor e retorna o indice do pivo
int parse(vector<int> &v, int begin, int end) {
  int pivot = v[end];
  int i = begin - 1;

  for (int j = begin; j < end; j++) {
    if (v[j] < pivot) {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i + 1], v[end]);
  return i + 1;
}

void quicksort(vector<int> &v, int begin, int end) {
  if (begin < end) {
    int pivotIndex = parse(v, begin, end);

    // elementos menores que o pivo
    quicksort(v, begin, pivotIndex - 1);

    // elementos maiores que o pivo
    quicksort(v, pivotIndex + 1, end);
  }
}

int main(int argc, char *argv[]) {
  vector<int> v = {1, 3, 2, 4, 92, 120, 121, 0, 1210, 10, 1};
  quicksort(v, 0, v.size() - 1);

  for (int n : v)
    cout << n << " ";
  cout << "\n";
  return 0;
}
