#ifndef __ASM_L4__L4X__ARM__LX_SYSCALLS_H__
#define __ASM_L4__L4X__ARM__LX_SYSCALLS_H__

typedef asmlinkage long (*syscall_t)(long a0,...);
extern syscall_t sys_call_table[];
extern syscall_t sys_oabi_call_table[];
extern char NR_syscalls[];

static inline int is_lx_syscall(unsigned nr)
{
	return nr < (unsigned long)NR_syscalls;
}

#endif /* ! __ASM_L4__L4X__ARM__LX_SYSCALLS_H__ */
