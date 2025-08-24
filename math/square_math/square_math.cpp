#include "math\square_math\square_math.h"


#include <math.h>
#include <assert.h>
#include "system\tools\tools.h"

double CountDiscriminant(const double a, const double b, const double c) {
    double discriminant = 0;
    discriminant = b*b - 4*a*c;
    return discriminant;
}

void RootsOfSquare(EquationParams* eq_adr, const double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    double part1 = -(eq_adr->b) / (2 * (eq_adr->a));
    double part2 = sqrt(d) / (2 * (eq_adr->a));
    eq_adr->x1 = part1 + part2;
    eq_adr->x2 = part1 - part2;
}
