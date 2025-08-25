#include <stdio.h>
#include "math\general_math\general_math.h"
#include "math\square_math\square_math.h"
#include "math\linear_math\linear_math.h"

void CompareWithZeroTest() {
    CompareWithZero_tester test[] ={{         1,   More},
                                    {        -1,   Less},
                                    {         0, Equals},
                                    {(1e-9)-(1e-10), Equals},
                                    {(1e-9)+(1e-10),   More}};
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        CompareWithZero_tester recent = test[i];
        Comparison result = CompareWithZero(recent.a);
        if (result != recent.expected) {
            printf(RED "FAILED: " RESET "test " YELLOW "#%d\n" RESET
                       "function: " BLUE "CompareWithZero\n" RESET
                       "expected -> " YELLOW "%d\n" RESET
                       "answer -> " YELLOW "%d\n\n" RESET, i+1, recent.expected, result);
        }
    }
}

void HowManySolutionsTest() {
    HowManySolutions_tester test[] = {{{ 0,  0,  0, NAN, NAN, ZeroSolutions},   InfiniteSolutions},
                                      {{ 0,  1,  0, NAN, NAN, ZeroSolutions},   OneSolution},
                                      {{ 1,  3,  2, NAN, NAN, ZeroSolutions},   TwoSolutions},
                                      {{ 1,  2,  1, NAN, NAN, ZeroSolutions},   OneSolution},
                                      {{71,  3, 77, NAN, NAN,  OneSolution},  ZeroSolutions}};
    int test_amount = sizeof(test)/sizeof(test[0]);
    for (int i = 0; i < test_amount; i++) {
        HowManySolutions(&test[i].eq, IsLinear(test[i].eq.a), CountDiscriminant(test[i].eq.a, test[i].eq.b, test[i].eq.c));
        if (test[i].eq.sol != test[i].sol_expected) {
            printf("FAILED: test #%d\nexpected -> %d\nanswer -> %d\n\n",
                   i+1, test[i].sol_expected, test[i].eq.sol);
        }
    }
}
