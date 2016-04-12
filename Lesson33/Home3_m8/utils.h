#pragma once
#ifndef _UTILS_H
#define _UTILS_H

/*
 * Returns count of characters in integer
 */
size_t num_char_count(__int64 num);

/**
 * Returns 1 if character is digit and 0 if not
 */
__int8 is_digit(char ch);

/**
 * Returns 1 if character is letter and 0 if not
 */
__int8 is_letter(char ch);

/**
 * Free ptr-to-ptr
 */
void* free_ptr_ptr(void **ptr, size_t count);

/**
* Returns x ^ y
*/
__int64 pow(__int64 x, __int64 y);

/**
* Returns absolute
*/
__int64 _llabs(__int64 x);

#endif