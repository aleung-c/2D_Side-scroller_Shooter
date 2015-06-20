/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:18:21 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 19:39:01 by ajulien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

// lib includes.

// zone jouable  des elements //
# define MAX_Y 54
# define MIN_Y 5
# define MAX_X 219
# define MIN_X 1

# include <iostream>
# include <string>
# include <sstream>
# include <ncurses.h>
# include <unistd.h>
# include <cstring>

class AEntity;
class Projectile;
class Ennemy;
class Player;
class Game;

typedef struct			s_ent_obj {
	AEntity *			obj;
	struct s_ent_obj	*next;
	struct s_ent_obj	*prev;
}						t_ent_obj;

# include "AEntity.hpp"
// Class includes.
# include "Projectile.hpp"
# include "Ennemy.hpp"
# include "Player.hpp"
# include "Game.hpp"




// functions.


#endif
