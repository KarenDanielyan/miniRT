/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:24:28 by kdaniely          #+#    #+#             */
/*   Updated: 2023/01/15 18:33:46 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	Reference: <ctype.h>
*
*	Description: ft_tolower converts leters ot lovercase
*	equivalent, if that representation exists in current
*	locale.
*
*	Return Value: Lowercase equivalent or c if DNE.
*/
int	ft_tolower(int c)
{
	if (!ft_isalpha(c))
		return (c);
	else if (c >= 'a' && c <= 'z')
		return (c);
	else
		return (c + 32);
}
