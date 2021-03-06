#include "StateMachine.hpp"

// GENERATED
#include "StateStartUp.hpp"
#include "StateOperational.hpp"

namespace SM
{
    StateMachine::StateMachine(StateId startState): currentState_(startState)
    {
        // GENERATED
        static StateStartUp stateStartUp;
        static StateOperational stateOperational;

        // GENERATED
        state[eStartUp] = &stateStartUp;
        state[eOperational] = &stateOperational;
    }

    void StateMachine::changeState(StateId newState)
    {
        if (currentState_ == newState)
        {
            return;
        }

        // execute "leaving" code for the previous state
        state[currentState_]->executeLeavingLogic();

        // switch state
        currentState_ = newState;

        // execute "entering" code for the new state
        state[currentState_]->executeEnteringLogic();
    }

    void StateMachine::run()
    {
        state[currentState_]->executeLogic();
        state[currentState_]->checkTransitions(*this);
    }
} // namespace SM
