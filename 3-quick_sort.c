#include "sort.h"

/**
 * quick_sort - sort an array using Quick sort
 * algorithm, Lomuto partition scheme
 * @array: array of numbers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int i = 0;
	int j = - 1;
	int temp;
	int p = array[size - 1];
	
	if (size <= 1)
		return;
	
	for(i = 0; i < (int)(size - 1); i++)
	{
		if (array[i] <= p)
		{
			j++;
			temp = array[i];
			array[i] = array [j];
			array[j] = temp;
		}
	}
	temp = array[j + 1];
	array[j + 1] = p;
	array[size - 1] = temp;
	print_array(array,size);
	quick_sort(array, j + 1);
	quick_sort(&array[j + 2], size - (j + 2));
}
