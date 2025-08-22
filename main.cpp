#include <math.h>
#include <stdio.h>
#include <assert.h>


enum Solutions {
    INF_S = -1,
    ZERO_S = 0,
    ONE_S = 1,
    TWO_S = 2
};

enum Errors {
    TypingError,
    UnexpectedError,
    Ok
};

enum Comparison {
    More,
    Less,
    Equals
};

struct EquationParams {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    Solutions sol = ZERO_S;
};

bool AskUser();
void Greeting(double* a, double* b, double* c);
void ClearBuffer();
void PrintError(Errors err);
Comparison CompareWithZero(double a);
bool IsLinear(double a);
void RootsOfLinear(EquationParams* eq_adr);
void RootsOfSquare(EquationParams* eq_adr, double d);
Errors HowManySolutions(EquationParams* eq_adr, bool is_linear, double d);
void SolutionFind(EquationParams* eq_adr, bool is_linear, double d);
Errors ShowAnswer(EquationParams* eq_adr, bool is_linear, double d);

int main() {
    while (true) {
        bool is_linear = 0;
        double d = NAN;
        EquationParams eq;
        Errors err;
        Greeting(&eq.a, &eq.b, &eq.c);
        d = eq.b*eq.b - 4*eq.a*eq.c;
        is_linear = IsLinear(eq.a);
        err = HowManySolutions(&eq, is_linear, d);
        if (err != Ok) {
            PrintError(err);
        }
        err = ShowAnswer(&eq, is_linear, d);
        if (err != Ok) {
            PrintError(err);
        }

        if (AskUser()) {
            continue;
        } else {
            break;
        }
    }
    return 0;
}

bool AskUser() {

    char answer = 0;
    printf("wanna continue? y/n\n");

    while (true) {

        scanf("%c", &answer);
        if (answer == 'y' || answer == 'n') {
            break;
        } else {
            printf("try again!\n");
        }
        ClearBuffer();
    }
    ClearBuffer();

    if (answer == 'y') {
        return 1;
    }

    return 0;
}


void Greeting(double* a, double* b, double* c) {
    printf("PLease, enter coefficients a, b, c of square EquationParams ax^2 + bx + c: \n");
    while (true) {
        if (scanf("%lf %lf %lf", a, b, c) == 3) {
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

void ClearBuffer() {
    while(true) {
            char p = 0;
            p = getchar();
            if (p == '\n' || p == EOF) {
                break;
            }
    }
}

void PrintError(Errors err) {
    switch (err) {
        case TypingError:
            printf("Typing Error\n");
            break;
        case UnexpectedError:
            printf("Unexpected Error\n");
            break;
        default:
            printf("Ok\n");
    }
}

Comparison CompareWithZero(double a) {
    assert(a != NAN);
    const double EPSILON = 1e-9;
    if (fabs(a) < EPSILON) {
        return Equals;
    } else {
        if (a > EPSILON) {
            return More;
        }
    }
    return Less;
}

bool IsLinear(double a) {
    assert(a != NAN);
    if (CompareWithZero(a) == Equals) {
        return 1;
    } else {
        return 0;
    }
}

void RootsOfLinear(EquationParams* eq_adr) {
    assert(eq_adr != nullptr);
    double root = -(eq_adr->c) / (eq_adr->b);
    eq_adr->x1 = root;
    eq_adr->x2 = root;
}

void RootsOfSquare(EquationParams* eq_adr, double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    double part1 = -(eq_adr->b) / (2 * (eq_adr->a));
    double part2 = sqrt(d) / (2 * (eq_adr->a));
    eq_adr->x1 = part1 + part2;
    eq_adr->x2 = part1 - part2;
}

Errors HowManySolutions(EquationParams* eq_adr, bool is_linear, double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    Errors err = Ok;
    if (is_linear == 1) {
        if (CompareWithZero(eq_adr->c) == Equals) {
            if (CompareWithZero(eq_adr->b) == Equals) {
                eq_adr->sol = INF_S;
            } else {
                eq_adr->sol = ONE_S;
            }
        } else {
            if (CompareWithZero(eq_adr->b) == Equals) {
                eq_adr->sol = ZERO_S;
            } else {
                eq_adr->sol = ONE_S;
            }
        }
    } else {
        switch (CompareWithZero(d)) {
            case Less:
                eq_adr->sol = ZERO_S;
                break;
            case Equals:
                eq_adr->sol = ONE_S;
                break;
            case More:
                eq_adr->sol = TWO_S;
                break;
            default:
                err = UnexpectedError;
        }
    }
    return Ok;
}

void SolutionFind(EquationParams* eq_adr, bool is_linear, double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    if (is_linear == 1) {
        RootsOfLinear(eq_adr);
    } else {
        RootsOfSquare(eq_adr, d);
    }
}

Errors ShowAnswer(EquationParams* eq_adr, bool is_linear, double d) {
    assert(eq_adr != nullptr);
    assert(d != NAN);
    Errors err = Ok;
    switch (eq_adr->sol) {
        case ZERO_S:
            printf("the Equation has no solutions\n");
            break;
        case ONE_S:
            SolutionFind(eq_adr, is_linear, d);
            printf("the Equation has one solution: %lf\n", eq_adr->x1);
            break;
        case TWO_S:
            SolutionFind(eq_adr, is_linear, d);
            printf("the Equation has two solution: %lf, %lf\n", eq_adr->x1, eq_adr->x2);
            break;
        case INF_S:
            printf("the Equation has infinite solutions\n");
            break;
        default:
            err = UnexpectedError;
    }
    return err;
}


