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
 * Returns all the lines up to first occurence of the string str in the 
 * file corresponding to the file descriptor fd
 **/
 
char    **parse_lgetl_from();
char    **parse_lgetl_to();
char    **parse_cgetn_from();
char    **parse_sgetn_from();
char    **parse_lgetn_from();
char    **parse_cgetn_to();
char    **parse_sgetn_to();
char    **parse_lgetn_to();
int     parse_cfirst();
int     parse_sfirst();
int     parse_xcfirst();
int     parse_xsfirst();
int     parse_first_pattern();
int     parse_xfirst_pattern();
int     parse_clast();
int     parse_slast();
int     parse_xclast();
int     parse_xslast();
int     parse_last_pattern();
int     parse_xlast_pattern();
int     parse_countc();
int     parse_counts();
int     parse_count_patterns();
int     parse_count_dims();
char    *parse_get_pattern();