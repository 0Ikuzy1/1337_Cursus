#include "phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::string cmd = "ADD";
    int i = 0;
    int j = 0;

    while (cmd != "Exit")
    {
        std::cout << "enter a command: ";
        if (!getline(std::cin, cmd) || std::cin.eof())
            return 0;
        else if (cmd == "ADD")
        {
            if (i > 7)
                i = i % 8;
            if (phonebook.get_info(i) == 0)
            {
                i++;
                if (j < 8)
                    j++;
            }
        }
        else if (cmd == "SEARCH")
        {
            if (j == 0)
                std::cout << "The Phonebook is empty currently" << std::endl;
            else
                helper(phonebook, j);
        }
        else if (cmd == "EXIT")
            break;
    }
    return (0);
}
