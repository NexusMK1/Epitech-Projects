#ifndef	READ_SIZE
#define	READ_SIZE (3)
#endif	/* !READ_SIZE */

#ifndef	GET_NEXT_LINE_H_

#define	GET_NEXT_LINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(const int fd);

#endif
