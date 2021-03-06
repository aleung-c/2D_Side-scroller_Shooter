/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eprojectile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleung-c <aleung-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 17:01:13 by ajulien           #+#    #+#             */
/*   Updated: 2015/06/21 19:17:28 by aleung-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EPROJECTILE_HPP
# define EPROJECTILE_HPP
# include "ft_retro.hpp"

class Eprojectile : public AEntity
{
	public:
		Eprojectile( int x, int y, char c );
		Eprojectile( Eprojectile const &src );
		virtual ~Eprojectile( void );
		Eprojectile & operator=( Eprojectile const &rhs );
		void die( void );
	private:
		t_epro_obj	* _n;
		void	shoot( void );
		Eprojectile( void );
};

#endif
