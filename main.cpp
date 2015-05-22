#include <iostream>
#include "memory.h"

using namespace std;

int main()
{
    memory::Memory mem;
    mem.Reset();
    mem.Page<std::string, int>().Write("aaa", 233);
    mem.Page<int, std::string>().Write(222, "ss");


    cout << "Hello World!" << mem.Page<std::string, int>().Read("aaa") << mem.Page<int, std::string>().Read(222) << endl;

    mem.Reset();

    cout << "Hello World!" << mem.Page<std::string, int>().Read("aaa") << mem.Page<int, std::string>().Read(222) << endl;
    return 0;
}

