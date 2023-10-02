#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends txt at end of file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: if function fails or filenames is NULL -- 1.
 * if the file does not exist the user lacks write permisssions - -1.
 * Otherwise -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	ssize_t nwrite;
	size_t len = 0;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);
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
