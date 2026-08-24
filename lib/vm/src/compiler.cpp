#include "compiler.hpp"

std::map<std::string, addr> global;
std::map<std::string, addr> local;
std::map<std::string, std::vector<addr>> forward;
std::map<addr, std::string> reverse;

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

void st(addr a, addr b) {
    assert(a + sizeof(b) < Cp);
    *(addr *)(&M[a]) = b;
}

addr label(std::string *s, bool glob) {
    reverse[Cp] = *s;
    if (glob) {
        global[*s] = Cp;
        local.clear();
    } else {
        local[*s] = Cp;
    }
    if (forward.find(*s) != forward.end())
        for (addr a : forward[*s]) st(a, Cp);
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

std::string resolve(addr a) {  //
    auto it = reverse.find(a);
    if (it != reverse.end())
        return "/" + it->second;
    else
        return "";
}
