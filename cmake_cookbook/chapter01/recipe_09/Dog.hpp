//
// Created by kuyuzhiqi on 2024/5/19.
//

#pragma once

#include "Animal.hpp"

class Dog final : public Animal {

public:
    Dog(const std::string &n) : Animal(n) {}
private:
    std::string name_impl() const override;
};