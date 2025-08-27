/*!
 * @file tools.h
 * @brief A Documented file.
 *
 * Details.
 */

#ifndef TOOLS
#define TOOLS

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#define MAX_LEN 100

#include <math.h>





enum Color {
    Reset = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34



};


/**
 * @enum Solutions
 * @brief Possible numbers of solutions for an equation.
 */
enum Solutions {
    InfiniteSolutions = -1, ///< Infinite number of solutions
    ZeroSolutions = 0,      ///< No solutions
    OneSolution = 1,        ///< One solution
    TwoSolutions = 2        ///< Two solutions
};

/**
 * @enum Errors
 * @brief Error status codes.
 */
enum Errors {
    TypingError,         ///< Typing error occurred
    UnexpectedError,     ///< Unexpected error occurred
    FileNameError,       ///< File name error occurred
    FileDataError,       ///< File name error occurred
    FlagError,
    TooManyFlagsError,           ///< File name error occurred
    Ok                   ///< No errors
};

/**
 * @enum Comparison
 * @brief Comparison results.
 */
enum Comparison {
    Less = -1, ///< Less than
    Equals = 0, ///< Equals
    More = 1   ///< More than
};

/**
 * @enum Answer
 * @brief Answers for yes/no questions.
 */
enum Answer {
    Yes, ///< Yes answer
    No   ///< No answer
};

/**
 * @struct EquationParams
 * @brief Stores main information about the square equation ax^2 + bx + c = 0
 *
 * @param a a-coefficient
 * @param b b-coefficient
 * @param c c-coefficient
 * @param x1 First root
 * @param x2 Second root
 * @param sol Number of solutions
 */
struct EquationParams {
    double a; ///< a-coefficient
    double b; ///< b-coefficient
    double c; ///< c-coefficient
    double x1;///< First root
    double x2;///< Second root
    Solutions sol; ///< Number of solutions
};


void PrintMeow();

void PrintGitMeow();





/**
 * @brief Clears input buffer.
 */
void ClearBuffer(void);

/**
 * @brief Prints error messages based on error status.
 *
 * @param err Error status
 */
void PrintError(Errors err);

/**
 * @brief Prints colorful text.
 *
 * @param text Text we want to print
 * @param color Color we want to use
 */
void PrintColor(const char* text, Color color);

/**
 * @brief Checks if there is anything in the buffer except blanks, EOF, and newlines.
 *
 * @return true if buffer contains non-blank characters, false otherwise
 */
bool CheckBuffer(void);



#endif // TOOLS
