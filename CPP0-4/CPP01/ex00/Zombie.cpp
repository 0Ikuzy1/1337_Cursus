#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string namee)
{
    name = namee;
}

std::string Zombie::getname( void )
{
    return(name);
}