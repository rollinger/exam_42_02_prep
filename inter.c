/*
Intersection: E is in A -AND- B
"abc123def" && "001233" => "123"
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

/* print once if s1[i++] is in s1 and s2  */
void    ft_inter(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        if (ft_was_before(s1, s1[i], i) == 0 && ft_is_in(s2, s1[i], 0) == 1)
            write(1, &s1[i], 1);
        ++i;
    }
    return ;
}
