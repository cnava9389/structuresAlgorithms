export module Math;

import <iostream>;
import <string>;
import <stdexcept>;

export class Variable {
	public:

		Variable(std::string &x, int y = 1) {
			value = x;
			coef = y;
		};
	
	private:
		std::string value;
		int coef;
	
	public:
		std::string getValue() {
			return this->value;
		};

		int getCoef() {
			return this->coef;
		}

		Variable operator + (Variable &obj) {
			if (this->getValue() != obj.getValue()) {
				throw std::invalid_argument("variables must be the same to be added");
			}

		}
};
