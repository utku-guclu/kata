#include <iostream>
#include <bitset>

// Function to set the MSB of an integer
unsigned int setMSB(unsigned int n) {
    int numBits = sizeof(n) * 8; // Total number of bits in the number
    int msbMask = 1 << (numBits - 1); // Mask for the MSB
    return n | msbMask; // Set the MSB
}

int main() {
    unsigned int n = 0b001011; // Example binary number
    unsigned int result = setMSB(n);
    std::cout << "Number after setting MSB: " << std::bitset<8>(result) << std::endl;
    return 0;
}

