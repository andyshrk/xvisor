/**
 * Copyright (c) 2018 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file riscv_asm.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief RISC-V assembler friendly macros and defines
 *
 * The source has been largely adapted from Linux 4.x or higher:
 * arch/riscv/include/asm/asm.h
 *
 * Copyright (C) 2015 Regents of the University of California
 *
 * The original code is licensed under the GPL.
 */

#ifndef __RISCV_ASM_H__
#define __RISCV_ASM_H__

#ifdef __ASSEMBLY__
#define __ASM_STR(x)	x
#else
#define __ASM_STR(x)	#x
#endif

#if __riscv_xlen == 64
#define __REG_SEL(a, b)	__ASM_STR(a)
#elif __riscv_xlen == 32
#define __REG_SEL(a, b)	__ASM_STR(b)
#else
#error "Unexpected __riscv_xlen"
#endif

#define REG_L		__REG_SEL(ld, lw)
#define REG_S		__REG_SEL(sd, sw)
#define SZREG		__REG_SEL(8, 4)
#define LGREG		__REG_SEL(3, 2)

#if __SIZEOF_POINTER__ == 8
#ifdef __ASSEMBLY__
#define RISCV_PTR		.dword
#define RISCV_SZPTR		8
#define RISCV_LGPTR		3
#else
#define RISCV_PTR		".dword"
#define RISCV_SZPTR		"8"
#define RISCV_LGPTR		"3"
#endif
#elif __SIZEOF_POINTER__ == 4
#ifdef __ASSEMBLY__
#define RISCV_PTR		.word
#define RISCV_SZPTR		4
#define RISCV_LGPTR		2
#else
#define RISCV_PTR		".word"
#define RISCV_SZPTR		"4"
#define RISCV_LGPTR		"2"
#endif
#else
#error "Unexpected __SIZEOF_POINTER__"
#endif

#if (__SIZEOF_INT__ == 4)
#define RISCV_INT		__ASM_STR(.word)
#define RISCV_SZINT		__ASM_STR(4)
#define RISCV_LGINT		__ASM_STR(2)
#else
#error "Unexpected __SIZEOF_INT__"
#endif

#if (__SIZEOF_SHORT__ == 2)
#define RISCV_SHORT		__ASM_STR(.half)
#define RISCV_SZSHORT		__ASM_STR(2)
#define RISCV_LGSHORT		__ASM_STR(1)
#else
#error "Unexpected __SIZEOF_SHORT__"
#endif

#define RISCV_SCRATCH_SMP_ID_OFFSET	(0 * __SIZEOF_POINTER__)
#define RISCV_SCRATCH_EXCE_STACK_OFFSET	(1 * __SIZEOF_POINTER__)
#define RISCV_SCRATCH_TMP0_OFFSET	(2 * __SIZEOF_POINTER__)
#define RISCV_SCRATCH_TMP1_OFFSET	(3 * __SIZEOF_POINTER__)
#define RISCV_SCRATCH_SIZE		64

#define RISCV_ARCH_REGS_zero		0
#define RISCV_ARCH_REGS_ra		1
#define RISCV_ARCH_REGS_sp		2
#define RISCV_ARCH_REGS_gp		3
#define RISCV_ARCH_REGS_tp		4
#define RISCV_ARCH_REGS_t0		5
#define RISCV_ARCH_REGS_t1		6
#define RISCV_ARCH_REGS_t2		7
#define RISCV_ARCH_REGS_s0		8
#define RISCV_ARCH_REGS_s1		9
#define RISCV_ARCH_REGS_a0		10
#define RISCV_ARCH_REGS_a1		11
#define RISCV_ARCH_REGS_a2		12
#define RISCV_ARCH_REGS_a3		13
#define RISCV_ARCH_REGS_a4		14
#define RISCV_ARCH_REGS_a5		15
#define RISCV_ARCH_REGS_a6		16
#define RISCV_ARCH_REGS_a7		17
#define RISCV_ARCH_REGS_s2		18
#define RISCV_ARCH_REGS_s3		19
#define RISCV_ARCH_REGS_s4		20
#define RISCV_ARCH_REGS_s5		21
#define RISCV_ARCH_REGS_s6		22
#define RISCV_ARCH_REGS_s7		23
#define RISCV_ARCH_REGS_s8		24
#define RISCV_ARCH_REGS_s9		25
#define RISCV_ARCH_REGS_s10		26
#define RISCV_ARCH_REGS_s11		27
#define RISCV_ARCH_REGS_t3		28
#define RISCV_ARCH_REGS_t4		29
#define RISCV_ARCH_REGS_t5		30
#define RISCV_ARCH_REGS_t6		31
#define RISCV_ARCH_REGS_sepc		32
#define RISCV_ARCH_REGS_sstatus		33
#define RISCV_ARCH_REGS_sp_exec		34
#define RISCV_ARCH_REGS_last		35

#define RISCV_ARCH_REGS_OFFSET(x)	((RISCV_ARCH_REGS_##x) * __SIZEOF_POINTER__)
#define RISCV_ARCH_REGS_SIZE		RISCV_ARCH_REGS_OFFSET(last)

#endif /* __RISCV_ASM_H__ */
