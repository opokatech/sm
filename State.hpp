#pragma once

#include <cstdint>

namespace SM
{
    enum StateId: uint8_t
    {
        // GENERATED STATE ENUMS
        eStartUp = 0,
        eOperational,
        eRunUp,
        eNormalMode,
        eRunDown,
        eFailure,
        eHeating,
        eHoldingMode,
        ePowerSaveMode,
        eCleaningPurge,

        // The last state is not really a state. Enums are set up as numbers,
        // starting with 0 and counting up. So if enums are not changed in
        // declaration the last entry should have value equal to total number
        // of declared items.
        STATES_COUNT
    };

    class StateMachine;

    class State
    {
        public:
            explicit State() {}
            virtual ~State() {}

            /// Does the logic once when entering the state.
            virtual void executeEnteringLogic() {}

            /// Does the logic in this state.
            virtual void executeLogic();

            /// Does the logic once when leaving the state.
            virtual void executeLeavingLogic() {}

            /// Checks transitions and changes state if possible.
            /// Returns true if state has changed.
            virtual bool changeState(StateMachine &sm) = 0;
    };
}
