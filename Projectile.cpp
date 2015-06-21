/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:40:38 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 13:57:17 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile( void ) : AEntity()
{
	return;
}

Projectile::Projectile( int x, int y, char c ) : AEntity(x, y, c){
	setvecX(1);
	type = "Projectile";
	t_pro_obj	*n = new t_pro_obj;
	t_pro_obj	*tmp;
	n->obj = this;
	n->next = NULL;
	if (Game::projec_list == NULL)
	{
		Game::projec_list = n;
		Game::projec_list_last = n;
		n->prev = NULL;
	}
	else
	{
		Game::projec_list_last->next = n;
		tmp = Game::projec_list_last;
		Game::projec_list_last = n;
		n->prev = tmp;
	}
	_n = n;
	return;
}

Projectile::Projectile( Projectile const &src ) : AEntity(src) {
	return ;
}

Projectile::~Projectile( void ) {
	return ;
}

void	Projectile::die( void ) {
	_n->prev->next = _n->next;
	if (_n->prev->next)
	_n->next->prev = _n->prev;
	return ;
}

Projectile & Projectile::operator=( Projectile const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //
void	Projectile::shoot( void ) {
}
