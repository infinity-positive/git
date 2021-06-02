#include <iostream>
using namespace std;

//声明一个基类， 未来可以去派生子类
class Base{
	public:
		Base(){
			val = 250;
			cout << "this is " << __func__ << endl;
		}

		~Base(){
			cout << "this is " << __func__ << endl;
		}
		void pubshow(){
			cout << "this is " << __func__ << endl;
			proshow();//受保护的
		}

	protected:
		//受保护的，不能直接通过对象调用
		void proshow(){
			cout << "this is " << __func__ << endl;
		}

	private:
		int val;

};

class Demo:protected Base{
	public:
		Demo(){
			ival = 3;
			cout << "this is " << __func__ << endl;
		}
		void dshow(){
			cout << "this is " << __func__ << endl;
			dproshow();
		}

	protected:
		void dproshow(){
			cout << "this is " << __func__ << endl;
		}

	private:
		int ival;
};

int main()
{
	Demo a;
	a.dshow();

	//保护继承，基类都属于派生类的保护，不可直接访问
	//a.dproshow();
	//a.pubshow();

	return 0;
}