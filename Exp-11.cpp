#include <stdio.h>
#include <windows.h>
DWORD WINAPI threadFunc(LPVOID lp){
    printf("Thread is running...\n");
    return 0;
}
int main(){
    HANDLE t = CreateThread(NULL, 0, threadFunc, NULL, 0, NULL);
    WaitForSingleObject(t, INFINITE);
    CloseHandle(t);
    return 0;
}
