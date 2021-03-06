/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:19:42 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/15 11:29:14 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrword(char const *s, char c)
{
	size_t	i;
	int		compt;

	i = 0;
	compt = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				if (s[i++] == '\0')
					break ;
			if (ft_strlen(s))
				compt++;
		}
		i++;
	}
	return (compt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	char	*sc;
	int		j[5];

	sc = ft_strctrim(s, c);
	j[4] = ft_nbrword(sc, c);
	ptr = (char**)malloc(sizeof(char*) * (j[4] + 1));
	j[2] = -1;
	j[1] = -1;
	while (++j[2] < j[4])
	{
		j[0] = 0;
		j[3] = 0;
		while (sc[++j[1]] != c && sc[j[1]] != '\0')
			j[3]++;
		ptr[j[2]] = ft_strnew(j[3] + 1);
		while (j[3] > 0)
			ptr[j[2]][j[0]++] = sc[j[1] - j[3]--];
		while (sc[j[1]] == c)
			j[1]++;
		j[1]--;
	}
	ptr[j[2]] = NULL;
	free(sc);
	return (ptr);
}
