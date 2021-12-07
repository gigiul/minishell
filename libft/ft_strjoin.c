/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:56:43 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/12/07 14:56:45 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*p;
	int			size_s1;
	int			size_s2;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	p = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (p)
	{
		while (s1[++i] != '\0')
			p[i] = s1[i];
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
