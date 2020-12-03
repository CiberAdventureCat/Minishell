/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:53:54 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 12:47:35 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_case(char *str1, char *str2, char *str3)
{
		ft_putstr(str1);
		ft_putstr(str2);
		ft_putstr(str3);
		exit(EXIT_FAILURE);
}