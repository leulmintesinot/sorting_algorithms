#include "sort.h"

/**
 * swap_ints - swap two integers
 * @x: first integer to swap
 * @y: second integer to swap
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - sorts an array of int in ascending order
 * @array: of int to sort
 * @size: of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, length = size;
	bool check = false;

	if (array == NULL || size < 2)
		return;

	while (check == false)
	{
		check = true;
		for (a = 0; a < length - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_ints(array + a, array + a + 1);
				print_array(array, size);
				check = false;
			}
		}
		length--;
	}
}
