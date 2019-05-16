#include <cstdint>
#include <iostream>

#include "Parameter.hpp"
#include "StateMachine.hpp"
#include "System.hpp"

int main()
{
    // user defined literals (_mBar, etc.) are living in namespace AC, so
    // they can be used only there. And since main() is not in AC:: then we need to use "using...".
    using namespace AC;

    SM::StateMachine sm(SM::eStartUp);

    for (int step = 0; step < 8; ++step)
    {
        std::cout << "=============================" << std::endl;
        std::cout << "STEP " << step << std::endl;
        std::cout << "pressure mBar: " << System::pressureChamber.getmBar() << std::endl;

        sm.run();
    }

    // assiging wrong types is invalid:
    // System::pressureChamber = System::chamberTemperature;

    System::pressureChamber = 5.0_uBar;
    std::cout << "pressure in mBar: " << System::pressureChamber.getmBar() << std::endl;

    Parameter::Pressure pressureThreshold{10.0_mBar};
    Parameter::Temperature temperatureThreshold{150.1_C};

    std::cout << "pressureChamber < threshold: " << (System::pressureChamber < pressureThreshold) << std::endl;

    // comparing different types is invalid
    // if (System::pressureChamber < temperatureThreshold)

    std::cout << "chamberTemperature: " << System::chamberTemperature.getCelsius() << std::endl;
    std::cout << "temperatureThreshold: " << temperatureThreshold.getCelsius() << std::endl;
    if (System::chamberTemperature == temperatureThreshold)
    {
        std::cout << "chamberTemperature == templateThreshold" << std::endl;
    }

    Parameter::Bool b{0};
    std::cout << "b == " << b.get() << std::endl;
    b.set(true);
    std::cout << "b == " << b.get() << std::endl;
    b.set(1);

    return 0;
}
