#pragma once

#include <stdio.h>

extern FILE *stdin;		/* Standard input stream.  */
extern FILE *stdout;	/* Standard output stream.  */
extern FILE *stderr;	/* Standard error output stream.  */

#define IN  stdin
#define OUT stdout
#define ERR stderr