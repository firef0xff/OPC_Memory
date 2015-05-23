#ifndef OPC_TYPE_H
#define OPC_TYPE_H
#include "def.h"
#include "cstdio"

namespace opc
{
/*задача этого класса - оперативное сопоставление типа данных с++ типу в контроллере*/

template <typename T>
class OPC_field
{
public:
    OPC_field(const char *proto_str, const addr_type addr)
        : addr(addr), ofset(0)
    {
        CompileAddr(proto_str, false);
    }
    OPC_field(const char *proto_str, const addr_type addr, const addr_ofset_type ofset)
        :addr(addr), ofset(ofset)
    {
        CompileAddr(proto_str, true);
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
    void CompileAddr(const char *proto_str, bool use_ofset)
    {
        if (proto_str)
            if (use_ofset)
                snprintf(addr_str, 40, "%s%lu.%u", proto_str, addr, ofset);
            else
                snprintf(addr_str, 40, "%s%lu", proto_str, addr);
        else
            if (use_ofset)
                snprintf(addr_str, 40, "%lu.%u", addr, ofset);
            else
                snprintf(addr_str, 40, "%lu", addr);
    }
    char addr_str[40] = {0};
    const addr_type addr;
    const addr_ofset_type ofset;

    T value;
};

}

#endif // OPC_TYPE_H
