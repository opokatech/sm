#pragma once

#include "State.hpp"

namespace SM
{
    class StateOperational: public State
    {
    public:
        StateOperational() {}

        virtual void executeLogic() override;

        virtual bool changeState(StateMachine &) override;
    };

} // namespace SM
