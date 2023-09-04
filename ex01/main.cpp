/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:46:14 by jholl             #+#    #+#             */
/*   Updated: 2022/03/23 13:58:07 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phone_book;
	std::string s_user_entry;

	while (1)
	{
		std::cout << "PhoneBook wait you type: \"ADD\", \"SEARCH\" or \"EXIT\".";
		std::cout << std::endl;
		std::getline(std::cin, s_user_entry);
		if (s_user_entry.length() == 3 && !s_user_entry.compare("ADD"))
			phone_book.add_contact();
		else if (s_user_entry.length() == 6 && !s_user_entry.compare("SEARCH"))
			phone_book.search_contact();
		else if (s_user_entry.length() == 4 && !s_user_entry.compare("EXIT"))
			return (0);
	}
	return (0);
}
