#include "symbol.h"

std::ostream& operator<< (std::ostream &out, Symbol &symbol)
{
    out << symbol._offset;
    return out;
}
