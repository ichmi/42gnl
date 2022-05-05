/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:00:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/05 17:07:06 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	fd = open("test", O_RDONLY);
	i = -1;
	while (++i < 4)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
