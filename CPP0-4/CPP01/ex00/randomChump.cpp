#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    Zombie* zombie;
    zombie->setname(name);
    zombie->announce();
}