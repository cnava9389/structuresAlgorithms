import Math;
import <iostream>;
import <string>;

int main() {	
	std::string g = "z";
	std::string y = "x";
	Variable x(y,3);
	Variable z(y,4);
	Variable c = x / z;
	Fraction f(2);
	Fraction d(3, 4);
	std::cout << c.repr() << "\n";
	std::cout << d.repr() << "\n";
	return 0;
}