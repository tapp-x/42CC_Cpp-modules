/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:01:33 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/15 17:53:58 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	ft_replace(std::string buffer, std::string s1, std::string s2)
{
	std::size_t	pos;
	while(true)
	{
		pos = buffer.find(s1);
		if (pos == std::string::npos)
			break ;
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
	}
	return (buffer);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of args" << std::endl;
		return (1);
	}

	std::string buffer;
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string newfile_name = av[1];
	newfile_name += ".replace";

	std::ifstream file;
	std::ofstream newfile;

	file.open(av[1], file.in);
	if (file.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return (1);
	}
	newfile.open(newfile_name.data(), file.out);
	if (newfile.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return (1);
	}
	while(std::getline(file, buffer))
	{
		buffer = ft_replace(buffer, s1, s2);
		newfile << buffer << std::endl;
	}
	file.close();
	newfile.close();
	return (0);
}
