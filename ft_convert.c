/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:22:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/01 16:30:23 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_utoa_base(unsigned int nbr, char *base, char *returned)
{
	long int	size;
	long int	nb;
	char		*temp;
	long int	retsize;
	
	nb = nbr;
	size = ft_strlen(base);
	if (nb >= size)
		if (!(returned = ft_utoa_base((unsigned int)(nb / size), base, returned)))
			return (NULL);
	retsize = ft_strlen(returned);
	if (!(temp = malloc(retsize + 2)))
	{
		free(returned);
		return (NULL);
	}
	ft_strcpy(temp, returned);
	temp[retsize] = base[nb % size];
	temp[retsize + 1] = '\0';
	return (temp);
}

char	*neg_initial(long int *nb, char *returned)
{
	if (*nb < 0)
	{
		free(returned);
		returned = malloc(2);
		returned[0] = '-';
		returned[1] = '\0';
		*nb = *nb * (-1);
	}
	return (returned);
}

char	*ft_itoa_base(int nbr, char *base, char *returned)
{
	long int	size;
	long int	nb;
	char		*temp;
	long int	retsize;
	
	nb = nbr;
	size = ft_strlen(base);
	neg_initial(&nb, returned);
	if (nb >= size)
		if (!(returned = ft_utoa_base((int)(nb / size), base, returned)))
			return (NULL);
	retsize = ft_strlen(returned);
	if (!(temp = malloc(retsize + 2)))
	{
		free(returned);
		return (NULL);
	}
	ft_strcpy(temp, returned);
	temp[retsize] = base[nb % size];
	temp[retsize + 1] = '\0';
	return (temp);
}
