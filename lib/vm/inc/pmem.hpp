/// @defgroup pmem pmem
/// @brief paged/peripherial memory
/// @ingroup memory
/// @{
#pragma once

#include "lib.hpp"
#include "pmem.hpp"

/// @ref pmem type / usage mode
enum pmode {
    unused,  ///< unused segment
    stat,    ///< statically allocated memory
    heap,    ///< global heap allocated (malloc/free)
    file,    ///< mmaped file (16M limited)
    io,      ///< memory-mapped periph (MCU)
};

/// @ref pmem segment structure
typedef struct {
    void* base;   ///< virtual/physical memory base
    size_t size;  ///< segment size, bytes
    pmode mode;   ///< @ref pmode
} segment;

/// static/dynamic @ref segment table (@ref pmem high byte = index)
extern segment mmu[Psz];

static_assert(sizeof(mmu) == sizeof(segment) * Psz);

extern void sync(uint8_t p);  ///< sync [buffered] @ref segment

/// @}
