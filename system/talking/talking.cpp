#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "system\tools\tools.h"
#include "math\general_math\general_math.h"


Errors Greeting(double* a, double* b, double* c) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    PrintColor("PLease, enter coefficients a, b, c of square equation ax^2 + bx + c: \n", Yellow);
    while (true) {
        int check_scanf = 0;
        bool check_buffer = 0;
        char get_q = 0;
        get_q = getc(stdin);
        if (get_q == 'q') {
            check_buffer = CheckBuffer(stdin);
            if (check_buffer) {
                return CriticalError;
            } else {
                PrintError(TypingError);
                PrintColor("try again!\nor enter " YELLOW "q" BLUE " to quit\n", Blue);
            }
        } else {
            ungetc(get_q, stdin);
            check_scanf = scanf("%lf %lf %lf", a, b, c);
            check_buffer = CheckBuffer(stdin);
            if (check_scanf == 3 && check_buffer)  {
                PrintColor("got it!\n", Green);
                break;
            } else {
                PrintError(TypingError);
                PrintColor("try again!\nor enter " YELLOW "q" BLUE " to quit\n", Blue);
            }
        }

    }
    return Ok;
}

void ShowAnswerFile(EquationParams* eq_adr, FILE* output_file) {
    assert(eq_adr != nullptr);

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

static Errors CheckQuit(char get_q) {
    bool check_buffer = CheckBuffer(stdin);
    if (check_buffer) {
        return CriticalError;
    } else {
        PrintError(TypingError);
        PrintColor("try again!\nor enter " YELLOW "q" BLUE " to quit\n", Blue);
    }
    return Ok;

}

static Errors WorkWithOutput(EquationParams* eq_adr, FILE* input_file, char* output_filename) {
    assert(eq_adr != nullptr);
    assert(input_file != nullptr);

    Errors err = Ok;
    char get_q = 0;
    PrintColor("enter output filename\n", Yellow);
    while (true) {
        get_q = getc(stdin);
        if (get_q == 'q') {
            err = CheckQuit(get_q);
            if (err != Ok) {
                return err;
            }
        } else {
            ungetc(get_q, stdin);
            scanf("%s", output_filename);
            if (CheckBuffer(stdin)) {
                FILE *output_file = fopen(output_filename, "r+");
                if (output_file == nullptr) {
                    PrintError(FileNameError);
                    PrintColor("try again!\nor enter " YELLOW "q" BLUE " to quit\n", Blue);
                } else {
                    err = FileProcessing(eq_adr, input_file, output_file);
                    break;
                }
                fclose(output_file);
            } else {
                PrintError(TypingError);
            }
        }
    }
    return err;
}

Errors FileGreeting(EquationParams* eq_adr, char* input_filename, char* output_filename) {
    assert(eq_adr != nullptr);
    assert(input_filename != nullptr);
    assert(output_filename != nullptr);

    Errors err = Ok;
    bool check_buffer = 0;
    char get_q = 0;
    PrintColor("enter input filename\n", Yellow);
    while (true) {
        get_q = getc(stdin);
        if (get_q == 'q') {
            err = CheckQuit(get_q);
            if (err != Ok) {
                return err;
            }
        } else {
            ungetc(get_q, stdin);
            scanf("%s", input_filename);
            check_buffer = CheckBuffer(stdin);
            if (check_buffer) {
                FILE *input_file = fopen(input_filename, "r");
                if (input_file == nullptr) {
                    PrintError(FileNameError);
                    PrintColor("try again!\nor enter " YELLOW "q" BLUE " to quit\n", Blue);
                } else {
                    err = WorkWithOutput(eq_adr, input_file, output_filename);
                    if (err != Ok) {
                        return err;
                    }
                    break;
                }
                fclose(input_file);
            } else {
                PrintError(TypingError);
            }
        }
    }
    return Ok;
}

bool AskUser() {
    char answer[4];
    PrintColor("wanna continue? yes/no\n", Yellow);
    while (true) {
        scanf("%3s", &answer);
        if (CheckBuffer(stdin) && (strcmp(answer, "yes") == 0 || strcmp(answer, "no") == 0)) {
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

