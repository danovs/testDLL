#include <windows.h>
#include <stdio.h>

typedef void(*TestHelloFunc)(void);

int main(int argc, char* argv[])
{
    HINSTANCE hLib;
    TestHelloFunc TestHello;

    
    hLib = LoadLibraryW(L"C:\\DLL\\AnotherDLL.dll");
    if (hLib == NULL) {
        printf("Error: Cannot load library\n");
        return -1;
    }

    
    TestHello = (TestHelloFunc)GetProcAddress(hLib, "TestHello");
    if (TestHello == NULL) {
        printf("Error: TestHello function not found\n");
        FreeLibrary(hLib);
        return -2;
    }

    
    printf("Calling TestHello from DLL...\n");
    TestHello();

    
    FreeLibrary(hLib);

    return 0;
}
