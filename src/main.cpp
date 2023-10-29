#include <iostream>

#include "../inc/gvector.hpp"

int main()
{
    std::cout << "Starting app" << std::endl;
    GVector vec(12);

    vec[0] = 4; vec[1] = 3; vec[2] = 14; vec[3] = 3; vec[4] = 312; vec[5] = 21;
    vec[6] = 3; vec[7] = 56; vec[8] = 34; vec[9] = 67; vec[10] = 22; vec[11] = 44;

    std::cout << "Initial GVector" << std::endl;
    vec.print();

    GVector vecCopy(vec);
    
    std::cout << "Copied GVector" << std::endl;
    vecCopy.print();

    GVector vecMove(std::move(vecCopy));

    std::cout << "Moved GVector" << std::endl;
    vecMove.print();

    return 0;
}
