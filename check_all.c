/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:28:46 by abellakr          #+#    #+#             */
/*   Updated: 2022/02/21 20:40:00 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*------------------------------------------------------*/
void	check_args(int ac, char **av, fdf_var *number)
{
	if (ac == 2)
	{
		number->zoom = 1;
		number->z_offset = 1;
	}
	if (ac == 4)
	{
		number->zoom = ft_atoi(av[2]);
		number->z_offset = ft_atoi(av[3]);
	}
	if (number->zoom == 0 || number->z_offset == 0)
	{
		number->zoom = 1;
		number->z_offset = 1;
	}
}

/*------------------------------------------------------*/
void	check_extension(char *fname)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = fname;
	while(i < ft_strlen(fname) - 4)
	{
		str++;
		i++;
	}
	if(ft_strncmp(str, ".fdf", 4))
	{
		perror("oops wrong file extention");
		exit(0);
	}
}
/*------------------------------------------------------*/
void	check_print(char **colones, int index)
{
		if(ft_isprint(colones[index][0]) <= 0)
		{
			free_function2(index, colones);
			perror("oops invalid map");
			exit(0);
		}
}
/*------------------------------------------------------*/
void	check_map(fdf_var *number, int index)
{
	if(index  < number->colones)
	{
		free_function(index, number->data_map);
		//system("leaks fdf");
		perror("oops invalid map short or long line");
		exit(0);
	}
}
/*-----------------------------------------------------*/
int check_color(char *str)
{
	int index;

	index = 0;
	while(str[index++])
	{
		if(ft_strchr(str, ','))
			return(1);
		index++;
	}
	return(0);
}