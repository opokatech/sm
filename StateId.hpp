#pragma once

#include <cstdint>

namespace SM
{
    enum StateId : uint8_t
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
        TOTAL_STATES
    };
} // namespace SM
