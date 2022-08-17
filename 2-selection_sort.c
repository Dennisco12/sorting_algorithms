#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int temp, smallest, idx;
	size_t n, m;

	if (size <= 2)
		return;
	n = 0;
	while (n < size - 1)
	{
		smallest = array[n];
		m = n;
		while (m < size)
		{
			if (array[m] < smallest)
			{
				smallest = array[m];
				idx = m;
			}
			m++;
		}
		if (smallest != array[n])
		{
			temp = array[idx];
			array[idx] = array[n];
			array[n] = temp;
			print_array(array, size);
		}
		n++;
	}
}
