#pragma once

#include <cstdint>

namespace SM
{
    class StateMachine;

    class State
    {
    public:
        explicit State();
        virtual ~State();

        /// Does the logic once when entering the state.
        virtual void executeEnteringLogic() {}

        /// Does the logic in this state.
        virtual void executeLogic() {}

        /// Does the logic once when leaving the state.
        virtual void executeLeavingLogic() {}

        /// Changes state if possible.
        virtual void checkTransitions(StateMachine &sm) = 0;
    };
} // namespace SM
