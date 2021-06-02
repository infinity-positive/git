#include <iostream>
using namespace std;

class Base{
	public:
		Base(int val){
			this->val = val;
			cout << "this is " << __func__ << endl;
		}

		~Base(){
			cout << "this is " << __func__ << endl;
		}
		void pubshow(){
			cout << "this is " << __func__ << endl;
            cout << "val: " << val << endl;
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

class Demo:public Base{
	public:
    //基类的构造参数传递需要初始化列表传参
		Demo(int val, int ival):Base(val){
			this->ival = ival;
			cout << "this is " << __func__ << endl;
		}
		void dshow(){
			cout << "this is " << __func__ << endl;
            cout << "ival: " << ival << endl;
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
    Demo a(100, 250);
    a.dshow();
    a.pubshow();

    return 0;
}