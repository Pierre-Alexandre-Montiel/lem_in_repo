#include "my_lemin.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstptr;
	const char	*srcptr;

	if (!dst && !src)
		return (NULL);
	dstptr = (char *) dst;
	srcptr = (const char *) src;
	while (n)
	{
		*dstptr = *srcptr;
		dstptr++;
		srcptr++;
		n--;
	}
	return (dst);
}

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	c = c % 128;
	len = ft_strlen(str);
	str = str + len;
	while (len + 1)
	{
		if (*str == c)
			return ((char *) str);
		len--;
		str--;
	}
	if (c == 0)
		return ((char *) str);
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	c = c % 128;
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	if (c == 0)
		return ((char *) str);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	len;
	void	*vdst;
	void	*vsrc;

	len = ft_strlen (src);
	if (!n)
		return (len);
	vdst = (void *) dst;
	vsrc = (void *) src;
	if (len + 1 < n)
		ft_memcpy (vdst, vsrc, len + 1);
	else if (len != 0)
	{
		ft_memcpy (vdst, vsrc, n - 1);
		dst[n - 1] = '\0';
	}
	return (len);
}

size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

size_t	move_ptr(char const *s, size_t n, size_t *index, char c)
{
	size_t	i;

	i = 0;
	if (c < 0)
	{
		*index = *index + 1;
		while (n)
		{
			if (*s == '\0')
				return (i);
			s++;
			n--;
			i++;
		}
	}
	else
	{
		while (s[i] == c)
			i++;
	}
	return (i);
}

char	*word_dup(const char *str, int size)
{
	char	*word;

	word = (char *) malloc ((size + 1) * sizeof (char));
	if (!word)
		return (NULL);
	ft_strlcpy (word, str, size + 1);
	return (word);
}

char	**free_all(char **ptr, size_t count)
{
	while (count)
	{
		free(ptr[count]);
		count--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	const char	*str;
	char		**ptr;
	size_t		i;

	if (!s)
		return (NULL);
	str = s;
	ptr = (char **) malloc ((word_count(s, c) + 1) * sizeof (char *));
	i = 0;
	while (*s != '\0' && ptr)
	{
		s += move_ptr(s, 0, 0, c);
		if (*s == '\0')
			break ;
		str = ft_strchr(s, c);
		if (!str)
			str = (char *) s + ft_strlen(s);
		ptr[i] = (char *) word_dup(s, str - s);
		if (!ptr[i])
			return (free_all(ptr, i + 1));
		s += move_ptr(s, str - s, &i, -1);
	}
	if (ptr)
		ptr[i] = 0;
	return (ptr);
}
