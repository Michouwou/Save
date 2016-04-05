// HEADER

char    *parse_strsstr(char *great, char *small, int *num)
{
    int i;
    int j;
    int k;
    
    i = 0;
    *num = 0;
    while (great[i] != 0)
    {
        j = 0;
        while (great[i + j] == small[j] && great[i + j] && small[j])
            ++j;
        if (small[j] == 0)
        {
            if (*num == 0)
                k = i;
            ++(*num);
        }
        ++i;
    }
    if (*num == 0)
        return (NULL);
    return (&(great[k]));
}