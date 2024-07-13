#include <string>
#include <iostream>
#include <string_view>
#include <cassert>

std::string createPhoneNumber(const int arr[10]){
    // Ensure the array has exactly 10 elements
    // Note: sizeof(arr) / sizeof(arr[0]) will not work as expected here because arr is a pointer in this context.
    //       We rely on the caller to ensure the array size is correct.
    
    std::string phoneNumber = "(";
    for (int i = 0; i < 10; ++i)
    {
        phoneNumber += std::to_string(arr[i]);
        if (i == 2)
            phoneNumber += ") ";
        else if (i == 5)
            phoneNumber += "-";
    }
    return phoneNumber;
}

int main()
{
    constexpr int phoneNumberArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::string phoneNumber = createPhoneNumber(phoneNumberArray); // => returns "(123) 456-7890"
    std::string_view phoneNumberView(phoneNumber);
    std::cout << phoneNumberView << "\n";

    return 0;
}

