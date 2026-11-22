*This project has been created as part of the 42 curriculum by rbourjal.*

# Description

`get_next_line()` reads from a file descriptor and returns one line per call.
The returned line includes `\n` when present. If the file does not end with
a `\n`, the last line is returned without it. It returns `NULL` at EOF or on error.

# Instructions

Compile the mandatory part with the default buffer size:

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

Or choose the buffer size at compilation:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

`main.c` is a test program; provide your own and free every line returned by `get_next_line()`.

## Algorithm

A static `stash` keeps the data that has not been returned yet. It keeps its value between calls to `get_next_line()`.

`read_to_stash()` reads data in chunks of `BUFFER_SIZE`. It stops when it finds a `\n` or reaches the end of the file. If `read()` returns an error, it frees the memory and returns `NULL`.

`gnl_strjoin()` joins the new data with the old stash and frees the old stash.

`extract_line()` takes the text up to the first `\n` and returns it, including the `\n`. If there is no `\n`, it returns the remaining text.

`trim_stash()` keeps the text after the returned line for the next call and frees the old stash.

This method can read lines of any length because it keeps reading until it finds a newline or reaches EOF. `BUFFER_SIZE` only controls how many bytes are read at a time.

For the bonus, I use `static char *stash[1024];` and access it with `stash[fd]`. Each file descriptor has its own stash, so its unread data stays separate. The file descriptor is checked against 1024 before it is used as an array index.

# Resources

- [`read(2)` manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [C static variabl](https://www.geeksforgeeks.org/c/static-variables-in-c/)

**AI use:** I used AI to explain the `read(2)` manual and static variables, review my understanding of the read/stash algorithm and memory management, suggest additional test cases, and clarify compilation and terminal commands. I wrote the implementation myself and used the explanations as learning and review support.
