/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:24:01 by nle-biha          #+#    #+#             */
/*   Updated: 2021/01/30 20:48:27 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
typedef int t_bool;

typedef struct	s_flags
{
	int		pad_size;
	t_bool	zero_pad;
	t_bool	left_align;
	int		width;
	int		precision;	
}				t_flags;
#endif
