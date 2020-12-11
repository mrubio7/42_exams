/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:34:25 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/11 16:43:34 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int map[256];
	int x;
	int z;

	x = 0;
	if (argc == 3)
	{
		while (x < 256)
		{
			map[x] = 0;
			x++;
		}
		z = 1;
		while (z < 3)
		{
			x = 0;
			while (argv[z][x] != '\0')
			{
				map[(int)argv[z][x]]++;
				if (map[(int)argv[z][x]] == 1)
					write(1, &argv[z][x], 1);
				x++;
			}
			z++;
		}
	}
	write(1, "\n", 1);
	return (0);
}