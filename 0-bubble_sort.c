#include "sort.h"

/**
 * bubble_sort - This sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the array
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = 1;
	int temp, flag = 1, on = 0;

	if (size < 2)
		return;
	while (flag == 1)
	{
		flag = 0;
		if (array[n] < array[n - 1] && n < size)
		{
			temp = array[n];
			array[n] = array[n - 1];
			array[n - 1] = temp;	/*swapped*/

			print_array(array, size);
			flag = 1;
			on = 0;
		}

		if (n == size - 1 && flag == 1)
		{
			n = 0;
			continue;
		}
		else if (n == size - 1 && flag == 0)
		{
			on += 1;
			if (on == 1)
			{
				flag = 1;
				n = 0;
				continue;
			}
			else if (on == 2)
				break;
		}
		else
			flag = 1;
		n++;
	}
}
