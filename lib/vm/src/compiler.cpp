#include "compiler.hpp"

std::map<std::string, addr> label;

addr compile(byte b) {
    assert(Cp < Msz);
    M[Cp++] = b;
    return Cp;
}
