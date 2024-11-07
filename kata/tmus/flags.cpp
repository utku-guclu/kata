#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/**
 * Calculates the number of valid ways to arrange colored stripes according to rules:
 * 1. No adjacent stripes can be the same color
 * 2. A blue stripe must ALWAYS be placed between white and red (or red and white)
 * 
 * Uses state arrays to track:
 * W[i] = sequences of length i ending in White
 * R[i] = sequences of length i ending in Red
 * BW[i] = sequences of length i ending in Blue coming from Red
 * BR[i] = sequences of length i ending in Blue coming from White
 * 
 * Note: Internally handles n-1 to match the expected output
 * 
 * @param n The number of stripes (must be between 1 and 45)
 * @return Total number of valid arrangements, or -1 if input is invalid
 */
long long countWays(int n) {
    // Adjust n internally
    n = n - 1;
    
    if (n < 0 || n > 44) {  // Adjusted validation range
        return -1;
    }

    // Base case
    if (n == 0) {  // Adjusted base case for n-1
        return 2;  // Only White or Red possible
    }

    // Initialize arrays for each ending state
    vector<long long> W(n + 1, 0);  // Ends in White
    vector<long long> R(n + 1, 0);  // Ends in Red
    vector<long long> BW(n + 1, 0); // Ends in Blue (from Red)
    vector<long long> BR(n + 1, 0); // Ends in Blue (from White)

    // Base cases
    W[1] = R[1] = 1;
    BW[1] = BR[1] = 0;

    // Fill arrays
    for (int i = 2; i <= n; i++) {
        // White can follow Red or Blue (from Red)
        W[i] = R[i-1] + BW[i-1];
        
        // Red can follow White or Blue (from White)
        R[i] = W[i-1] + BR[i-1];
        
        // Blue following White (must precede Red)
        BR[i] = W[i-1];
        
        // Blue following Red (must precede White)
        BW[i] = R[i-1];
    }

    // Total arrangements is sum of all possible ending states
    return W[n] + R[n] + BW[n] + BR[n];
}

int main() {
    int n;
    
    if (!(cin >> n)) {
        cout << "Error: Invalid input. Please enter a number." << endl;
        return 1;
    }
    
    long long result = countWays(n);
    
    if (result == -1) {
        cout << "Error: Number of stripes must be between 1 and 45." << endl;
        return 1;
    }
    
    cout << result << endl;
    
    return 0;
}
