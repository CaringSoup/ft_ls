/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_ print_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:53:32 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/27 14:40:32 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_normal(t_lists *head)
{
	struct stat		*my_stat;
	struct passwd	*user_id;
	struct group	*group_id;

	my_stat = NULL;
	stat(head->data.name, my_stat);
	sort_alpha(head);
	sort_time(head);
	while  (head != NULL)
	{
		ft_check_permissions(head);
//		ft_check_links(head);
		stat(head->data.name, my_stat);
		printf("%d", my_stat->st_nlink);
		//ft_check_group(head);
		user_id = getpwuid(my_stat->st_uid);
		printf(" %s ", user_id->pw_name);
		group_id = getgrgid(my_stat->st_gid);
		printf(" %s ", group_id->gr_name); 
		printf("%lld", my_stat->st_size);
		ft_get_time(head);
	}
}
