#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
class Complex
{
public:
	void display()
	{
		cout << _real << endl;
		cout	<< _image << endl;
	}
	Complex(double real=0.0, double image=0.0)
		:_real(real)
		, _image(image)
	{}
	Complex(const Complex&d)
		:_real(d._real)
		, _image(d._image)
	{}
	Complex&operator = (const Complex&d)
	{
		if (this != &d)
		{
			this->_real = d._real;
			this->_image = d._image;
		}
		return *this;
	}
	bool operator<(const Complex&d)
	{
		return(this->_real < d._real
			|| this->_real == d._image&&this->_image < d._image);
	}
	bool operator==(const Complex& d)
	{
		return(this->_real == d._real || this->_image == d._image);
	}
	bool operator!=(const Complex&d)
	{
		return!(*this == d);
	}
	bool operator>(const Complex&d)
	{
		return!(*this < d || *this == d);
	}
	Complex operator+(const Complex&d)
	{
		Complex tmp;
		tmp._real = this->_real + d._real;
		tmp._image = this->_image + d._image;
		return tmp;
	}
	Complex operator - (const Complex&d)
	{
		Complex tmp;
		tmp._real = this->_real - d._real;
		tmp._image = this->_image - d._image;
		return tmp;
	}
	Complex operator+=(const Complex&d)
	{
		this->_real += d._real;
		this->_image += d._image;
		return *this;
	}
	Complex operator-=(const Complex&d)
	{
		this->_real -= d._real;
		this->_image -= d._image;
		return *this;
	}
	Complex operator++()//Ç°ÖÃ
	{
		this->_real ++;
		this->_image++;
		return *this;
	}
	Complex operator++(int)//ºóÖÃ
	{
		Complex temp(*this);
		this->_real++;
		this->_image++;
		return temp;
	}
private:
	double _real;
	double _image;
};
void Test()
{
	Complex s1(1.0,1.0);
	Complex s2(2.0, 2.0);
	Complex ret = ++s1;//s1++,s1+s2,s1-s2,s1+=s2,s1-=s2;
	ret.display();
}
int main()
{
	Test();
	system("pause");
	return 0;
}