#include <iostream>
#include <mutex>
using namespace std;

#define LAZY
#ifdef LAZY

// 懒汉式写法
class Singleton {
private:
    Singleton() {}
private:
    static mutex lock;
    static Singleton* sig;
public:
    static Singleton* instance() {
        if (sig == nullptr) {
            lock_guard<mutex> lk(lock);
            if (sig == nullptr)
                sig = new Singleton();
        }
        return sig;
    }
    Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};
Singleton* Singleton::sig = nullptr;
mutex Singleton::lock; // 内外定义，链接时分配内存

#elif HUNGRY

// 饿汉式写法
class Singleton {
private:
    Singleton() {}
private:
    static Singleton* sig;
public:
    static Singleton* instance() {
        return sig;
    }
    Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};
Singleton* Singleton::sig = new Singleton;

#endif

int main()
{
    Singleton * sig = nullptr;
    sig = Singleton::instance();
    if (sig) {
        cout << "instance success" << endl;
    } else {
        cout << "instance failed" << endl;
    }
    return 0;
}