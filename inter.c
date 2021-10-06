/*
Intersection: E is in A -AND- B
*/

#include <unistd.h>

static char    *ft_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (0);
}

static int has_dup(char *s, char c, int i)
{
    while(s[--i])
        if (s[i] == c)
            return (1);
    return (0);
}

/*

*/
void ft_inter(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        if (has_dup(s1, s1[i], i) == 0 && ft_strchr(s2, s1[i]) )
            write(1, &s1[i], 1);
        ++i;
    }
    return ;
}

// int main(int argc, char **argv)
// {
//     if (argc != 3)
//         write(1, "\n", 1);
//     else
//     {
//         inter(argv[1], argv[2]);
//         write(1, "\n", 1);
//     }
//     return (1);
// }