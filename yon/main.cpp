/*
 * main.cpp
 *
 *  Created on: Oct. 8, 2022
 *      Author: Matthew Hinton
 */

#include "yon.h"


int main(void) {
	//std::string decnum{""};
	long double dec{ };
	int decPrecision{ };		// number of decimal places right of the radix point
	int yonPrecision{ };
	std::string yonnum{""}, decnum{""};

	std::cout << "\nType \"q\" to quit\n\n";

	while (true) {
		std::cout << "Decimal: ";
		std::cin >> decnum;

		if (decnum.find("q") != std::string::npos) {
			return 0;
		}

		decPrecision = 0;
		if (decnum.find(".") != std::string::npos) {
			decPrecision = decnum.size() - decnum.find(".");
		}
		if (decnum.size() - decPrecision > MAX_PRECISION) {
			yonnum = "E3";
		} else {
			--decPrecision;
			dec = stold(decnum);

			yonPrecision = 0;
			if (EXTRA_PRECISION) {
				if (decPrecision > 0) {
					yonPrecision = decPrecision;
				}
			} else {
				yonPrecision = floor( log( pow(10, decPrecision) ) / log(13) );
			}
			yonnum = yon(dec, yonPrecision);
		}

		if (yonnum == "E1") {
			std::cout << "This blasphemous number is not holy enough to be displayed in Baker's Dozenal without offending our lord and saviour ...\n\n";
		} else if (yonnum == "E2") {
			std::cout << "This number is too holy to be converted by a mere command line program. You should do this in your head to avoid offending our lord and saviour ...\n\n";
		} else if (yonnum == "E3") {
			std::cout << "A number this long and complicated aught to be kept in the mind, lest we risk a dark forest strike from a malevolent civilization with sophon technology.\n\n";
		} else if (yonnum == "E4") {
			std::cout << "This number doesn't obey all the known laws of mathematics. If you are reading this, it is most likely a message from our lord and saviour.\n\n";
		} else {
			std::cout << "Baker's Dozenal: " + yonnum + "\n\n";
		}
	}

	return 0;
}



