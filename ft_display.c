/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:59:49 by nle-biha          #+#    #+#             */
/*   Updated: 2021/01/30 22:12:04 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_min(int a, int b)
{
	if ( a < b)
		return (a);
	return (b);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	ft_putpad(t_flags flags)
{
	char c;

	c = ' ';
	if (flags.zero_pad)
		c = '0';
	while(flags.pad_size-- > 0)
	{
		write(1, &c, 1);
	}
}

void	ft_display_string(t_flags *flags, char *s)
{
	flags->pad_size = flags->width - ft_min(flags->precision, ft_strlen(s));
	if (flags->left_align)
		ft_putpad(*flags);
	write(1, s, ft_min(flags->precision, ft_strlen(s)));
	if (!flags->left_align)
		ft_putpad(*flags);
}
