#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a = "";
    std::cin >> a;

    string b = "";
    std::cin >> b;

    int len1 = a.size();
    int len2 = b.size();

    std::cout << len1 + " " << len2 << "\n";

    std::cout << a + b << "\n";
    char x = {};  
    x = a[0];
    a[0] = b[0];
    b[0] = x;
    
    std::cout << a + " " + b;

    return 0;
}
