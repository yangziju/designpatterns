#include <iostream>
using namespace std;

class SellBase
{
public:
	virtual double acceptCash(double cash) = 0;
};

// 原价收费
class CashNormal :public SellBase
{
public:
	double acceptCash(double cash)
	{
		return cash;
	}
};
// 打折收费
class CashRebate :public SellBase
{
	double rebate;
public:
	CashRebate(double n) :rebate(n) {}
	double acceptCash(double cash)
	{
		return cash * rebate;
	}
};
// 满减收费
class CashReturn :public SellBase
{
	double cashreturn;
	double condition;
public:
	CashReturn(double ou, double co):condition(ou),cashreturn(co){}
	double acceptCash(double cash)
	{
		return cash - (cash / condition)*cashreturn;
	}
};

class SellContext
{
	SellBase* sb;
public:
	SellContext(int type)
	{
		switch (type)
		{
		case 1:
			sb = new CashNormal; break;
		case 2:
			sb = new CashRebate(0.8); break;
		case 3:
			sb = new CashReturn(200, 50); break;
		default:
			cout << "此活动方式不存在！" << endl; break;
		}
	}
	double getResult(double money)
	{
		return sb->acceptCash(money);
	}
};

int main()
{
	SellContext sc(3);
	int rs = sc.getResult(600);
	cout << rs << endl;

	SellContext sc2(2);
	int rs2 = sc2.getResult(100);
	cout << rs2 << endl;

	SellContext sc3(1);
	int rs3 = sc3.getResult(100);
	cout << rs3 << endl;
	return 0;
}