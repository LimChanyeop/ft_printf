/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:59:47 by clim              #+#    #+#             */
/*   Updated: 2021/02/09 16:36:10 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int  ret;
	//ret = ft_printf("s = |%s|\n", "string");
	//printf("\nret=%d\n", ret);
	ret = ft_printf("|%5.d|", 0);
	printf("\nret=%d\n", ret);
	//ret = ft_printf("i = |%-10.6i|\n", 1234);
	//printf("\nret=%d\n", ret);
	//ret = ft_printf("u = |%-9.6u|\n", 1234);
	//printf("\nret=%d\n", ret); 
	//ret = ft_printf("c = |%-10c|\n", 'c');
	//printf("\nret=%d\n", ret); 
	//ret = ft_printf("x = |%-10.2x|\n", 1234);
	//printf("\nret=%d\n", ret);
	//ret = ft_printf("p = |%p|\n", &a);
}
