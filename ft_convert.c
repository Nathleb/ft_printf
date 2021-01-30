/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:22:54 by nle-biha          #+#    #+#             */
/*   Updated: 2021/01/30 23:08:30 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

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

int main()
{
	char *returned = malloc(1);
	char *result = ft_itoa_base(321321,"0123456789",returned);
	printf("%s", result);
	free(result);

}
