#include "Zombie.hpp"

int main() {
    Zombie *heapZombie = newZombie("FOO");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Foo");

    return 0;
}
