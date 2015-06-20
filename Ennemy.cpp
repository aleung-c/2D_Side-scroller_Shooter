/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:31:58 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 17:24:36 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Ennemy::Ennemy( void ) : AEntity(1, 20, 'P')
{
	return;
}

Ennemy::Ennemy( int x, int y, char c ) : AEntity(x, y, c){
	setvecX(-1);
	return;
}

Ennemy::Ennemy( Ennemy const &src ) : AEntity(src) {
	return ;
}

Ennemy::~Ennemy( void ) {
	return ;
}

Ennemy & Ennemy::operator=( Ennemy const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //
void	Ennemy::shoot( void ) {
}

// accessors //
