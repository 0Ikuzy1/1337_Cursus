#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
// #include <algorithm>

class Contact
{
    private:
        int Index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void    set_contact(const std::string &fn , const std::string &ln , const std::string &nn, const std::string &pn , const std::string &ds, int i );
        int get_index() const;
        std::string get_fn() const;
        std::string get_ln() const;
        std::string get_nn() const;
        std::string get_pn() const;
        std::string get_ds() const;

};

#endif