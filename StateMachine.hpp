#pragma once

#include <cstdint>
#include "State.hpp"
// GENERATED
#include "StateStartUp.hpp"
#include "StateOperational.hpp"

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

            // Genarated
            StateStartUp stateStartUp;
            StateOperational stateOperational;
    };
}
