#include "main.h"

/**
 * validate_elf - Checks if an ELF file.
 * @fh: pointer to elf header string
 */
void validate_elf(Elf64_Ehdr *fh)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (fh->e_ident[i] == 127 ||
		    fh->e_ident[i] == 'E' ||
		    fh->e_ident[i] == 'L' ||
		    fh->e_ident[i] == 'F')
			continue;

		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Prints the magic numbers
 * @fh: pointer to elf header string
 */
void print_magic(Elf64_Ehdr *fh)
{
	int i = 0;

	printf("  Magic:   ");

	for (; i < EI_NIDENT; i++)
	{
		printf("%02x", fh->e_ident[i]);

		if (i + 1 == EI_NIDENT)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class
 * @fh: pointer to elf header string
 */
void print_class(Elf64_Ehdr *fh)
{
	printf("  Class:                             ");

	switch (fh->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", fh->e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data
 * @fh: pointer to elf header string
 */
void print_data(Elf64_Ehdr *fh)
{
	printf("  Data:                              ");

	switch (fh->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", fh->e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version
 * @fh: pointer to elf header string
 */
void print_version(Elf64_Ehdr *fh)
{
	printf("  Version:                           %d",
	       fh->e_ident[EI_VERSION]);

	if (fh->e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - Prints the OS/ABI
 * @fh: pointer to elf header string
 */
void print_osabi(Elf64_Ehdr *fh)
{
	printf("  OS/ABI:                            ");

	switch (fh->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", fh->e_ident[EI_OSABI]);
	}
}

/**
 * print_abiversion - Prints the ABI version
 * @fh: pointer to elf header string
 */
void print_abiversion(Elf64_Ehdr *fh)
{
	printf("  ABI Version:                       %d\n",
	       fh->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type
 * @fh: pointer to elf header string
 */
void print_type(Elf64_Ehdr *fh)
{
	unsigned int e_type = fh->e_type;

	if (fh->e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = e_type >> 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point
 * @fh: pointer to elf header string
 */
void print_entry(Elf64_Ehdr *fh)
{
	unsigned long int e_entry = fh->e_entry;

	printf("  Entry point address:               ");

	if (fh->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);

		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (fh->e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
		return;
	}

	printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes file.
 * @elf: The file descriptor of the ELF file.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in ELF file
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *fh;
	int o_fd, r_fd;

	o_fd = open(argv[1], O_RDONLY);
	if (o_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	fh = malloc(sizeof(Elf64_Ehdr));
	if (fh == NULL)
	{
		close_elf(o_fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r_fd = read(o_fd, fh, sizeof(Elf64_Ehdr));
	if (r_fd == -1)
	{
		free(fh);
		close_elf(o_fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf(fh);
	printf("ELF Header:\n");
	print_magic(fh);
	print_class(fh);
	print_data(fh);
	print_version(fh);
	print_osabi(fh);
	print_abiversion(fh);
	print_type(fh);
	print_entry(fh);

	free(fh);
	close_elf(o_fd);
	return (0);
}
