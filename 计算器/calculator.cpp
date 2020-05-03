#include <iostream>
using namespace std;
class CalBase
{
public:
	double num1;
	double num2;
public:
	virtual double cal() = 0;
};

class Add : public CalBase
{
public:
	double cal()
	{
		return num1 + num2;
	}
};

class Sub : public CalBase
{
public:
	double cal()
	{
		return num1 - num2;
	}
};

class Mul : public CalBase
{

public:
	double cal()
	{
		return num1 * num2;
	}
};

class Div :public CalBase
{
public:
	double cal()
	{
		return num1 / num2;
	}
};

class Factory
{
public:
	CalBase* createCal(char type)
	{
		switch (type)
		{
		case '+':
			return new Add();
		case '-':
			return new Sub();
		case '*':
			return new Mul();
		case '/':
			return new Div();
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
		CalBase* cal = ftory->createCal(oper);
		cal->num1 = num1;
		cal->num2 = num2;

		result = cal->cal();

		cout << "计算结果:" << result << endl;
	}
	return 0;
}
