/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/09/22 21:49:38 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdlib.h>

t_op		g_op_tab[17] =
{
	{0, 0, {0}, {{0}}, 0, 0, 0, 0, 4},
	{"live", 1, {1, 0, 0},
		{
			{DIR_CODE}
		},
		1, 10, "alive", 0, 4},

	{"ld", 2, {2, 1, 0},
		{
			{DIR_CODE, IND_CODE},
			{REG_CODE}},
		2, 5, "load", 1, 4},

	{"st", 2, {1, 2, 0},
		{
			{REG_CODE},
			{IND_CODE, REG_CODE}
		},
		3, 5, "store", 1, 4},

	{"add", 3, {1, 1, 1},
		{	{REG_CODE},
			{REG_CODE},
			{REG_CODE}},
		4, 10, "addition", 1, 4},

	{"sub", 3, {1, 1, 1},
		{
			{REG_CODE},
			{REG_CODE},
			{REG_CODE}},
		5, 10, "subtraction", 1, 4},

	{"and", 3, {3, 3, 1},
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, IND_CODE, DIR_CODE},
			{REG_CODE}},
		6, 6, "bitwise AND", 1, 4},

	{"or", 3, {3, 3, 1},
		{
			{REG_CODE, IND_CODE, DIR_CODE},
			{REG_CODE, IND_CODE, DIR_CODE},
			{REG_CODE}},
		7, 6, "bitwise OR", 1, 4},

	{"xor", 3, {3, 3, 1},
		{
			{REG_CODE, IND_CODE, DIR_CODE},
			{REG_CODE, IND_CODE, DIR_CODE},
			{REG_CODE}},
		8, 6, "bitwise XOR", 1, 4},

	{"zjmp", 1, {1, 0, 0},
		{DIR_CODE},
		9, 20, "jump if non-zero", 0, 2},

	{"ldi", 3, {3, 2, 1},
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{DIR_CODE, REG_CODE},
			{REG_CODE}},
			10, 25,"load index", 1, 2},

	{"sti", 3, {1, 3, 2},
		{
			{REG_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{DIR_CODE, REG_CODE}},
		11, 25, "store index", 1, 2},

	{"fork", 1, {1, 0, 0},
		{{DIR_CODE}},
		12, 800, "fork", 0, 2},

	{"lld", 2, {2, 1, 0},
		{
			{DIR_CODE, IND_CODE},
			{REG_CODE}},
		13, 10, "long load", 1, 4},

	{"lldi", 3, {3, 2, 1},
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{DIR_CODE, REG_CODE},
			{REG_CODE}},
		14, 50, "long load index", 1, 2},

	{"lfork", 1, {1, 0, 0}, {
			{DIR_CODE}},
		15, 1000, "long fork", 0, 2},
	{"aff", 1, {1, 0, 0},
        {{REG_CODE}},
        16, 2, "aff", 1, 4}
};
