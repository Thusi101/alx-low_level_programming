#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - - 1.
 * Othererwise -1.
 */

int create_file(const char *filename, char *text_content)
{
	int file;
	ssize_t nwrite;
	size_t len = 0;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		nwrite = write(file, text_content, len);
		if (nwrite == -1 || nwrite != (ssize_t)len)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}
