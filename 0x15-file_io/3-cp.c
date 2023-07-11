#include "main.h"

/**
 * main - copy contents from one file to another
 * @ac: number of arguments
 * @av: arrary of arguments as strings
 * Return: returns 0 (Success)
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to;
	ssize_t read_char, written_char;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0664);
	while ((read_char = read(fd_from, buf, 1024)))
	{
		if (fd_from == -1 || read_char == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			exit(98);
		}
		written_char = write(fd_to, buf, read_char);
		if (fd_to == -1 || written_char == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}

	read_char = close(fd_from);
	written_char = close(fd_to);
	if (read_char == -1 || written_char == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
			read_char == -1 ? fd_from : fd_to);
		exit(100);
	}
	return (0);
}
