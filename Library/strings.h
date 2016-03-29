#pragma once
#ifndef _STRINGS_H
#define _STRINGS_H

/**
 * Removes character at given position 'pos' from string 'str'
 */
char* str_pos_del(char* str, size_t pos);

/**
 * Adds character 'ch' at given position 'pos' to string 'str'
 */
char* str_pos_add(char* str, size_t pos, const char ch);

/**
 * Deletes all given characters 'ch' from string 'str'
 */
char* str_chr_del(char* str, const char ch);

/**
 * Replaces 'find' characters with 'replace' ones
 */
char* str_chr_replace(char* str, const char find, const char replace);

/**
 * Returns count of all 'find' characters in string 'str'
 */
size_t str_chrs_count(const char* str, const char* find);

/**
* Returns count of 'find' character in string 'str'
*/
size_t str_chr_count(const char* str, char find);

/**
 * Compares the two strings and returns 0 if they are equal,
 * 1 if the first string bigger than the second and -1 otherwise
 */
__int8 str_cmp(const char* str1, const char* str2);

/**
 * Converts string 'str' to int and return it
 */
__int64 str_to_int(const char* str);

/**
 * Converts number to string and returns pointer to string
 */
char* int_to_str(__int64 num);


/**
 * Converts all characters in string to uppercase
 */
char* str_to_upper(char* str);


/**
* Converts all characters in string to lowercase
*/
char* str_to_lower(char* str);


/**
 * Reverse string and return pointer to new string
 */
char* str_rev(const char* str);


/**
 * Replaces 'find' string with 'replace' string in 'str' and returns new pointer to 'str'
 */
char* str_str_replace(const char* str, const char* find, const char* replace);


/**
 * Returns pointer to longest string
 */
char* str_find_max(char** str, size_t count);


/**
 * Returns array of pointers to words start. Set replace to 1 if you want replace separators with '\0'
 */
char** str_to_words(char* str, size_t* count, const char* separators, __int8 replace);

#endif /* _STRINGS_H */