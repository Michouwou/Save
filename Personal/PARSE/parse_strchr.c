// HEADER

int     parse_strchr(char *str, int c)
{
    int i;
    
    i = 0;
    while (str[i] != 0 && str[i] != c)
        ++i;
    if (str[i] == 0)
        return (-1);
    return (i);
}