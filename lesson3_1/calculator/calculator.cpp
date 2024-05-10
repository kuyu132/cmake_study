//
// Created by kuyuzhiqi on 2024/5/10.
//

#include "calculator.h"
#include "add.h"
#include "sub.h"

int Calculator::calcAdd(int a, int b) {
    return add(a, b);
}

int Calculator::calSub(int a, int b) {
    return sub(a, b);
}