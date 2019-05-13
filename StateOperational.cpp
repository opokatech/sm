#include <iostream>

#include "StateMachine.hpp"
#include "StateOperational.hpp"

namespace SM
{
    void StateOperational::executeEnteringLogic()
    {
        std::cout << "operational entering logic" << std::endl;
    }

    void StateOperational::executeLogic()
    {
        std::cout << "operational normal logic" << std::endl;
    }
    void StateOperational::executeLeavingLogic()
    {
        std::cout << "operational leaving logic" << std::endl;
    }

    void StateOperational::checkTransitions(StateMachine &sm)
    {
        static uint32_t i = 0;

        i += 1;

        if (i > 3)
        {
            i = 0;
            sm.changeState(StateId::eStartUp);
        }
    }
} // namespace SM
