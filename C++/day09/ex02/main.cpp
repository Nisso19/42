#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
	std::cout << "Usage: ./PmergeMe number [...]" << std::endl;
	return (1);
    }

	clock_t start;
	clock_t start2;
	double clock_per_us;
	double timeVector;
	double timeList;

	clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000000;

    int i = 1;
    int j = 0;
    while (argv[i])
    {
        while(argv[i][j])
        {
            if(argv[i][j] < '0' || argv[i][j] > '9')
                return(std::cout << "Invalid input\n", 0);
            j++;
        }
        j = 0;
        i++;
    }
    int *array = new int[argc];
    char *endptr = NULL;
    i = 0;
    while(i != argc - 1)
    {
        errno = 0;
        array[i] = strtol(argv[i + 1], &endptr, 10);
        if(array[i] < 0)
             return(delete[] array, std::cout << "Invalid input, number < 0\n", 0);
        if(argv[i] == endptr)
            return(delete[] array,std::cout << "Invalid input\n", 0);
        if(errno != 0)
            return(delete[] array,std::cout << "Invalid input\n", 0);
        i++;
    } 
    int *array2 = new int[argc];
    memcpy(array2, array, sizeof(int) * i + 1);
    std::cout << "Avant : "; 
    j = 1;
    while(argv[j])
    {
        std::cout << argv[j] << " ";
        j++;
    }
    std::cout << std::endl;
    start = clock();
    PmergeMe SortVector(array, i, 0);
    timeVector = (clock() - start) / clock_per_us;
    std::cout << "Apres : ";
    SortVector.printContainer();
	std::cout << "----------------------------------------" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeVector  << "ms" << std::endl;
    start2 = clock();
    PmergeMe SortList(array2, i, 1);
    timeList = (clock() - start2) / clock_per_us;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << timeList << "ms" << std::endl;
    delete[] array;
    delete[] array2;
    return 0;
}