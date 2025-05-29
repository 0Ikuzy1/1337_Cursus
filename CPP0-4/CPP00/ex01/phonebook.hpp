#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
    public:
        Contact contacts[8];
        int    get_info(int i);
        void    search(int i) const;
        void    display(int i) const;
};

int isalphabetic(std::string str);
int isnum(std::string str);
void    helper(Phonebook phonebook, int j);
int isprintable(std::string str);

#endif