#ifndef OPC_TYPE_H
#define OPC_TYPE_H
#include "def.h"
#include "table.h"
#include "opc_addr.h"

namespace opc
{
/*задача этого класса - оперативное сопоставление типа данных с++ типу в контроллере*/

template <typename T>
class OPC_field
{
public:
    OPC_field(const Table *parent, const addr_type addr)
        : addr(addr), ofset(0), value(0)
    {
        CompileAddr<T>(addr_str, sizeof(addr_str), parent, addr);
    }
    OPC_field(const Table *parent,const addr_type addr, const addr_ofset_type ofset)
        :addr(addr), ofset(ofset),value(0)
    {
        CompileAddr<T>(addr_str, sizeof(addr_str), parent, addr, &ofset);
    }

    ~OPC_field()
    {}

    const T& operator ()() const
    {
        return value;
    }

    T& operator ()(const T &val)
    {
        return value = val;
    }

    const char* AddrStr() const
    {
        return addr_str;
    }
private:
    OPC_field (const OPC_field&);
    void operator = (const OPC_field&);

    char addr_str[41] = {0};
    const addr_type addr;
    const addr_ofset_type ofset;

    T value;
};

typedef OPC_field<__int32_t> Fint;
typedef OPC_field<float> Freal;
typedef OPC_field<bool> Fbool;
}

#endif // OPC_TYPE_H
