/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:13:31 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/31 15:39:15 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

void printData(const Data* data) {
    std::cout << "First Name: " << data->firstName << std::endl;
    std::cout << "Last Name: " << data->lastName << std::endl;
    std::cout << "Nickname: " << data->nickname << std::endl;
    std::cout << "Age: " << data->age << std::endl;
}

int main() {
    Data data1;
    data1.firstName = "Alice";
    data1.lastName = "Smith";
    data1.nickname = "Ali";
    data1.age = 25;
    
    Data data2;
    data2.firstName = "Bob";
    data2.lastName = "Johnson";
    data2.nickname = "Bobby";
    data2.age = 30;
    
    Data data3;
    data3.firstName = "Charlie";
    data3.lastName = "Brown";
    data3.nickname = "Chuck";
    data3.age = 22;
    
    Data* data_tab[] = {&data1, &data2, &data3};
    uintptr_t serializedArray[3];
    
    std::cout << "Original Data:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Data " << i+1 << ":" << std::endl;
        printData(data_tab[i]);
        std::cout << std::endl;
    }

    // Serialize the pointers
    for (int i = 0; i < 3; ++i) {
        serializedArray[i] = Serializer::serialize(data_tab[i]);
        std::cout << "Serialized Data " << i+1 << ": " << serializedArray[i] << std::endl;
    }
    std::cout << std::endl;

    Data* deserializedArray[3];
    for (int i = 0; i < 3; ++i) {
        deserializedArray[i] = Serializer::deserialize(serializedArray[i]);
        std::cout << "Deserialized Data " << i+1 << ":" << std::endl;
        printData(deserializedArray[i]);
        std::cout << std::endl;

        // Verify that the original pointer and deserialized pointer are the same
        if (deserializedArray[i] == data_tab[i]) {
            std::cout << "Deserialization successful, pointers match." << std::endl;
        } else {
            std::cout << "Deserialization failed, pointers do not match." << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
