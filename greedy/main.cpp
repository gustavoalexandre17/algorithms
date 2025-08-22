#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// maximizando o numero de atividades que nao
// ocorrem ao mesmo tempo

struct activity {
  int begin, end;
};

bool compare(const activity &a, const activity &b) { return a.end < b.end; }

int main(int argc, char *argv[]) {
  vector<activity> act = {{2, 4},  {4, 5}, {6, 9},  {9, 10},
                          {8, 12}, {6, 7}, {15, 16}};
  sort(act.begin(), act.end(), compare);

  int count = 0;
  int last_end = -1;

  for (const auto &a : act) {
    if (a.begin >= last_end) {
      last_end = a.end;
      count++;
    }
  }

  std::cout << "Total activities: " << count << endl;
  return 0;
}
