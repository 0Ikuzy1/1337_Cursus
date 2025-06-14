#include "Fixed.hpp"
#include <cmath>
#include <iostream>

// Default constructor
Fixed::Fixed() : _value(0) {}

// Int constructor
Fixed::Fixed(const int n) { _value = n << _fractionalBits; }

// Float constructor
Fixed::Fixed(const float f) { _value = static_cast<int>(roundf(f * (1 << _fractionalBits))); }

// Copy constructor
Fixed::Fixed(const Fixed& other) : _value(other._value) {}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other._value;
    return *this;
}

// Destructor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(_value) / (1 << _fractionalBits); }

int Fixed::toInt(void) const { return _value >> _fractionalBits; }

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed res;
    res._value = this->_value + rhs._value;
    return res;
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed res;
    res._value = this->_value - rhs._value;
    return res;
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed res;
    res._value = static_cast<int>((static_cast<long long>(this->_value) * rhs._value) >> _fractionalBits);
    return res;
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed res;
    res._value = static_cast<int>((static_cast<long long>(this->_value) << _fractionalBits) / rhs._value);
    return res;
}

// Increment/decrement
Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_value;
    return tmp;
}
Fixed& Fixed::operator--() {
    --_value;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_value;
    return tmp;
}

// Min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Output stream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}