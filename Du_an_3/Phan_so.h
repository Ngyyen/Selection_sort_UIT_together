#ifndef PHAN_SO_H
#define PHAN_SO_H

#include <iostream>
#include <numeric>
#include <iomanip>
using namespace std;

int gcd(int a, int b);

class Phan_so {
	friend istream& operator>>(istream&, Phan_so&);
	friend ostream& operator<<(ostream&, const Phan_so&);
private:
	int tu = 0;
	int mau = 1;
public:
	Phan_so() = default;
	Phan_so(int a, int b) : tu(a), mau(b) { /*this->rut_gon();*/ }
	ostream& Print_double(ostream&);
	Phan_so& rut_gon();
	Phan_so reverse() const;
	Phan_so operator+ (const Phan_so&) const;
	Phan_so operator- (const Phan_so&) const;
	Phan_so operator/ (const Phan_so&) const;
	Phan_so operator* (const Phan_so&) const;
	bool operator> (const Phan_so&) const;

};

istream& operator>>(istream& is, Phan_so& ps) {
	is >> ps.tu >> ps.mau;
	//ps.rut_gon();
	return is;
}

ostream& operator<<(ostream& os, const Phan_so& ps) {
	os << setw(5) << ps.tu << setw(5) << ps.mau;
	return os;
}

ostream& Phan_so::Print_double(ostream& os) {
	double ps = (tu * 1.0) / (mau * 1.0);
	os << ps;
	return os;
}

Phan_so Phan_so::operator+ (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.mau + rhs.tu * mau;
	ret.mau = mau * rhs.mau;
	ret.rut_gon();
	return ret;
}

Phan_so Phan_so::operator- (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.mau - rhs.tu * mau;
	ret.mau = mau * rhs.mau;
	ret.rut_gon();
	return ret;
}

Phan_so Phan_so::operator* (const Phan_so& rhs) const {
	Phan_so ret;
	ret.tu = tu * rhs.tu;
	ret.mau = mau * rhs.mau;
	ret.rut_gon();
	return ret;
}

Phan_so Phan_so::operator/ (const Phan_so& rhs) const {
	Phan_so ret;
	ret = (*this) * rhs.reverse();
	ret.rut_gon();
	return ret;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

Phan_so& Phan_so::rut_gon() {
	int ucln = gcd(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
	return *this;
}

Phan_so Phan_so::reverse() const {
	Phan_so ret(mau, tu);
	return ret;
}

bool Phan_so::operator> (const Phan_so& x) const {
	double lhs = (tu * 1.0) / (mau * 1.0);
	double rhs = (x.tu * 1.0) / (x.mau * 1.0);
	return lhs > rhs;
}

#endif