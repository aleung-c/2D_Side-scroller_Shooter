/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:17:43 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 16:59:19 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void ft_retro( void )
{
	Game		game;
	
	Player		player(8, 20, 'P'); // player class daughter of Entity
	Ennemy		ennemies2(20, 12, 'E'); 
	Ennemy		ennemies3(30, 22, 'E'); 
		Ennemy		ennemies4(100, 22, 'E'); 
	// Player		player2(5, 12, 'P');
	// Ennemy and player have Projectile subclass.

	game.init(); // start gamescreen et variables de jeu ( score, hp, etc etc );
	game.g_place(/*, items*/);
	while (1)
	{
		game.g_refresh();
		sleep(1);
		// clear();
		 // Prends le joueurs, les ennemies,
		// ce qui inclue leurs projectiles lancés, et les affiche sur le screen.

		refresh();

	}
	endwin();
}

int main( void )
{
		ft_retro();
	return (0);
}