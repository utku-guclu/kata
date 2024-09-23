#include <iostream>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class PandigitalProducts {
private:
    unordered_set<int> uniqueProducts;
    int pandigitalMasks[10];

    bool isPandigital(long long num, int n) {
        int mask = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0 || digit > n || (mask & (1 << digit))) return false;
            mask |= (1 << digit);
            num /= 10;
        }
        return mask == pandigitalMasks[n];
    }

public:
    PandigitalProducts() {
        // Pre-compute pandigital masks
        for (int n = 1; n <= 9; ++n) {
            pandigitalMasks[n] = (1 << (n + 1)) - 2;
        }
    }

    long long solve() {
        for (int n = 2; n <= 9; ++n) {
            int maxProduct = pow(10, n) - 1;
            
            for (int i = 1; i <= sqrt(maxProduct); ++i) {
                for (int j = i; j <= maxProduct / i; ++j) {
                    int product = i * j;
                    if (product > maxProduct) break;
                    
                    string combined = to_string(i) + to_string(j) + to_string(product);
                    if (combined.length() == n && isPandigital(stoll(combined), n)) {
                        uniqueProducts.insert(product);
                    }
                }
            }
        }

        long long sum = 0;
        for (int product : uniqueProducts) {
            sum += product;
        }
        return sum;
    }
};

int main() {
    PandigitalProducts solver;
    long long result = solver.solve();
    cout << "The sum of all pandigital products is: " << result << endl;
    return 0;
}
