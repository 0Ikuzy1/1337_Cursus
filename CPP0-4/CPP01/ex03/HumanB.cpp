#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}