/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:11:17 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 13:54:41 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
count_contact(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::add_contact(void)
{
	if (count_contact == MAX_CONTACT)
	{
		std::cout << "Contact maximum size exceeded. Rewrite of the last." << std::endl;
		contacts[count_contact - 1].complete_fields();
	}
	else
	{
		std::cout << "Record new contact." << std::endl;	
		contacts[count_contact].complete_fields();
		count_contact++;
	}
}

void PhoneBook::search_contact(void)
{
	std::string s_user_entry; 
	if (count_contact == 0)
	{
		std::cout << "There is currently no contact. Goodbye." << std::endl;
		return ;
	}
	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	for (int actual_contact = 0; actual_contact < count_contact; actual_contact++)
	{
		contacts[actual_contact].show_resume(actual_contact);
	}
	std::cout << "To show more information about a specific contact type the";
	std::cout << " associated index. [0-8]" << std::endl;
	std::getline(std::cin, s_user_entry);
	if (s_user_entry.length() == 1 &&  isdigit(s_user_entry[0]))
	{
		if ((s_user_entry[0] - '0') < count_contact)	
			contacts[s_user_entry[0] - '0'].print();
		else
			std::cout << "Sorry. Contact doesn't exist." << std::endl;
	}
	else
		std::cout << "Sorry. Invalid index." << std::endl;
}
