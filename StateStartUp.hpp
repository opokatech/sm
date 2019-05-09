#pragma once

#include "State.hpp"

namespace SM
{
    class StateStartUp: public State
    {
    public:
        StateStartUp() {}

        virtual void executeLogic() override;

        virtual bool changeState(StateMachine &sm) override;
    };

} // namespace SM
