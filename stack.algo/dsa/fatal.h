#ifndef _FATAL_H_
#define _FATAL_H_

#include <stdio.h>
#include <stdlib.h>

#define Error(msg) fprintf(stderr, "%s\n", msg), exit(1)

#endif
