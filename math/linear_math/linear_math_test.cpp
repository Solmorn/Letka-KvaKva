#include <stdio.h>
#include "math\linear_math\linear_math.h"
#include "math\general_math\general_math.h"


void IsLinearTest() {
    IsLinear_tester test[] ={{.a =  1, .expected = 0},
                             {.a = 10, .expected = 0},
                             {.a = -1, .expected = 0},
                             {.a =  0, .expected = 1}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
        IsLinear_tester recent = test[i];
        bool result = IsLinear(recent.a);
        if (result != recent.expected) {
            printf(RED "FAILED: " RESET "test " YELLOW "#%d\n" RESET
                       "expected -> " YELLOW "%d\n" RESET
                       "answer -> " YELLOW "%d\n\n" RESET, i+1, recent.expected, result);
        }
    }
}

void RootsOfLinearTest() {
    RootsOfLinear_tester test[] ={{.eq = {.a = 0, .b =  2, .c =   3, .x1 =  NAN, .x2 =  NAN, .sol =  ZeroSolutions}, .x1_expected =  -1.5, .x2_expected = -1.5},
                                  {.eq = {.a = 0, .b =  2, .c =   0, .x1 =  NAN, .x2 =  NAN, .sol =  ZeroSolutions}, .x1_expected =     0, .x2_expected =    0},
                                  {.eq = {.a = 0, .b =  2, .c =  -4, .x1 =  NAN, .x2 =  NAN, .sol =  ZeroSolutions}, .x1_expected =     2, .x2_expected =    2}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
        RootsOfLinear(&test[i].eq);
        if (CompareWithZero(test[i].eq.x1-test[i].x1_expected) != Equals || CompareWithZero(test[i].eq.x2-test[i].x2_expected) != Equals) {
            printf("FAILED: test #%d\nexpected -> x1 = %lf, x2 = %lf\nanswer -> x1 = %lf, x2 = %lf\n\n",
                   i+1, test[i].x1_expected, test[i].x2_expected, test[i].eq.x1, test[i].eq.x2);
        }
    }
}

