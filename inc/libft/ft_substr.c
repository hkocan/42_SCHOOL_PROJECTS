/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan    <hkocan@student.42kocaeli.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/02/26 15:03:57 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		i = ft_strlen(s + start);
	substr = (char *)malloc(i + 1);
	if (!substr)
		return (NULL);
	return (ft_strlcpy(substr, s + start, i + 1), substr);
}
