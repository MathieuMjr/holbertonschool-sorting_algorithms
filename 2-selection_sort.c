#include "sort.h"

/**
 * selection_sort - sort data inside an array
 * with selection algorithm
 * @array: adress of the array
 * @size: number of element
 *
 * Return:
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i;
	unsigned long int j;
	int v_min;
	int i_min;

	for (i = 0; i < size; i++)
	{
		v_min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i] && array[j] < v_min)
			{
				v_min = array[j];
				/*printf("%d\n", v_min);*/
				i_min = j;
			}
		}
		if (v_min < array[i])
		{
			array[i_min] = array[i];
			array[i] = v_min;
			print_array(array, size);
		}
	}
}
