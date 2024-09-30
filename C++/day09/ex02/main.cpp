#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
	std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
	return (1);
    }

	clock_t start;
	double clock_per_us;
	double timeVector;
	double timeList;

	clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000000;

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
    int *array2 = new int[argc];
    memcpy(array2, array, sizeof(int) * i + 1);
    start = clock();
    PmergeMe SortList(array2, i, 1);
    timeList = (clock() - start) / clock_per_us;
    std::cout << "Temps list : " << timeList << "ms" << std::endl;
    // start = clock();
    // PmergeMe SortVector(array, i, 0);
    // timeVector = (clock() - start) / clock_per_us;
    // std::cout << "Temps vecteur : " << timeVector  << "ms" << std::endl;
    return 0;
}