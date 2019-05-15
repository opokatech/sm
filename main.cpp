#include <cstdint>
#include <iostream>

#include "StateMachine.hpp"
#include "System.hpp"
#include "Parameter.hpp"

using namespace AC;

int main()
{
    SM::StateMachine sm;

    for (int step = 0; step < 8; ++step)
    {
        std::cout << "=============================" << std::endl;
        std::cout << "STEP " << step << std::endl;
        std::cout << "pressure mBar: " << AC::System::pressureChamber.getmBar() << std::endl;

        sm.run();
    }

    // System::pressureChamber = System::chamberTemperature;
    System::pressureChamber = 5.0_uBar;
    std::cout << "pressure in mBar: " << System::pressureChamber.getmBar() << std::endl;

    return 0;
}
