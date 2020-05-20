#include <iostream>
using namespace std;
// 抽象算法类
class Strategy
{
public:
	virtual ~Strategy(){};
	virtual void AlgorithmInterface() = 0;
};
// 具体算法A
class ConcreteStrategyA : public Strategy
{
public:
	virtual ~ConcreteStrategyA() {}
	void AlgorithmInterface() 
	{
		cout << "算法A实现..." << endl;
	}
};
// 具体算法B
class ConcreteStrategyB : public Strategy
{
public:
	virtual ~ConcreteStrategyB() {}
	void AlgorithmInterface()
	{
		cout << "算法B实现..." << endl;
	}
};
// 具体算法C
class ConcreteStrategyC : public Strategy
{
public:
	virtual ~ConcreteStrategyC() {}
	void AlgorithmInterface()
	{
		cout << "算法C实现..." << endl;
	}
};
// 上下文
class Context
{
public:
	Context(Strategy* strategy) :strategy(strategy) {}
	// 上下文方法 - 根据具体的策略对象调用其算法的方法
	void ContextInterface()
	{
		strategy->AlgorithmInterface();
	}
private:
	Strategy* strategy;
};

int main()
{
	// 实例不同的策略调用对应的接口获得不同的结果
	Context contxtA(new ConcreteStrategyA()); 
	contxtA.ContextInterface();

	Context contxtB(new ConcreteStrategyB());
	contxtB.ContextInterface();

	Context contxtC(new ConcreteStrategyC());
	contxtC.ContextInterface();
	return 0;
}