#include "search_algos.h"

/**
 * print_arr - helper func to print array everytime array is halved
 * @array: array
 * @l: left index of original array
 * @r: right index of original array
 **/
void print_arr(int *array, size_t l, size_t r)
{
	size_t i;

	printf("Searching in array: ");
	for (i = l; i <= r; i++)
	{
		if (i != r)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}


/**
 * binary_search - search for target value and return index
 * @array: array
 * @size: size of array
 * @value: target value
 * Return: index; or -1 if not found
 **/
int binary_search(int *array, size_t size, int value)
{
	size_t mid;
	size_t l = 0;
	size_t r = size - 1;

	if (!array)
		return (-1);

	while (l <= r)
	{
		print_arr(array, l, r);
		mid = (l + r) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			r = mid;
		else
			l = mid + 1;
	}
	return (-1);
}
