#include "main.h"

/**
 * read_textfile - read from file
 * @filename: name of file to read from
 * @letters: the number of letters to read from
 * Return: ssize_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t c_read = 0, printed = 0;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	c_read = read(fd, buffer, letters);
	if (c_read == -1)
		return (0);

	printed = write(STDOUT_FILENO, buffer, c_read);
	if (c_read != printed)
		return (0);

	close(fd);
	free(buffer);
	return (c_read);
}
