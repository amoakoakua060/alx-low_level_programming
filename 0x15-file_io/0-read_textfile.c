#include "main.h"

/**
 * read_textfile - print in lowercase
 * @filename: name of file to read from
 * @letters: the number of letters to read from
 *
 * Return: ssize_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r_char = 0, p_char = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);
	if (filename == NULL || buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	r_char = read(fd, buffer, letters);
	if (r_char == -1)
		return (0);

	p_char = write(STDOUT_FILENO, buffer, r_char);
	if (r_char != p_char)
		return (0);

	free(buffer);
	close(fd);
	return (r_char);
}
