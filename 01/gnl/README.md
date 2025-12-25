<i>This project has been created as part
of the 42 curriculum by joasampa</i>

## Description

The goal of this project is to implement the function get_next_line, which reads a file descriptor line by line.
Each call to the function returns the next line from the file, including the newline character (\n) when present.
The main challenge of this project is to correctly handle partial reads, memory management, and persistent state between function calls, while respecting strict constraints such as buffer size, function length, and coding style.

## Instructions

The project must be compiled with a user-defined buffer size using the BUFFER_SIZE macro.
Example compilation command:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c

Algorithm Explanation

The algorithm relies on a static buffer (stash) that persists between calls to get_next_line The workflow is as follows:

1- A static stash is maintained for each file descriptor to store unread data.
2- Data is read from the file into a temporary buffer until a newline is found or EOF is reached.
3- The buffer is appended to the stash.
4- Once a newline is present (or EOF occurs), a line is extracted from the stash.
5- Any remaining data after the extracted line is kept in the stash for the next call.
6- The extracted line is returned to the caller.

This approach ensures that lines spanning multiple reads are handled correctly and that no data is lost between calls

## Resources

Documentation & References
man 2 read
man 3 malloc
man 3 free
The official 42 subject PDF for get_next_line

AI Usage

Artificial intelligence was used as a learning and debugging aid during the development of this project.
AI assistance was used to:

- Clarify algorithmic concepts

- Understand edge cases

- Review code logic and explanations

- All code was written, tested, and validated by the author, and the final implementation fully complies with the project specifications and constraints.