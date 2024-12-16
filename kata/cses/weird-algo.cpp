#include <bits/stdc++.h>
using namespace std;

int weird(int num) {
  if (num % 2 == 0) {
    num /= 2;
  } else {
    num = 3 * num + 1;
  }
  return num;
}

int main() {
  int num{};
  cin >> num;

  while (num != 1) {
    num = weird(num);
    cout << num << " ";
  }

  return 0;
}
