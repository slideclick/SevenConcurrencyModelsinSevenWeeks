#include "windows.h"
#include "stdio.h"
DWORD WINAPI WriteToDatabase( LPVOID lpParam )
{ 

	int i = *(int*)lpParam; 
	printf("%d\n",i);
	return TRUE; 
}
void main()
{
	HANDLE  aThread[4];
	// Create worker threads
	for(int i=0; i < 2; i++ )
	{
		aThread[i] = CreateThread( 
			NULL,
			0,
			(LPTHREAD_START_ROUTINE) WriteToDatabase, 
			&i,//reinterpret_cast<void*>(i),    //&   
			0,          
			NULL);
			Sleep(1000);
	}
	
}

