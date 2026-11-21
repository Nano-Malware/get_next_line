#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *stash, char *buf);
char	*gnl_substr(const char *s, size_t start, size_t len);

#endif
