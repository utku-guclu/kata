#include <iostream>
using namespace std;

constexpr int calculateSeconds(int N, int M) { return N * (M + 1); }

int main() {
  int N, M;
  // read the two numbers
  cin >> N >> M;

  cout << calculateSeconds(N, M) << "\n";
  return 0;
}
