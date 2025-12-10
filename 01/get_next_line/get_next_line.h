#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// If the user didn't pass -D BUFFER_SIZE=n when compiling,
// define a default BUFFER_SIZE.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

// Main function
char	*get_next_line(int fd);

// Helpers (your prototypes)
int		find_newline(char *s);
char	*join_and_free(char *s1, char *s2);
char	*extract_line(char *stash);
char	*extract_new_stash(char *stash);

#endif
