#include <iostream>
#include "memory.h"
#include "opc_field.h"
#include "table.h"
#include "opc_types.h"

class DB10 : public opc::Table
{
public:
    DB10(): Table("DB10")
    {}

    opc::Fint field1 = {name, 100};
};

using namespace std;

int main()
{
    memory::Memory mem;
    mem.Reset();
    mem.Page<int>().Write(0, 233);
    mem.Page<std::string>().Write(1, "ss");

//    int -> DINT;
//    float -> REAL;
//    bool -> X;



    DB10 db10;
    opc::OPC_field<int> d("S7:[S7 connection_4]DB10,REAL", 100);
    d(mem.Page<int>().Read(0));

    db10.field1();

    cout << d.AddrStr() << " value is " << d()<< endl;
    cout << "Hello World!" << mem.Page<int>().Read(1) << mem.Page<std::string>().Read(1)<< endl;

    mem.Reset();

    cout << d.AddrStr() << " value is " << d()<< endl;
    cout << "Hello World! " << mem.Page<int>().Read(1) << mem.Page<std::string>().Read(1)<< endl;

    return 0;
}

