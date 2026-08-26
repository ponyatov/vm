#include "memory.hpp"

byte M[Msz];

addr Cp = 0;
addr Ip = 0;

addr R[Rsz];
byte Rp = 0;

cell D[Dsz];
byte Dp = 0;

addr fetch(addr a) {  //
    return *(addr*)(&M[a]);
}
