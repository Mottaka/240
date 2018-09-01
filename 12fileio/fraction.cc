#include "fraction.h"

int Fraction::num() const {
  return num_;
}

int Fraction::den() const {
  return den_;
}

const Fraction Fraction::Add(const Fraction& rhs) const {
  return Fraction(num_*rhs.den_ + rhs.num_*den_, rhs.den_*den_);
}

const Fraction Fraction::Mult(const Fraction& rhs) const {
  return Fraction(num_*rhs.num_, den_*rhs.den_);
}

const Fraction Fraction::Negate() const {
  return Fraction(-num_, den_);
}

const Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
  return Fraction(lhs.num_*rhs.den_ + rhs.num_*lhs.den_, rhs.den_*lhs.den_);
}

const Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
  return Fraction(lhs.num_*rhs.den_ - lhs.den_*rhs.num_, lhs.den_*rhs.den_);
}

const Fraction operator*(const Fraction& lhs,
                         const Fraction& rhs) {
  return lhs.Mult(rhs);
}

const Fraction operator-(const Fraction& f) {
  return f.Negate();
}

ostream& operator<<(ostream& lhs, const Fraction& rhs) {
  lhs << rhs.num_ << "/" << rhs.den_;
  return lhs;
}

istream& operator>>(istream& lhs, Fraction& rhs) {
  // step 1: get num
  char byte;
  string num = "";
  lhs.get(byte);
  while (byte != '/') {
    assert(('0' <= byte && byte <= '9') || byte == ' ' || byte == '\n');

    num += byte;
    lhs.get(byte);
  }

  // step 2: get den
  lhs.get(byte);
  while (byte == ' ')
    lhs.get(byte);

  string den = "";
  while ('0' <= byte && byte <= '9') {
    den += byte;
    lhs.get(byte);
  }
  lhs.putback(byte);

  // step 3: profit
  rhs = Fraction(stoi(num), stoi(den));
  
  return lhs;
}

