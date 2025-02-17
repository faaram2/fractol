/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayeganya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:42:10 by ayeganya          #+#    #+#             */
/*   Updated: 2024/01/22 15:47:28 by ayeganya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') \
			|| (x >= '0' && x <= '9'))
		return (1);
	else
		return (0);
}
