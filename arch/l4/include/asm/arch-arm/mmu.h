#ifndef __ARM_MMU_H
#define __ARM_MMU_H

#ifdef CONFIG_MMU

#ifdef CONFIG_L4
#include <asm/generic/mmu.h>
#endif

typedef struct {
#ifdef CONFIG_CPU_HAS_ASID
	atomic64_t	id;
#else
	int		switch_pending;
#endif
	unsigned int	vmalloc_seq;
	unsigned long	sigpage;
#ifdef CONFIG_VDSO
	unsigned long	vdso;
#endif

#ifdef CONFIG_L4
	l4_cap_idx_t task;
	enum l4x_unmap_mode_enum l4x_unmap_mode;
#endif
} mm_context_t;

#ifdef CONFIG_CPU_HAS_ASID
#define ASID_BITS	8
#define ASID_MASK	((~0ULL) << ASID_BITS)
#define ASID(mm)	((unsigned int)((mm)->context.id.counter & ~ASID_MASK))
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
	unsigned long	end_brk;
} mm_context_t;

#endif

#endif
