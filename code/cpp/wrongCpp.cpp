#include <iostream>
#include <string>
#include <windows.h>
// should not print Oh while it will
// VS2013 will print Oh
//http://www.ituring.com.cn/article/194454

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    static std::string x = std::string(10000000, 'e');
    if (x.length() == 0) {
        std::cout << "Oh!" << std::endl;
    }
    else {
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