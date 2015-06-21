/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.GameEvent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:31:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 23:18:27 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void Game::GameEvents() {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
		if (tmp->obj->getType() == "Player")
			check_PlayerEvents(tmp->obj);
		else if (tmp->obj->getType() == "Ennemy")
			check_EnnemyEvents(tmp->obj);
		else if (tmp->obj->getType() == "Projectile")
			check_ProjectileEvents(tmp->obj);
		tmp = tmp->next;
	}
}

void Game::check_PlayerEvents(AEntity *player) {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
		// collision player - objet.
		if (tmp->obj->getType() == "Ennemy")
		{

			if (player->getPosX() == tmp->obj->getPosX()
				&& player->getPosY() == tmp->obj->getPosY())
			{
				sleep(1);
				// call die player.
				//std::cout << "Collision ennemy !" << std::endl;
			}
		}
		tmp = tmp->next;
	}
}

void Game::check_EnnemyEvents(AEntity * ennemy) {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	if (ennemy->getPosX() == MIN_X + 1)
	{
		mvaddch(ennemy->getPosY(), ennemy->getPosX(), ' ');
		ennemy->die();
		// delete ennemy;
	}
	while (tmp)
	{
		if (tmp->obj->getType() == "Projectile")
		{
			if ((ennemy->getPosX() == tmp->obj->getPosX() ||
				ennemy->getPosX() == (tmp->obj->getPosX() - 1))
				&&  ennemy->getPosY() == tmp->obj->getPosY())
			{
				// sleep(1);
				mvaddch(ennemy->getPosY(), ennemy->getPosX(), ' ');
				ennemy->die();
				// delete ennemy;
				// call die player.
				//std::cout << "Collision projectile - ennemy !" << std::endl;
			}
		}
		tmp = tmp->next;
	}
}

void Game::check_ProjectileEvents(AEntity *projectile) {
	t_ent_obj *tmp;

	tmp = Game::obj_list;
	while (tmp)
	{
			if (projectile->getPosX() == MAX_X)
			{
				// sleep(1);
				mvaddch(projectile->getPosY(), projectile->getPosX(), ' ');
				projectile->die();
				// delete projectile;
				// call die player.
				//std::cout << "Collision projectile - ennemy !" << std::endl;
			}
		tmp = tmp->next;
	}
}
