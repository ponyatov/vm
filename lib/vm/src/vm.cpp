#include "vm.hpp"

int vm() {
    for (uint8_t i = 0; true; i++) {
        assert(i < 0x11);
        assert(Ip < Cp);
        Op op = (Op)M[Ip++];
        if (debug) { fprintf(stderr, "%.4X: %.2X", Ip - 1, (byte)op); }
        switch (op) {
            case Op::nop:
                nop();
                break;
            case Op::halt:
                halt();
                break;
            case Op::dump:
                dump();
                break;
            case Op::jmp:
                jmp();
                break;
            default:
                fprintf(stderr, " ???\n\n");
                exit(-1);
        }
    }
    return 0;
}
