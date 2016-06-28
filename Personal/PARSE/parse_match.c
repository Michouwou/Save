// HEADER

static int  is_punctuation(char c)
{
    if (c > 32 && c < 48)
        return (1);
    else if (c > 57 && c < 65)
        return (1);
    else if (c > 90 && c < 97)
        return (1);
    else if (c > 122 && c < 127)
        return (1);
    return (0);
}

int         parse_match(char *str, char *pattern)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (str[i] != 0 && pattern[j] != 0)
    {
        if (pattern[j] == 'a' && (str[i] > 122 || str[i] < 97))
            return (0);
        else if (pattern[j] == 'A' && (str[i] > 90 || str[i] < 65))
            return (0);
        else if (pattern[j] == 'i' && (str[i] > 57 || str[i] < 48))
            return (0);
        else if (pattern[j] == '.' && !is_punctuation(pattern[i]))
            return (0);
        else if (pattern[j] == '*' && !parse_match(str + i, pattern + j + 1))
            ++i;
        else if (pattern[j] != 'a' && pattern[j] != 'A' && pattern[j] != 'i' &&
            pattern[j] != '.' && pattern[j] != '*')
            return (0);
        else
        {
            ++i;
            ++j;
        }
    }
    return (pattern[j] == 0 ? 1 : 0);
}