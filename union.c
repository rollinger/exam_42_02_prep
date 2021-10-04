/*

*/
#include <unistd.h>

char    *ft_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (0);
}

int has_dup(char *s, char c, int i)
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
        if (has_dup(s1, s1[i], i) == 0)
            write(1, &s1[i], 1);
        i++;
    }
    while(s2[j])
    {
        // if (has_dup(s2, s2[j], j) == 0 && ft_strchr(s1, s2[j]) == 0)
        if (has_dup(s2, s2[j], j) == 0 && has_dup(s1, s2[j], i) == 0)
            write(1, &s2[j], 1);
        j++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
        write(1, "\n", 1);
    else
    {
        ft_union(argv[1], argv[2]);
        write(1, "\n", 1);
    }
    return (1);
}