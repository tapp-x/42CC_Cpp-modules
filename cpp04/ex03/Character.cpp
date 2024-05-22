#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {
    std::cout << "Default constructor called for Character" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(Character const & other) : _name(other._name) {
    std::cout << "Copy constructor called for Character" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (!other._inventory[i])
            _inventory[i] = NULL; 
        else
            _inventory[i] = other._inventory[i]->clone();
    }
}

Character& Character::operator=(Character const & other) {
    std::cout << "Assignation operator called for Character" << std::endl;
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; ++i) 
        {
            delete _inventory[i];
            if (!other._inventory[i])
                _inventory[i] = NULL; 
            else
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Destructor called for Character" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
}

std::string const & Character::getName() const {
    return (_name);
}

void Character::equip(AMateria* to_equip) {
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) 
        {
            _inventory[i] = to_equip;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
