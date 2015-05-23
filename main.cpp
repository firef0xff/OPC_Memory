#include <iostream>
#include "memory.h"
#include "opc_type.h"

using namespace std;

int main()
{
    memory::Memory mem;
    mem.Reset();
    mem.Page<int>().Write(0, 233);
    mem.Page<std::string>().Write(1, "ss");

    opc::OPC_field<int> d("S7:[S7 connection_4]DB10,REAL", 100);
    d(mem.Page<int>().Read(0));

    cout << d.AddrStr() << " value is " << d()<< endl;
    cout << "Hello World!" << mem.Page<int>().Read(1) << mem.Page<std::string>().Read(1)<< endl;

    mem.Reset();

    cout << d.AddrStr() << " value is " << d()<< endl;
    cout << "Hello World! " << mem.Page<int>().Read(1) << mem.Page<std::string>().Read(1)<< endl;

    return 0;
}

