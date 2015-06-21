/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:18:21 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/21 18:36:16 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

// lib includes.

// zone jouable  des elements //
# define MAX_Y 33
# define MIN_Y 6
# define MAX_X 136
# define MIN_X 3

# include <iostream>
# include <string>
# include <sstream>
# include <ncurses.h>
# include <unistd.h>
# include <cstring>
# include <ctime>

class AEntity;
class Projectile;
class Ennemy;
class Player;
class Game;
class Eprojectile;
class Background;

typedef struct			s_en_obj {
	Ennemy *			obj;
	struct s_en_obj	*next;
	struct s_en_obj	*prev;
}						t_en_obj;

typedef struct			s_pro_obj {
	Projectile *			obj;
	struct s_pro_obj	*next;
	struct s_pro_obj	*prev;
}						t_pro_obj;

typedef struct			s_epro_obj {
	Eprojectile *			obj;
	struct s_epro_obj	*next;
	struct s_epro_obj	*prev;
}						t_epro_obj;

typedef struct			s_bg_obj {
	Background *			obj;
	struct s_bg_obj	*next;
	struct s_bg_obj	*prev;
}						t_bg_obj;

// Class includes.
# include "AEntity.hpp"
# include "Projectile.hpp"
# include "Ennemy.hpp"
# include "Player.hpp"
# include "Game.hpp"
# include "Eprojectile.hpp"
# include "Background.hpp"


// functions.


#endif
