#include "sort.h"

/**
* bubble_sort - Sorts an array using the Bubble sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp = 0, check = 0;

	while (1)
	{
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[(i + 1)])
			{
				temp = array[i];
				array[i] = array[(i + 1)];
				array[(i + 1)] = temp;
				print_array(array, size);
			}
		}
		for (j = 0; j < (size - 1); j++)
			if (array[j] > array[(j + 1)])
				check = 1;

		if (!check)
			break;
		check = 0;
	}
}
