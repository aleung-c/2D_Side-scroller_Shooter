/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulien <ajulien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:31:46 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 14:02:05 by ajulien          ###   ########.fr       */
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

private:
	Ennemy( void );
	void		shoot( void );
	t_en_obj	*_n;
	Ennemy( Ennemy const &src );
};
#endif
