#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace::std;

class Singleton
{
public:
	static bool flag;
	static Singleton& instance()
	{
		static Singleton singleton;
		return singleton;
	}
	int getTemp()
	{
		return temp;
	}
private:
	int temp;
	Singleton(){
		if (!Singleton::flag)
		{
			sleep(1);
			return;
		}
		temp = 100;
	}
	~Singleton(){}
};

bool Singleton::flag = false;

void* thread(void*arg)
{
	Singleton::flag = true;
	cout << "thread temp:" << Singleton::instance().getTemp() << endl;

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;

	pthread_create(&tid, NULL, thread, NULL);
	cout << "Main temp:" << Singleton::instance().getTemp() << endl;
	pthread_join(tid, NULL);

	return 0;
}