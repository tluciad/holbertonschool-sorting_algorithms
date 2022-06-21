#include "sort.h"
/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: Array to set in order
 * @size: size parameter
 */
void bubble_sort(int *array, size_t size)
{
	int new = 1;
	size_t i;

	if (size < 2)
		return;

	while (new == 1)
	{
		new = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				array[i] = array[i] + array[i + 1];
				array[i + 1] = array[i] - array[i + 1];
				array[i] = array[i] - array[i + 1];
				print_array(array, size);
				new = 1;
			}
		}
	}
}
