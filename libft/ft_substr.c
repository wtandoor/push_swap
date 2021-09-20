/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtandoor <wtandoor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:34:17 by wtandoor          #+#    #+#             */
/*   Updated: 2021/04/23 17:34:18 by wtandoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		size;
	int		j;
	char	*new;

	size = 0;
	j = 0;
	if (s == 0)
		return (0);
	if ((int)start >= ft_strlen(s))
		len = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (size != (int)start)
		size++;
	while (j < len)
		new[j++] = s[size++];
	new[j] = '\0';
	return (new);
}
