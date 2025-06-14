#include "Zombie.hpp"

int main()
{
    int N = -10;

    Zombie *horde = zombieHorde(N, "FOO ");
    if (!horde)
    {
        std::cout << "N must be greater than 0." << std::endl;
        return 1;
    }
    int i = 0;
    while (i < N) {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return 0;
}
