#pragma once

#include "State.hpp"

namespace SM
{
    class StateOperational: public State
    {
    public:
        StateOperational() {}

        virtual void executeEnteringLogic() override;
        virtual void executeLogic() override;
        virtual void executeLeavingLogic() override;

        virtual bool changeState(StateMachine &) override;
    };

} // namespace SM
