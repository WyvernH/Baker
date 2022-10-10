/*
 * main.cpp
 *
 *  Created on: Oct. 8, 2022
 *      Author: Matthew Hinton
 */

#include "yon.h"


int main(void) {

	long double dec{ };
	int decPrecision{ }, yonPrecision{ }, radixCount{ };
	std::string decimalCharacters{".0123456789"};
	std::string yonnum{""}, decnum{""};
	bool decimal, ignoreZeroFraction;

	std::cout << "\nType \"q\" to quit...\n\n";

	while (true) {
		yonnum = "";

		std::cout << "Decimal: ";
		std::cin >> decnum;

		if (decnum.find("q") != std::string::npos) {
			return 0;
		} else {
			decimal = true;
			radixCount = 0;
			for (unsigned i{ }; i < decnum.size(); ++i) {
				if (decimalCharacters.find(decnum.at(i)) == std::string::npos) {
					decimal = false;
				} else if (decimalCharacters.find(decnum.at(i)) == 0) {
					++radixCount;
				}
			}
			if (radixCount > 1) {
				decimal = false;
			}
			if (decimal) {
				decPrecision = 0;
				while (decnum.size() > 0) {
					if (decnum.front() != decimalCharacters.at(1)) {
						break;
					} else {
						decnum.erase(decnum.begin());
					}
				}
				if (radixCount == 1) {
					while (decnum.size() > 0 && decnum.back() != '.') {
						if (decnum.back() != decimalCharacters.at(1)) {
							break;
						} else {
							decnum.pop_back();
							++decPrecision;
						}
					}
				}
				if (decnum == "") {
					yonnum == "0";
				} else {
					if (IGNORE_ZERO_FRACTION && decnum.back() == '.') {
						ignoreZeroFraction = true;
					} else { ignoreZeroFraction = false; }
					if (decnum.find(".") != std::string::npos) {
						decPrecision += decnum.size() - decnum.find(".");
					}
					if (decnum.find(".") != std::string::npos && (decnum.find(".") > MAX_PRECISION || decnum.size() - decnum.find(".") - 1 > MAX_PRECISION) ) {
						yonnum = "E3";
					} else if (decnum.find(".") == std::string::npos && decnum.size() > MAX_PRECISION) {
						yonnum = "E3";
					} else if (TRUNC_PRECISION == false && decPrecision > MAX_PRECISION) {
						yonnum = "E3";
					} else {
						if (decPrecision > MAX_PRECISION) {
							decPrecision = MAX_PRECISION + 1;
						}
						--decPrecision;
						if (decnum.find(".") == 0) { decnum = "0" + decnum; }
						if (decnum.find(".") == decnum.size() - 1) { decnum = decnum + "0"; }
						dec = stold(decnum);

						yonPrecision = 0;
						if (EXTRA_PRECISION) {
							if (decPrecision > 0) {
								yonPrecision = decPrecision;
							}
						} else {
						yonPrecision = floor( log( pow(10, decPrecision) ) / log(13) );
						}
						yonnum = yon(dec, yonPrecision, ignoreZeroFraction);
					}
				}
			} else {
				yonnum = "E4";
			}
		}

		if (yonnum == "E1") {
			std::cout << "\nThis blasphemous number is not holy enough to be displayed in Baker's Dozenal without offending our lord and saviour Francois.\n\n\n";
		} else if (yonnum == "E2") {
			std::cout << "\nThis number is too holy to be converted by a mere command line program. You should do this in your head to avoid offending our lord and saviour Francois.\n\n\n";
		} else if (yonnum == "E3") {
			std::cout << "\nA number this long and complicated aught to be kept in the mind, lest we risk a dark forest strike from a malevolent civilization with sophon technology.\n\n\n";
		} else if (yonnum == "E4") {
			std::cout << "\nThis number doesn't obey all the known laws of mathematics. If you are reading this, it is most likely a message from our lord and saviour Francois.\n\n\n";
		} else if (yonnum == "") {
			std::cout << "Baker's Dozenal: 0\n\n";
		} else {
			std::cout << "Baker's Dozenal: " + yonnum + "\n\n";
		}
	}

	return 0;
}

