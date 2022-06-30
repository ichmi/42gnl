# gnl | 42sp

## Introduction
This project is about programming a function that returns a line read from a file descriptor. Here we have a very convenient function to any collection,
but it will also make you learn a highly interesting new concept in C programming like `static` variables, pre-processor statements, and memory management.

## How it works
Repeated calls (e.g., using a loop) to the `get_next_line` function should let you read the text file pointed to by the file descriptor, one line at a time, and the function should return the line that was read. If there is nothing else to read or if an error occurred, it will just return `NULL`.
The function works as expected both when reading a file and when reading from the standard input.
Note that the returned line will include the terminating \n character, except if the end of file was reached and does not end with a \n character.

You can explicitly define the buffer size for read() by setting the value of `BUFFER_SIZE` during compilation:
```bash
clang main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1024
```
The `get_next_line` function can manage multiple file descriptors at the same time. For example, if we can read from the file descriptors 3, 4 and 5, we should be
able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. It means that, we should be able to call get_next_line to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth. 

## Usage
Here is a simple exemple of how you can use it:
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd = open("files/enemy.txt", O_RDONLY);
	char *p = get_next_line(fd);
	while (p)
	{
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	return (0);
}
```
What will happen is that, `get_next_line` will return a line of the given file descriptor (value returned by the function `open`. i.e. value `3`). Each call on that file descriptor will get its next line until EOF (till we reach the end of the file and `read` function start returning `0`).
