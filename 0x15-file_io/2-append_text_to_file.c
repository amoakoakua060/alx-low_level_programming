#include "main.h"

/**
 * main - copies content into another file
 * @ac: number of arguments
 * @av: arrary of arguments as strings
 *
 * Return: 0 (Success)
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to;
	ssize_t from, to;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	while ((from = read(fd_from, buffer, 1024)))
	{
		if (fd_from == -1 || from == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			exit(98);
		}
		to = write(fd_to, buffer, from);
		if (fd_to == -1 || to == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}
	from = close(fd_from);
	to = close(fd_to);
	if (from != -1 && to != -1)
		return (0);
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
			from == -1 ? fd_from : fd_to);
	exit(100);
}
