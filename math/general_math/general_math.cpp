#include <math.h>
#include <assert.h>

#include "system\tools\tools.h"
#include "system\talking\talking.h"
#include "math\square_math\square_math.h"
#include "math\linear_math\linear_math.h"


void SolutionFind(EquationParams* eq_adr, const bool is_linear, const double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    if (is_linear == 1) {
        RootsOfLinear(eq_adr);
    } else {
        RootsOfSquare(eq_adr, d);
    }
}

Errors CalculateAnswer(EquationParams* eq_adr, const bool is_linear, const double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    Errors err = Ok;
    switch (eq_adr->sol) {
        case ZeroSolutions:
            break;
        case OneSolution:
        case TwoSolutions:
            SolutionFind(eq_adr, is_linear, d);
            break;
        case InfiniteSolutions:
            break;
        default:
            err = UnexpectedError;
    }
    return err;
}

Comparison CompareWithZero(const double a) {
    assert(a != NAN);
    const double EPSILON = 1e-9;
    if (fabs(a) < EPSILON) {
        return Equals;
    } else if (a > EPSILON) {
        return More;
    }
    return Less;
}

Errors HowManySolutions(EquationParams* eq_adr, const bool is_linear, const double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    Errors err = Ok;
    if (is_linear) {
        if (CompareWithZero(eq_adr->c) == Equals) {
            if (CompareWithZero(eq_adr->b) == Equals) {
                eq_adr->sol = InfiniteSolutions;
            } else {
                eq_adr->sol = OneSolution;
            }
        } else {
            if (CompareWithZero(eq_adr->b) == Equals) {
                eq_adr->sol = ZeroSolutions;
            } else {
                eq_adr->sol = OneSolution;
            }
        }
    } else {
        switch (CompareWithZero(d)) {
            case Less:
                eq_adr->sol = ZeroSolutions;
                break;
            case Equals:
                eq_adr->sol = OneSolution;
                break;
            case More:
                eq_adr->sol = TwoSolutions;
                break;
            default:
                err = UnexpectedError;
                return err;
        }
    }
    return Ok;
}

Errors Solver(EquationParams* eq_adr) {
    bool is_linear = 0;
    double d = NAN;
    Errors err = Ok;
    d = CountDiscriminant(eq_adr->a, eq_adr->b, eq_adr->c);
    is_linear = IsLinear(eq_adr->a);
    err = HowManySolutions(eq_adr, is_linear, d);
    if (err != Ok) {
        return err;
    } else {
        err = CalculateAnswer(eq_adr, is_linear, d);
        return err;
    }
}

