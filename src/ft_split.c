#include "../inc/push_swap.h"

int	getwordcount(char *s)
{
	int	count;
	int	i;
	int	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == ' ')
		;
	while (s[--len] && s[len] == ' ' && i < len)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == ' ' && s[i - 1] != ' ')
			count++;
		i++;
	}
	return (count);
}

char	*fillword(char *s, int startindex, int len)
{
	char	*word;
	int		i;

	i = -1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len)
		word[i] = s[startindex + i];
	word[i] = 0;
	return (word);
}

char	**ft_split(char *s)
{
	int		start;
	int		end;
	int		i;
	int		count;
	char	**res;

	start = 0;
	i = -1;
	count = getwordcount(s);
	res = (char **)malloc(sizeof(char *) * count + 1);
	while (++i < count)
	{
		while (s[start] && s[start] == ' ')
			start++;
		end = start;
		while (s[end] && s[end] != ' ')
			end++;
		res[i] = fillword(s, start, end - start);
		start = end;
	}
	res[i] = 0;
	return (res);
}