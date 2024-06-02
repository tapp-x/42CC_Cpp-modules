/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:10:51 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/02 13:28:33 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T*              _tab;
    unsigned int    _size;

public:
    Array() : _tab(NULL), _size(0) {}
    Array(unsigned int size) : _tab(new T[size]()), _size(size) {}

    ~Array() {
        delete[] _tab;
    }
    
    Array(const Array& other) : _tab(NULL), _size(0) {
        *this = other;
    }

    Array& operator=(const Array& other) {
        if (this != &other) 
        {
            delete[] _tab;
            _size = other._size;
            _tab = new T[_size];
            for (unsigned int i = 0; i < _size; i++) 
                _tab[i] = other._tab[i];
        }
        return (*this);
    }


    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("index out of bounds");
        }
        return (_tab[index]);
    }

    unsigned int get_size() const {
        return (_size);
    }
};

#endif