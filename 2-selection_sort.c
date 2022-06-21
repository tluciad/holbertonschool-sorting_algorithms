#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array to check
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int check;
	/*must have more than 2 elements to compare*/
	if (size < 2)
		return;
	if (array == NULL)
		return;

	/*i < size - 1 because single element is also min element*/
	for (i = 0; i < size - 1; i++) /*advance the position*/
	{                              /*through the entire array*/
		temp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[temp])
				temp = j;
		}
		if (i != temp)
		{
			check = array[i];
			array[i] = array[temp];
			array[temp] = check;
			print_array(array, size);
		}
	}
}
