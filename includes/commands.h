/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:18:01 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/21 17:27:48 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H
# include "corewar.h"
# define MAX_ARGS 3
# define LIVE_OP 0x01
# define LOAD_OP 0x02
# define STORE_OP 0x03
# define ADD_OP 0x04
# define SUB_OP 0x05
# define AND_OP 0x06
# define OR_OP 0x07
# define XOR_OP 0x08
# define ZJMP_OP 0x09
# define LOADINDEX_OP 0x0a
# define STOREINDEX_OP 0x0b
# define FORK_OP 0x0c
# define LLOAD_OP 0x0d
# define LLOADINDEX_OP 0x0e
# define LFROK_OP 0x0f
# define AFF_OP 0x10


#endif
