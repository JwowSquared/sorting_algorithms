#include "sort.h"

/**
* selection_sort - algo that finds the smallest number and fits it in place
* @array: array to sort
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t idx, i, min;

	if (array == NULL || size < 2)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		min = idx;
		for (i = idx + 1; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		if (min != idx)
		{
			temp = array[idx];
			array[idx] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
