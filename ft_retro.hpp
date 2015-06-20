/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:18:21 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 15:06:43 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETO_HPP
# define FT_RETO_HPP

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

typedef struct			s_ent_obj {
	void *			obj;
	struct s_ent_obj	*next;
}						t_ent_obj;

// Class includes.
# include "AEntity.hpp"


# include "Player.hpp"
# include "Game.hpp"
// # include "Ennemy.hpp"



// functions.


#endif
