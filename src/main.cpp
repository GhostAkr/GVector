#include <iostream>

#include "../inc/gvector.h"

int main()
{
    std::cout << "Starting app" << std::endl;
    GAlg::GVectorI vec(5);

    vec[0] = 1; vec[1] = 2; vec[2] = 3; vec[3] = 4; vec[4] = 5;

    int mult = 3;
    int res = 1;
    auto foo = [=, &res](int& val) -> void {
        val *= mult;
        res = 0;
    };

    std::cout << "res before: " << res << std::endl;
    std::cout << "Vector before" << std::endl;
    vec.print();
    
    vec.apply(foo);

    std::cout << "res after: " << res << std::endl;
    std::cout << "Vector after" << std::endl;
    vec.print();

    return 0;
}
