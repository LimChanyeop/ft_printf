/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:59:47 by clim              #+#    #+#             */
/*   Updated: 2021/02/03 15:59:29 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char c = 'c';
	int a = -1234567;
	ft_printf("|%10c|\n", c);
	ft_printf("|%-3.6d|", a);
}
