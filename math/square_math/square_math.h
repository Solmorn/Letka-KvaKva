#ifndef SQUARE_MATH
#define SQUARE_MATH

#include "system\tools\tools.h"

struct Discriminant_tester {
    double a, b, c;
    double expected;
};

void RootsOfSquare(EquationParams* eq_adr, const double d);
double CountDiscriminant(const double a, const double b, const double c);

void DiscriminantTest();

#endif
