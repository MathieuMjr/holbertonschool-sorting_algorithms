#include "sort.h"

/**
 * bubble_sort - sort data inside an array
 * @array: adress of the array
 * @size: number of element
 *
 * Return:
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i; /*loop counter*/
	int swap_counter = 1; /*pour rentrer dans la while
							swap_counter ne doit pas être 0
							ensuite il incrémentera dès qu'une condition
							de swap est rencontrée*/
	int temp;/*stock la valeur */

	while (swap_counter != 0)
	{
		swap_counter = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap_counter++;
				print_array(array, size);
			}
		}
	}
}
