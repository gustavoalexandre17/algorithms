#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int CAPACIDADE_MAX = 7;

int maxValue(int i, int j, const vector<int> &w, const vector<int> &v,
             int (*m)[CAPACIDADE_MAX + 1]) {
  if (i == 0 || j == 0) {
    return 0;
  }
  if (m[i][j] != -1) {
    return m[i][j];
  }
  if (w[i - 1] > j) {
    m[i][j] = maxValue(i - 1, j, w, v, m);
  } else {
    m[i][j] = max(maxValue(i - 1, j, w, v, m),
                  v[i - 1] + maxValue(i - 1, j - w[i - 1], w, v, m));
  }
  return m[i][j];
}

int main() {
  vector<int> weight = {4, 2, 7, 4, 13, 2};
  vector<int> value = {14, 21, 26, 18, 30, 10};

  const int n = weight.size();
  const int W = CAPACIDADE_MAX;

  int matrix[n + 1][W + 1];

  memset(matrix, -1, sizeof(matrix));

  cout << "Valor maximo: " << maxValue(n, W, weight, value, matrix) << endl;

  return 0;
}
