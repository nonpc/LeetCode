//1114.多线程一次打印
#if 0
/*
我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}

三个不同的线程将会共用一个 Foo 实例。

	线程 A 将会调用 one() 方法
	线程 B 将会调用 two() 方法
	线程 C 将会调用 three() 方法

请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

示例 1:
输入: [1,2,3]
输出: "onetwothree"
解释:
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。

示例 2:
输入: [1,3,2]
输出: "onetwothree"
解释:
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。

注意:
尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。

你看到的输入格式主要是为了确保测试的全面性。
在真实的面试中遇到过这道题？

解题思路 : 
可以这么理解，每个线程相当于一个人，执行代码相当于需要进到房间，执行one()这个人A房间对他不设防，
可以直接进去，而执行two()的这个人B需要打开smx这个锁才能进去，而执行three()的这个人C需要打开两把锁才能进入。
一开始门上是有两把锁的，所以一开始只有A能进入，出来之后想让B可以进入C不能进去，怎么办呢？
可以让A出来之前把smx锁打开，然后B就可以进去了，C不能进去，然后B出来之前把smx和tmx都打开，然后C才能进去。

*/
//测试代码
#if 0
mutex m;
condition_variable cond;

int flag = 0;
//std::lock_guard<std::mutex> lockGuard(m);
void func(int id)
{
	for (int i = 0; i < 3; ++i)
	{
		unique_lock<mutex> lk(m);
		while (flag != id)
			cond.wait(lk);
		cout << static_cast<char>('A' + id) << " " << endl;
		flag = (flag + 1) % 3;
		cond.notify_all();
	}
}

void main()
{
	thread A(func, 0);
	thread B(func, 1);
	func(2);
	cout << endl;

	A.join();
	B.join();

	system("pause");
}
#endif

//实际提交代码
#if 0
class Foo 
{
public:
	mutex smx;
	mutex tmx;
	Foo() 
	{
		smx.lock();
		tmx.lock();
	}

	void first(function<void()> printFirst)
	{
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		smx.unlock();
	}

	void second(function<void()> printSecond) 
	{
		lock_guard<mutex> lg(smx);
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		tmx.unlock();
	}

	void third(function<void()> printThird) 
	{
		lock_guard<mutex> lg(tmx);
		lock_guard<mutex> lg1(smx);
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

#endif


#endif