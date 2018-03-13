#include <iostream>
using namespace std;
class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int i, int j);
	~ComplexNumber();
	void Input();
	void Output();
	bool IsEqual(ComplexNumber i);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber i);
	ComplexNumber Subtract(ComplexNumber i);
	ComplexNumber Multiplication(ComplexNumber i);
	float Magnitude();
};

int main()
{
	ComplexNumber c1, c2;
	bool c1equalsc2;

	c1.Input();
	c2.Input();

	cout << "c1 :";
	c1.Output();

	cout << "c2 :";
	c2.Output();

	cout << endl;

	c1equalsc2 = c1.IsEqual(c2);
	if (c1equalsc2) 
		cout << "c1 equals c2" << endl << endl;
	else 
		cout << "c1 not equals c2" << endl << endl;

	cout << "Conjugate c1: ";
	c1.Conjugate().Output();

	cout << "Conjugate c2: ";
	c2.Conjugate().Output();

	cout << "c1 + c2: "; c1.Add(c2).Output();
	cout << "c1 - c2: "; c1.Subtract(c2).Output();
	cout << "c1 * c2: "; c1.Multiplication(c2).Output();

	cout << "Mag of c1: " << c1.Magnitude() << endl;
	cout << "Mag of c2: " << c2.Magnitude() << endl;

	system("pause");
	return 0;
}

inline ComplexNumber::ComplexNumber()
{

}

inline ComplexNumber::ComplexNumber(int realPart, int imaginaryPart)
{
	real = realPart;
	imaginary = imaginaryPart;
}

inline ComplexNumber::~ComplexNumber() //Does Nothing.
{

}

inline void ComplexNumber::Input() // this method should not be in this class because it make it tightly coupled to console window :P
{
	cout << "Real:";
	cin >> real;
	cout << "Imaginary:";
	cin >> imaginary;
	cout << endl;
}

inline void ComplexNumber::Output()
{
	cout << real << "+ (" << imaginary << "i)" << endl << endl;
}

inline bool ComplexNumber::IsEqual(ComplexNumber i)
{
	return (real == i.real && imaginary == i.imaginary);
}

inline ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber n;
	n.real = real;
	n.imaginary = -imaginary;
	return n;
}

inline ComplexNumber ComplexNumber::Add(ComplexNumber i)
{
	ComplexNumber n;
	n.real = i.real + real;
	n.imaginary = i.imaginary + imaginary;
	return n;
}

inline ComplexNumber ComplexNumber::Subtract(ComplexNumber i)
{
	ComplexNumber n;
	n.real = real - i.real;
	n.imaginary = imaginary - i.imaginary;
	return n;
}

inline ComplexNumber ComplexNumber::Multiplication(ComplexNumber i)
{
	ComplexNumber z;
	int a = real, b = imaginary, c = i.real, d = i.imaginary;
	z.real = a*c - b*d;
	z.imaginary = b*c + a*d;
	return z;
	// later add required ifs
}

inline float ComplexNumber::Magnitude()
{
	int x = real, y = imaginary;
	return sqrt((x*x) + (y*y));
}
