
#include "Fixed.hpp"

//Default Constructor
Fixed::Fixed(void) : _rawBits(0) {	
}

//Parametic Constructor : int
Fixed::Fixed(int const value) {
	this->_rawBits = value << _fractional_point;
}

//Parametic Constructor : float
Fixed::Fixed(float const value) {
	this->_rawBits = roundf(value * (1u << _fractional_point));
}

//Copy Constructor
Fixed::Fixed(Fixed const & src) : _rawBits(0) {
	*this = src;
}

//Assignation operator
Fixed	&Fixed::operator=(Fixed const &rhs) {
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

//Destructor
Fixed::~Fixed(void) {
}

// non-static member functions:
int Fixed::getRawBits(void) const {
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return (getRawBits() / (float)(1u << this->_fractional_point));
}

int		Fixed::toInt(void) const {
	int	retval = getRawBits() >> _fractional_point;
	return (retval);
}

// comparison operators
bool	Fixed::operator>(Fixed const &rhs) {
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) {
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) {
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) {
	return (this->getRawBits() != rhs.getRawBits());
}

// aritmetic operators
Fixed	Fixed::operator+(Fixed const &rhs) const {
	float	total = this->toFloat() + rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	float	total = this->toFloat() - rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	float	total = this->toFloat() * rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	float	rawtotal = float(this->_rawBits) / float(rhs._rawBits);
	return (Fixed(rawtotal));
}

Fixed	&Fixed::operator++() {
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--() {
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return (temp);
}

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
