#include <iostream>
#include <fstream>
#include <string>
#include "replace.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: cannot open input file." << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::string replaced = str_replace(content, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cout << "Error: cannot open output file." << std::endl;
        return 1;
    }
    outfile << replaced;
    outfile.close();

    return 0;
}
