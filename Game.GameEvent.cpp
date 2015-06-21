/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.GameEvent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:31:44 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 17:10:59 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void Game::GameEvents() {
	t_en_obj *tmp_enn;
	t_pro_obj *tmp_proj;

	tmp_enn = Game::ennemy_list;
	tmp_proj = Game::projec_list;

	while (tmp_proj)
	{
		if (tmp_proj->obj->getPosX() == MAX_X - 1)
		{
			mvaddch(tmp_proj->obj->getPosY(), tmp_proj->obj->getPosX(), ' ');
			tmp_proj->obj->die();
			delete tmp_proj->obj;
			delete tmp_proj;
			// tmp_proj = Game::projec_list;
			// delete tmp_proj;
		}
		tmp_proj = tmp_proj->next;
	}
	while (tmp_enn)
	{
		check_EnnemyEvents(tmp_enn);
		tmp_enn = tmp_enn->next;
	}
	check_PlayerEvents();
}

void Game::check_PlayerEvents( void ) {
	t_en_obj *tmp_enn;

	tmp_enn = Game::ennemy_list;
	while (tmp_enn)
	{
		// collision player - objet.
			if (Game::p1->getPosX() == tmp_enn->obj->getPosX()
				&& Game::p1->getPosY() == tmp_enn->obj->getPosY())
			{
				sleep(1);
				// call die player.
				//std::cout << "Collision ennemy !" << std::endl;
			}
		tmp_enn = tmp_enn->next;
	}
}

void Game::check_EnnemyEvents(t_en_obj * ennemy) {
	t_pro_obj *tmp_proj;

	if (ennemy->obj->getPosX() == MIN_X + 1)
	{
		mvaddch(ennemy->obj->getPosY(), ennemy->obj->getPosX(), ' ');
		ennemy->obj->die();
		delete ennemy->obj;
		delete ennemy;
		return ;
	}
	tmp_proj = Game::projec_list;
	// check collision project - ennemy;
	while (tmp_proj)
	{
		if ((ennemy->obj->getPosX() == tmp_proj->obj->getPosX() ||
			ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 1)
			|| ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 2)
			|| ennemy->obj->getPosX() == (tmp_proj->obj->getPosX() - 3))
			&&  ennemy->obj->getPosY() == tmp_proj->obj->getPosY())
		{
			// sleep(1);
			mvaddch(ennemy->obj->getPosY(), ennemy->obj->getPosX(), ' ');
			ennemy->obj->die();
			mvaddch(tmp_proj->obj->getPosY(), tmp_proj->obj->getPosX(), ' ');
			tmp_proj->obj->die();
			delete ennemy->obj;
			//delete ennemy;
			delete tmp_proj->obj;
			// delete tmp_proj;
			return ;

			// tmp_proj = Game::projec_list;
			// delete tmp_proj;
			// call die player.
			//std::cout << "Collision projectile - ennemy !" << std::endl;
		}
		tmp_proj = tmp_proj->next;
	}
}

// void Game::check_ProjectileEvents(AEntity *projectile) {
// 	t_en_obj *tmp;

// 	tmp = Game::obj_list;
// 	while (tmp)
// 	{
// 			if (projectile->getPosX() == MAX_X )
// 			{
// 				// sleep(1);
// 				mvaddch(projectile->getPosY(), projectile->getPosX(), ' ');
// 				projectile->die();
// 				delete projectile;
// 				// call die player.
// 				//std::cout << "Collision projectile - ennemy !" << std::endl;
// 			}
// 		tmp = tmp->next;
// 	}
// }
