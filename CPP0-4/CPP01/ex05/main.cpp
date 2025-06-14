#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    Harl harl;
    std::string level = argv[1];
    harl.complain(level);
    return 0;
}
