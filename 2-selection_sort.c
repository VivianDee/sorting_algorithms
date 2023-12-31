#include "sort.h"

/**
* selection_sort - Sorts an array using the Selection sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	int check = 0, min = 0;

	if (!array || size == 0)
		return;

	min = array[0];
	while (i < size)
	{
		for (k = i; k < size; k++)
		{
			if (array[k] <= min)
			{
				min = array[k];
			}
		}
		if (array[i] == min)
			min *= 100;

		check = array[i];
		for (j = i; j < size; j++)
		{
			if (check > array[j] && array[j] <= min)
			{
				min = array[j];
				array[j] = check;
				check = min;
				array[i] = check;
				print_array(array, size);
				min = array[j];
			}
		}
		i++;
	}
}
