/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:43:19 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 23:00:44 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include "Projectile.hpp"
Player::Player( void ) : AEntity(1, 20, 'P')
{
//	std::cout << "Player set." << std::endl;
	type = "Player";
	return;
}

Player::Player( int x, int y, char c ) : AEntity(x, y, c) {
	//std::cout << "Player set." << std::endl;
	type = "Player";
	return;
}

Player::Player( Player const &src ) : AEntity(src) {
	return ;
}

Player::~Player( void ) {
	return ;
}

Player & Player::operator=( Player const &rhs ) {
	posX = rhs.posX;
	posY = rhs.posY;
	display = rhs.display;
	return (*this);
}

// functions //

void	Player::shoot( void ) {
	Projectile *p = new Projectile(getPosX() + 1, getPosY(), '-');
	if (p)
	{}
	return;
}
