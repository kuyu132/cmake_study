//
// Created by kuyuzhiqi on 2024/5/19.
//
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Factory.hpp"

#include <cstdlib>
#include <iostream>
#include <memory>

typedef std::function<std::unique_ptr<Animal>(const std::string &)> CreateAnimal;

int main() {
    // 先创建标签
    Factory<CreateAnimal> farm;
    farm.subscribe("CAT", [](const std::string &n) {
        return std::make_unique<Cat>(n);
    });
    farm.subscribe("DOG", [](const std::string &n) {
        return std::make_unique<Dog>(n);
    });

    // 根据标签创建对象
    std::unique_ptr<Animal> simon = farm.create("CAT", "Simon");
    std::unique_ptr<Animal> marlowe = farm.create("DOG", "Marlowe");

    std::cout << simon->name() << std::endl;
    std::cout << marlowe->name() << std::endl;

    // 创建的指针要销毁，不然会报：Process finished with exit code 133 (interrupted by signal 5:SIGTRAP)
    // 可以创建自定义删除器
    simon.release();
    marlowe.release();
    return EXIT_SUCCESS;
}