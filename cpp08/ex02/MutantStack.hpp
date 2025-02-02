/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:17:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/15 17:17:04 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
			std::stack<T>::operator=(other);
			}
			return (*this);
		}

		iterator begin() {
			return (this->c.begin)();
		}

		iterator end() {
			return (this->c.end());
		}
};

#endif
