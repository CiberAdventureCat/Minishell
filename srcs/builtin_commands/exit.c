/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:15:19 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 19:19:12 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long long int		atoi_with_long(const char *str, int *flag)
{
	int			index;
	long long int	n;
	int			sign;

	index = 0;
	n = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = (44 - str[index]);
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (sign == 1 && (n > (n * 10 + (str[index] - '0'))))
		{
			*flag = 1;
			return (-1);
		}
		if (sign == -1 && (n * sign < ((n * 10 + (str[index] - '0')) * sign)))
		{
			*flag = 1;
			return (0);
		}	
		n = (n * 10 + (str[index] - '0'));
		index++;
	}
	n = n * sign;
	return (n);
}

void	ft_exit(t_commands *cmd, t_data *all)
{
	int			i;
	long long int	number;
	int			flag;

	i = -1;
	flag = 0;
	ft_putendl("exit");
	if (cmd->count_args == 0)
		program_exit(cmd, all, global_status);
	else if (cmd->count_args > 0)
	{
		number = atoi_with_long((char *)cmd->lst->content, &flag);
		while (((char *)cmd->lst->content)[++i])
			if (ft_isdigit(((char *)cmd->lst->content)[i]) == 0 || (((char *)cmd->lst->content)[0] != '-' \
			&& ((char *)cmd->lst->content)[0] != '+' && flag == 1))
			{
				error_case("minishell: exit: ", (char *)cmd->lst->content, ": numeric argument required\n");
				program_exit(cmd, all, global_status);
			}
		if (cmd->count_args == 1)
		{
			if (number > 255)
				number -= 256;
			global_status = number;
			program_exit(cmd, all, global_status);	
		}
		else if (cmd->count_args > 1)
			error_case("minishell: ", "exit: ", "too many arguments\n");
		global_status = 1;
	}	
}