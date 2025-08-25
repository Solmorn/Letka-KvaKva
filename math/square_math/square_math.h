/*! \file square_math.h
    \brief A Documented file.

    Details.
*/

#ifndef SQUARE_MATH
#define SQUARE_MATH

#include "system\tools\tools.h"

struct Discriminant_tester {
    double a, b, c;
    double expected;
};

struct RootsOfSquare_tester {
    EquationParams eq = {NAN, NAN, NAN, NAN, NAN, ZeroSolutions};
    double x1_expected = 0, x2_expected = 0;
};

void RootsOfSquare(EquationParams* eq_adr, const double d);
double CountDiscriminant(const double a, const double b, const double c);


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Tests function RootsOfSquare(EquationParams* eq_adr, const double d)
//!
//! @return Nothing
//!
//! @note Prints failed tests and information about them
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

void RootsOfSquareTest();

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Tests function CountDiscriminant(const double a, const double b, const double c)
//!
//! @return Nothing
//!
//! @note Prints failed tests and information about them
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

void DiscriminantTest();

#endif
