#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - Displays the info contained in the ELF header @ start of an ELF file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd, i;
	ssize_t nread;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	nread = read(fd, &header, sizeof(header));
	close(fd);

	if (nread != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2]
			!= ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}

	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");

	/* Rest of your code to print the other fields... */

	return (0);
}
