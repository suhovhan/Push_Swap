/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:14 by suhovhan          #+#    #+#             */
/*   Updated: 2022/10/16 22:36:16 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	getwordcount(char *s, char c)
{
	int	count;
	int	i;
	int	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--len] && s[len] == c && i < len)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

char	*fillword(char *s, int start_index, int len)
{
	char	*word;
	int		i;

	i = -1;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len && s[i] != '\0')
		word[i] = s[start_index + i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		count;
	char	**res;

	start = 0;
	i = -1;
	count = getwordcount(s, c);
	res = (char **)malloc(sizeof(char *) * count + 1);
	while (++i < count)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] != '\0' && s[end] != c)
			end++;
		res[i] = fillword(s, start, end - start);
		start = end;
	}
	res[i] = 0;
	return (res);
}
