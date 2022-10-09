/*
 * yon.cpp
 *
 *  Created on: Oct. 7, 2022
 *      Author: Matthew Hinton
 */

#include "yon.h"


std::string yon(long double dec, int yonPrecision) {

	long double idec{ }, fdec{ };
	std::string yonnum{""};
	std::string yonDigit[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};

	fdec = modf(dec, &idec);

	long double i{ }, j{ };
	int y{ };
	i = floor( ( log(idec) / log(13) ) + 0.01 );
	j = log(idec) / log(10);

	if (idec == 0) {
		yonnum = "0";
	} else if (idec == pow(10, round(j)) && fdec == 0) {
		return "E1";
	} else if (idec == pow(13, i) && fdec == 0) {
		return "E2";
	} else {
		while (idec > 0 || i >= 0) {
			y = (int) floor( idec / pow(13, i) );
			if (y < 13) {
				yonnum += yonDigit[y];
			} else {
				return "E4";
			}
			idec -= y * pow(13, i);
			--i;
		}
	}

	if (yonPrecision != 0) {
		yonnum += ".";

		int f{ };
		while (f < yonPrecision) {
			fdec *= 13;
			y = floor(fdec);
			if (y < 13) {
				yonnum += yonDigit[y];
			} else {
				return "E4";
			}
			fdec -= y;
			++f;
		}
	}

	return yonnum;
};



