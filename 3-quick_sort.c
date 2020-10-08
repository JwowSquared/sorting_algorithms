#include "sort.h"

/**
* lomuto - implementation of the lomuto partition for quick sort
* @array: array to modify
* @size: length of the array
* @left: left bound of the current partition
* @right: right bound of the current partition
*
* Return: index to split on
*/
int lomuto(int *array, size_t size, int left, int right)
{
	int pivot = array[right], i = left - 1, j;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			array_swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}
	array_swap(array, i + 1, right);
	if (i + 1 != right)
		print_array(array, size);
	return (i + 1);
}

/**
* r_quick_sort - function that does most of the quick sorting
* @array: array to modify
* @size: length of the array
* @left: left bound of current partition
* @right: right bound of current partition
*/
void r_quick_sort(int *array, size_t size, int left, int right)
{
	int div;

	if (left < right)
	{
		div = lomuto(array, size, left, right);
		r_quick_sort(array, size, left, div - 1);
		r_quick_sort(array, size, div + 1, right);
	}
}

/**
* quick_sort - nice fast efficient sorting algorithm
* @array: array to sort
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	r_quick_sort(array, size, 0, size - 1);
}

/**
* array_swap - swaps two elements from an array
* @array: array to swap within
* @left: left element to be swapped with right
* @right: right element to be swapped with left
*/
void array_swap(int *array, int left, int right)
{
	int temp = array[left];

	array[left] = array[right];
	array[right] = temp;
}
