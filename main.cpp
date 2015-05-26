#include <iostream>
#include "memory.h"
#include "opc_field.h"
#include "table.h"

class DB10 : public opc::Table
{
public:
    DB10(): Table("DB10")
    {}

    opc::Fint field1 = {this, 100};
    opc::Freal field2 = {this, 110};
    opc::Fbool field3 = {this, 111, 1};
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

    db10.field1(mem.Page<int>().Read(0));
    cout << db10.field1.AddrStr() << endl
         << db10.field2.AddrStr() << endl
         << db10.field3.AddrStr() << endl;

    cout << db10.field1.AddrStr() << " value is " << db10.field1()<< endl;
    cout << "Hello World!" << mem.Page<int>().Read(0) << mem.Page<std::string>().Read(1)<< endl;

    mem.Reset();

    cout << db10.field1.AddrStr() << " value is " << db10.field1()<< endl;
    cout << "Hello World! " << mem.Page<int>().Read(1) << mem.Page<std::string>().Read(1)<< endl;

    return 0;
}

