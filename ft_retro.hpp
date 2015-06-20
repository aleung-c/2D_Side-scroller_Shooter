/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 10:18:21 by aleung-c          #+#    #+#             */
/*   Updated: 2015/06/20 12:51:15 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETO_HPP
# define FT_RETO_HPP

// lib includes.

# include <iostream>
# include <string>
# include <sstream>
# include <ncurses.h>

#include <unistd.h>

// Class includes.
# include "AEntity.hpp"

typedef struct			s_ent_obj {
	AEntity	*			obj;
	struct s_ent_obj	*next;
}						t_ent_obj;


# include "Game.hpp"

// # include "Player.hpp"
// # include "Ennemy.hpp"



// functions.


#endif 