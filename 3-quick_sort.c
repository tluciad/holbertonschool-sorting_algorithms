#include "sort.h"
/**
 * swap - function tha switch two indexes
 * @low: min value
 * @high: max value
 * @array: array to sort
 */
void swap(int array[], int low, int high)
{
	array[low] = array[low] + array[high];
	array[high] = array[low] - array[high];
	array[low] = array[low] - array[high];
}
/**
 * partition - function that make a pivot as a division point *
 * @array: array to sort
 * @low: min value
 * @high: max value
 * @size: size of array
 * Return: integer
 */
size_t partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high && array[i] != array[j])
	{
		swap(array, i, high);
		print_array(array, size);
	}
	return (i);
}
/**
 * _sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm *
 * @array: array to sort
 * @low: min value
 * @high: max value
 * @size: size of array
 */
void _sort(int array[], int low, int high, size_t size)
{
	int p = partition(array, low, high, size);

	if (low >= high)
		return;

	_sort(array, low, p - 1, size);
	_sort(array, p + 1, high, size);
}
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm *
 * @array: array to sort
 * @size:  size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	_sort(array, 0, size - 1, size);
}
