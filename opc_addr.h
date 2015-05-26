#ifndef OPC_TYPES_H
#define OPC_TYPES_H
#include "def.h"
#include <cstdio>

#include "table.h"

namespace opc
{
const char* getType (const int &)
{
    return "DINT";
}
const char* getType (const float &)
{
    return "REAL";
}
const char* getType (const bool &)
{
    return "X";
}

const char* getProto()
{
    return "S7:[S7 connection_4]";
}

template <typename T>
void CompileAddr(char* buf,
                 size_t buf_len,
                 const Table *table,
                 const addr_type &addr,
                 const addr_ofset_type *ofset = 0)
{
    const char* type = getType(T());
    const char* proto = getProto();
    if (ofset)
        snprintf(buf, buf_len - 1, "%s%s,%s%lu.%u", proto, table->Name(), type, addr, *ofset);
    else
        snprintf(buf, buf_len - 1, "%s%s,%s%lu", proto, table->Name(), type, addr);
}
}


#endif // OPC_TYPES_H
