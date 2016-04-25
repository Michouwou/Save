// HEADER

int     parse_strchr(char *str, int c);
/**
 * Returns the index of the first occurence of the character of ASCII value c
 **/

int     parse_strschr(char *str, int c, int *num);
/**
 * Returns the index of the first occurence of the character of ASCII value c
 * and stores in num the total number of occurences of this character itn str
 **/

char    *parse_strstr(char *great, char *small);
/**
 * Returns a pointer to the first occurence of the string small in great
 **/
 
char    *parse_strsstr(char *great, char *small, int *num);
/**
 * Returns a pointer to the first occurence of the string small in great
 * and stores in num the total number of occurences of small
 **/

int     parse_match(char *str, char *pattern);
/**
 * Returns 1 if the pattern matches at least the 'beginning' of str, 0 if not
 **/
 
char    **parse_pattern(char *str, char *pattern);
/**
 * Returns a bi-dimensional array (tab[][]) containing all the substrings in
 * str corresponding to the pattern 'pattern' and terminated by a NULL pointer
 * --- The pattern has the form 'aaaiiiAAA*...' where 'a' is a lower case
 * letter, 'A' is an upper case letter, 'i' is a number, '*' is a wildcard and
 * '.' represents non-alphanumeric characters
 **/
 
char    **parse_split_c(char *str, int c);
/**
 * The same as ft_strsplit
 **/
 
char    **parse_split_s(char *str, char *separator);
/**
 * Returns a bi-dimensional array containing the the content of str, separated
 * according to 'separator' (not included)
 **/
 
char    **parse_cgetl_from(int fd, int c);
/**
 * Returns all the lines from the first occurence of the character c in the file
 * corresponding to the file descriptor fd
 **/
 
char    **parse_cgetl_to(int fd, int c);
/**
 * Returns all the lines up to the first occurence of the character c in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_sgetl_from(int fd, char *str);
/**
 * Returns all the lines from the first occurence of the string str in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_sgetl_to(int fd, char *str);
/**
 * Returns all the lines up to the first occurence of the string str in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_lgetl_from(int fd, char *line);
/**
 * Returns all the lines from the first occurence of the line 'line' in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_lgetl_to(int fd, char *line);
/**
 * Returns all the lines up to  the first occurence of the line 'line' in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_cgetn_from(int fd, int c);
/**
 * Returns n lines from the first occurence of the character c in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_sgetn_from(int fd, char *str);
/**
 * Returns n lines from the first occurence of the string str in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_lgetn_from(int fd, char *line);
/**
 * Returns n lines from the first occurence of the line 'line' in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_cgetn_to(int fd, int c);
/**
 * Returns n lines up to the first occurence of the character c in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_sgetn_to(int fd, char *str);
/**
 * Returns n lines up to the first occurence of the string str in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_lgetn_to(int fd, char *line);
/**
 * Returns n lines up to the first occurence of the line 'line' in the 
 * file corresponding to the file descriptor fd
 **/
 
int     parse_sfirst(char *great, char *small);
/**
 * Returns the index of the first character of the first occurence of the
 * string small in great
 **/
 
int     parse_xcfirst(int c, char **tab);
/**
 * Returns the index of the string in which the first occurence of c is found
 **/
 
int     parse_xsfirst(char *str, char **tab);
/**
 * Returns the index of the string in which the first occurence of str is found
 **/
 
int     parse_first_pattern(char *pattern, char *str);
/**
 * Returns the index of the first character of the first occurence of pattern
 * in str
 **/
 
int     parse_xfirst_pattern(char *pattern, char **tab);
/**
 * Returns the index of the strign in which the first of pattern is found
 **/
 
int     parse_clast(int c, char *str);
/**
 * Returns the index of the last occurence of the character c in str
 **/
 
int     parse_slast(char *small, char *great);
/**
 * Returns the index of the first character of the last occurence of the 
 * string small in great
 **/
 
int     parse_xclast(int c, char **tab);
/**
 * Returns the index of the last string in which the character c was found
 **/
 
int     parse_xslast(char *str, char **tab);
/**
 * Returns the index of the last string in which an occurence of the string str
 * was found
 **/
 
int     parse_last_pattern(char *pattern, char *str);
/**
 * Returns the idnex of the first character of the last 'pattern' found in str
 **/
 
int     parse_xlast_pattern(char *pattern, char **tab);
/**
 * Returns the index of the last string where an occurence of the 'pattern' was
 * found
 **/
 
int     parse_countc(int c, char *str);
/**
 * Returns the number of occurences of c found in str
 **/
 
int     parse_counts(char *small, char *great);
/**
 * Returns the number of occurences of small in great
 **/
 
int     parse_count_patterns(char *pattern, char *str);
/**
 * Returns the number of occurences of 'pattern' in str
 **/
 
int     parse_count_dims(char *dim, char **tab);
/**
 * Returns the number of strings strictly equals to dim found in tab
 **/
 
char    *parse_get_pattern(char *str);
/**
 * Returns a pattern that corresponds to str, so that it can be reused
 * somewhere else
 **/
 
int     parse_countw(char *str)
/**
 * Returns the number of words in str
 **/