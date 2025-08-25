/*!
 * @file talking.h
 * @brief A Documented file.
 *
 * Details.
 */

#ifndef TALKING
#define TALKING

#include "system\tools\tools.h"

/**
 * @brief Asks user if they want to continue.
 *
 * @return true/false
 */
bool AskUser(void);

/**
 * @brief Asks user to enter coefficients of the square equation ax^2 + bx + c = 0.
 *
 * @param[out] a Pointer to a-coefficient.
 * @param[out] b Pointer to b-coefficient.
 * @param[out] c Pointer to c-coefficient.
 *
 * @return Nothing
 */
void Greeting(double* a, double* b, double* c);


void FileGreeting(double* a, double* b, double* c, char* filename_adr);

/**
 * @brief Shows answer to user.
 *
 * @param[in,out] eq_adr Pointer to the equation.
 *
 * @return Error status.
 */
Errors ShowAnswer(EquationParams* eq_adr);

#endif // TALKING

