/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondard <agondard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:47:22 by agondard          #+#    #+#             */
/*   Updated: 2021/12/23 20:18:00 by agondard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
#include <stdio.h>

int	line(char *name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			i++;
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (i);
}

int	main(void)
{
	int		fd;

	fd = open("../map/map_sujet.ber", O_RDONLY);
	printf("%d\n", line(fd));
	close (fd);
	return (0);
}
