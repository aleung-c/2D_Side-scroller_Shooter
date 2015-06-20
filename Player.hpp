/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 11:42:39 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/20 14:48:21 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player: public AEntity
{
	public:
		Player( void );
		Player( int x, int y, char c );
		Player( Player const &src );
		~Player( void );
		Player & operator=( Player const &rhs );

		void	shoot( void );
	private:

};

#endif