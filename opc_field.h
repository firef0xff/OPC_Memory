#ifndef OPC_TYPE_H
#define OPC_TYPE_H
#include "def.h"
#include "table.h"
#include <cstdio>


namespace opc
{
/*задача этого класса - оперативное сопоставление типа данных с++ типу в контроллере*/

template <typename T>
class OPC_field
{
public:
    OPC_field(const Table &parent, const addr_type addr)
        : addr(addr), ofset(0), parent(parent)
    {
        CompileAddr(false);
    }
    OPC_field(const Table &parent, const addr_type addr, const addr_ofset_type ofset)
        :addr(addr), ofset(ofset), parent(parent)
    {
        CompileAddr(true);
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
    void CompileAddr(bool use_ofset)
    {
        if (use_ofset)
            snprintf(addr_str, 40, "%s%lu.%u", parent.Name(), addr, ofset);
        else
            snprintf(addr_str, 40, "%s%lu", parent.Name(), addr);
    }
    char addr_str[41] = {0};
    const addr_type addr;
    const addr_ofset_type ofset;
    const Table &parent;

    T value;
};

typedef OPC_field<__int32_t> Fint;
typedef OPC_field<float> Freal;
typedef OPC_field<bool> Fbool;
}

#endif // OPC_TYPE_H
