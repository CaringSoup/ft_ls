/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:35:32 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/27 14:35:31 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_alpha(t_lists *head)
{
	t_lists	*temp;
	t_lists	*temp2;
	t_lists	*temp3;

	temp = head;
	temp2 = head;
	while (temp != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp2->next && (ft_strcmp(temp2->data.name, temp2->next->data.name) > 0))
			{
				temp3 = (t_lists *)malloc(sizeof(t_lists));
				temp3->data = temp->data;
				temp->data = temp2->next->data;
				temp2->next->data = temp3->data;
				free(temp3);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = head;
	}
}

int		main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		*details;
	t_lists *head;

	(void)ac;
	(void)av;
	head = NULL;
	dir = opendir(".");
	details = malloc(sizeof(struct stat));
	if (dir == NULL)
	{
		printf("Error opening directory");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		head = add_struct(head);
		head->data.name = sd->d_name;
		stat(ft_strjoin("./", sd->d_name), details);
		head->data.date = details->st_mtime;
	}
	sort_alpha(head);
	ft_print_normal(head);
	closedir(dir);
	return (0);
}

t_lists	*add_struct(t_lists *head)
{
	t_lists	*temp;
	
	temp = (t_lists*)malloc(sizeof(t_lists));
	temp->next = head;
	head = temp;
	return (head);
}

void	sort_time(t_lists *head)
{
	t_lists	*temp;
	t_lists	*temp2;
	t_lists	*temp3;

	temp = head;
	temp2 = head;
	while (temp != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp2->next && temp2->data.date > temp2->next->data.date)
			{
				temp3 = (t_lists *)malloc(sizeof(t_lists));
				temp3->data = temp->data;
				temp->data = temp2->next->data;
				temp2->next->data = temp3->data;
				free(temp3);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
		temp2 = head;
	}
}
