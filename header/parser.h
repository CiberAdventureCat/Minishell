/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:35:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 19:59:13 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "lexer.h"
#include "minishell.h"

typedef	enum		e_cmd_type
{
	CMD_ECHO = 1,
	CMD_CD = 2,
	CMD_PWD = 3,
	CMD_EXPORT = 4,
	CMD_UNSET = 5,
	CMD_ENV = 6,
	CMD_EXIT = 7,
	CMD_ERROR = -1,
}					t_cmd_type;

t_commands		*parse(t_data *data, t_lexer *lexerbuf);
t_commands		*init_struct_commands(t_commands *cmd, t_data *data);
void 			init(t_commands **cmd);

#endif
