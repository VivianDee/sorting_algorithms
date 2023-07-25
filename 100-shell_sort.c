#include "sort.h"

/**
* check_sorted - checks if an array is sorted at an
* interval of 'gap'
* @array: An array of integers
* @size: The size of the array
* @gap: The interval used in sorting the array
*
* Return:
* - 0 if array is not sorted
* - 1 if array is sorted
*/
int check_sorted(int *array, size_t size, size_t gap)
{
	size_t i = 0, j = gap;

	while (j < size)
	{
		if (array[i] > array[j])
			return (0);

		j++;
		i++;
	}
	return (1);
}


/**
* sort_sequence - Sorts an array with an interval of 'gap'
* @array: An array of integers
* @size: The size of the array
* @gap: The interval used in sorting the array
*
*/
void sort_sequence(int *array, size_t size, size_t gap)
{
	size_t i = 0, j = gap;
	int temp = 0;

	while (1)
	{
		if (array[i] > array[j])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		if ((j + 1) < size)
		{
			j++;
			i++;
		}
		else
		{
			j = gap;
			i = 0;
		}
		if (check_sorted(array, size, gap))
			break;
	}
}


/**
* shell_sort - Sorts an array using the Shell sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/
void shell_sort(int *array, size_t size)
{
	size_t sequence = 1;

	while ((sequence * 3 + 1) < size)
	{
		sequence = (sequence * 3) + 1;
	}
	while (sequence > 0)
	{
		sort_sequence(array, size, sequence);
		print_array(array, size);
		sequence = (sequence - 1) / 3;
	}
}
