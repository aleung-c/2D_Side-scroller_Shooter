/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:31:46 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 19:17:37 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENNEMY_HPP
# define ENNEMY_HPP
# include "ft_retro.hpp"

class Ennemy : public AEntity
{
public:
		Ennemy( int x, int y, char c );
		~Ennemy( void );
		Ennemy & operator=( Ennemy const &rhs );
		void	die( void );
			void		shoot( void );
private:
	Ennemy( void );
	t_en_obj	*_n;
	Ennemy( Ennemy const &src );
};
#endif
