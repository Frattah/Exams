#include <unistd.h>
#include <stdarg.h>

int	put_chr(char c)
{
	return (write(1, &c, 1));
}

int	put_int(int n)
{
	int	out;

	out = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 10)
	{
		out += put_int(n / 10);
		out += put_int(n % 10);
	}
	else
		return (put_chr("0123456789"[n]));
	return (out);
}

int	put_hex(unsigned int x)
{
	int	out;

	out = 0;
	if (x > 16)
	{
		out += put_hex(x / 16);
		out += put_hex(x % 16);
	}
	else
		return (put_chr("0123456789abcdef"[x]));
	return (out);
}

int	put_str(char *s)
{
	int	i;
	int	out;

	if (s == NULL)
		return(write(1,"(null)", 6));
	i = -1;
	out = 0;
	while (s[++i])
		out += put_chr(s[i]);
	return (out);
}

int	ft_printf(const char *s, ...)
{
	int		chr;
	int		i;
	va_list	args;

	chr = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd')
				chr += put_int(va_arg(args, int));
			if (s[i] == 's')
				chr += put_str(va_arg(args, char *));
			if (s[i] == 'x')
				chr += put_hex(va_arg(args, unsigned int));
		}
		else
			chr += put_chr(s[i]);
	}
	va_end(args);
	return (chr);
}
