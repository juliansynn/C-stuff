// Workshop 5: operator overloading
// File: Fraction.cpp
// Name: Julian (Hoh-il) Synn
// Date: Feb 17, 2018
/////////////////////////////////////////////


// TODO: insert header files
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;

namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator_int, int denominator_int) {
		if (numerator_int >= 0 && denominator_int > 0) {
			numerator = numerator_int;
			denominator = denominator_int;
			this->reduce();
		}

		else {
			//denominator = 0; 
			*this = Fraction();
		}
	}

	// TODO: implement the max query
	int Fraction::max() const {
		int ReturnValue;

		if (numerator > denominator) {
			ReturnValue = numerator;
		}

		else {
			ReturnValue = denominator;
		}
		return ReturnValue;
	}



	// TODO: implement the min query
	int Fraction::min() const {
		int ReturnValue;
		if (numerator < denominator) {
			ReturnValue = numerator;
		}

		else {
			ReturnValue = denominator;
		}
		return ReturnValue;
	}




	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	//void Fraction::reduce() {
	//	denominator = denominator / gcd();
	//	numerator = numerator / gcd();
	//}
	void Fraction::reduce() {
		int reduc = this->gcd();
		numerator /= reduc;
		denominator /= reduc;
	}



	// TODO: implement the display query
	void Fraction::display() const {

		if (isEmpty()) {
			cout << "no fraction stored";
		}

		else if (denominator == 1) {
			cout << numerator;
		}

		else {
			cout << numerator << "/" << denominator;
		}

	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool tf;

		if (denominator == 0) {
			tf = true;
		}
		else {
			tf = false;
		}
		return tf;
	}

	//// TODO: implement the + operator
	//Fraction Fraction::operator+(const Fraction& rhs) const {
	//	
	//	// declare a new fraction as your retValue
	//	Fraction retValue;
	//	// check if current obj is NOT empty, and right hand side is NOT empty as well
	//	if (isEmpty() && rhs.isEmpty())
	//	{
	//		//TO DO::add them togther and store the value in your retValue
	//	}
	//	//return your retValue
	//	return retValue;
	//
	//	}

	//Fraction Fraction::operator+(const Fraction& rhs) const {
	//	if (isEmpty()) {
	//		return Fraction();
	//	}
	//	else {
	//		int numerator = (this->numerator*rhs.denominator) + (this->denominator*rhs.numerator);
	//		int denominator = this->denominator*rhs.denominator;
	//		Fraction retValue(numerator, denominator);
	//		retValue.reduce();
	//		return retValue;
	//	}
	//}


	//Lab 5B new operator +
	Fraction 
		operator+(const Fraction & rhs, const Fraction & lhs) {
		if (lhs.isEmpty()) { //lhs is the current object, lhs rhs; a+b, a is the current obj
			return Fraction();
		}
		else {
			int numerator = (lhs.numerator*rhs.denominator) + (lhs.denominator*rhs.numerator);
			int denominator = lhs.denominator*rhs.denominator;
			Fraction retValue(numerator, denominator);
			retValue.reduce();
			return retValue;
		}
	}
}