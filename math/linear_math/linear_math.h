#ifndef LINEAR_MATH
#define LINEAR_MATH

#include "system\tools\tools.h"


struct IsLinear_tester {
    double a = 0;
    bool expected = 0;
};

struct RootsOfLinear_tester {
    EquationParams eq = {NAN, NAN, NAN, NAN, NAN, ZeroSolutions};
    double x1_expected = 0, x2_expected = 0;
};

bool IsLinear(const double a);
void RootsOfLinear(EquationParams* eq_adr);

void IsLinearTest();
void RootsOfLinearTest();


#endif
