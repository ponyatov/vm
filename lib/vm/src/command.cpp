#include "compiler.hpp"
#include "main.hpp"
#include "vm.hpp"

// `( -- )` do nothing (empty command)
void nop() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
}

// `( -- )` stop the whole @ref vm
void halt() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    fini();
    exit(0);
}

// `( -- )` dump @ref vm state
void dump() {
    if (debug) fprintf(stderr, " %s\n", __func__);  //
    const int bpl = 0x10;                           // bytes/line
    char ascii[bpl + 1];                            // accumulator
    uint8_t ascip = 0;                              // pointer
    uint8_t remaining = bpl;                        // end bytes
    for (addr a = 0; a < Cp; a++) {
        if (a % bpl == 0) {
            fprintf(stderr, "\n%.4X: ", a);
            ascip = 0;
            remaining = bpl;
        }
        {
            byte b = M[a];
            fprintf(stderr, "%.2X ", b);
            ascii[ascip++] = b >= ' ' && b < 0x80 ? b : '.';
            remaining--;
        }
        if (!remaining) {
            ascii[ascip] = 0;
            fprintf(stderr, "%s", ascii);
        }
    }
    if (remaining) {
        for (int i = 0; i < remaining; i++)  // \ pad bytes
            fprintf(stderr, "   ");          // /
        ascii[ascip] = 0;
        fprintf(stderr, "%s\n\n", ascii);
    } else
        fprintf(stderr, "\n");
}

// `(R: -- addr)` nested call
void call() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    abort();
}

// `(R: addr -- )` return from @ref call
void ret() {  //
    if (debug) fprintf(stderr, " %s\n", __func__);
    abort();
}

// `( -- )` unconditional jump
void jmp() {
    Ip = fetch(Ip);
    if (debug)
        fprintf(stderr, " %s %.4X%s\n", __func__, Ip, resolve(Ip).c_str());
    assert(Ip < Cp);
}
