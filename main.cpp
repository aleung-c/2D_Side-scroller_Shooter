/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:17:43 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 23:19:31 by aleung-c         ###   ########.fr       */
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

	// Player		player2(5, 12, 'P');
	// Ennemy and player have Projectile subclass.

	game.init(); // start gamescreen et variables de jeu ( score, hp, etc etc );
	game.g_place(/*, items*/);
	
	game.spawn();
	player.shoot();
	while (1)
	{
			game.spawn();
			game.g_check_getch();
			
			usleep(1);
			game.g_refresh();
			game.GameEvents();

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