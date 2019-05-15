#pragma once

#include <cstdint>

namespace AC
{
    namespace Parameter
    {
        class Real
        {
        public:
            Real(float value = 0) : value_(value) {}

            float get() const
            {
                return value_;
            }

            void set(float value)
            {
                value_ = value;
            }

            bool operator<(const Real &value) const
            {
                return value_ < value.value_;
            }

            bool operator<=(const Real &value) const
            {
                return value_ <= value.value_;
            }

            bool operator==(const Real &value) const
            {
                return value_ == value.value_;
            }

            bool operator>(const Real &value) const
            {
                return value_ > value.value_;
            }

            bool operator>=(const Real &value) const
            {
                return value_ >= value.value_;
            }

        protected:
            float value_ = 0;
        };

        template <typename T> inline T operator+(const T &left, const T &right)
        {
            return T(left.get() + right.get());
        }

        template <typename T> inline T operator-(const T &left, const T &right)
        {
            return T(left.get() - right.get());
        }

        class Pressure: public Real
        {
        public:
            // by mBar by default
            Pressure(float value = 0) : Real(value) {}

            float getmBar() const
            {
                return value_;
            }

            float getuBar() const
            {
                return 1000 * value_;
            }

            float getBar() const
            {
                return value_ / 1000.0;
            }

            void setmBar(float value)
            {
                value_ = value;
            }
        };

        class Temperature: public Real
        {
        public:
            Temperature(float value = 0) : Real(value) {}

            float getCelsius() const
            {
                return value_;
            }

            void setCelsius(float value)
            {
                value_ = value;
            }
        };

    } // namespace Parameter

    // those are valid in namespace AC and below!
    inline Parameter::Pressure operator"" _Bar(long double value)
    {
        return Parameter::Pressure(value * 1000);
    }

    inline Parameter::Pressure operator"" _mBar(long double value)
    {
        return Parameter::Pressure(value);
    }

    inline Parameter::Pressure operator"" _uBar(long double value)
    {
        return Parameter::Pressure(value / 1000);
    }


    inline Parameter::Temperature operator"" _C(long double value)
    {
        return Parameter::Temperature(value);
    }
} // namespace AC
