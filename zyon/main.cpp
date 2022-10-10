/*
 * main.cpp
 *
 *  Created on: Oct. 8, 2022
 *      Author: Matthew Hinton
 */

#include "../yon/yon.h"
#include "zyon.h"


int main(void) {

	long double dec{ };
	int dozPrecision{ }, yonPrecision{ }, radixCount{ };
	std::string dozenalCharacters{".0123456789AaBbXxEe"};
	std::string yonnum{""}, doznum{""};
	bool dozenal, ignoreZeroFraction;

	std::cout << "\nType \"q\" to quit...\n\n";

	while (true) {
		yonnum = "";

		std::cout << "Dozenal: ";
		std::cin >> doznum;

		if (doznum.find("q") != std::string::npos) {
			return 0;
		} else {
			dozenal = true;
			radixCount = 0;
			for (unsigned i{ }; i < doznum.size(); ++i) {
				if (dozenalCharacters.find(doznum.at(i)) == std::string::npos) {
					dozenal = false;
				} else if (dozenalCharacters.find(doznum.at(i)) == 0) {
					++radixCount;
				}
			}
			if (radixCount > 1) {
				dozenal = false;
			}
			if (dozenal) {
				dozPrecision = 0;
				while (doznum.size() > 0) {
					if (doznum.front() != dozenalCharacters.at(1)) {
						break;
					} else {
						doznum.erase(doznum.begin());
					}
				}
				if (radixCount == 1) {
					while (doznum.size() > 0 && doznum.back() != '.') {
						if (doznum.back() != dozenalCharacters.at(1)) {
							break;
						} else {
							doznum.pop_back();
							++dozPrecision;
						}
					}
				}
				if (doznum == "") {
					yonnum = "0";
				} else {
					if (IGNORE_ZERO_FRACTION && doznum.back() == '.') {
						ignoreZeroFraction = true;
					} else { ignoreZeroFraction = false; }
					if (doznum.find(".") != std::string::npos) {
						dozPrecision += doznum.size() - doznum.find(".");
					}
					if (doznum.find(".") != std::string::npos && (doznum.find(".") > MAX_PRECISION || doznum.size() - doznum.find(".") - 1 > MAX_PRECISION) ) {
						yonnum = "E3";
					} else if (doznum.find(".") == std::string::npos && doznum.size() > MAX_PRECISION) {
						yonnum = "E3";
					} else if (TRUNC_PRECISION == false && dozPrecision > MAX_PRECISION) {
						yonnum = "E3";
					} else {
						if (dozPrecision > MAX_PRECISION) {
							dozPrecision = MAX_PRECISION + 1;
						}
						--dozPrecision;
						dec = doztodec(doznum);

						yonPrecision = 0;
						if (EXTRA_PRECISION) {
							if (dozPrecision > 0) {
								yonPrecision = dozPrecision;
							}
						} else {
							yonPrecision = floor( log( pow(12, dozPrecision) ) / log(13) );
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
