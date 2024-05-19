//
// Created by kuyuzhiqi on 2024/5/19.
//

#include "Cat.hpp"

std::string Cat::name_impl() const {
    return "I'm " + name_ + " the cat!";
}
