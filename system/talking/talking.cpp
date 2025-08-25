#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "system\tools\tools.h"


void Greeting(double* a, double* b, double* c) {
    PrintColor("PLease, enter coefficients a, b, c of square equation ax^2 + bx + c: \n", Yellow);
    while (true) {
        int check_scanf = 0;
        bool check_buffer = 0;
        check_scanf = scanf("%lf %lf %lf", a, b, c);
        check_buffer = CheckBuffer();
        if (check_scanf == 3 && check_buffer)  {
            PrintColor("got it!\n", Green);
            break;
        } else {
            PrintError(TypingError);
            PrintColor("try again!\n", Blue);
        }
        ClearBuffer();
    }
    ClearBuffer();
}

void FileGreeting(double* a, double* b, double* c, char* filename) {
    PrintColor("enter filename\n", Yellow);
    while (true) {
        scanf("%s", filename);
        if (CheckBuffer()) {
            FILE *file = fopen(filename, "r");
            if (file == nullptr) {
                PrintError(FileNameError);
                PrintColor("try again!\n", Blue);
            } else {
                if (fscanf(file, "%lf %lf %lf", a, b, c) != 3) {
                    PrintError(FileDataError);
                    PrintColor("try again!\n", Blue);
                } else {
                    fclose(file);
                    break;
                }
            }
            fclose(file);
        } else {
            PrintError(TypingError);
        }
    }
}

bool AskUser() {
    char answer[4];
    PrintColor("wanna continue? yes/no\n", Yellow);
    while (true) {
        scanf("%3s", &answer);
        if ((strcmp(answer, "yes") == 0 || strcmp(answer, "no") == 0) && CheckBuffer()) {
            break;
        } else {
            PrintColor("try again!\n", Blue);
        }
        ClearBuffer();
    }
    ClearBuffer();

    if (strcmp(answer, "yes") == 0) {
        return 1;
    }

    return 0;
}

Errors ShowAnswer(EquationParams* eq_adr) {
    assert(eq_adr != nullptr);
    Errors err = Ok;
    switch (eq_adr->sol) {
        case ZeroSolutions:
            printf(GREEN "the Equation has no solutions\n" RESET);
            break;
        case OneSolution:
            printf(GREEN "the Equation has one solution: " RESET "%lf\n", eq_adr->x1);
            break;
        case TwoSolutions:
            printf(GREEN "the Equation has two solution: " RESET "%lf, %lf\n", eq_adr->x1, eq_adr->x2);
            break;
        case InfiniteSolutions:
            printf(GREEN "the Equation has infinite solutions\n" RESET);
            break;
        default:
            err = UnexpectedError;
    }
    return err;
}

