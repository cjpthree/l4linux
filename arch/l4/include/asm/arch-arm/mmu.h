#ifndef __ARM_MMU_H
#define __ARM_MMU_H

#ifdef CONFIG_MMU

#include <asm/generic/mmu.h>

typedef struct {
#ifdef CONFIG_CPU_HAS_ASID
	u64 id;
#endif
	unsigned int vmalloc_seq;

	l4_cap_idx_t task;
	enum l4x_unmap_mode_enum l4x_unmap_mode;
} mm_context_t;

#ifdef CONFIG_CPU_HAS_ASID
#define ASID_BITS	8
#define ASID_MASK	((~0ULL) << ASID_BITS)
#define ASID(mm)	((mm)->context.id & ~ASID_MASK)
#else
#define ASID(mm)	(0)
#endif

#else

/*
 * From nommu.h:
 *  Copyright (C) 2002, David McCullough <davidm@snapgear.com>
 *  modified for 2.6 by Hyok S. Choi <hyok.choi@samsung.com>
 */
typedef struct {
	unsigned long		end_brk;
} mm_context_t;

#endif

#endif
