/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:15:26 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 14:02:27 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact;

#define NUMBER_FIELDS 5

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	complete_fields(void);
		void	show_resume(int actual_contact);
		void	print(void);
		std::string get_nickname(void) const;
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_darkest_secret(void) const;
		std::string get_phone_number(void) const;

	private:
		std::string _fields[NUMBER_FIELDS]; 
		static const std::string _fields_names[NUMBER_FIELDS];
	};

#endif
