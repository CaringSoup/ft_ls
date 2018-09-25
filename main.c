/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:35:32 by gferreir          #+#    #+#             */
/*   Updated: 2018/09/25 11:11:27 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	print_normal(head);
	closedir(dir);
	return (0);
}

void	print_normal(t_lists *head)
{
	sort_alpha(head);
	sort_time(head);
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

/*void	sort_time(t_lists *head)
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
} */

/*void	sort_date(t_lists *date)
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
}*/

static void		check_permissions(t_lists *head)
{
	while (head != NULL)
	{
		stat(head->data.name);
		if (stat.st_mode & S_ISREG) 
			printf("-");
		else if (stat.st_mode & S_ISDIR)
			printf("d");
		else if (stat.st_mode & S_IFLNK)
			printf("s");
		else if (stat.st_mode & S_IFSOCK)
			printf("s");
		else if (stat.st_mode & S_IFBLK)
			printf("b");
		else if (stat.st_mode & S_IFCHR)
			printf("c");
		else if (stat.st_mode & S_IFIFO)
			printf("p");

		if ((stat.st_mode & S_IRUSR) ? printf("r") : printf("-"));
		else if ((stat.st_mode & S_IWUSR) ? printf("w") : printf("-"));
		else if ((stat.st_mode & S_IXUSR) ? printf("x") : printf("-"));

		if ((stat.st_mode & S_IRGRP) ? printf("r") : printf("-"));
		else if (stat.st_mode & S_IWGRP) ? printf("w") : printf("-");
		else if (stat.st_mode & S_IXGRP) ? printf("x") : printf("-");

		if ((stat.st_mode & S_IROTH) ? printf("r") : printf("-"));
		else if (stat.st_mode & S_IWOTH) ? printf("w") : printf("-");
		else if (stat.st_mode & S_IXOTH) ? printf("x") : printf("-");

		if ()
		head = head->next;
	}
}
