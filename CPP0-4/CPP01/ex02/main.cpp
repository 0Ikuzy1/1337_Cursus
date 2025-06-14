#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // Print memory addresses
    std::cout << "Memory address of str:      " << &str << std::endl;
    std::cout << "Memory address held by PTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by REF: " << &stringREF << std::endl;

    // Print values
    std::cout << "Value of str:               " << str << std::endl;
    std::cout << "Value pointed by PTR:       " << *stringPTR << std::endl;
    std::cout << "Value pointed by REF:       " << stringREF << std::endl;

    return 0;
}
