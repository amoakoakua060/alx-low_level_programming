#include "main.h"

/**
 * append_text_to_file - create and append to file
 * @filename: name of file to read from
 * @text_content: string to append into file
 *
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;
	ssize_t check_write = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
		while (text_content[len] != '\0')
			len++;

	check_write = write(fd, text_content, len);
	if (check_write == -1)
		return (-1);

	close(fd);
	return (1);
}
