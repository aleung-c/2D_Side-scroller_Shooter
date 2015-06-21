/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:17:43 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 14:31:35 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void ft_retro( void )
{
	Game		game;

	Player		player(8, 20, 'P'); // player class daughter of Entity

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	int		i=0;
	// Player		player2(5, 12, 'P');
	// Ennemy and player have Projectile subclass.

	game.init(); // start gamescreen et variables de jeu ( score, hp, etc etc );
	game.g_place(/*, items*/);

	game.spawn();
	// player.shoot();
	while (1)
	{
			usleep(100);
			i++;
			game.g_check_getch();

			if (i == 300 || i == 900 || i == 600)
			{
				game.g_refresh();
				game.GameEvents();
			}
			game.spawn();
			if (i == 1000)
			{

				i =0;
			}


			// clear();

			refresh();
	}
	endwin();
}

int main( void )
{
		ft_retro();
	return (0);
}
