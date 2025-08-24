#include <stdio.h>
#include "math\linear_math\linear_math.h"

void IsLinearTest() {
    IsLinear_tester test[] ={{ 1, 1},
                             {10, 1},
                             {-1, 1},
                             { 0, 0}};
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        IsLinear_tester recent = test[i];
        bool result = IsLinear(recent.a);
        if (result != recent.expected) {
            printf("FAILED: test #%d\nexpected -> %d\nanswer -> %d\n\n", i+1, recent.expected, result);
        }
    }
}

void RootsOfLinearTest() {
    RootsOfLinear_tester test[] ={{{0,  2,  3, NAN, NAN, ZeroSolutions}, -1.5, -1.5},
                                  {{0,  2,  0, NAN, NAN, ZeroSolutions},    0,    0},
                                  {{0,  2, -4, NAN, NAN, ZeroSolutions},    2,    2}};
    int test_amount = sizeof(test)/sizeof(test[0]);
    for (int i = 0; i < test_amount; i++) {
        RootsOfLinear(&test[i].eq);
        if (test[i].eq.x1 != test[i].x1_expected || test[i].eq.x2 != test[i].x2_expected) {
            printf("FAILED: test #%d\nexpected -> x1 = %lf, x2 = %lf\nanswer -> x1 = %lf, x2 = %lf\n\n",
                   i+1, test[i].x1_expected, test[i].x2_expected, test[i].eq.x1, test[i].eq.x2);
        }
    }
}
