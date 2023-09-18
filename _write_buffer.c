#include <stdio.h>
#include <stddef.h>
#include "main.h"
#include <stdlib.h>
/**
 * write_buffer - Writes the contents of the buffer to stdout
 * @buffer: The buffer to be written
 * @buffer_i: Pointer to the index tracking the next free position
 *		in the buffer
 * @count: Pointer to the total number of characters that have been written
*/

void write_buffer(char *buffer, int *buffer_i, int *count)
{
	if (*buffer_i > 0)
	{
		write(1, buffer, *buffer_i);
		*count += *buffer_i;
		*buffer_i = 0;
	}
}
