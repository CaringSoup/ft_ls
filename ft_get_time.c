/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:10:51 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/27 12:38:06 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_time(t_lists *head)
{
	int		i;
	struct stat	*my_stat;
	char	*my_time;
	
	i =	0;
	my_stat = NULL;
	stat(head->data.name, my_stat);
	my_time = ctime(&my_stat->st_mtime);
	while (my_time[i] && i > 4  && i < 12)
		ft_putchar(my_time[i++]);
}
