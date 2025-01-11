/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:14:50 by aryamamo          #+#    #+#             */
/*   Updated: 2024/11/13 12:14:45 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **lst, int i)
{
	while (i >= 0)
	{
		free(lst[i]);
		i--;
	}
	free(lst);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	make_lst(char **lst, const char **s, char c, int *i)
{
	size_t	word_len;

	while (**s == c && **s)
		(*s)++;
	if (**s)
	{
		if (ft_strchr(*s, c))
			word_len = ft_strchr(*s, c) - *s;
		else
			word_len = ft_strlen(*s);
		lst[*i] = ft_substr(*s, 0, word_len);
		if (!lst[*i])
			return (0);
		(*i)++;
		*s += word_len;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!make_lst(lst, &s, c, &i))
		{
			free_split(lst, i - 1);
			return (NULL);
		}
	}
	lst[i] = NULL;
	return (lst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**result;
// 	char	c;

// 	c = 'b';
// 	result = ft_split("aabbcc", c);
// 	printf("%s\n", *result);
// 	return (0);
// }
