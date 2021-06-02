
#include <iostream>
using namespace std;

class Arr{
	public:
		Arr(int size = 5);
		Arr(const Arr &);
		~Arr();
		void show();
		int &operator[](const int );
		friend int * operator&(const Arr &);
		friend Arr operator+(const Arr &, const Arr &);
		void operator=(const Arr &);
		friend Arr operator<<(const Arr &, int);

	private:
		int size;
		int *arr;
};


Arr::Arr(int size):arr(new int[size])
{
	this->size = size;
}

Arr::Arr(const Arr &obj):arr(new int[obj.size])
{
	this->size = obj.size;
	for(int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

Arr::~Arr()
{
	if(arr){
		delete []arr;
	}
}

void Arr::show()
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int &Arr::operator[](const int i)
{
	return arr[i];
}

int * operator&(const Arr &obj)
{
	return obj.arr;
}

Arr operator+(const Arr &a, const Arr &b)
{
	Arr tmp(a.size + b.size);
	int i, j;
	for(i = 0; i < a.size; i++)
	{
		tmp.arr[i] = a.arr[i];
	}
	for(j = 0; j < b.size; j++)
	{
		tmp.arr[j+i] = b.arr[j];
	}
	return tmp;
}

void Arr::operator=(const Arr &a)
{
	if(a.size != size)
	{
		delete []arr;
		size = a.size;
		arr = new int[size];
		for(int i = 0; i < size; i++)
		{
			arr[i] = a.arr[i];
		}
	}
	else
	{
		for(int i = 0; i < a.size; i++)
			arr[i] = a.arr[i];
	}

}

Arr operator<<(const Arr &obj, int pos)
{
	Arr tmp = obj;
	int t, i;
	while(pos--)
	{
		t = tmp[0];
		for(i = 0; i < tmp.size-1; i++)
		{
			tmp[i] = tmp[i+1];
		}
		tmp[tmp.size-1] = t;
	}
	return tmp;
}



int main(int argc, char * argv[])
{
	Arr a;
	for(int i = 0; i < 5; i++)
	{
		a[i] = i;//调用了重载的运算符
	}
	Arr b(3);
	for(int i = 0; i < 5; i++)
		b[i] = i*i;

	Arr c = b;//拷贝构造
	c.show();
	b.show();
	c = b << 2;
	c.show();
	c = a+b;
	c.show();

	return 0;
}

