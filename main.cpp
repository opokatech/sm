#include <cstdint>
#include <iostream>

#include "StateMachine.hpp"

int main()
{
    SM::StateMachine sm;

    for (int step = 0; step < 8; ++step)
    {
        std::cout << "=============================" << std::endl;
        std::cout << "STEP " << step << std::endl;

        sm.run();
    }
    return 0;
}
