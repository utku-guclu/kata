#include <iostream>
#include <cmath>

int main() {
    const int TOTAL_HATS = 9;
    const int PAINTED_HATS = 7;
    
    // Calculate the maximum guaranteed number of different collections
    int maxGuaranteedCollections = std::pow(2, PAINTED_HATS);
    
    std::cout << "The maximum number of guaranteed different hat collections (N) is: " 
              << maxGuaranteedCollections << std::endl;
    
    // Explain the reasoning
    std::cout << "\nExplanation:" << std::endl;
    std::cout << "1. Each dwarf has " << TOTAL_HATS << " hats, of which " << PAINTED_HATS << " will be painted." << std::endl;
    std::cout << "2. In the worst case, the dwarves can ensure that the same " << PAINTED_HATS 
              << " hat numbers are painted for all dwarves." << std::endl;
    std::cout << "3. This leaves " << TOTAL_HATS - PAINTED_HATS << " hat numbers potentially unpainted for each dwarf." << std::endl;
    std::cout << "4. With " << PAINTED_HATS << " hats, each having 2 color possibilities, we get 2^" 
              << PAINTED_HATS << " = " << maxGuaranteedCollections << " guaranteed different collections." << std::endl;
    std::cout << "5. Any attempt to guarantee more than this can be thwarted by the dwarves' choices." << std::endl;

    return 0;
}
