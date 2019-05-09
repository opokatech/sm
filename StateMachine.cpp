#include "StateMachine.hpp"


namespace SM
{
    StateMachine::StateMachine()
    {
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

    void StateMachine::Run()
    {
        state[currentState_]->executeLogic();
        state[currentState_]->changeState(*this);
    }
} // namespace SM
