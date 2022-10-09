/*
 * zyon.cpp
 *
 *  Created on: Oct. 8, 2022
 *      Author: Matthew Hinton
 */

#include "zyon.h"


long double doztodec(std::string doznum) {

	long double dec{ };
	int exp{ }, digit{ };
	std::string dozDigits[] = {"0123456789ABC", "0123456879abc", "0123456789XEZ", "0123456789xez"};

	if (doznum.find(".") != std::string::npos) {
		exp = doznum.find(".") - 1;
	} else {
		exp = doznum.size() - 1;
	}

	int i{ };
	while (exp >= 0) {
		digit = 13;
		i = 0;
		while (i < sizeof(dozDigits) && digit > 12) {
			if (dozDigits[i].find(doznum.front()) != std::string::npos) {
				digit = dozDigits[i].find(doznum.front());
			}
			++i;
		}
		if (digit > 12) {
			printf("Error!!!"); // get rid of these lines later
			return 0.0;
		}

		dec += digit * pow(12, exp);
		doznum.erase(doznum.begin());
		--exp;
	}

	if (doznum != "") {
		doznum.erase(doznum.begin());
		while (doznum.size() > 0) {
			digit = 13;
			i = 0;
			while (i < sizeof(dozDigits) && digit > 12) {
				if (dozDigits[i].find(doznum.front()) != std::string::npos) {
					digit = dozDigits[i].find(doznum.front());
				}
				++i;
			}
			if (digit > 12) {
				printf("Error!!!"); // get rid of these lines later
				return 0.0;
			}

			dec += digit * pow(12, exp);
			doznum.erase(doznum.begin());
			--exp;
		}

	}

	return dec;
}

