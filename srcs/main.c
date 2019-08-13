/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksey <aleksey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:42:09 by aleksey           #+#    #+#             */
/*   Updated: 2019/08/13 17:22:12 by aleksey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int argc, char** argv) {
	int fd = 0;
	char buf[1];
	int much = 16;
	int check = IND_SIZE;

	ft_putstr("privet\n");
	if (argc > 1) {
		fd = open(argv[1], O_RDONLY);
		while (much--) {
			read(fd, buf, 1);
			buf[1] = '\0';
			printf("%x ", buf);
		}
		printf("\n");
	}
}

