#include <iostream>
using namespace std;

// 抽象主题类
class Subject
{
public:
	virtual ~Subject() {}
	virtual void request() = 0;
};

// 真实主题类
class RealSubject:public Subject
{
public:
	void request()
	{
		cout << "真实类" << endl;
	}
};

// 代理主题类 1
class Proxy:public Subject
{
private:
	Subject* base;
public:
	Proxy() { base = nullptr; }
	~Proxy()
	{
		if (base != nullptr)
			delete base;
	}
	void request()
	{
		if (base == nullptr)
		{
			base = new RealSubject();
		}
		cout << "代理类间接调用";
		base->request();
	}
};

// 代理主题类 2
class Proxy :public Subject
{
private:
	Subject* base; // 指向真实类
public:
	Proxy(Subject* realSub)
	{
		base = realSub;
	}
	~Proxy()
	{
		if (base != nullptr)
			delete base;
	}
	void request()
	{
		cout << "代理类间接调用";
		base->request();
	}
};

// 代理类1对应的main
void main()
{
	Proxy px;
	px.request();
}

// 代理类2对应的main
void main()
{
	Subject* sub = new RealSubject();
	Proxy proxy(sub);
	proxy.request();
}