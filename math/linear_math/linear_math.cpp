#include <assert.h>
#include "math\general_math\general_math.h"
#include "system\tools\tools.h"


bool IsLinear(const double a) {
    assert(a != NAN);

    if (CompareWithZero(a) == Equals) {
        return 1;
    } else {
        return 0;
    }
}

void RootsOfLinear(EquationParams* eq_adr) {
    assert(eq_adr != nullptr);

    double root = -(eq_adr->c) / (eq_adr->b);
    eq_adr->x1 = root;
    eq_adr->x2 = root;
    if (CompareWithZero(eq_adr->c) == Equals) {
        eq_adr->x1 = 0;
        eq_adr->x2 = 0;
    }
}

