#ifndef GENERAL_MATH
#define GENERAL_MATH

#include "system\tools\tools.h"

struct CompareWithZero_tester {
    double a = 0;
    Comparison expected = Equals;
};

struct RootsOfSquare_tester {
    EquationParams eq = {NAN, NAN, NAN, NAN, NAN, ZeroSolutions};
    double x1_expected = 0, x2_expected = 0;
};

struct HowManySolutions_tester {
    EquationParams eq = {NAN, NAN, NAN, NAN, NAN, ZeroSolutions};
    Solutions sol_expected = ZeroSolutions;
};



Comparison CompareWithZero(const double a);
Errors HowManySolutions(EquationParams* eq_adr, bool is_linear, double d);
Errors CalculateAnswer(EquationParams* eq_adr, bool is_linear, double d);
void Solver(EquationParams* eq_adr);
void SolutionFind(EquationParams* eq_adr, bool is_linear, double d);

void CompareWithZeroTest();
void RootsOfSquareTest();
void HowManySolutionsTest();

#endif

