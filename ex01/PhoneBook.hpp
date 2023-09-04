/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:04:37 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 14:02:29 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACT 8

class PhoneBook
{
	public:

		void	add_contact(void);
		void	search_contact(void);
		void	exit_contact(void);

		PhoneBook(void);
		~PhoneBook(void);

	private:

		Contact contacts[MAX_CONTACT];
		int count_contact;
};

#endif
