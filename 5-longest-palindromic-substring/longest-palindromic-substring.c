char* longestPalindrome(char* s)
{
    int     i;
    int     k;
    int     x;
    int     count;
    int     index;
    int     max;
    char    *total;

    i = 0;
    k = 0;
    x = 0;
    count = 1;
    index = 0;
    max = 1;
    while (s[i])
    {
        k = i;
        x = i;
        if (s[i + 1] && s[i] == s[i + 1])
        {
            count = 0;
            k = i + 1;
            x = i;
            while (x >= 0 && s[k] && s[x] == s[k])
            {
                count += 2;
                x--;
                k++;
            }
            if (count > max)
            {
                max = count;
                index = i - (max / 2) + 1;
            }
        }
        if (s[i + 1] && i > 0)
        {
            count = 1;
            k = i + 1;
            x = i - 1;
            while (x >= 0 && s[k] && s[x] == s[k])
            {
                count += 2;
                x--;
                k++;
            }
            if (count > max)
            {
                max = count;
                index = i - (max / 2);
            }
        }
        i++;
    }
    total = malloc(max + 1);
    if (!total)
        return (NULL);
    total[max] = '\0';
    i = index;
    k = 0;
    while(max)
    {
        total[k] = s[i];
        i++;
        k++;
        max--;
    }
    return (total);
}