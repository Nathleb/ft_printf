/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:59:49 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/01 17:14:21 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putpad(t_flags flags)
{
	char c;

	c = ' ';
	if (flags.zero_pad && !flags.left_align)
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
