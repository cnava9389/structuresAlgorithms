export module Math;

import <iostream>;
import <string>;
import <stdexcept>;
import <cmath>;

export class Fraction {
private:
	double num;
	double den;
	double value;
private:
	void roundString(std::string& str, int places = 0) {
		size_t index = str.find(".");
		if (places == 0) {
			str.resize(index);
		}
		else {
			str.resize(index + places + 1);
		}
	}
public:
	Fraction(double x, double y) {
		num = x;
		den = y;
		value = x / y;
		value = value;
	} // its the to_string function that is making it longer than needs to be rewrite or re implement Fraction class.
	Fraction(int x) {
		num = 0;
		den = 0;
		value = x;
	}
	Fraction(double x) {
		num = 0;
		den = 0;
		value = x;
	}

	double getValue() {
		return this->value;
	}

	std::string repr() {
		if (this->num != 0 && this->den != 0) {
			std::string result = std::to_string(this->num);
			this->roundString(result);
			std::string result2 = std::to_string(this->den);
			this->roundString(result2);
			result += "/" + result2;
			return result;
		}
		else {
			std::string result = std::to_string(this->value);
			this->roundString(result, 2);
			return result;
		}
	}

	Fraction operator += (int x) {
		this->value += x;
		return *this;
	}

	Fraction operator += (double x) {
		this->value += x;
		return *this;
	}

	Fraction operator += (Fraction& x) {
		this->value += x.value;
		return *this;
	}

	Fraction operator *= (Fraction& x) {
		this->value *= x.value;
		return *this;
	}

	Fraction operator *= (double x) {
		this->value *= x;
		return *this;
	}
};

export class Variable {
private:
	std::string var;
	Fraction coef;
	int exp;

public:

	Variable(std::string& x, double y = 1, int z = 1) {
		var = x;
		Fraction coef(y);
		exp = z;
	};

private:
	void addCoef(double x) {
		this->coef += x;
	};

	void addExp(int x) {
		this->exp += x;
	};
	
	void multiplyCoef(double x) {
		this->coef *= x;
	};

public:
	std::string getVar() {
		return this->var;
	};

	double getCoef() {
		return this->coef.getValue();
	};

	int getExp() {
		return this->exp;
	};

	Variable operator + (Variable& obj) {
		std::string myVal = this->getVar();
		std::string objVal = obj.getVar();
		try {
			if (myVal != objVal) {
				throw std::invalid_argument("variables must be the same to be added");
			}

			this->addCoef(obj.getCoef());
			return *this;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}

	}

	Variable operator - (Variable& obj) {
		std::string myVal = this->getVar();
		std::string objVal = obj.getVar();
		try {
			if (myVal != objVal) {
				throw std::invalid_argument("variables must be the same to be subtracted");
			}

			this->addCoef(-obj.getCoef());
			return *this;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}

	}

	Variable operator * (Variable& obj) {
		std::string myVal = this->getVar();
		std::string objVal = obj.getVar();
		try {
			if (myVal != objVal) {
				throw std::invalid_argument("variables must be the same to be multiplied");
			}

			this->addExp(obj.getExp());
			this->multiplyCoef(obj.getCoef());
			return *this;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}
	}

	Variable operator / (Variable& obj) {
		std::string myVal = this->getVar();
		std::string objVal = obj.getVar();
		try {
			if (myVal != objVal) {
				throw std::invalid_argument("variables must be the same to be divided");
			}

			this->addExp(-obj.getExp());
			this->multiplyCoef(1 / obj.getCoef());
			return *this;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	std::string repr() {
		if (this->exp == 0) {
			return std::to_string(this->coef.getValue());
		}
		else if (this->exp == 1) {
			return std::to_string(this->coef.getValue()) + this->var;
		}
		else {
			return std::to_string(this->coef.getValue()) + this->var + "^" + std::to_string(this->exp);
		}
	}
};
