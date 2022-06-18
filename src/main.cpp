/*
 * @Author       : DJtang
 * @Date         : 2022-01-23
 * @copyleft GPL 2.0
 */

#include <iostream>
#include "webserver.h"

int main() {
    Webserver* obj = new Webserver;
    obj->print();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
