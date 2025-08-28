#include <stdio.h>
#include "math\square_math\square_math.h"
#include "system\tools\tools.h"


void DiscriminantTest() {
    Discriminant_tester test[] = {{.a = 1, .b = 2, .c = 1, .expected =  0},
                                  {.a = 1, .b = 4, .c = 4, .expected =  0},
                                  {.a = 2, .b = 1, .c = 1, .expected = -7},
                                  {.a = 1, .b = 5, .c = 1, .expected = 21}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
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
    RootsOfSquare_tester test[] = {{.eq = {.a = 1, .b = -5, .c = 6, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .x1_expected =  3, .x2_expected =  2},
                                   {.eq = {.a = 1, .b =  2, .c = 1, .x1 = NAN, .x2 = NAN, .sol = ZeroSolutions}, .x1_expected = -1, .x2_expected = -1}};

    size_t test_amount = sizeof(test)/sizeof(test[0]);
    for (size_t i = 0; i < test_amount; i++) {
        RootsOfSquare(&(test[i].eq), CountDiscriminant(test[i].eq.a, test[i].eq.b, test[i].eq.c));
        if (test[i].eq.x1 != test[i].x1_expected || test[i].eq.x2 != test[i].x2_expected) {
            printf(RED "FAILED: test #%d\nexpected -> x1 = %lf, x2 = %lf\nanswer -> x1 = %lf, x2 = %lf\n\n",
                   i+1, test[i].x1_expected, test[i].x2_expected, test[i].eq.x1, test[i].eq.x2);
        }
    }
}

