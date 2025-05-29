#include "phonebook.hpp"

void    Contact::set_contact(const std::string &fn , const std::string &ln , const std::string &nn, const std::string &pn , const std::string &ds, int i)
{
    Index = i + 1;
    first_name = fn;
    last_name = ln;
    nickname = nn;
    phone_number = pn;
    darkest_secret = ds;
}
std::string Contact::get_fn() const{return first_name;}

std::string Contact::get_ln() const{return last_name;}

std::string Contact::get_nn() const{return nickname;}

std::string Contact::get_pn() const{return phone_number;}

std::string Contact::get_ds() const{return darkest_secret;}

int Contact::get_index() const{return Index;}