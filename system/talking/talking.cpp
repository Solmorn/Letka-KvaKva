#include <stdio.h>
#include <assert.h>
#include "system\tools\tools.h"


void Greeting(double* a, double* b, double* c) {
    printf("PLease, enter coefficients a, b, c of square EquationParams ax^2 + bx + c: \n");
    while (true) {
        int check_scanf = 0;
        bool check_buffer = 0;
        check_scanf = scanf("%lf %lf %lf", a, b, c);
        check_buffer = CheckBuffer();
        if (check_scanf == 3 && check_buffer)  {
            printf("got it!\n");
            break;
        } else {
            PrintError(TypingError);
            printf("try again!\n");
        }
        ClearBuffer();
    }
    ClearBuffer();
}

bool AskUser() {
    Answer answer = No;
    printf("wanna continue? y/n\n");
    while (true) {
        scanf("%c", &answer);
        if (answer == Yes || answer == No) {
            break;
        } else {
            printf("try again!\n");
        }
        ClearBuffer();
    }
    ClearBuffer();

    if (answer == Yes) {
        return 1;
    }

    return 0;
}

Errors ShowAnswer(EquationParams* eq_adr) {
    assert(eq_adr != nullptr);
    Errors err = Ok;
    switch (eq_adr->sol) {
        case ZeroSolutions:
            printf("the Equation has no solutions\n");
            break;
        case OneSolution:
            printf("the Equation has one solution: %lf\n", eq_adr->x1);
            break;
        case TwoSolutions:
            printf("the Equation has two solution: %lf, %lf\n", eq_adr->x1, eq_adr->x2);
            break;
        case InfiniteSolutions:
            printf("the Equation has infinite solutions\n");
            break;
        default:
            err = UnexpectedError;
    }
    return err;
}

