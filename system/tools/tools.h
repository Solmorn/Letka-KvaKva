#ifndef TOOLS
#define TOOLS

#include <math.h>

enum Solutions {
    InfiniteSolutions = -1,
    ZeroSolutions = 0,
    OneSolution = 1,
    TwoSolutions = 2
};

enum Errors {
    TypingError,
    UnexpectedError,
    Ok
};

enum Comparison {
    Less = -1,
    Equals = 0,
    More = 1

};

enum Answer {
    Yes = 'y',
    No = 'n'
};

struct EquationParams {
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    Solutions sol = ZeroSolutions;
};

void ClearBuffer();
void PrintError(Errors err);
bool CheckBuffer();

#endif
