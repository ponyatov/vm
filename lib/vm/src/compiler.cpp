#include "compiler.hpp"

std::map<std::string, addr> global;
std::map<std::string, addr> local;
std::map<std::string, std::vector<addr>> forward;

addr compile(byte b) {
    assert(Cp + sizeof(b) < Msz);
    M[Cp] = b;
    Cp += sizeof(b);
    return Cp;
}

addr compile(addr a) {
    assert(Cp + sizeof(a) < Msz);
    *(addr *)(&M[Cp]) = a;
    Cp += sizeof(a);
    return Cp;
}

extern addr label(std::string *s, bool glob) {  //
    if (glob) {
        global[*s] = Cp;
        local.clear();
    } else {
        local[*s] = Cp;
    }
    return Cp;
}

addr resolve(std::string *s) {
    auto it = local.find(*s);
    if (it != local.end()) return it->second;

    it = global.find(*s);
    if (it != global.end()) return it->second;

    forward[*s].push_back(Cp);
    return -1;
}
