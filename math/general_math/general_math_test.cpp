#include <stdio.h>
#include "math\general_math\general_math.h"
#include "math\square_math\square_math.h"
#include "math\linear_math\linear_math.h"

void CompareWithZeroTest() {
    CompareWithZero_tester test[] ={{.a =              1, .expected =   More},
                                    {.a =             -1, .expected =   Less},
                                    {.a =              0, .expected = Equals},
                                    {.a = (1e-9)-(1e-10), .expected = Equals},
                                    {.a = (1e-9)+(1e-10), .expected =   More}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
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
    HowManySolutions_tester test[] = {{.eq = {.a =  0, .b =  0, .c =  0, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .sol_expected =   InfiniteSolutions},
                                      {.eq = {.a =  0, .b =  1, .c =  0, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .sol_expected =         OneSolution},
                                      {.eq = {.a =  1, .b =  3, .c =  2, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .sol_expected =        TwoSolutions},
                                      {.eq = {.a =  1, .b =  2, .c =  1, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .sol_expected =         OneSolution},
                                      {.eq = {.a = 71, .b =  3, .c = 77, .x1 = NAN, .x2 = NAN, .sol =   OneSolution}, .sol_expected =       ZeroSolutions}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
        HowManySolutions(&test[i].eq, IsLinear(test[i].eq.a), CountDiscriminant(test[i].eq.a, test[i].eq.b, test[i].eq.c));
        if (test[i].eq.sol != test[i].sol_expected) {
            printf("FAILED: test #%d\nexpected -> %d\nanswer -> %d\n\n",
                   i+1, test[i].sol_expected, test[i].eq.sol);
        }
    }
}
