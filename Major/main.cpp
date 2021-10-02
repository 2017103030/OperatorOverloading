//Source Code for Review operator overloading
//2021.10.11 CheolHyeon Jeong

#include <iostream>
using namespace std;


class Basket{
	int apple;
	int pear;
	int galic;
public:
	Basket(int a = 0, int p = 0, int g = 0) : apple(a), pear(p), galic(g) {}
	void Print() const {
		printf("apple : %d, pear : %d, galic : %d\n", apple, pear, galic);
	}
	// + Operator Overloading
	Basket operator+( const Basket & arg) const {
		Basket bk;
		bk.apple = apple + arg.apple;
		bk.pear = pear + arg.pear;
		bk.galic = galic + arg.galic;
		return bk;
	}
	// ++ prefix Operator Overloading
	const Basket& operator++() {
		++apple;
		++pear;
		++galic;
		return *this;
	}
	// ++ posfix Operator Overloading
	const Basket& operator++(int) {
		apple++;
		pear++;
		galic++;
		return *this;
	}
	// -- prefix Operator Overloading
	const Basket& operator--() {
		--apple;
		--pear;
		--galic;
		return *this;
	}
	// -- posifx Operator Overloading
	const Basket& operator--(int) {
		apple--;
		pear--;
		galic--;
		return *this;
	}
	// - prefix Operation Overloading
	const Basket &operator-() const {
		return Basket(-apple, -pear, -galic);
	}
	// == Operator Overloading
	bool operator==(const Basket& arg) const {
		return (apple == arg.apple && pear == arg.pear && galic == arg.galic);
	}
	// != Operator Overloading
	bool operator!=(const Basket& arg) const {
		return !(*this == arg);
	}

	// [] Operation Overloading
	int operator[](int idx) const {
		if (idx == 0) return apple;
		else if (idx == 1) return pear;
		else if (idx == 2) return galic;
		else throw "Index which is over size of basket";
	}

	int& operator[](int idx) {
		if (idx == 0) return apple;
		else if (idx == 1) return pear;
		else if (idx == 2) return galic;
		else throw "Index which is over size of basket";
	}
	//operator int() Overloading
	operator int() const {
		return apple;
	}

	// for Global operator funciton overloading
	friend const Basket operator+(const Basket, int);
	friend const Basket operator+(int, const Basket);
	friend ostream& operator<< (ostream& os, Basket& arg);

};

// Basket + integer type operation
const Basket operator+(const Basket left_basket, int right) {
	return(Basket(left_basket.apple + right, left_basket.pear + right, left_basket.galic + right));
}
// integer + Basket type operation
const Basket operator+(int left, const Basket right_basket) {
	return(Basket(right_basket.apple + left, right_basket.pear + left, right_basket.galic + left));
}
// Basket - integer type operation
const Basket operator-(const Basket left_basket, int right) {
	return operator+(left_basket, -right);
}
// integer - Basket type operation
const Basket operator-(int left, const Basket right_basket) {
	return operator+(left, -right_basket);
}

//operator << overloading
ostream& operator<< (ostream& os, Basket& arg) {
	os << arg.apple << ", " << arg.pear << ", " << arg.galic << endl;
	return os;
}

int main() {
	//operator + Overloading Example
	cout << "Operator '+' Overloading Example" << endl;
	Basket basket1(1, 3, 2);
	Basket basket2(3, 4, 2);
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "basket2 : " << endl;
	basket2.Print();
	cout << "summation : " << endl;
	Basket basket_summation = basket1 + basket2;
	basket_summation.Print();
	cout << endl;

	//operator ++ Posfix , Prefix Overloading Example
	cout << "Operator ++ Posfix, Prefix Overloading Example" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "basket2 : " << endl;
	basket2.Print();
	++basket1;
	basket2++;
	cout << "++basket1 : " << endl;
	basket1.Print();
	cout << "basket2++ : " << endl;
	basket2.Print();
	cout << endl;

	//operator -- Posfix , Prefix Overloading Example
	cout << "Operator -- Posfix, Prefix Overloading Example" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "basket2 : " << endl;
	basket2.Print();
	--basket1;
	basket2--;
	cout << "--basket1 : " << endl;
	basket1.Print();
	cout << "basket2-- : " << endl;
	basket2.Print();
	cout << endl;

	//operator == and != Example;
	Basket b0(1, 1, 1);
	Basket b1(1, 1, 1);
	cout << "b0 : " << endl;
	b0.Print();
	cout << "b1 : " << endl;
	b1.Print();
	cout << (b0 == b1) << endl;
	cout << (b0 != b1) << endl;

	Basket b2(1, 2, 1);
	Basket b3(1, 1, 1);
	cout << "b2 : " << endl;
	b2.Print();
	cout << "b3 : " << endl;
	b3.Print();
	cout << (b2 == b3) << endl;
	cout << (b2 != b3) << endl;

	//Overloading by using global functions
	//Basket + integer operation
	cout << "Basket + integer operation" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "basket1 + 1: " << endl;
	Basket result = basket1 + 1;
	result.Print();
	cout << endl;

	//integer + Basket operation
	cout << "integer + Basket operation" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	result = 1 + basket1;
	cout << "1 + basket1" << endl;
	result.Print();
	cout << endl;

	//Basket - integer operation
	cout << "Basket - integer operation" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "basket1 - 1: " << endl;
	result = basket1 - 1;
	result.Print();
	cout << endl;

	//integer - Basket operation
	cout << "integer - Basket operation" << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	result = 1 - basket1;
	cout << "1 - basket1" << endl;
	result.Print();
	cout << endl;

	//operator << overloading
	cout << "operator << test result " << endl;
	cout << "basket1 : " << endl;
	basket1.Print();
	cout << "operator << result : " << endl;
	cout << basket1 << endl;

	//operator [] overloading
	cout << "operator [] test result" << endl;
	cout << "basket1 : " << endl;
	cout << basket1 << endl;
	for (int i = 0; i < 3; i++) {
		cout << "idx : " << basket1[i] << endl;
	}
	cout << endl;

	//operator [] overloading for change component
	cout << "operator [] test result" << endl;
	cout << "basket1 : " << endl;
	cout << basket1 << endl;
	cout << "basket1[0] = 100 : " << endl;
	basket1[0] = 100;
	cout << "basket1 : " << endl;
	cout << basket1 << endl;
	return 0;

}