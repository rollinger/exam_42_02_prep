int printf_redux(char *format, ...);
void ft_inter(char *s1, char *s2);
void ft_union(char *s1, char *s2);

int main()
{
    printf_redux("Testing INTER\n");
    ft_inter("1234556","abc2d3e4fghi");
    printf_redux(" => should be 234\n");

    printf_redux("Testing UNION\n");
    ft_union("123456","abc2d3e4fghi");
    printf_redux(" => should be abcdefghi\n");

    printf_redux("Testing PRINTF\n");
    int bytes;
    bytes = printf_redux("%c %c %c",'1',0,'2');
    printf_redux("(%d)\n",bytes);
    bytes = printf_redux("%s %s%c%c","Hello","World",'!',' ');
    printf_redux("(%d)\n",bytes);
    bytes = printf_redux("%d%i%%%c",10,0,' ');
    printf_redux("(%d)\n",bytes);
    bytes = printf_redux("%x%X:%X%x",99,111,987,654);
    printf_redux("(%d)\n",bytes);
    return (1);
}