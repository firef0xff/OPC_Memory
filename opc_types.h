#ifndef OPC_TYPES_H
#define OPC_TYPES_H
#include "opc_field.h"

namespace opc
{
const char* getType (const Fint &)
{
    return "DINT";
}
const char* getType (const Freal &)
{
    return "REAL";
}
const char* getType (const Fbool &)
{
    return "X";
}

const char* getProto()
{
    return "S7:[S7 connection_4]";
}
}
#endif // OPC_TYPES_H
