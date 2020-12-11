/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:20:20 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/11 16:31:32 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int x;
	int map[256];

	x = 0;
	if (argc == 3)
	{
		while (argv[2][x] != '\0')
		{
			map[(int)argv[2][x]] = 1;
			x++;
		}
		x = 0;
		while (argv[1][x] != '\0')
		{
			map[(int)argv[1][x]]++;
			if (map[(int)argv[1][x]] > 1)
			{
				write(1, &argv[1][x], 1);
				map[(int)argv[1][x]] = 0;
			}
			x++;
		}
	}
	write(1, "\n", 1);
	return (0);
}