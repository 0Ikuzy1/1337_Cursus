
#include <iostream>
#include <cctype>

void    print_upper(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (std ::isalpha(av[i]))
            std::cout<<(char)std ::toupper(av[i]);
        else
            std::cout<<av[i];
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (i < ac)
            print_upper(av[i++]);
        std::cout<<std::endl;
    }
    else
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
}
