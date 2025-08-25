#include <stdio.h>
#include "math\square_math\square_math.h"
#include "system\tools\tools.h"

void DiscriminantTest() {
    Discriminant_tester test[] = {{1, 2, 1,  0},
                                  {1, 4, 4,  0},
                                  {2, 1, 1, -7},
                                  {1, 5, 1, 21}};
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        Discriminant_tester recent = test[i];
        double result = CountDiscriminant(recent.a, recent.b, recent.c);
        if (result != recent.expected) {
            printf(RED "FAILED: " RESET "test " YELLOW "#%d\n" RESET
                       "expected -> " YELLOW "%d\n" RESET
                       "answer -> " YELLOW "%d\n\n" RESET, i+1, recent.expected, result);
        }
    }

}

void RootsOfSquareTest() {
    RootsOfSquare_tester test[] = {{{ 1,  -5,  6, NAN, NAN, ZeroSolutions},  3,   2},
                                   {{ 1,  2,  1, NAN, NAN, ZeroSolutions},   -1,   -1}};
    int test_amount = sizeof(test)/sizeof(test[0]);
    for (int i = 0; i < test_amount; i++) {

        RootsOfSquare(&(test[i].eq), CountDiscriminant(test[i].eq.a, test[i].eq.b, test[i].eq.c));
        if (test[i].eq.x1 != test[i].x1_expected || test[i].eq.x2 != test[i].x2_expected) {
            printf(RED "FAILED: test #%d\nexpected -> x1 = %lf, x2 = %lf\nanswer -> x1 = %lf, x2 = %lf\n\n",
                   i+1, test[i].x1_expected, test[i].x2_expected, test[i].eq.x1, test[i].eq.x2);
        }
    }
}
