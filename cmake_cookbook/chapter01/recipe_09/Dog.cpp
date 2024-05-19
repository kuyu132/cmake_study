//
// Created by kuyuzhiqi on 2024/5/19.
//

#include "Dog.hpp"

std::string Dog::name_impl() const {
    return "I'm " + name_ + " the dog!";
}
