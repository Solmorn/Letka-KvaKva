/*!
 * @file general_math.h
 * @brief A Documented file.
 *
 * Details.
 */

#ifndef GENERAL_MATH
#define GENERAL_MATH

#include "system\tools\tools.h"

/**
 * @struct CompareWithZero_tester
 * @brief Structure for testing comparison with zero.
 *
 * @param a Value to compare.
 * @param expected Expected comparison result.
 */
struct CompareWithZero_tester {
    double a;              /**< Value to compare */
    Comparison expected;   /**< Expected result */
};

/**
 * @struct HowManySolutions_tester
 * @brief Structure for testing the number of solutions.
 *
 * @param eq Equation parameters.
 * @param sol_expected Expected number of solutions.
 */
struct HowManySolutions_tester {
    EquationParams eq;     /**< Equation parameters */
    Solutions sol_expected;/**< Expected number of solutions */
};


Errors FileProcessing(EquationParams* eq_adr, FILE* input_file, FILE* output_file);

/**
 * @brief Compares a double typed number to 0, considering a small epsilon.
 *
 * @param[in] a Value to compare.
 *
 * @return Comparison status.
 *
 * @note Statuses: Less, Equals, More
 * @note EPSILON = 1e-9
 */
Comparison CompareWithZero(const double a);

/**
 * @brief Finds how many solutions the square equation has.
 *
 * @param[in] is_linear Flag indicating if equation is linear.
 * @param[in] d Discriminant of the equation.
 * @param[out] eq_adr Pointer to the equation parameters.
 *
 * @return Number of solutions status.
 *
 * @note Statuses: InfiniteSolutions, ZeroSolutions, OneSolution, TwoSolutions
 * @note Calls: CompareWithZero(const double a)
 */
Errors HowManySolutions(EquationParams* eq_adr, const bool is_linear, const double d);



/**
 * @brief Starts the process of solving the square equation.
 *
 * @param[out] eq_adr Pointer to the equation parameters.
 *
 * @return Nothing.
 *
 * @note Calls: CountDiscriminant(const double a, const double b, const double c),
 *       IsLinear(const double a),
 *       HowManySolutions(EquationParams* eq_adr, const bool is_linear, const double d),
 *       CalculateAnswer(EquationParams* eq_adr, const bool is_linear, const double d),
 *       ShowAnswer(EquationParams* eq_adr)
 */
Errors Solver(EquationParams* eq_adr);



/**
 * @brief Tests function CompareWithZero(const double a).
 *
 * @return Nothing.
 *
 * @note Prints failed tests and related information.
 */
void CompareWithZeroTest();

/**
 * @brief Tests function HowManySolutions(EquationParams* eq_adr, const bool is_linear, const double d).
 *
 * @return Nothing.
 *
 * @note Prints failed tests and related information.
 */
void HowManySolutionsTest();

#endif // GENERAL_MATH
