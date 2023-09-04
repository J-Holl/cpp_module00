/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:15:28 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 14:02:04 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::print(void)
{
	for (int actual_field = 0; actual_field < NUMBER_FIELDS; actual_field++)
	{
		std::cout << _fields_names[actual_field] << ": ";	
		std::cout << _fields[actual_field] << std::endl;	
	}
}

void	Contact::show_resume(int actual_contact)
{
	std::cout << std::setfill (' ') << std::setw(10);
	std::cout << actual_contact << "|";

	for (int i = 0; i < 3; i++)		
	{
		if (_fields[i].length() < 10)
		{	
			std::cout << std::setfill (' ') << std::setw(10);
			std::cout << _fields[i];
		}
		else
		{	
			std::cout << std::setfill (' ') << std::setw(9);
			std::cout << _fields[i].substr(0, 9) << ".";
		}
		if (i != 2)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void	Contact::complete_fields(void)
{
	for (int actual_field = 0; actual_field < NUMBER_FIELDS; actual_field++)
	{
		std::cout << "Fill \""<< _fields_names[actual_field] << "\":" <<std::endl;
		std::getline(std::cin, _fields[actual_field]);
		if (_fields[actual_field].length() == 0)
		{
			std::cout << "Empty fields are not allowed by our favorite PhoneBook." << std::endl;
			actual_field--;
		}
	}
}

const std::string Contact::_fields_names[NUMBER_FIELDS] = {
		"First name",
		"Last name",
		"Nickname",
		"Darkest secret",
		"Phone number"
		}; 

std::string Contact::get_first_name(void) const
{
	return(_fields[0]);
}

std::string Contact::get_last_name(void) const
{
	return(_fields[1]);
}

std::string Contact::get_nickname(void) const
{
	return(_fields[2]);
}

std::string Contact::get_darkest_secret(void) const
{
	return(_fields[3]);
}

std::string Contact::get_phone_number(void) const
{
	return(_fields[4]);
}
