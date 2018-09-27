/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:07:44 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/27 13:44:44 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_permissions_2(t_lists *head)
{
	struct stat	*my_stat;

	my_stat = NULL;
	stat(head->data.name, my_stat);
	(my_stat->st_mode & S_IRUSR) ? printf("r") : printf("-");
	(my_stat->st_mode & S_IWUSR) ? printf("w") : printf("-");
	(my_stat->st_mode & S_IXUSR) ? printf("x") : printf("-");

	(my_stat->st_mode & S_IRGRP) ? printf("r") : printf("-");
	(my_stat->st_mode & S_IWGRP) ? printf("r") : printf("-");
	(my_stat->st_mode & S_IXGRP) ? printf("x") : printf("-");

	(my_stat->st_mode & S_IROTH) ? printf("r") : printf("-");
	(my_stat->st_mode & S_IWOTH) ? printf("w") : printf("-");
	(my_stat->st_mode & S_IXOTH) ? printf("x") : printf("-");
}

void	ft_check_permissions(t_lists *head)
{
	struct stat	*my_stat;

	my_stat = NULL;
	stat(head->data.name, my_stat);
	while (head)
	{
		if (my_stat->st_mode & S_IFREG)
			printf("-");
		else if (my_stat->st_mode & S_IFDIR)
			printf("d");
		else if (my_stat->st_mode & S_IFLNK)
			printf("s");
		else if (my_stat->st_mode & S_IFSOCK)
			printf("s");
		else if (my_stat->st_mode & S_IFBLK)
			printf("b");
		else if (my_stat->st_mode & S_IFCHR)
			printf("c");
		else if (my_stat->st_mode & S_IFIFO)
			printf ("p");
		ft_check_permissions_2(head);
		head = head->next;
	}
}

