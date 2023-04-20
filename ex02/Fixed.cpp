
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
	Fixed	answer;

	answer.setRawBits(this->_rawBits + rhs.getRawBits());
	return (answer);
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	Fixed	answer;

	answer.setRawBits(this->_rawBits - rhs.getRawBits());
	return (answer);
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	Fixed	answer;

	float	total = (this->_rawBits * rhs.getRawBits()) >> this->_fractional_point;
	answer.setRawBits(total);
	return (answer);
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

// static member functions
Fixed const	&Fixed::min(Fixed const &fa, Fixed const &fb) {
	if (fa.getRawBits() < fb.getRawBits())
		return (fa);
	return (fb);
}

Fixed	&Fixed::min(Fixed &fa, Fixed &fb) {
	if (fa < fb)
		return (fa);
	return (fb);
}

Fixed const	&Fixed::max(Fixed const &fa, Fixed const &fb) {
	if (fa.getRawBits() > fb.getRawBits())
		return (fa);
	return (fb);
}

Fixed	&Fixed::max(Fixed &fa, Fixed &fb) {
	if (fa > fb)
		return (fa);
	return (fb);
}

// overload insertion («) operator
std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
