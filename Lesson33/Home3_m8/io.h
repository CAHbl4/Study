#pragma once
#ifndef _IO_H
#define _IO_H
#define HALT	""
#include <stdio.h>

/**
* Flushes the given stream
*/
void flush_stream(FILE* fp);

/**
 * Returns the pointer to string readed from given stream
 */
char* read_string(FILE* fp);

/**
* Returns the pointer to array of pointer to strings readed from given stream
*/
char** read_strings(FILE*fp, char** str, size_t* count);

/**
 * Returns the integer readed from given stream
 */
__int64 read_int(FILE* fp);


/**
* Returns the character readed from given stream
*/
char read_char(FILE* fp);


#endif /* _IO_H */