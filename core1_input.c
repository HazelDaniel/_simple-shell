#include "utils/main.h"

ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	char *buffer = NULL, read_c = '\0';
	static ssize_t count;
	int read_n = 0, ret, i = 0;

	if (count == 0)
		fflush(stream);
	else
		return(-1);

	count = 0;

	buffer = malloc(120 * sizeof(char));
	if (buffer == NULL)
		return (-1);

	while (read_c != '\n')
	{
		read_n = read(STDIN_FILENO, &read_c, 1);
		if (read_n == -1 || (read_n == count == 0))
		{
			free(buffer);
			break;
		}
		if (read_n == 0 && count)
		{
			/*normal end of stream*/
			count++;
			break;
		}
		if (count >= 120)
			buffer = _realloc(buffer, _al_len_(buffer), _al_len_(buffer) + 1);
		if (buffer == NULL)
			return (-1);
		buffer[count] = read_c;
		count++;
	}
	buffer[count] = '\0';

	// find a way to copy the buffer into the dynamic buffer address lineptr
	// *line_ptr = buffer;
	// for (; i < count; i++)
	// {
	// 	(*line_ptr)[i] = buffer[i];
	// 	if (i == *n)
	// 		(*n)++;
	// }
	// (*line_ptr)[i] = '\0';

	ret = count;
	if (read_n)
		count = 0;
	return (ret);
}
