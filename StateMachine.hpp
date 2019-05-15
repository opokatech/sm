#pragma once

#include <cstdint>
#include "StateId.hpp"
#include "State.hpp"

namespace SM
{
    class StateMachine
    {
        public:
            explicit StateMachine(StateId startState);
            // called from states
            void changeState(StateId newState);

            StateId getState() const { return currentState_; }

            void run();
        private:
            StateId currentState_;
            State * state[TOTAL_STATES];
    };
}
