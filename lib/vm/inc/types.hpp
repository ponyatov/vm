/// @defgroup types types
/// @brief embedded @ref vm specific types\e
/// @ingroup vm
/// @{
#pragma once
#include "stdint.h"

/// single byte
typedef uint8_t byte;

/// @ref M address (64K limited for MCU usage & code compactness)
typedef uint16_t addr;

/// @ref D signed integer (32-bit as most universal)
typedef int32_t cell;

/// paged memory pointer (MMU-like for I/O and mem2mem DMA)
typedef struct {
    uint32_t segment : 8;  ///< index in emulated @ref mmu table
    uint32_t offset : 24;  ///< offset (up to 16M slice)
} pmem;

static_assert(sizeof(pmem) == sizeof(cell));

/// @}
