/*!
 * @file linear_math.h
 * @brief A Documented file.
 *
 * Details.
 */

#ifndef LINEAR_MATH
#define LINEAR_MATH

#include "math\general_math\general_math.h"
#include "system\tools\tools.h"

/**
 * @struct IsLinear_tester
 * @brief Structure for testing linearity.
 *
 * @param a Coefficient to test.
 * @param expected Expected boolean result.
 */
struct IsLinear_tester {
    double a;       /**< Coefficient a */
    bool expected;  /**< Expected result */
};

/**
 * @struct RootsOfLinear_tester
 * @brief Structure for testing roots of linear equation.
 *
 * @param eq Equation parameters
 * @param x1_expected Expected root 1
 * @param x2_expected Expected root 2
 */
struct RootsOfLinear_tester {
    EquationParams eq;   /**< Equation parameters */
    double x1_expected;  /**< Expected root 1 */
    double x2_expected;  /**< Expected root 2 */
};

/**
 * @brief Checks if a function is linear.
 *
 * @param[in] a a-coefficient.
 *
 * @return true if linear, false otherwise.
 */
bool IsLinear(const double a);

/**
 * @brief Finds root of linear case.
 *
 * @param[out] eq_adr Pointer to the equation parameters.
 */
void RootsOfLinear(EquationParams* eq_adr);

/**
 * @brief Tests function IsLinear(const double a).
 *
 * @note Prints failed tests and information about them.
 */
void IsLinearTest();

/**
 * @brief Tests function RootsOfLinear(EquationParams* eq_adr).
 *
 * @note Prints failed tests and information about them.
 */
void RootsOfLinearTest();

#endif // LINEAR_MATH

