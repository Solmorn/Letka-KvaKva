#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "system\tools\tools.h"
#include "math\general_math\general_math.h"


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
    }
}

void ShowAnswerFile(EquationParams* eq_adr, FILE* input_file, FILE* output_file) {
    assert(eq_adr != nullptr);
    Errors err = Ok;
    switch (eq_adr->sol) {
        case ZeroSolutions:
            fprintf(output_file, "the Equation has no solutions\n");
            break;
        case OneSolution:
            fprintf(output_file, "the Equation has one solution: %lf\n", eq_adr->x1);
            break;
        case TwoSolutions:
            fprintf(output_file, "the Equation has two solution: %lf, %lf\n", eq_adr->x1, eq_adr->x2);
            break;
        case InfiniteSolutions:
            fprintf(output_file, "the Equation has infinite solutions\n");
            break;
        default:
            fprintf(output_file, "Unexpected error\n");
    }
}

void FileProcessing(EquationParams* eq_adr, FILE* input_file, FILE* output_file) {
    bool check = true;
    while (check) {
        switch (fscanf(input_file, "%lf %lf %lf\n", &(eq_adr->a), &(eq_adr->b), &(eq_adr->c))) {
            case 3:
                Solver(eq_adr);
                ShowAnswerFile(eq_adr, input_file, output_file);
                break;
            case EOF:
                check = false;
                break;
            default:
                fprintf(output_file, "syka\n");
        }
    }
}



void FileGreeting(EquationParams* eq_adr, char* input_filename, char* output_filename) {
    PrintColor("enter input filename\n", Yellow);
    while (true) {
        scanf("%s", input_filename);
        if (CheckBuffer()) {
            FILE *input_file = fopen(input_filename, "r");
            if (input_file == nullptr) {
                PrintError(FileNameError);
                PrintColor("try again!\n", Blue);
            } else {
                PrintColor("enter output filename\n", Yellow);
                while (true) {
                    scanf("%s", output_filename);
                    if (CheckBuffer()) {
                        FILE *output_file = fopen(output_filename, "w");
                        if (output_file == nullptr) {
                            PrintError(FileNameError);
                            PrintColor("try again!\n", Blue);
                        } else {
                            FileProcessing(eq_adr, input_file, output_file);
                            fclose(output_file);
                            break;
                        }
                        fclose(output_file);
                    } else {
                        PrintError(TypingError);
                    }
                }
                break;
            }
            fclose(input_file);
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
        if (CheckBuffer() && (strcmp(answer, "yes") == 0 || strcmp(answer, "no") == 0)) {
            break;
        } else {
            PrintColor("try again!\n", Blue);
        }
    }
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



