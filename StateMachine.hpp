#pragma once

#include <cstdint>
#include "State.hpp"

namespace SM
{
    class StateMachine
    {
        public:
            explicit StateMachine();
            // called from states
            void changeState(StateId newState);

            StateId getState() const { return currentState_; }

            void run();
        private:
            StateId currentState_ = StateId::eStartUp; // GENERATED
            State * state[STATES_COUNT];
    };
}
