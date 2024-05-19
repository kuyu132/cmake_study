//
// Created by kuyuzhiqi on 2024/5/19.
//

#include "Animal.hpp"

Animal::Animal(const std::string &n) :name_(n){
}

std::string Animal::name() const {
    return name_impl();
}
