/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_two_dimensional_array_from_lst.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:01:45 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 14:05:55 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**create_two_dimensional_array_from_lst(t_list *lst)
{
	t_list	*tmp;
	size_t	i;
	char	**new_array;

	tmp = lst;
	i = -1;
	if (!(new_array = (char **)malloc(sizeof(char *) * (ft_lstsize(tmp) + 1))))
		return (NULL);
	while (tmp)
	{
		new_array[++i] = tmp->content;
		tmp = tmp->next;
	}
	new_array[++i] = NULL;
	return (new_array);
}
