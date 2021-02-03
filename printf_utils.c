/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:43:03 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/03 21:17:40 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int		ft_strlen(const char *str)
{
	unsigned int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int		ft_min(int a, int b)
{
	if ( a < b)
		return (a);
	return (b);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((ret = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret[0] = '\0';
		return (ret);
	}
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		ft_isin(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		   return (1);
		i++;
	}
	return (0);
}
