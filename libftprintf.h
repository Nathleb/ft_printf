/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:44:28 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/02 01:45:07 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
typedef int t_bool;

int		ft_isin(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_min(int a, int b);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
void    ft_display_string(t_flags *flags, char *s);
char    *ft_utoa_base(unsigned int nbr, char *base, char *returned);
char    *ft_itoa_base(int nbr, char *base, char *returned);
#endif

