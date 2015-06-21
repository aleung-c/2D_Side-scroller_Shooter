/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:40:38 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 13:54:37 by aleung-c         ###   ########.fr       */
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
