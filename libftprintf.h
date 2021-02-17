/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:44:28 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/17 20:40:26 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define HEX "0123456789ABCDEF"
# define HE "0123456789abcdef"
# define DEC "0123456789"
# define CONV "cspdiuxX%"

typedef int	t_bool;
typedef struct	s_flags
{
	t_bool	zero;
	t_bool	left;
	int		width;
	int		prec;
	char	conv_type;
	int		pad_size;
}				t_flags;
int				ft_display_int(t_flags flags, int nb);
int				ft_printf(const char *str, ...);
int				ft_display_p(t_flags flags, unsigned long int nb, char *base);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_max(int a, int b);
int				ft_display_ui(t_flags flags, unsigned int nb, char *base);
int				ft_display_char(t_flags flags, char c);
t_flags			printf_parse(char *str, va_list *ap);
int				ft_isin(const char *s, int c);
int				ft_min(int a, int b);
char			*ft_strcpy(char *dest, char *src);
int				ft_display_string(t_flags flags, char *s);
char			*ft_litoa_base(long int nbr, char *base, char *returned);
char			*ft_ulitoa_b(unsigned long int nbr, char *base, char *returned);
#endif
