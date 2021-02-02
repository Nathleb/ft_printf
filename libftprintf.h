/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:44:28 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/02 02:05:51 by nle-biha         ###   ########.fr       */
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
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_min(int a, int b);
unsigned int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char    *ft_litoa_base(long int nbr, char *base, char *returned);
#endif

