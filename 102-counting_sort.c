#include "sort.h"
/**
 * counting_sort - A function that sorts an array using the counting sort
 * algorithm in c
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max;
	size_t i;
	int *count, output[10];

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int *) * max + 1);

	for (i = 0; i < max + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] == 
	}

	for (i = 1; i < size; i++)
		count[i] += count[i - 1];

	i = size - 1;
	while (array[i])
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	print_array(count, 100);

	for (i = 0; i < size; i++)
		array[i] = output[i];
}
