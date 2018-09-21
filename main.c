/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:35:32 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/20 16:01:33 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	DIR *dir;
	struct dirent *sd;
	t_lists *head;

	head = NULL;
	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error opening directory");
		exit(1);
	}
	while ((sd = readdir(dir)) != NULL)
	{
		head = add_struct(head);
		head->data.name = sd->d_name;
	}
	sort_alpha(head);
	print_normal(head);
	closedir(dir);
	return (0);
}

void	print_normal(t_lists *head)
{
	while (head != NULL)
	{
		printf("%s\n", head->data.name);
		head = head->next;
	}
}

t_lists	*add_struct(t_lists *head)
{
	t_lists	*temp;
	
	temp = (t_lists*)malloc(sizeof(t_lists));
	temp->next = head;
	head = temp;
	return (head);
}

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

void	sort_date(t_lists *date)
{
}

static void		sort_handlers(char c, t_lists *list)
{
		if (c == 'l')
			list->options = 1;
		else if (c == 'R')
			list-> = 1;
		else if (c == 'a')
			list-> = 1;
		else if (c == 'r')
			list-> = 1;
		else if (c == 't')
			list->time = 1;
		else
		{
			ft_putstr("ft_ls: illegal option -- ", 2);
			ft_putchar(c, 2);
			ft_putchar('\n', 2);
			exit(1);
		}
}
