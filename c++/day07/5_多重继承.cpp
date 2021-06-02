#include<iostream>
using namespace std;

class wolf{
    public:
        wolf(){
            cout << "this is " << __func__ << endl;
        }
        ~wolf(){
            cout << "this is " << __func__ << endl;
        }
};

class man{
    public:
        man(){
            cout << "this is " << __func__ << endl;
        }
        ~man(){
            cout << "this is " << __func__ << endl;
        }
};

//构造调用顺序和继承的顺序一致,从左至右
//析构调用顺序和构造相反
class wolfman:public wolf, public man{
    public:
        wolfman(){
            cout << "This is " << __func__ << endl;
        }
        ~wolfman(){
            cout << "this is " << __func__ << endl;
        }
};

int main()
{
    wolfman a;
}