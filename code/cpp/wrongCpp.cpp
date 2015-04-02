#include <iostream>
#include <string>
#include <windows.h>
// should not print Oh while it will
// VS2013 will print Oh
//http://www.ituring.com.cn/article/194454

class my:public std::string
{
   public: my(int l, char c):std::string(10000000, 'e')
    {
    std::cout << "iAmConstruct"<< std::endl;
    }
    

};

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    SetThreadAffinityMask(GetCurrentThread(), 0x00000001);// remove this you will see Oh
    static my x = my(10000000, 'e');
    printf("thredid: %d\n", GetCurrentThreadId());
    if (x.length() == 0) {
        printf("thredid: %d\n", GetCurrentThreadId());
        std::cout << "Oh!" << std::endl;
    }
    else {
        printf("thredid: %d\n", GetCurrentThreadId());
        std::cout << x.length() << std::endl;
    }

    return 0;
}

int main()
{
    CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    Sleep(100);
    return 0;
}