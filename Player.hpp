/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:42:39 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 14:30:44 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "ft_retro.hpp"

class Player : public AEntity
{
	public:
		Player( int x, int y, char c );
		~Player( void );
		Player & operator=( Player const &rhs );
		void	shoot( void );
		void	die( void );

	private:
		Player( Player const &src );
		Player( void );
};

#endif
