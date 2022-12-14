/*
 * yon.h
 *
 *  Created on: Oct. 8, 2022
 *      Author: Matthew Hinton
 */

#ifndef YON_YON_H_
#define YON_YON_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>

#define MAX_PRECISION 13
#define IGNORE_ZERO_FRACTION false	// Set to true to output x instead of x.0 when fractional part is nil.
#define TRUNC_PRECISION true	// Set to true to ignore any zeros beyond MAX_PRECISION in input after the radix point.
#define EXTRA_PRECISION true	// Setting this to "true" will use the same number of significant figures after the radix point in baker's dozenal.
								// Setting this to "false" will convert sig figs from decimal into baker's dozenal.

std::string yon(long double dec, int yonPrecision, bool ignoreZeroFraction);

#endif /* YON_YON_H_ */
