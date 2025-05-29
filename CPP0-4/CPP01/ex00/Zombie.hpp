#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"

class Zombie{
    private:
        std::string name;

    public:
        void setname(std::string namee);
        std::string getname( void );
        void announce( void );
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
};

# endif