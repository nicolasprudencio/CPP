#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &other);

		// Destructor
		~Fixed();

		// Assignment operator
		Fixed &operator=(const Fixed &other);

		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Increment and Decrement operators
		Fixed &operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed &operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement

		// Static member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		// Friend functions
		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
};

#endif
