// HEADER

char    *parse_strstr(char *great, char *small)
{
    int i;
    int j;
    
    i = 0;
    while (great[i] != 0)
    {
        j = 0;
        while (great[i + j] == small[j] && great[i + j] && small[j])
            ++j;
        if (small[j] == 0)
            return (&(great[i]));
        ++i;
    }
    return (NULL);
}