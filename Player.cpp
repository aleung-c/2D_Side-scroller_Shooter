/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:43:19 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 14:51:42 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Player::Player( void ) : AEntity(1, 20, 'P')
{ 
	std::cout << "Player set." << std::endl;
	return;
}

Player::Player( int x, int y, char c ) : AEntity(x, y, c) {
	std::cout << "Player set." << std::endl;
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
	std::cout << "Player shoots !" << std::endl;
}