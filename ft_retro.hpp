/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:18:21 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 22:39:19 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

// lib includes.

// zone jouable  des elements //
# define MAX_Y 35
# define MIN_Y 5
# define MAX_X 139
# define MIN_X 1

# include <iostream>
# include <string>
# include <sstream>
# include <ncurses.h>
# include <unistd.h>
# include <cstring>
# include <ctime>

class AEntity;
//class Projectile;
class Ennemy;
class Player;
class Game;

typedef struct			s_ent_obj {
	AEntity *			obj;
	struct s_ent_obj	*next;
	struct s_ent_obj	*prev;
}						t_ent_obj;

// Class includes.
# include "AEntity.hpp"
# include "Projectile.hpp"
# include "Ennemy.hpp"
# include "Player.hpp"
# include "Game.hpp"




// functions.


#endif
