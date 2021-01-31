/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:07 by nle-biha          #+#    #+#             */
/*   Updated: 2021/01/31 17:22:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//"cspdiuxX%"
//"-0.*"

#include "libftprintf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

int		ft_chr(const char *s, int c)
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

void	ft_pfdisplay(char *str, va_list ap)
{
	unsigned int i;
	unsigned int j;
	char *conv;

	conv = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i++], 1);
		else
		{
			j = ++i;
			while (!ft_chr(conv, str[i]))
				i++;
			ft_substr(str, j, i-j);
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	
	va_end(ap); 
}
