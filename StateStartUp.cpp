#include <iostream>

#include "StateMachine.hpp"
#include "StateStartUp.hpp"

namespace SM
{
    void StateStartUp::executeLogic()
    {
        std::cout << "startup normal logic" << std::endl;
    }

    void StateStartUp::executeLeavingLogic()
    {
        std::cout << "startup leaving state" << std::endl;
    }

    bool StateStartUp::changeState(StateMachine &sm)
    {
        // generated transition comment:
        // TEMPERATURE_OK
        // user needs to write the condition

        std::cout << "startup changing to operational" << std::endl;
        sm.changeState(StateId::eOperational);
        return true;
    }
} // namespace SM
