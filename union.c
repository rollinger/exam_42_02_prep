/*
Union: E is in A -OR- B
"12234556" || "a2b3c454519" => 123456abc9
*/
#include <unistd.h>

static int  ft_is_in(char *s, char c, int i)
{
    while (s[i])
        if (s[i++] == c)
            return (1);
    return (0);
}

/* checks if c has been in s[--i] and before */
static int  ft_was_before(char *s, char c, int i)
{
    while(s[--i])
        if (s[i] == c)
            return (1);
    return (0);
}

void ft_union(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while(s1[i])
    {
        if (ft_was_before(s1, s1[i], i) == 0)
            write(1, &s1[i], 1);
        i++;
    }
    while(s2[j])
    {
        if (ft_was_before(s2, s2[j], j) == 0 && ft_is_in(s1, s2[j], 0) == 0)
            write(1, &s2[j], 1);
        j++;
    }
}
