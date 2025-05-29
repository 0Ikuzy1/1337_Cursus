#include "phonebook.hpp"

int    Phonebook::get_info(int i)
{
    std::string fn, ln, nn, pn, ds;

    std::cout << "Enter your First Name: ";
    if (!std::getline(std::cin, fn) || isalphabetic(fn) == 1)
    {
        std::cout << "Invalid First Name" << std::endl;
        return 1;
    }
    std::cout << "Enter your last Name: ";
    if (!std::getline(std::cin, ln) || isalphabetic(ln) == 1)
    {
        std::cout << "Invalid Last Name" << std::endl;
        return 1;
    }
    std::cout << "Enter your NickName: ";
    if (!std::getline(std::cin, nn) || isprintable(nn) == 1)
    {
        std::cout << "Invalid NickName" << std::endl;
        return 1;
    }
    std::cout << "Enter your Phone Number: ";
    if (!std::getline(std::cin, pn) || isnum(pn) == 1)
    {
        std::cout << "Invalid Phone Number" << std::endl;
        return 1;
    }
    std::cout << "Enter your Darkest secret: ";
    if (!std::getline(std::cin, ds) || isprintable(ds) == 1)
    {
        std::cout << "Invalid Darkest secret" << std::endl;
        return 1;
    }
    contacts[i].set_contact(fn, ln, nn, pn, ds, i);
    return 0;
}

void    Phonebook::search(int i) const
{

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "     " << contacts[i].get_index() << "    |";
    if (contacts[i].get_fn().length() > 10)
        std::cout << contacts[i].get_fn().substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << contacts[i].get_fn() << "|";
    if (contacts[i].get_ln().length() > 10)
        std::cout << contacts[i].get_ln().substr(0,9) << ".|";
    else
        std::cout << std::setw(10) << contacts[i].get_ln() << "|";
    if (contacts[i].get_nn().length() > 10)
        std::cout << contacts[i].get_nn().substr(0,9) << ".|" << std::endl;
    else
        std::cout << std::setw(10) << contacts[i].get_nn() << "|" << std::endl;
}

void    Phonebook::display(int i) const
{
    std::cout << "First Name: " << contacts[i].get_fn() << std::endl;
    std::cout << "Last Name: " << contacts[i].get_ln() << std::endl;
    std::cout << "NickName: " << contacts[i].get_nn() << std::endl;
    std::cout << "Phone Number: " << contacts[i].get_pn() << std::endl;
    std::cout << "Darkest Secret: " << contacts[i].get_ds() << std::endl;
}