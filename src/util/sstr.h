#ifndef _SSTR_H
#define _SSTR_H

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
            ( std::ostringstream() << std::dec << x ) ).str()

#endif