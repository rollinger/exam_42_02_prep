#include <stdarg.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return (i);
}

int char_conv(va_list args)
{
    write(1, va_arg(args, int), 1);
    return (1);
}

int string_conv(va_list args)
{
    char *s = va_arg(args, char *);
    int sc;
    if (!s)
        s = "(null)";
    sc = ft_strlen(s);
    write(1, s, sc);
    return (sc);
}

int decimal_conv(va_list args)
{
    //write(1, va_arg(args, int), 1);
    
    return (1);
}

int percent_conv()
{
    char percent = '%';
    write(1, &percent, 1);
    return (1);
}

int ft_convert(char c, va_list args)
{
    int b = 0;
    if(c == 'c')
        b = char_conv(args);
    else if(c == 's')
        b = string_conv(args);
    else if(c == 'd' || c == 'i')
        b = decimal_conv(args);
    else if(c == '%')
        b = percent_conv();
    return (b);
}

int printf(char *format, ...)
{
    va_list args;
    int     nc = 0;
    int     i = 0;

    va_start(args, format);
    while( format[i] != '\0 ')
    {
        if (format[i] == '%')
        {
            write(1,format[i],1);
            ++nc;
        }
        else
        {
            ++i;
            nc += ft_convert(format[i], args);
        }
    }
    va_end(args);

    return (nc);
}