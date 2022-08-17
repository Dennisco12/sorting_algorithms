#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * It implements the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int last = size - 1, pivot, n, idx, temp;

	while (last != 0)
	{
		n = 0;
		pivot = array[last];
		while (n < last)
		{
			if (array[n] > pivot)
			{
				/* set a flag on array[n]*/
				idx = n;
				break;
			}
			n++;
		}
		if (n != last)
		{
			while (n != last)
			{
				n++;
				if (array[n] < pivot || n == last)
				{
					temp = array[n];
					array[n] = array[idx];
					array[idx] = temp;
					print_array(array, size);
					break;
				}
			}
		}
		else
			last -= 1;
	}
}
