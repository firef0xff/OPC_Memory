#include "table.h"
#include <cstring>
namespace opc
{
Table::Table(const char* name)
    :name(name)
{    
}

Table::~Table()
{}

const char* Table::Name() const
{
    return name;
}
}
