#pragma once

#include "State.hpp"

namespace SM
{
    class StateStartUp: public State
    {
    public:
        StateStartUp() {}

        virtual void executeLogic() override;
        virtual void executeLeavingLogic() override;

        virtual void checkTransitions(StateMachine &sm) override;
    };

} // namespace SM
