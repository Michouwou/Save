// HEADER

int     parse_strschr(char *str, int c, int *num)
{
    int i;
    int j;
    
    i = 0;
    *num = 0;
    while (str[i] != 0)
    {
        if (str[i] == c)
        {
            if (!*num)
                j = i;
            ++(*num);
        }
        ++i;
    }
    if (*num == 0)
        return (-1);
    return (j);
}