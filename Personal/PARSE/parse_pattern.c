// HEADER

char    **parse_pattern(char *str, char *pattern)
{
    int     i;
    int     k;
    char    **ret;
    
    ret = (char**)malloc(sizeof(char*) *
        (parse_count_patterns(pattern, str) + 1));
    k = 0;
    while (str[i] != 0)
    {
        if (parse_match(&(str[i]), pattern))
            ret[k++] = ft_strsub(str, i, ft_strlen(pattern));
        ++i;
    }
    ret[k] = NULL;
    return (ret);
}