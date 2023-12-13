/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:21 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/13 12:09:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *nptr)
{
	size_t		i;
	long long	number;
	int			sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		number = number * 10 + nptr[i++] - 48;
	return (number * sign);
}

size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	old_i;
	size_t	count;

	i = 0;
	old_i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		old_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (old_i < i)
			count++;
	}
	return (count);
}

size_t	compute_w_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**free_strs(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words_count;
	size_t	i;
	size_t	cpd_w;

	if (!s)
		return (NULL);
	i = 0;
	cpd_w = 0;
	words_count = ft_countword(s, c);
	split = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!split)
		return (NULL);
	split[words_count] = NULL;
	while (s[i] && cpd_w < words_count)
	{
		while (s[i] && s[i] == c)
			i++;
		split[cpd_w] = ft_substr(s, i, compute_w_len(s + i, c));
		if (!split[cpd_w++])
			return (free_strs(split, words_count));
		i += compute_w_len(s + i, c);
	}
	return (split);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && dst && src)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
