/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:43:30 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/17 12:07:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
	return ((a < b) ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b) {
	return ((a > b) ? a : b);
}

#endif
