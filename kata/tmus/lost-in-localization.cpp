#include <iostream>
#include <string>

std::string getDesignation(int n) {
  if (1 <= n && n <= 4) {
    return "few";
  } else if (5 <= n && n <= 9) {
    return "several";
  } else if (10 <= n && n <= 19) {
    return "pack";
  } else if (20 <= n && n <= 49) {
    return "lots";
  } else if (50 <= n && n <= 99) {
    return "horde";
  } else if (100 <= n && n <= 249) {
    return "throng";
  } else if (250 <= n && n <= 499) {
    return "swarm";
  } else if (500 <= n && n <= 999) {
    return "zounds";
  } else if (n >= 1000) {
    return "legion";
  } else {
    throw std::out_of_range("Input value is out of range");
  }
}

int main() {
  int n;
  std::cin >> n;

  try {
    std::cout << getDesignation(n) << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
