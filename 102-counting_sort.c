#include "sort.h"

/**
* counting_sort - Sorts an array using the Counting sort algorithm
* @array: An array of integers
* @size: The size of the array
*
*/
void counting_sort(int *array, size_t size)
{
	int max = 0, buffer[1024], output[1024], check = 0, count = 0, k = 0;
	size_t i = 0, j = 0;

	if (!array || size == 0)
		return;
	while (i < size)
	{
		if (max < array[i])
			max = array[i];
		i++;
	}
	for (k = 0; k <= max; k++)
		buffer[k] = 0;
	i = 0;
	while (i < size)
	{
		check = array[i];
		count = 0;
		for (j = 0; j < size; j++)
			if (array[i] == array[j])
				count++;
		buffer[(array[i])] = count;
		i++; }
	for (k = 1; k <= max; k++)
		buffer[k] += buffer[k - 1];
	print_array(buffer, max + 1);
	i = 0;
	for (i = 0; i < size; i++)
	{
		check = array[i];
		output[(buffer[check] - 1)] = check;
		buffer[check]--; }
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
