#include "fractol.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = s;
	while (i < n)
		tmp[i++] = 0;
}

void	*x_calloc(size_t size)
{
	void	*str;

	str = (void *)malloc (size);
	if (str == NULL)
	{
		write(1, "x_calloc error.\n", 16);
		exit (-1);
	}
	ft_bzero(str, (size));
	return (str);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_str_tolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

