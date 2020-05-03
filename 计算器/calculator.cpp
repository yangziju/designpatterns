#include <iostream>
using namespace std;
class CalBase
{
public:
	virtual double cal() = 0;
};

class Add : public CalBase
{
	double num1;
	double num2;
public:
	Add(double n1, double n2) :num1(n1), num2(n2) {}
	double cal()
	{
		return num1 + num2;
	}
};

class Sub : public CalBase
{
	double num1;
	double num2;
public:
	Sub(double n1, double n2) :num1(n1), num2(n2) {}
	double cal()
	{
		return num1 - num2;
	}
};

class Mul : public CalBase
{
	double num1;
	double num2;
public:
	Mul(double n1, double n2) :num1(n1), num2(n2) {}
	double cal()
	{
		return num1 * num2;
	}
};

class Div :public CalBase
{
	double num1;
	double num2;
public:
	Div(double n1, double n2) :num1(n1), num2(n2) {}
	double cal()
	{
		return num1 / num2;
	}
};

class Factory
{
public:
	CalBase* createCal(double num1, double num2, char type)
	{
		switch (type)
		{
		case '+':
			return new Add(num1, num2);
		case '-':
			return new Sub(num1, num2);
		case '*':
			return new Mul(num1, num2);
		case '/':
			return new Div(num1, num2);
		default:
			cout << "运算符输入错误" << endl;
			break;
		}
		return nullptr;
	}
};
int main()
{
	while (true)
	{
		double num1, num2, result;
		char oper;
		cout << "请输入计算式(运算符为#表示退出)：" << endl;
		cin >> num1 >> oper >> num2;
		if (oper == '#') break;
		Factory* ftory = nullptr;
		CalBase* cal = ftory->createCal(num1, num2, oper);
		result = cal->cal();
		cout << "计算结果:" << result << endl;
	}
	return 0;
}
