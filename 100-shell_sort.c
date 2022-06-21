#include "sort.h"

/* Shell sort*/
void shell_sort(int *array, size_t size)
{
	/* Rearrange elements at each n/2, n/4, n/8, ... intervals*/
	for (int interval = size / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < size; i += 1)
		{

			int temp = array[i];
			int j;

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
}
