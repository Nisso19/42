#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
	std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
	return (1);
    }

    int i = 0;
    int *array = new int[argc];

    char *endptr = NULL;
    while(i != argc - 1)
    {
        errno = 0;
        array[i] = strtol(argv[i + 1], &endptr, 10);
        if(argv[i] == endptr)
            return(std::cout << "Invalid input\n", 0);
        if(errno != 0)
            return(std::cout << "Invalid input\n", 0);
        i++;
    }
    PmergeMe Sort(array, i, 0);
}