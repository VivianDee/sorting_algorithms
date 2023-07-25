#include "sort.h"

/**
* quick_sort_recursive - Sorts an array recursively using
* the Quick sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high], temp = 0, i = low - 1, j;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, size);

		quick_sort_recursive(array, low, i, size);
		quick_sort_recursive(array, i + 2, high, size);
	}
}


/**
* quick_sort - Sorts an array using the Quick sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
