#include "config.hpp"
#include "main.hpp"
#include "memory.hpp"
#include "pmem.hpp"

segment mmu[Psz] = {
    {mmu, sizeof(mmu), pmode::stat},  ///< @ref mmu (recursive)
    {M, Msz, pmode::stat},            ///< @ref M
    {R, Rsz, pmode::stat},            ///< @ref R
    {D, Dsz, pmode::stat},            ///< @ref D
};

void init() {
    // memset(mmu, 0, sizeof(segment) * Psz);
    atexit(fini);
}

void fini() {
    for (int p = 0; p < Psz; p++) {
        switch (mmu[p].mode) {
            case pmode::heap:       // free heap-allocated memory
                free(mmu[p].base);  //
                break;
            case pmode::file:
                sync(p);
                munmap(mmu[p].base, mmu[p].size);
                break;
            default: {
            }
        }
    }
}

void sync(uint8_t p) {
    switch (mmu[p].mode) {
        case pmode::heap:
#if defined(__x86_64__) || defined(__i386__)
            __sync_synchronize();
#endif
#ifdef __arm__
            __clear_cache(mmu[p].base, mmu[p].base + mmu[p].size);
#endif
            break;
        case pmode::file:
#ifdef __linux__
            msync(mmu[p].base, mmu[p].size, MS_SYNC);
#endif
            break;
        default:
            break;
    }
}
