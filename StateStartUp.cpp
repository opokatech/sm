#include "StateStartUp.hpp"
#include "StateMachine.hpp"

namespace SM
{
    void StateStartUp::executeLogic() {}

    bool StateStartUp::changeState(StateMachine &sm)
    {
        // generated transition comment:
        // TEMPERATURE_OK
        // user needs to write the condition

        sm.changeState(StateId::eOperational);
        return true;
    }
} // namespace SM
