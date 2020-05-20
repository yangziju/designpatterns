// 懒汉式
class Single
{
private:
	Single() { }
public:
	static Single* inistance()  // 这里为啥是静态函数：非静态成员必须与特定对象对应
	{
		if (sig == nullptr)
			sig = new Single;
		return sig;
	}
private:
	static Single* sig;	// 这里为啥是静态成员：非静态成员必须与特定对象对应
};
Single* Single::sig = nullptr;


// 饿汉式
class Single
{
private:
	Single() { }
public:
	static Single* inistance()  // 这里为啥是静态函数：非静态成员必须与特定对象对应
	{
		return sig;
	}
private:
	static Single* sig;	// 这里为啥是静态函数：非静态成员必须与特定对象对应
};
Single* Single::sig = new Single;


// 懒汉式
class Single
{
private:
	Single() { }
public:
	static Single* inistance()  // 这里为啥是静态函数：非静态成员必须与特定对象对应
	{
		// 多线程优化
		if (sig == nullptr)
		{
			unique_lock<mutex> qlock(mtx);
				if (sig == nullptr)
					sig = new Single;
		}
		return sig;
	}
private:
	static mutex mtx;
	static Single* sig;	// 这里为啥是静态函数：非静态成员必须与特定对象对应
};
Single* Single::sig = nullptr;