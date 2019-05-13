#pragma once

#include <cstdint>
#include "State.hpp"

namespace SM
{
    class StateMachine
    {
        public:
            explicit StateMachine();
            void changeState(StateId newState);

            StateId getState() const { return currentState_; }

            void Run();
        private:
            StateId currentState_ = StateId::eStartUp; // GENERATED
            State * state[STATES_COUNT];
    };
}
