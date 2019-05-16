#pragma once

#include <cstdint>

namespace AC
{
    namespace Parameter
    {
        class Real
        {
        public:
            explicit Real(float value = 0) : value_(value) {}

            float get() const
            {
                return value_;
            }

            void set(float value)
            {
                value_ = value;
            }

            bool equal(const Real &other, float delta = 0.000001) const
            {
                if (value_ > other.value_)
                {
                    return (value_ - other.value_) < delta;
                }
                else
                {
                    return (other.value_ - value_) < delta;
                }
            }

        protected:
            float value_ = 0;
        };

        class Bool
        {
        public:
            explicit Bool(bool value = false) : value_(value) {}

            bool get() const
            {
                return value_;
            }

            void set(bool value)
            {
                value_ = value;
            }

            bool equal(const Bool &other) const
            {
                return value_ == other.get();
            }

        protected:
            bool value_ = false;
        };

        class Pressure: public Real
        {
        public:
            // by mBar by default
            explicit Pressure(float value = 0) : Real(value) {}

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
            explicit Temperature(float value = 0) : Real(value) {}

            float getCelsius() const
            {
                return value_;
            }

            void setCelsius(float value)
            {
                value_ = value;
            }
        };

        template <typename T> inline T operator+(const T &left, const T &right)
        {
            return T(left.get() + right.get());
        }

        template <typename T> inline T operator-(const T &left, const T &right)
        {
            return T(left.get() - right.get());
        }

        template <typename T> bool operator<(const T &left, const T &right)
        {
            return left.get() < right.get();
        }

        template <typename T> bool operator<=(const T &left, const T &right)
        {
            return left.get() < right.get();
        }

        template <typename T> bool operator==(const T &left, const T &right)
        {
            return left.equal(right);
        }

        template <typename T> bool operator>(const T &left, const T &right)
        {
            return left.get() > right.get();
        }

        template <typename T> bool operator>=(const T &left, const T &right)
        {
            return left.get() >= right.get();
        }
    } // namespace Parameter

    // those are valid in the whole namespace AC and below!
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
