#include "vm.hpp"

/// `( -- )` do nothing (empty command)
void nop() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
}

/// `( -- )` stop the whole @ref vm
void halt() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    exit(0);
}

/// `( -- )` dump @ref vm state
void dump() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    for (addr a = 0; a < Cp; a++) {  //
        fprintf(stderr, "%.2X ", M[a]);
    }
    fprintf(stderr, "\n");
}

///<`(R: -- addr)` nested call
void call() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    abort();
}

/// `(R: addr -- )` return from @ref call
void ret() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    abort();
}

/// `( -- )` unconditional jump
void jmp() {
    Ip = fetch(Ip);
    if (debug) fprintf(stderr, " %s %.4X\n", __func__, Ip);
    assert(Ip < Cp);
}
