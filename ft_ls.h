/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:26:37 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/25 10:48:49 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>

#include <stdio.h>

typedef struct		s_node
{
	char			*name;
	long			date;
}					t_node;

typedef struct		s_lists
{
	t_node			data;
	struct s_lists	*next;
}					t_lists;

void				print_normal(t_lists *head);
t_lists				*add_struct(t_lists *head);
void				sort_alpha(t_lists *head);
void				sort_time(t_lists *head);

#endif
