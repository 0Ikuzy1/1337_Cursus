#include "phonebook.hpp"

int isnum(std::string str)
{
    if (str.empty()) 
        return 1;
    int i = 0;
    while (str[i])
    {
        if (isdigit(str[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int isalphabetic(std::string str)
{
    if (str.empty()) 
        return 1;
    int i = 0;
    while (str[i])
    {
        if (isalpha(str[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int isprintable(std::string str)
{
    if (str.empty()) 
        return 1;
    int i = 0;
    while (str[i])
    {
        if (isprint(str[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

void    helper(Phonebook phonebook, int j)
{
    int i = 0;
    int s = 0;
    std::cout << "which Contact's details you want to acces ?" << std::endl << std::endl;
    std::cout << std::endl << "   Index  |";
    std::cout << "First Name|";
    std::cout << "Last Name |";
    std::cout << " NickName |" << std::endl;
    while (i < j)
        phonebook.search(i++);
    std::cout << "Enter the Index: ";
    if (!(std::cin >> s) || s < 1 || s > 8 || s > i)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    std::cout << std::endl;
    phonebook.display(s - 1);
    std::cout << std::endl;
}
