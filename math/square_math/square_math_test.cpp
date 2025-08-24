#include <stdio.h>
#include "math\square_math\square_math.h"

void DiscriminantTest() {
    Discriminant_tester test[] = {{1, 2, 1,  0},
                                  {1, 4, 4,  0},
                                  {2, 1, 1, -7},
                                  {1, 5, 1, 21}};
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        Discriminant_tester recent = test[i];
        double result = CountDiscriminant(recent.a, recent.b, recent.c);
        if (result != recent.expected) {
            printf("FAILED: test #%d\nexpected -> %d\nanswer -> %d\n\n", i+1, recent.expected, result);
        }
    }

}
