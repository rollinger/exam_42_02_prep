#include <stdarg.h>
#include <unistd.h>

/* returns bytes of nullterm buffer */
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return (i);
}

/* prints out nullterm buffer and returns bytes written */
int string_conv(va_list args)
{
    char *s = va_arg(args, char *);
    if (!s)
        s = "(null)";
    return (write(1, s, ft_strlen(s)));
}

/* prints one char if not a \0; return 1*/
int char_conv(va_list args)
{
    int c = va_arg(args, int);
    if (c > 0)
        write(1, &c, 1);
    return (1);
}

/* prints a % and return 1 */
int percent_conv()
{
    char    percent = '%';
    write(1, &percent, 1);
    return (1);
}

/* prints the number and returns the number of digits */
int	ft_putnbr(int n)
{
    char c;
    int digits = 1;
	if (n == -2147483648)
	    return (write(11, "-2147483648", 1));
	if (n < 0)
	{
		digits += write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
    {
		c = n + '0';
        digits += write(1, &c, 1);
	}
	return (digits);
}

/* calls putnbr */
int decimal_conv(va_list args)
{
    int nbr = va_arg(args, int);
    return (ft_putnbr(nbr));
}

/**/
int ft_ntox(int nbr, char *buf)
{
    char *base = "0123456789abcdef";
    // TODO...
}

/* calls n to hex, prints it out and returns the bytes */
int hex_conv(va_list args)
{
    char    hex_str[100];
    int     nbr = va_arg(args, int);

	ft_ntox(nbr, hex_str);
	return (write(1, hex_str, ft_strlen(hex_str)));
}

/* conversion flag switch; returns bytes */
int ft_convert(char c, va_list args)
{
    int b = 0;

    if(c == 'c')
        b = char_conv(args);
    else if(c == '%')
        b = percent_conv();
    else if(c == 's')
        b = string_conv(args);
    else if(c == 'd' || c == 'i')
        b = decimal_conv(args);
    else if(c == 'x' || c == 'X')
        b = hex_conv(args);
    return (b);
}

/* Printf Entry Point*/
int printf_redux(char *format, ...)
{
    va_list args;
    int     nc = 0;
    int     i = 0;

    va_start(args, format);
    while( format[i] != '\0')
    {
        if (format[i] != '%')
        {
            write(1, &format[i++], 1);
            ++nc;
        }
        else
        {
            nc += ft_convert(format[++i], args);
            ++i;
        }
            
    }
    va_end(args);
    return (nc);
}