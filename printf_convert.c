/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 01:45:48 by nle-biha          #+#    #+#             */
/*   Updated: 2021/02/02 02:09:34 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*neg_initial(long int *nb, char *returned)
{
	if (*nb < 0)
	{
		free(returned);
		returned = (char *)malloc(2 * sizeof(char));
		returned[0] = '-';
		returned[1] = '\0';
		*nb = *nb * (-1);
	}
	return (returned);
}

char	*ft_litoa_base(long int nb, char *base, char *returned)
{
	long int	size;
	char		*temp;
	long int	retsize;
	
	size = ft_strlen(base);
	returned = neg_initial(&nb, returned);
	if (nb >= size)
		if (!(returned = ft_litoa_base((nb / size), base, returned)))
			return (NULL);
	retsize = ft_strlen(returned);
	if (!(temp = (char *)malloc((retsize + 2) * sizeof(char))))
	{
		free(returned);
		return (NULL);
	}
	ft_strcpy(temp, returned);
	free(returned);
	temp[retsize] = base[nb % size];
	temp[retsize + 1] = '\0';
	return (temp);
}

char    		*ft_ulitoa_base(unsigned long int nb, char *base, char *returned)
{
	long int	size;
	char		*temp;
	long int	retsize;

	size = ft_strlen(base);
	if (nb >= size)
		if (!(returned = ft_litoa_base((nb / size), base, returned)))
			return (NULL);
	retsize = ft_strlen(returned);
	if (!(temp = (char *)malloc((retsize + 2) * sizeof(char))))
	{
		free(returned);
		return (NULL);
	}
	ft_strcpy(temp, returned);
	free(returned);
	temp[retsize] = base[nb % size];
	temp[retsize + 1] = '\0';
	return (temp);
}
