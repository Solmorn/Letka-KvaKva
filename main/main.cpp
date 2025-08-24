#include <string.h>

#include "math\general_math\general_math.h"
#include "math\linear_math\linear_math.h"
#include "math\square_math\square_math.h"
#include "system\talking\talking.h"


void Testing();

int main(int argc, char *argv[]) {
    bool test_mode = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0) {
            test_mode = true;
            break;
        }
    }
    if (test_mode) {
        Testing();
    } else {
        while (true) {
            EquationParams eq;
            Errors err;
            Greeting(&eq.a, &eq.b, &eq.c);
            Solver(&eq);
            if (AskUser()) {
                continue;
            } else {
                break;
            }
        }
    }
    return 0;
}

void Testing() {
    CompareWithZeroTest();
    RootsOfSquareTest();
    HowManySolutionsTest();
    IsLinearTest();
    RootsOfLinearTest();
    DiscriminantTest();
}

