/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:44:28 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/03 21:17:54 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
typedef int t_bool;
typedef struct	s_flags
{
	t_bool	zero_pad;
	t_bool	left_align;
	int		width;
	int		precision;
	char	conv_type;
}				t_flags;

int				ft_atoi(const char *nptr);
t_flags			printf_parse(char *str, va_list ap);
int				ft_isin(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_min(int a, int b);
unsigned int	ft_strlen(const char *str);
char			*ft_strcpy(char *dest, char *src);
char    		*ft_litoa_base(long int nbr, char *base, char *returned);
#endif

