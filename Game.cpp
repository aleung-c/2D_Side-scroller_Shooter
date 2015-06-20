/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:07:54 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 11:19:43 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

// init and canon ft //
Game::Game( void ) : _scr_x(220), _scr_x(55), _scroll(1), _nb_life(3) {
	std::cout << "Game created." << std::endl:
}

Game::Game( Game const &src ) {
	*this = src;
}

Game::~Game( void ) {
	std::cout << "End of Game." << std::endl:
}

Game & operator=( Game const &rhs ) {
	this->_scr_x = rhs._scr_x;
	this->_scr_Y = rhs._scr_Y;
	this->_nb_life = rhs._nb_life;
}

// Game class functions //

void Game:init( void ) {
	int r_scrx; // real values of the screen; user inputed;
	int r_scry;

	getmaxyx(stdscr, r_scrx, r_scry);
	if ( r_scrx < this->_scr_x || r_scry < this->_scr_y )
	{
		std::cout << "Screen too small to launch game" << std::endl;
		exit(-1);
	}
	initscr();

}

// accessors //

int Game::get_scr_x( void ) const {
	return (this->_scr_x);
}

int Game::get_scr_y( void ) const {
	return (this->_scr_y);
}

int Game::get_scroll( void ) const {
	return (this->_scroll);
}

int Game::get_nb_life( void ) const {
	return (this->_nb_life);
}


void Game::set_scr_x( int var ) {
	this->_scr_x = var;
}

void Game::set_scr_y( int var ) {
	this->_scr_y = var;
}

void Game::set_scroll( int var ) {
	this->_scroll = var;
}

void Game::set_nb_life( int var ) {
	this->_nb_life = var;
}