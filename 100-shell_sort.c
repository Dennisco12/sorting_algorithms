#include "sort.h"

/**
 * shell_sort - A function that sorts an array in
 * ascending order using the Shell sort algorithm
 * The Knuth sequence was implemented (1, 4, 13, 40, ...)
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t knuth[20];
	size_t gap, idx, temp, smidx, num;
	int n = 1;

	knuth[0] = 1;
	while (n < 20)
	{
		knuth[n] = (knuth[n - 1] * 3) + 1;
		n++;
	}

	n = 0;
	while (knuth[n + 1] < size)
		n++;

	while (n >= 0)
	{
		gap = knuth[n];
		num = 0;
		while (num < gap)
		{
			idx = num;
			while (idx < size - 1)
			{
				smidx = idx;
				while (idx + gap < size)
				{
					if (array[idx + gap] < array[smidx])
						smidx = idx + gap;
					gap += knuth[n];
				}
				if (smidx != idx)
				{
					temp = array[idx];
					array[idx] = array[smidx];
					array[smidx] = temp;
				}
				gap = knuth[n];
				idx += gap;
			}
			num++;
		}
		print_array(array, size);
		n--;
	}
}
