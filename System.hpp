#pragma once

#include "Parameter.hpp"

namespace AC
{
    namespace System
    {
        // HW component - as access to hw
        // all HW components - their parameters are inside them available via get/set
        // all parameters which should be shared
        extern Parameter::Pressure pressureChamber;
        extern Parameter::Temperature chamberTemperature;
    }
}
