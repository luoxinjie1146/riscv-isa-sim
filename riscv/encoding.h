/* See LICENSE for license details. */

#ifndef RISCV_CSR_ENCODING_H
#define RISCV_CSR_ENCODING_H

#define MSTATUS_UIE         0x00000001
#define MSTATUS_SIE         0x00000002
#define MSTATUS_HIE         0x00000004
#define MSTATUS_MIE         0x00000008
#define MSTATUS_UPIE        0x00000010
#define MSTATUS_SPIE        0x00000020
#define MSTATUS_HPIE        0x00000040
#define MSTATUS_MPIE        0x00000080
#define MSTATUS_SPP         0x00000100
#define MSTATUS_HPP         0x00000600
#define MSTATUS_MPP         0x00001800
#define MSTATUS_FS          0x00006000
#define MSTATUS_XS          0x00018000
#define MSTATUS_MPRV        0x00020000
#define MSTATUS_SUM         0x00040000
#define MSTATUS_MXR         0x00080000
#define MSTATUS_TVM         0x00100000
#define MSTATUS_TW          0x00200000
#define MSTATUS_TSR         0x00400000
#define MSTATUS32_SD        0x80000000
#define MSTATUS_UXL         0x0000000300000000
#define MSTATUS_SXL         0x0000000C00000000
#define MSTATUS64_SD        0x8000000000000000

#define SSTATUS_UIE         0x00000001
#define SSTATUS_SIE         0x00000002
#define SSTATUS_UPIE        0x00000010
#define SSTATUS_SPIE        0x00000020
#define SSTATUS_SPP         0x00000100
#define SSTATUS_FS          0x00006000
#define SSTATUS_XS          0x00018000
#define SSTATUS_SUM         0x00040000
#define SSTATUS_MXR         0x00080000
#define SSTATUS32_SD        0x80000000
#define SSTATUS_UXL         0x0000000300000000
#define SSTATUS64_SD        0x8000000000000000

#define DCSR_XDEBUGVER      (3U<<30)
#define DCSR_NDRESET        (1<<29)
#define DCSR_FULLRESET      (1<<28)
#define DCSR_EBREAKM        (1<<15)
#define DCSR_EBREAKH        (1<<14)
#define DCSR_EBREAKS        (1<<13)
#define DCSR_EBREAKU        (1<<12)
#define DCSR_STOPCYCLE      (1<<10)
#define DCSR_STOPTIME       (1<<9)
#define DCSR_CAUSE          (7<<6)
#define DCSR_DEBUGINT       (1<<5)
#define DCSR_HALT           (1<<3)
#define DCSR_STEP           (1<<2)
#define DCSR_PRV            (3<<0)

#define DCSR_CAUSE_NONE     0
#define DCSR_CAUSE_SWBP     1
#define DCSR_CAUSE_HWBP     2
#define DCSR_CAUSE_DEBUGINT 3
#define DCSR_CAUSE_STEP     4
#define DCSR_CAUSE_HALT     5

#define MCONTROL_TYPE(xlen)    (0xfULL<<((xlen)-4))
#define MCONTROL_DMODE(xlen)   (1ULL<<((xlen)-5))
#define MCONTROL_MASKMAX(xlen) (0x3fULL<<((xlen)-11))

#define MCONTROL_SELECT     (1<<19)
#define MCONTROL_TIMING     (1<<18)
#define MCONTROL_ACTION     (0x3f<<12)
#define MCONTROL_CHAIN      (1<<11)
#define MCONTROL_MATCH      (0xf<<7)
#define MCONTROL_M          (1<<6)
#define MCONTROL_H          (1<<5)
#define MCONTROL_S          (1<<4)
#define MCONTROL_U          (1<<3)
#define MCONTROL_EXECUTE    (1<<2)
#define MCONTROL_STORE      (1<<1)
#define MCONTROL_LOAD       (1<<0)

#define MCONTROL_TYPE_NONE      0
#define MCONTROL_TYPE_MATCH     2

#define MCONTROL_ACTION_DEBUG_EXCEPTION   0
#define MCONTROL_ACTION_DEBUG_MODE        1
#define MCONTROL_ACTION_TRACE_START       2
#define MCONTROL_ACTION_TRACE_STOP        3
#define MCONTROL_ACTION_TRACE_EMIT        4

#define MCONTROL_MATCH_EQUAL     0
#define MCONTROL_MATCH_NAPOT     1
#define MCONTROL_MATCH_GE        2
#define MCONTROL_MATCH_LT        3
#define MCONTROL_MATCH_MASK_LOW  4
#define MCONTROL_MATCH_MASK_HIGH 5

#define MIP_SSIP            (1 << IRQ_S_SOFT)
#define MIP_HSIP            (1 << IRQ_H_SOFT)
#define MIP_MSIP            (1 << IRQ_M_SOFT)
#define MIP_STIP            (1 << IRQ_S_TIMER)
#define MIP_HTIP            (1 << IRQ_H_TIMER)
#define MIP_MTIP            (1 << IRQ_M_TIMER)
#define MIP_SEIP            (1 << IRQ_S_EXT)
#define MIP_HEIP            (1 << IRQ_H_EXT)
#define MIP_MEIP            (1 << IRQ_M_EXT)

#define SIP_SSIP MIP_SSIP
#define SIP_STIP MIP_STIP

#define PRV_U 0
#define PRV_S 1
#define PRV_H 2
#define PRV_M 3

#define SATP32_MODE 0x80000000
#define SATP32_ASID 0x7FC00000
#define SATP32_PPN  0x003FFFFF
#define SATP64_MODE 0xF000000000000000
#define SATP64_ASID 0x0FFFF00000000000
#define SATP64_PPN  0x00000FFFFFFFFFFF

#define SATP_MODE_OFF  0
#define SATP_MODE_SV32 1
#define SATP_MODE_SV39 8
#define SATP_MODE_SV48 9
#define SATP_MODE_SV57 10
#define SATP_MODE_SV64 11

#define PMP_R     0x01
#define PMP_W     0x02
#define PMP_X     0x04
#define PMP_A     0x18
#define PMP_L     0x80
#define PMP_SHIFT 2

#define PMP_TOR   0x08
#define PMP_NA4   0x10
#define PMP_NAPOT 0x18

#define IRQ_S_SOFT   1
#define IRQ_H_SOFT   2
#define IRQ_M_SOFT   3
#define IRQ_S_TIMER  5
#define IRQ_H_TIMER  6
#define IRQ_M_TIMER  7
#define IRQ_S_EXT    9
#define IRQ_H_EXT    10
#define IRQ_M_EXT    11
#define IRQ_COP      12
#define IRQ_HOST     13

#define DEFAULT_RSTVEC     0x00001000
#define CLINT_BASE         0x02000000
#define CLINT_SIZE         0x000c0000
#define EXT_IO_BASE        0x40000000
#define DRAM_BASE          0x80000000 //lxj// 指令存储区首地址

/* page table entry (PTE) fields */
#define PTE_V     0x001 /* Valid */
#define PTE_R     0x002 /* Read */
#define PTE_W     0x004 /* Write */
#define PTE_X     0x008 /* Execute */
#define PTE_U     0x010 /* User */
#define PTE_G     0x020 /* Global */
#define PTE_A     0x040 /* Accessed */
#define PTE_D     0x080 /* Dirty */
#define PTE_SOFT  0x300 /* Reserved for Software */

#define PTE_PPN_SHIFT 10

#define PTE_TABLE(PTE) (((PTE) & (PTE_V | PTE_R | PTE_W | PTE_X)) == PTE_V)

#ifdef __riscv

#if __riscv_xlen == 64
# define MSTATUS_SD MSTATUS64_SD
# define SSTATUS_SD SSTATUS64_SD
# define RISCV_PGLEVEL_BITS 9
# define SATP_MODE SATP64_MODE
#else
# define MSTATUS_SD MSTATUS32_SD
# define SSTATUS_SD SSTATUS32_SD
# define RISCV_PGLEVEL_BITS 10
# define SATP_MODE SATP32_MODE
#endif
#define RISCV_PGSHIFT 12
#define RISCV_PGSIZE (1 << RISCV_PGSHIFT)

#ifndef __ASSEMBLER__

#ifdef __GNUC__

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })

#define swap_csr(reg, val) ({ unsigned long __tmp; \
  asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "rK"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })

#define rdtime() read_csr(time)
#define rdcycle() read_csr(cycle)
#define rdinstret() read_csr(instret)

#endif

#endif

#endif

#endif
/* Automatically generated by parse-opcodes.  */
#ifndef RISCV_ENCODING_H
#define RISCV_ENCODING_H
#define MATCH_BEQ 0x63
#define MASK_BEQ  0x707f
#define MATCH_BNE 0x1063
#define MASK_BNE  0x707f
#define MATCH_BLT 0x4063
#define MASK_BLT  0x707f
#define MATCH_BGE 0x5063
#define MASK_BGE  0x707f
#define MATCH_BLTU 0x6063
#define MASK_BLTU  0x707f
#define MATCH_BGEU 0x7063
#define MASK_BGEU  0x707f
#define MATCH_JALR 0x67
#define MASK_JALR  0x707f
#define MATCH_JAL 0x6f
#define MASK_JAL  0x7f
#define MATCH_LUI 0x37
#define MASK_LUI  0x7f
#define MATCH_AUIPC 0x17
#define MASK_AUIPC  0x7f
#define MATCH_ADDI 0x13
#define MASK_ADDI  0x707f
#define MATCH_SLLI 0x1013
#define MASK_SLLI  0xfc00707f
#define MATCH_SLTI 0x2013
#define MASK_SLTI  0x707f
#define MATCH_SLTIU 0x3013
#define MASK_SLTIU  0x707f
#define MATCH_XORI 0x4013
#define MASK_XORI  0x707f
#define MATCH_SRLI 0x5013
#define MASK_SRLI  0xfc00707f
#define MATCH_SRAI 0x40005013
#define MASK_SRAI  0xfc00707f
#define MATCH_ORI 0x6013
#define MASK_ORI  0x707f
#define MATCH_ANDI 0x7013
#define MASK_ANDI  0x707f
#define MATCH_ADD 0x33
#define MASK_ADD  0xfe00707f
#define MATCH_SUB 0x40000033
#define MASK_SUB  0xfe00707f
#define MATCH_SLL 0x1033
#define MASK_SLL  0xfe00707f
#define MATCH_SLT 0x2033
#define MASK_SLT  0xfe00707f
#define MATCH_SLTU 0x3033
#define MASK_SLTU  0xfe00707f
#define MATCH_XOR 0x4033
#define MASK_XOR  0xfe00707f
#define MATCH_SRL 0x5033
#define MASK_SRL  0xfe00707f
#define MATCH_SRA 0x40005033
#define MASK_SRA  0xfe00707f
#define MATCH_OR 0x6033
#define MASK_OR  0xfe00707f
#define MATCH_AND 0x7033
#define MASK_AND  0xfe00707f
#define MATCH_ADDIW 0x1b
#define MASK_ADDIW  0x707f
#define MATCH_SLLIW 0x101b
#define MASK_SLLIW  0xfe00707f
#define MATCH_SRLIW 0x501b
#define MASK_SRLIW  0xfe00707f
#define MATCH_SRAIW 0x4000501b
#define MASK_SRAIW  0xfe00707f
#define MATCH_ADDW 0x3b
#define MASK_ADDW  0xfe00707f
#define MATCH_SUBW 0x4000003b
#define MASK_SUBW  0xfe00707f
#define MATCH_SLLW 0x103b
#define MASK_SLLW  0xfe00707f
#define MATCH_SRLW 0x503b
#define MASK_SRLW  0xfe00707f
#define MATCH_SRAW 0x4000503b
#define MASK_SRAW  0xfe00707f
#define MATCH_LB 0x3
#define MASK_LB  0x707f
#define MATCH_LH 0x1003
#define MASK_LH  0x707f
#define MATCH_LW 0x2003
#define MASK_LW  0x707f
#define MATCH_LD 0x3003
#define MASK_LD  0x707f
#define MATCH_LBU 0x4003
#define MASK_LBU  0x707f
#define MATCH_LHU 0x5003
#define MASK_LHU  0x707f
#define MATCH_LWU 0x6003
#define MASK_LWU  0x707f
#define MATCH_SB 0x23
#define MASK_SB  0x707f
#define MATCH_SH 0x1023
#define MASK_SH  0x707f
#define MATCH_SW 0x2023
#define MASK_SW  0x707f
#define MATCH_SD 0x3023
#define MASK_SD  0x707f
#define MATCH_FENCE 0xf
#define MASK_FENCE  0x707f
#define MATCH_FENCE_I 0x100f
#define MASK_FENCE_I  0x707f
#define MATCH_MUL 0x2000033
#define MASK_MUL  0xfe00707f
#define MATCH_MULH 0x2001033
#define MASK_MULH  0xfe00707f
#define MATCH_MULHSU 0x2002033
#define MASK_MULHSU  0xfe00707f
#define MATCH_MULHU 0x2003033
#define MASK_MULHU  0xfe00707f
#define MATCH_DIV 0x2004033
#define MASK_DIV  0xfe00707f
#define MATCH_DIVU 0x2005033
#define MASK_DIVU  0xfe00707f
#define MATCH_REM 0x2006033
#define MASK_REM  0xfe00707f
#define MATCH_REMU 0x2007033
#define MASK_REMU  0xfe00707f
#define MATCH_MULW 0x200003b
#define MASK_MULW  0xfe00707f
#define MATCH_DIVW 0x200403b
#define MASK_DIVW  0xfe00707f
#define MATCH_DIVUW 0x200503b
#define MASK_DIVUW  0xfe00707f
#define MATCH_REMW 0x200603b
#define MASK_REMW  0xfe00707f
#define MATCH_REMUW 0x200703b
#define MASK_REMUW  0xfe00707f
#define MATCH_AMOADD_W 0x202f
#define MASK_AMOADD_W  0xf800707f
#define MATCH_AMOXOR_W 0x2000202f
#define MASK_AMOXOR_W  0xf800707f
#define MATCH_AMOOR_W 0x4000202f
#define MASK_AMOOR_W  0xf800707f
#define MATCH_AMOAND_W 0x6000202f
#define MASK_AMOAND_W  0xf800707f
#define MATCH_AMOMIN_W 0x8000202f
#define MASK_AMOMIN_W  0xf800707f
#define MATCH_AMOMAX_W 0xa000202f
#define MASK_AMOMAX_W  0xf800707f
#define MATCH_AMOMINU_W 0xc000202f
#define MASK_AMOMINU_W  0xf800707f
#define MATCH_AMOMAXU_W 0xe000202f
#define MASK_AMOMAXU_W  0xf800707f
#define MATCH_AMOSWAP_W 0x800202f
#define MASK_AMOSWAP_W  0xf800707f
#define MATCH_LR_W 0x1000202f
#define MASK_LR_W  0xf9f0707f
#define MATCH_SC_W 0x1800202f
#define MASK_SC_W  0xf800707f
#define MATCH_AMOADD_D 0x302f
#define MASK_AMOADD_D  0xf800707f
#define MATCH_AMOXOR_D 0x2000302f
#define MASK_AMOXOR_D  0xf800707f
#define MATCH_AMOOR_D 0x4000302f
#define MASK_AMOOR_D  0xf800707f
#define MATCH_AMOAND_D 0x6000302f
#define MASK_AMOAND_D  0xf800707f
#define MATCH_AMOMIN_D 0x8000302f
#define MASK_AMOMIN_D  0xf800707f
#define MATCH_AMOMAX_D 0xa000302f
#define MASK_AMOMAX_D  0xf800707f
#define MATCH_AMOMINU_D 0xc000302f
#define MASK_AMOMINU_D  0xf800707f
#define MATCH_AMOMAXU_D 0xe000302f
#define MASK_AMOMAXU_D  0xf800707f
#define MATCH_AMOSWAP_D 0x800302f
#define MASK_AMOSWAP_D  0xf800707f
#define MATCH_LR_D 0x1000302f
#define MASK_LR_D  0xf9f0707f
#define MATCH_SC_D 0x1800302f
#define MASK_SC_D  0xf800707f
#define MATCH_ECALL 0x73
#define MASK_ECALL  0xffffffff
#define MATCH_EBREAK 0x100073
#define MASK_EBREAK  0xffffffff
#define MATCH_URET 0x200073
#define MASK_URET  0xffffffff
#define MATCH_SRET 0x10200073
#define MASK_SRET  0xffffffff
#define MATCH_MRET 0x30200073
#define MASK_MRET  0xffffffff
#define MATCH_DRET 0x7b200073
#define MASK_DRET  0xffffffff
#define MATCH_SFENCE_VMA 0x12000073
#define MASK_SFENCE_VMA  0xfe007fff
#define MATCH_WFI 0x10500073
#define MASK_WFI  0xffffffff
#define MATCH_CSRRW 0x1073
#define MASK_CSRRW  0x707f
#define MATCH_CSRRS 0x2073
#define MASK_CSRRS  0x707f
#define MATCH_CSRRC 0x3073
#define MASK_CSRRC  0x707f
#define MATCH_CSRRWI 0x5073
#define MASK_CSRRWI  0x707f
#define MATCH_CSRRSI 0x6073
#define MASK_CSRRSI  0x707f
#define MATCH_CSRRCI 0x7073
#define MASK_CSRRCI  0x707f
#define MATCH_HFENCE_VVMA 0x22000073
#define MASK_HFENCE_VVMA  0xfe007fff
#define MATCH_HFENCE_GVMA 0x62000073
#define MASK_HFENCE_GVMA  0xfe007fff
#define MATCH_FADD_S 0x53
#define MASK_FADD_S  0xfe00007f
#define MATCH_FSUB_S 0x8000053
#define MASK_FSUB_S  0xfe00007f
#define MATCH_FMUL_S 0x10000053
#define MASK_FMUL_S  0xfe00007f
#define MATCH_FDIV_S 0x18000053
#define MASK_FDIV_S  0xfe00007f
#define MATCH_FSGNJ_S 0x20000053
#define MASK_FSGNJ_S  0xfe00707f
#define MATCH_FSGNJN_S 0x20001053
#define MASK_FSGNJN_S  0xfe00707f
#define MATCH_FSGNJX_S 0x20002053
#define MASK_FSGNJX_S  0xfe00707f
#define MATCH_FMIN_S 0x28000053
#define MASK_FMIN_S  0xfe00707f
#define MATCH_FMAX_S 0x28001053
#define MASK_FMAX_S  0xfe00707f
#define MATCH_FSQRT_S 0x58000053
#define MASK_FSQRT_S  0xfff0007f
#define MATCH_FADD_D 0x2000053
#define MASK_FADD_D  0xfe00007f
#define MATCH_FSUB_D 0xa000053
#define MASK_FSUB_D  0xfe00007f
#define MATCH_FMUL_D 0x12000053
#define MASK_FMUL_D  0xfe00007f
#define MATCH_FDIV_D 0x1a000053
#define MASK_FDIV_D  0xfe00007f
#define MATCH_FSGNJ_D 0x22000053
#define MASK_FSGNJ_D  0xfe00707f
#define MATCH_FSGNJN_D 0x22001053
#define MASK_FSGNJN_D  0xfe00707f
#define MATCH_FSGNJX_D 0x22002053
#define MASK_FSGNJX_D  0xfe00707f
#define MATCH_FMIN_D 0x2a000053
#define MASK_FMIN_D  0xfe00707f
#define MATCH_FMAX_D 0x2a001053
#define MASK_FMAX_D  0xfe00707f
#define MATCH_FCVT_S_D 0x40100053
#define MASK_FCVT_S_D  0xfff0007f
#define MATCH_FCVT_D_S 0x42000053
#define MASK_FCVT_D_S  0xfff0007f
#define MATCH_FSQRT_D 0x5a000053
#define MASK_FSQRT_D  0xfff0007f
#define MATCH_FADD_Q 0x6000053
#define MASK_FADD_Q  0xfe00007f
#define MATCH_FSUB_Q 0xe000053
#define MASK_FSUB_Q  0xfe00007f
#define MATCH_FMUL_Q 0x16000053
#define MASK_FMUL_Q  0xfe00007f
#define MATCH_FDIV_Q 0x1e000053
#define MASK_FDIV_Q  0xfe00007f
#define MATCH_FSGNJ_Q 0x26000053
#define MASK_FSGNJ_Q  0xfe00707f
#define MATCH_FSGNJN_Q 0x26001053
#define MASK_FSGNJN_Q  0xfe00707f
#define MATCH_FSGNJX_Q 0x26002053
#define MASK_FSGNJX_Q  0xfe00707f
#define MATCH_FMIN_Q 0x2e000053
#define MASK_FMIN_Q  0xfe00707f
#define MATCH_FMAX_Q 0x2e001053
#define MASK_FMAX_Q  0xfe00707f
#define MATCH_FCVT_S_Q 0x40300053
#define MASK_FCVT_S_Q  0xfff0007f
#define MATCH_FCVT_Q_S 0x46000053
#define MASK_FCVT_Q_S  0xfff0007f
#define MATCH_FCVT_D_Q 0x42300053
#define MASK_FCVT_D_Q  0xfff0007f
#define MATCH_FCVT_Q_D 0x46100053
#define MASK_FCVT_Q_D  0xfff0007f
#define MATCH_FSQRT_Q 0x5e000053
#define MASK_FSQRT_Q  0xfff0007f
#define MATCH_FLE_S 0xa0000053
#define MASK_FLE_S  0xfe00707f
#define MATCH_FLT_S 0xa0001053
#define MASK_FLT_S  0xfe00707f
#define MATCH_FEQ_S 0xa0002053
#define MASK_FEQ_S  0xfe00707f
#define MATCH_FLE_D 0xa2000053
#define MASK_FLE_D  0xfe00707f
#define MATCH_FLT_D 0xa2001053
#define MASK_FLT_D  0xfe00707f
#define MATCH_FEQ_D 0xa2002053
#define MASK_FEQ_D  0xfe00707f
#define MATCH_FLE_Q 0xa6000053
#define MASK_FLE_Q  0xfe00707f
#define MATCH_FLT_Q 0xa6001053
#define MASK_FLT_Q  0xfe00707f
#define MATCH_FEQ_Q 0xa6002053
#define MASK_FEQ_Q  0xfe00707f
#define MATCH_FCVT_W_S 0xc0000053
#define MASK_FCVT_W_S  0xfff0007f
#define MATCH_FCVT_WU_S 0xc0100053
#define MASK_FCVT_WU_S  0xfff0007f
#define MATCH_FCVT_L_S 0xc0200053
#define MASK_FCVT_L_S  0xfff0007f
#define MATCH_FCVT_LU_S 0xc0300053
#define MASK_FCVT_LU_S  0xfff0007f
#define MATCH_FMV_X_W 0xe0000053
#define MASK_FMV_X_W  0xfff0707f
#define MATCH_FCLASS_S 0xe0001053
#define MASK_FCLASS_S  0xfff0707f
#define MATCH_FCVT_W_D 0xc2000053
#define MASK_FCVT_W_D  0xfff0007f
#define MATCH_FCVT_WU_D 0xc2100053
#define MASK_FCVT_WU_D  0xfff0007f
#define MATCH_FCVT_L_D 0xc2200053
#define MASK_FCVT_L_D  0xfff0007f
#define MATCH_FCVT_LU_D 0xc2300053
#define MASK_FCVT_LU_D  0xfff0007f
#define MATCH_FMV_X_D 0xe2000053
#define MASK_FMV_X_D  0xfff0707f
#define MATCH_FCLASS_D 0xe2001053
#define MASK_FCLASS_D  0xfff0707f
#define MATCH_FCVT_W_Q 0xc6000053
#define MASK_FCVT_W_Q  0xfff0007f
#define MATCH_FCVT_WU_Q 0xc6100053
#define MASK_FCVT_WU_Q  0xfff0007f
#define MATCH_FCVT_L_Q 0xc6200053
#define MASK_FCVT_L_Q  0xfff0007f
#define MATCH_FCVT_LU_Q 0xc6300053
#define MASK_FCVT_LU_Q  0xfff0007f
#define MATCH_FMV_X_Q 0xe6000053
#define MASK_FMV_X_Q  0xfff0707f
#define MATCH_FCLASS_Q 0xe6001053
#define MASK_FCLASS_Q  0xfff0707f
#define MATCH_FCVT_S_W 0xd0000053
#define MASK_FCVT_S_W  0xfff0007f
#define MATCH_FCVT_S_WU 0xd0100053
#define MASK_FCVT_S_WU  0xfff0007f
#define MATCH_FCVT_S_L 0xd0200053
#define MASK_FCVT_S_L  0xfff0007f
#define MATCH_FCVT_S_LU 0xd0300053
#define MASK_FCVT_S_LU  0xfff0007f
#define MATCH_FMV_W_X 0xf0000053
#define MASK_FMV_W_X  0xfff0707f
#define MATCH_FCVT_D_W 0xd2000053
#define MASK_FCVT_D_W  0xfff0007f
#define MATCH_FCVT_D_WU 0xd2100053
#define MASK_FCVT_D_WU  0xfff0007f
#define MATCH_FCVT_D_L 0xd2200053
#define MASK_FCVT_D_L  0xfff0007f
#define MATCH_FCVT_D_LU 0xd2300053
#define MASK_FCVT_D_LU  0xfff0007f
#define MATCH_FMV_D_X 0xf2000053
#define MASK_FMV_D_X  0xfff0707f
#define MATCH_FCVT_Q_W 0xd6000053
#define MASK_FCVT_Q_W  0xfff0007f
#define MATCH_FCVT_Q_WU 0xd6100053
#define MASK_FCVT_Q_WU  0xfff0007f
#define MATCH_FCVT_Q_L 0xd6200053
#define MASK_FCVT_Q_L  0xfff0007f
#define MATCH_FCVT_Q_LU 0xd6300053
#define MASK_FCVT_Q_LU  0xfff0007f
#define MATCH_FMV_Q_X 0xf6000053
#define MASK_FMV_Q_X  0xfff0707f
#define MATCH_FLW 0x2007
#define MASK_FLW  0x707f
#define MATCH_FLD 0x3007
#define MASK_FLD  0x707f
#define MATCH_FLQ 0x4007
#define MASK_FLQ  0x707f
#define MATCH_FSW 0x2027
#define MASK_FSW  0x707f
#define MATCH_FSD 0x3027
#define MASK_FSD  0x707f
#define MATCH_FSQ 0x4027
#define MASK_FSQ  0x707f
#define MATCH_FMADD_S 0x43
#define MASK_FMADD_S  0x600007f
#define MATCH_FMSUB_S 0x47
#define MASK_FMSUB_S  0x600007f
#define MATCH_FNMSUB_S 0x4b
#define MASK_FNMSUB_S  0x600007f
#define MATCH_FNMADD_S 0x4f
#define MASK_FNMADD_S  0x600007f
#define MATCH_FMADD_D 0x2000043
#define MASK_FMADD_D  0x600007f
#define MATCH_FMSUB_D 0x2000047
#define MASK_FMSUB_D  0x600007f
#define MATCH_FNMSUB_D 0x200004b
#define MASK_FNMSUB_D  0x600007f
#define MATCH_FNMADD_D 0x200004f
#define MASK_FNMADD_D  0x600007f
#define MATCH_FMADD_Q 0x6000043
#define MASK_FMADD_Q  0x600007f
#define MATCH_FMSUB_Q 0x6000047
#define MASK_FMSUB_Q  0x600007f
#define MATCH_FNMSUB_Q 0x600004b
#define MASK_FNMSUB_Q  0x600007f
#define MATCH_FNMADD_Q 0x600004f
#define MASK_FNMADD_Q  0x600007f
#define MATCH_C_NOP 0x1
#define MASK_C_NOP  0xffff
#define MATCH_C_ADDI16SP 0x6101
#define MASK_C_ADDI16SP  0xef83
#define MATCH_C_JR 0x8002
#define MASK_C_JR  0xf07f
#define MATCH_C_JALR 0x9002
#define MASK_C_JALR  0xf07f
#define MATCH_C_EBREAK 0x9002
#define MASK_C_EBREAK  0xffff
#define MATCH_C_SRLI_RV32 0x8001
#define MASK_C_SRLI_RV32  0xfc03
#define MATCH_C_SRAI_RV32 0x8401
#define MASK_C_SRAI_RV32  0xfc03
#define MATCH_C_SLLI_RV32 0x2
#define MASK_C_SLLI_RV32  0xf003
#define MATCH_C_LD 0x6000
#define MASK_C_LD  0xe003
#define MATCH_C_SD 0xe000
#define MASK_C_SD  0xe003
#define MATCH_C_ADDIW 0x2001
#define MASK_C_ADDIW  0xe003
#define MATCH_C_LDSP 0x6002
#define MASK_C_LDSP  0xe003
#define MATCH_C_SDSP 0xe002
#define MASK_C_SDSP  0xe003
#define MATCH_C_LQ 0x2000
#define MASK_C_LQ  0xe003
#define MATCH_C_SQ 0xa000
#define MASK_C_SQ  0xe003
#define MATCH_C_LQSP 0x2002
#define MASK_C_LQSP  0xe003
#define MATCH_C_SQSP 0xa002
#define MASK_C_SQSP  0xe003
#define MATCH_C_ADDI4SPN 0x0
#define MASK_C_ADDI4SPN  0xe003
#define MATCH_C_FLD 0x2000
#define MASK_C_FLD  0xe003
#define MATCH_C_LW 0x4000
#define MASK_C_LW  0xe003
#define MATCH_C_FLW 0x6000
#define MASK_C_FLW  0xe003
#define MATCH_C_FSD 0xa000
#define MASK_C_FSD  0xe003
#define MATCH_C_SW 0xc000
#define MASK_C_SW  0xe003
#define MATCH_C_FSW 0xe000
#define MASK_C_FSW  0xe003
#define MATCH_C_ADDI 0x1
#define MASK_C_ADDI  0xe003
#define MATCH_C_JAL 0x2001
#define MASK_C_JAL  0xe003
#define MATCH_C_LI 0x4001
#define MASK_C_LI  0xe003
#define MATCH_C_LUI 0x6001
#define MASK_C_LUI  0xe003
#define MATCH_C_SRLI 0x8001
#define MASK_C_SRLI  0xec03
#define MATCH_C_SRAI 0x8401
#define MASK_C_SRAI  0xec03
#define MATCH_C_ANDI 0x8801
#define MASK_C_ANDI  0xec03
#define MATCH_C_SUB 0x8c01
#define MASK_C_SUB  0xfc63
#define MATCH_C_XOR 0x8c21
#define MASK_C_XOR  0xfc63
#define MATCH_C_OR 0x8c41
#define MASK_C_OR  0xfc63
#define MATCH_C_AND 0x8c61
#define MASK_C_AND  0xfc63
#define MATCH_C_SUBW 0x9c01
#define MASK_C_SUBW  0xfc63
#define MATCH_C_ADDW 0x9c21
#define MASK_C_ADDW  0xfc63
#define MATCH_C_J 0xa001
#define MASK_C_J  0xe003
#define MATCH_C_BEQZ 0xc001
#define MASK_C_BEQZ  0xe003
#define MATCH_C_BNEZ 0xe001
#define MASK_C_BNEZ  0xe003
#define MATCH_C_SLLI 0x2
#define MASK_C_SLLI  0xe003
#define MATCH_C_FLDSP 0x2002
#define MASK_C_FLDSP  0xe003
#define MATCH_C_LWSP 0x4002
#define MASK_C_LWSP  0xe003
#define MATCH_C_FLWSP 0x6002
#define MASK_C_FLWSP  0xe003
#define MATCH_C_MV 0x8002
#define MASK_C_MV  0xf003
#define MATCH_C_ADD 0x9002
#define MASK_C_ADD  0xf003
#define MATCH_C_FSDSP 0xa002
#define MASK_C_FSDSP  0xe003
#define MATCH_C_SWSP 0xc002
#define MASK_C_SWSP  0xe003
#define MATCH_C_FSWSP 0xe002
#define MASK_C_FSWSP  0xe003
#define MATCH_CUSTOM0 0xb
#define MASK_CUSTOM0  0x707f
#define MATCH_CUSTOM0_RS1 0x200b
#define MASK_CUSTOM0_RS1  0x707f
#define MATCH_CUSTOM0_RS1_RS2 0x300b
#define MASK_CUSTOM0_RS1_RS2  0x707f
#define MATCH_CUSTOM0_RD 0x400b
#define MASK_CUSTOM0_RD  0x707f
#define MATCH_CUSTOM0_RD_RS1 0x600b
#define MASK_CUSTOM0_RD_RS1  0x707f
#define MATCH_CUSTOM0_RD_RS1_RS2 0x700b
#define MASK_CUSTOM0_RD_RS1_RS2  0x707f
#define MATCH_CUSTOM1 0x2b
#define MASK_CUSTOM1  0x707f
#define MATCH_CUSTOM1_RS1 0x202b
#define MASK_CUSTOM1_RS1  0x707f
#define MATCH_CUSTOM1_RS1_RS2 0x302b
#define MASK_CUSTOM1_RS1_RS2  0x707f
#define MATCH_CUSTOM1_RD 0x402b
#define MASK_CUSTOM1_RD  0x707f
#define MATCH_CUSTOM1_RD_RS1 0x602b
#define MASK_CUSTOM1_RD_RS1  0x707f
#define MATCH_CUSTOM1_RD_RS1_RS2 0x702b
#define MASK_CUSTOM1_RD_RS1_RS2  0x707f
#define MATCH_CUSTOM2 0x5b
#define MASK_CUSTOM2  0x707f
#define MATCH_CUSTOM2_RS1 0x205b
#define MASK_CUSTOM2_RS1  0x707f
#define MATCH_CUSTOM2_RS1_RS2 0x305b
#define MASK_CUSTOM2_RS1_RS2  0x707f
#define MATCH_CUSTOM2_RD 0x405b
#define MASK_CUSTOM2_RD  0x707f
#define MATCH_CUSTOM2_RD_RS1 0x605b
#define MASK_CUSTOM2_RD_RS1  0x707f
#define MATCH_CUSTOM2_RD_RS1_RS2 0x705b
#define MASK_CUSTOM2_RD_RS1_RS2  0x707f
#define MATCH_CUSTOM3 0x7b
#define MASK_CUSTOM3  0x707f
#define MATCH_CUSTOM3_RS1 0x207b
#define MASK_CUSTOM3_RS1  0x707f
#define MATCH_CUSTOM3_RS1_RS2 0x307b
#define MASK_CUSTOM3_RS1_RS2  0x707f
#define MATCH_CUSTOM3_RD 0x407b
#define MASK_CUSTOM3_RD  0x707f
#define MATCH_CUSTOM3_RD_RS1 0x607b
#define MASK_CUSTOM3_RD_RS1  0x707f
#define MATCH_CUSTOM3_RD_RS1_RS2 0x707b
#define MASK_CUSTOM3_RD_RS1_RS2  0x707f
#define MATCH_VSETVLI 0x7057
#define MASK_VSETVLI  0x8000707f
#define MATCH_VSETVL 0x80007057
#define MASK_VSETVL  0xfe00707f
#define MATCH_VLB_V 0x10000007
#define MASK_VLB_V  0x1df0707f
#define MATCH_VLH_V 0x10005007
#define MASK_VLH_V  0x1df0707f
#define MATCH_VLW_V 0x10006007
#define MASK_VLW_V  0x1df0707f
#define MATCH_VLE_V 0x7007
#define MASK_VLE_V  0x1df0707f
#define MATCH_VLBU_V 0x7
#define MASK_VLBU_V  0x1df0707f
#define MATCH_VLHU_V 0x5007
#define MASK_VLHU_V  0x1df0707f
#define MATCH_VLWU_V 0x6007
#define MASK_VLWU_V  0x1df0707f
#define MATCH_VSB_V 0x27
#define MASK_VSB_V  0x1df0707f
#define MATCH_VSH_V 0x5027
#define MASK_VSH_V  0x1df0707f
#define MATCH_VSW_V 0x6027
#define MASK_VSW_V  0x1df0707f
#define MATCH_VSE_V 0x7027
#define MASK_VSE_V  0x1df0707f
#define MATCH_VLSB_V 0x18000007
#define MASK_VLSB_V  0x1c00707f
#define MATCH_VLSH_V 0x18005007
#define MASK_VLSH_V  0x1c00707f
#define MATCH_VLSW_V 0x18006007
#define MASK_VLSW_V  0x1c00707f
#define MATCH_VLSE_V 0x8007007
#define MASK_VLSE_V  0x1c00707f
#define MATCH_VLSBU_V 0x8000007
#define MASK_VLSBU_V  0x1c00707f
#define MATCH_VLSHU_V 0x8005007
#define MASK_VLSHU_V  0x1c00707f
#define MATCH_VLSWU_V 0x8006007
#define MASK_VLSWU_V  0x1c00707f
#define MATCH_VSSB_V 0x8000027
#define MASK_VSSB_V  0x1c00707f
#define MATCH_VSSH_V 0x8005027
#define MASK_VSSH_V  0x1c00707f
#define MATCH_VSSW_V 0x8006027
#define MASK_VSSW_V  0x1c00707f
#define MATCH_VSSE_V 0x8007027
#define MASK_VSSE_V  0x1c00707f
#define MATCH_VLXB_V 0x1c000007
#define MASK_VLXB_V  0x1c00707f
#define MATCH_VLXH_V 0x1c005007
#define MASK_VLXH_V  0x1c00707f
#define MATCH_VLXW_V 0x1c006007
#define MASK_VLXW_V  0x1c00707f
#define MATCH_VLXE_V 0xc007007
#define MASK_VLXE_V  0x1c00707f
#define MATCH_VLXBU_V 0xc000007
#define MASK_VLXBU_V  0x1c00707f
#define MATCH_VLXHU_V 0xc005007
#define MASK_VLXHU_V  0x1c00707f
#define MATCH_VLXWU_V 0xc006007
#define MASK_VLXWU_V  0x1c00707f
#define MATCH_VSXB_V 0xc000027
#define MASK_VSXB_V  0x1c00707f
#define MATCH_VSXH_V 0xc005027
#define MASK_VSXH_V  0x1c00707f
#define MATCH_VSXW_V 0xc006027
#define MASK_VSXW_V  0x1c00707f
#define MATCH_VSXE_V 0xc007027
#define MASK_VSXE_V  0x1c00707f
#define MATCH_VSUXB_V 0x1c000027
#define MASK_VSUXB_V  0xfc00707f
#define MATCH_VSUXH_V 0x1c005027
#define MASK_VSUXH_V  0xfc00707f
#define MATCH_VSUXW_V 0x1c006027
#define MASK_VSUXW_V  0xfc00707f
#define MATCH_VSUXE_V 0x1c007027
#define MASK_VSUXE_V  0xfc00707f
#define MATCH_VLBFF_V 0x11000007
#define MASK_VLBFF_V  0x1df0707f
#define MATCH_VLHFF_V 0x11005007
#define MASK_VLHFF_V  0x1df0707f
#define MATCH_VLWFF_V 0x11006007
#define MASK_VLWFF_V  0x1df0707f
#define MATCH_VLEFF_V 0x1007007
#define MASK_VLEFF_V  0x1df0707f
#define MATCH_VLBUFF_V 0x1000007
#define MASK_VLBUFF_V  0x1df0707f
#define MATCH_VLHUFF_V 0x1005007
#define MASK_VLHUFF_V  0x1df0707f
#define MATCH_VLWUFF_V 0x1006007
#define MASK_VLWUFF_V  0x1df0707f
#define MATCH_VFADD_VF 0x5057
#define MASK_VFADD_VF  0xfc00707f
#define MATCH_VFSUB_VF 0x8005057
#define MASK_VFSUB_VF  0xfc00707f
#define MATCH_VFMIN_VF 0x10005057
#define MASK_VFMIN_VF  0xfc00707f
#define MATCH_VFMAX_VF 0x18005057
#define MASK_VFMAX_VF  0xfc00707f
#define MATCH_VFSGNJ_VF 0x20005057
#define MASK_VFSGNJ_VF  0xfc00707f
#define MATCH_VFSGNJN_VF 0x24005057
#define MASK_VFSGNJN_VF  0xfc00707f
#define MATCH_VFSGNJX_VF 0x28005057
#define MASK_VFSGNJX_VF  0xfc00707f
#define MATCH_VFMV_S_F 0x42005057
#define MASK_VFMV_S_F  0xfff0707f
#define MATCH_VFMERGE_VFM 0x5c005057
#define MASK_VFMERGE_VFM  0xfe00707f
#define MATCH_VFMV_V_F 0x5e005057
#define MASK_VFMV_V_F  0xfff0707f
#define MATCH_VMFEQ_VF 0x60005057
#define MASK_VMFEQ_VF  0xfc00707f
#define MATCH_VMFLE_VF 0x64005057
#define MASK_VMFLE_VF  0xfc00707f
#define MATCH_VMFORD_VF 0x68005057
#define MASK_VMFORD_VF  0xfc00707f
#define MATCH_VMFLT_VF 0x6c005057
#define MASK_VMFLT_VF  0xfc00707f
#define MATCH_VMFNE_VF 0x70005057
#define MASK_VMFNE_VF  0xfc00707f
#define MATCH_VMFGT_VF 0x74005057
#define MASK_VMFGT_VF  0xfc00707f
#define MATCH_VMFGE_VF 0x7c005057
#define MASK_VMFGE_VF  0xfc00707f
#define MATCH_VFDIV_VF 0x80005057
#define MASK_VFDIV_VF  0xfc00707f
#define MATCH_VFRDIV_VF 0x84005057
#define MASK_VFRDIV_VF  0xfc00707f
#define MATCH_VFMUL_VF 0x90005057
#define MASK_VFMUL_VF  0xfc00707f
#define MATCH_VFRSUB_VF 0x9c005057
#define MASK_VFRSUB_VF  0xfc00707f
#define MATCH_VFMADD_VF 0xa0005057
#define MASK_VFMADD_VF  0xfc00707f
#define MATCH_VFNMADD_VF 0xa4005057
#define MASK_VFNMADD_VF  0xfc00707f
#define MATCH_VFMSUB_VF 0xa8005057
#define MASK_VFMSUB_VF  0xfc00707f
#define MATCH_VFNMSUB_VF 0xac005057
#define MASK_VFNMSUB_VF  0xfc00707f
#define MATCH_VFMACC_VF 0xb0005057
#define MASK_VFMACC_VF  0xfc00707f
#define MATCH_VFNMACC_VF 0xb4005057
#define MASK_VFNMACC_VF  0xfc00707f
#define MATCH_VFMSAC_VF 0xb8005057
#define MASK_VFMSAC_VF  0xfc00707f
#define MATCH_VFNMSAC_VF 0xbc005057
#define MASK_VFNMSAC_VF  0xfc00707f
#define MATCH_VFWADD_VF 0xc0005057
#define MASK_VFWADD_VF  0xfc00707f
#define MATCH_VFWSUB_VF 0xc8005057
#define MASK_VFWSUB_VF  0xfc00707f
#define MATCH_VFWADD_WF 0xd0005057
#define MASK_VFWADD_WF  0xfc00707f
#define MATCH_VFWSUB_WF 0xd8005057
#define MASK_VFWSUB_WF  0xfc00707f
#define MATCH_VFWMUL_VF 0xe0005057
#define MASK_VFWMUL_VF  0xfc00707f
#define MATCH_VFWMACC_VF 0xf0005057
#define MASK_VFWMACC_VF  0xfc00707f
#define MATCH_VFWNMACC_VF 0xf4005057
#define MASK_VFWNMACC_VF  0xfc00707f
#define MATCH_VFWMSAC_VF 0xf8005057
#define MASK_VFWMSAC_VF  0xfc00707f
#define MATCH_VFWNMSAC_VF 0xfc005057
#define MASK_VFWNMSAC_VF  0xfc00707f
#define MATCH_VFADD_VV 0x1057
#define MASK_VFADD_VV  0xfc00707f
#define MATCH_VFREDSUM_VS 0x4001057
#define MASK_VFREDSUM_VS  0xfc00707f
#define MATCH_VFSUB_VV 0x8001057
#define MASK_VFSUB_VV  0xfc00707f
#define MATCH_VFREDOSUM_VS 0xc001057
#define MASK_VFREDOSUM_VS  0xfc00707f
#define MATCH_VFMIN_VV 0x10001057
#define MASK_VFMIN_VV  0xfc00707f
#define MATCH_VFREDMIN_VS 0x14001057
#define MASK_VFREDMIN_VS  0xfc00707f
#define MATCH_VFMAX_VV 0x18001057
#define MASK_VFMAX_VV  0xfc00707f
#define MATCH_VFREDMAX_VS 0x1c001057
#define MASK_VFREDMAX_VS  0xfc00707f
#define MATCH_VFSGNJ_VV 0x20001057
#define MASK_VFSGNJ_VV  0xfc00707f
#define MATCH_VFSGNJN_VV 0x24001057
#define MASK_VFSGNJN_VV  0xfc00707f
#define MATCH_VFSGNJX_VV 0x28001057
#define MASK_VFSGNJX_VV  0xfc00707f
#define MATCH_VFMV_F_S 0x42001057
#define MASK_VFMV_F_S  0xfe0ff07f
#define MATCH_VMFEQ_VV 0x60001057
#define MASK_VMFEQ_VV  0xfc00707f
#define MATCH_VMFLE_VV 0x64001057
#define MASK_VMFLE_VV  0xfc00707f
#define MATCH_VMFORD_VV 0x68001057
#define MASK_VMFORD_VV  0xfc00707f
#define MATCH_VMFLT_VV 0x6c001057
#define MASK_VMFLT_VV  0xfc00707f
#define MATCH_VMFNE_VV 0x70001057
#define MASK_VMFNE_VV  0xfc00707f
#define MATCH_VFDIV_VV 0x80001057
#define MASK_VFDIV_VV  0xfc00707f
#define MATCH_VFMUL_VV 0x90001057
#define MASK_VFMUL_VV  0xfc00707f
#define MATCH_VFMADD_VV 0xa0001057
#define MASK_VFMADD_VV  0xfc00707f
#define MATCH_VFNMADD_VV 0xa4001057
#define MASK_VFNMADD_VV  0xfc00707f
#define MATCH_VFMSUB_VV 0xa8001057
#define MASK_VFMSUB_VV  0xfc00707f
#define MATCH_VFNMSUB_VV 0xac001057
#define MASK_VFNMSUB_VV  0xfc00707f
#define MATCH_VFMACC_VV 0xb0001057
#define MASK_VFMACC_VV  0xfc00707f
#define MATCH_VFNMACC_VV 0xb4001057
#define MASK_VFNMACC_VV  0xfc00707f
#define MATCH_VFMSAC_VV 0xb8001057
#define MASK_VFMSAC_VV  0xfc00707f
#define MATCH_VFNMSAC_VV 0xbc001057
#define MASK_VFNMSAC_VV  0xfc00707f
#define MATCH_VFCVT_XU_F_V 0x88001057
#define MASK_VFCVT_XU_F_V  0xfc0ff07f
#define MATCH_VFCVT_X_F_V 0x88009057
#define MASK_VFCVT_X_F_V  0xfc0ff07f
#define MATCH_VFCVT_F_XU_V 0x88011057
#define MASK_VFCVT_F_XU_V  0xfc0ff07f
#define MATCH_VFCVT_F_X_V 0x88019057
#define MASK_VFCVT_F_X_V  0xfc0ff07f
#define MATCH_VFWCVT_XU_F_V 0x88041057
#define MASK_VFWCVT_XU_F_V  0xfc0ff07f
#define MATCH_VFWCVT_X_F_V 0x88049057
#define MASK_VFWCVT_X_F_V  0xfc0ff07f
#define MATCH_VFWCVT_F_XU_V 0x88051057
#define MASK_VFWCVT_F_XU_V  0xfc0ff07f
#define MATCH_VFWCVT_F_X_V 0x88059057
#define MASK_VFWCVT_F_X_V  0xfc0ff07f
#define MATCH_VFWCVT_F_F_V 0x88061057
#define MASK_VFWCVT_F_F_V  0xfc0ff07f
#define MATCH_VFNCVT_XU_F_V 0x88081057
#define MASK_VFNCVT_XU_F_V  0xfc0ff07f
#define MATCH_VFNCVT_X_F_V 0x88089057
#define MASK_VFNCVT_X_F_V  0xfc0ff07f
#define MATCH_VFNCVT_F_XU_V 0x88091057
#define MASK_VFNCVT_F_XU_V  0xfc0ff07f
#define MATCH_VFNCVT_F_X_V 0x88099057
#define MASK_VFNCVT_F_X_V  0xfc0ff07f
#define MATCH_VFNCVT_F_F_V 0x880a1057
#define MASK_VFNCVT_F_F_V  0xfc0ff07f
#define MATCH_VFSQRT_V 0x8c001057
#define MASK_VFSQRT_V  0xfc0ff07f
#define MATCH_VFCLASS_V 0x8c081057
#define MASK_VFCLASS_V  0xfc0ff07f
#define MATCH_VFWADD_VV 0xc0001057
#define MASK_VFWADD_VV  0xfc00707f
#define MATCH_VFWREDSUM_VS 0xc4001057
#define MASK_VFWREDSUM_VS  0xfc00707f
#define MATCH_VFWSUB_VV 0xc8001057
#define MASK_VFWSUB_VV  0xfc00707f
#define MATCH_VFWREDOSUM_VS 0xcc001057
#define MASK_VFWREDOSUM_VS  0xfc00707f
#define MATCH_VFWADD_WV 0xd0001057
#define MASK_VFWADD_WV  0xfc00707f
#define MATCH_VFWSUB_WV 0xd8001057
#define MASK_VFWSUB_WV  0xfc00707f
#define MATCH_VFWMUL_VV 0xe0001057
#define MASK_VFWMUL_VV  0xfc00707f
#define MATCH_VFDOT_VV 0xe4001057
#define MASK_VFDOT_VV  0xfc00707f
#define MATCH_VFWMACC_VV 0xf0001057
#define MASK_VFWMACC_VV  0xfc00707f
#define MATCH_VFWNMACC_VV 0xf4001057
#define MASK_VFWNMACC_VV  0xfc00707f
#define MATCH_VFWMSAC_VV 0xf8001057
#define MASK_VFWMSAC_VV  0xfc00707f
#define MATCH_VFWNMSAC_VV 0xfc001057
#define MASK_VFWNMSAC_VV  0xfc00707f
#define MATCH_VADD_VX 0x4057
#define MASK_VADD_VX  0xfc00707f
#define MATCH_VSUB_VX 0x8004057
#define MASK_VSUB_VX  0xfc00707f
#define MATCH_VRSUB_VX 0xc004057
#define MASK_VRSUB_VX  0xfc00707f
#define MATCH_VMINU_VX 0x10004057
#define MASK_VMINU_VX  0xfc00707f
#define MATCH_VMIN_VX 0x14004057
#define MASK_VMIN_VX  0xfc00707f
#define MATCH_VMAXU_VX 0x18004057
#define MASK_VMAXU_VX  0xfc00707f
#define MATCH_VMAX_VX 0x1c004057
#define MASK_VMAX_VX  0xfc00707f
#define MATCH_VAND_VX 0x24004057
#define MASK_VAND_VX  0xfc00707f
#define MATCH_VOR_VX 0x28004057
#define MASK_VOR_VX  0xfc00707f
#define MATCH_VXOR_VX 0x2c004057
#define MASK_VXOR_VX  0xfc00707f
#define MATCH_VRGATHER_VX 0x30004057
#define MASK_VRGATHER_VX  0xfc00707f
#define MATCH_VSLIDEUP_VX 0x38004057
#define MASK_VSLIDEUP_VX  0xfc00707f
#define MATCH_VSLIDEDOWN_VX 0x3c004057
#define MASK_VSLIDEDOWN_VX  0xfc00707f
#define MATCH_VADC_VXM 0x42004057
#define MASK_VADC_VXM  0xfe00707f
#define MATCH_VMADC_VXM 0x46004057
#define MASK_VMADC_VXM  0xfe00707f
#define MATCH_VSBC_VXM 0x4a004057
#define MASK_VSBC_VXM  0xfe00707f
#define MATCH_VMSBC_VXM 0x4e004057
#define MASK_VMSBC_VXM  0xfe00707f
#define MATCH_VMERGE_VXM 0x5c004057
#define MASK_VMERGE_VXM  0xfe00707f
#define MATCH_VMV_V_X 0x5e004057
#define MASK_VMV_V_X  0xfff0707f
#define MATCH_VMSEQ_VX 0x60004057
#define MASK_VMSEQ_VX  0xfc00707f
#define MATCH_VMSNE_VX 0x64004057
#define MASK_VMSNE_VX  0xfc00707f
#define MATCH_VMSLTU_VX 0x68004057
#define MASK_VMSLTU_VX  0xfc00707f
#define MATCH_VMSLT_VX 0x6c004057
#define MASK_VMSLT_VX  0xfc00707f
#define MATCH_VMSLEU_VX 0x70004057
#define MASK_VMSLEU_VX  0xfc00707f
#define MATCH_VMSLE_VX 0x74004057
#define MASK_VMSLE_VX  0xfc00707f
#define MATCH_VMSGTU_VX 0x78004057
#define MASK_VMSGTU_VX  0xfc00707f
#define MATCH_VMSGT_VX 0x7c004057
#define MASK_VMSGT_VX  0xfc00707f
#define MATCH_VSADDU_VX 0x80004057
#define MASK_VSADDU_VX  0xfc00707f
#define MATCH_VSADD_VX 0x84004057
#define MASK_VSADD_VX  0xfc00707f
#define MATCH_VSSUBU_VX 0x88004057
#define MASK_VSSUBU_VX  0xfc00707f
#define MATCH_VSSUB_VX 0x8c004057
#define MASK_VSSUB_VX  0xfc00707f
#define MATCH_VAADD_VX 0x90004057
#define MASK_VAADD_VX  0xfc00707f
#define MATCH_VSLL_VX 0x94004057
#define MASK_VSLL_VX  0xfc00707f
#define MATCH_VASUB_VX 0x98004057
#define MASK_VASUB_VX  0xfc00707f
#define MATCH_VSMUL_VX 0x9c004057
#define MASK_VSMUL_VX  0xfc00707f
#define MATCH_VSRL_VX 0xa0004057
#define MASK_VSRL_VX  0xfc00707f
#define MATCH_VSRA_VX 0xa4004057
#define MASK_VSRA_VX  0xfc00707f
#define MATCH_VSSRL_VX 0xa8004057
#define MASK_VSSRL_VX  0xfc00707f
#define MATCH_VSSRA_VX 0xac004057
#define MASK_VSSRA_VX  0xfc00707f
#define MATCH_VNSRL_VX 0xb0004057
#define MASK_VNSRL_VX  0xfc00707f
#define MATCH_VNSRA_VX 0xb4004057
#define MASK_VNSRA_VX  0xfc00707f
#define MATCH_VNCLIPU_VX 0xb8004057
#define MASK_VNCLIPU_VX  0xfc00707f
#define MATCH_VNCLIP_VX 0xbc004057
#define MASK_VNCLIP_VX  0xfc00707f
#define MATCH_VWSMACCU_VX 0xf0004057
#define MASK_VWSMACCU_VX  0xfc00707f
#define MATCH_VWSMACC_VX 0xf4004057
#define MASK_VWSMACC_VX  0xfc00707f
#define MATCH_VWSMACCSU_VX 0xf8004057
#define MASK_VWSMACCSU_VX  0xfc00707f
#define MATCH_VWSMACCUS_VX 0xfc004057
#define MASK_VWSMACCUS_VX  0xfc00707f
#define MATCH_VADD_VV 0x57
#define MASK_VADD_VV  0xfc00707f
#define MATCH_VSUB_VV 0x8000057
#define MASK_VSUB_VV  0xfc00707f
#define MATCH_VMINU_VV 0x10000057
#define MASK_VMINU_VV  0xfc00707f
#define MATCH_VMIN_VV 0x14000057
#define MASK_VMIN_VV  0xfc00707f
#define MATCH_VMAXU_VV 0x18000057
#define MASK_VMAXU_VV  0xfc00707f
#define MATCH_VMAX_VV 0x1c000057
#define MASK_VMAX_VV  0xfc00707f
#define MATCH_VAND_VV 0x24000057
#define MASK_VAND_VV  0xfc00707f
#define MATCH_VOR_VV 0x28000057
#define MASK_VOR_VV  0xfc00707f
#define MATCH_VXOR_VV 0x2c000057
#define MASK_VXOR_VV  0xfc00707f
#define MATCH_VRGATHER_VV 0x30000057
#define MASK_VRGATHER_VV  0xfc00707f
#define MATCH_VADC_VVM 0x42000057
#define MASK_VADC_VVM  0xfe00707f
#define MATCH_VMADC_VVM 0x46000057
#define MASK_VMADC_VVM  0xfe00707f
#define MATCH_VSBC_VVM 0x4a000057
#define MASK_VSBC_VVM  0xfe00707f
#define MATCH_VMSBC_VVM 0x4e000057
#define MASK_VMSBC_VVM  0xfe00707f
#define MATCH_VMERGE_VVM 0x5c000057
#define MASK_VMERGE_VVM  0xfe00707f
#define MATCH_VMV_V_V 0x5e000057
#define MASK_VMV_V_V  0xfff0707f
#define MATCH_VMSEQ_VV 0x60000057
#define MASK_VMSEQ_VV  0xfc00707f
#define MATCH_VMSNE_VV 0x64000057
#define MASK_VMSNE_VV  0xfc00707f
#define MATCH_VMSLTU_VV 0x68000057
#define MASK_VMSLTU_VV  0xfc00707f
#define MATCH_VMSLT_VV 0x6c000057
#define MASK_VMSLT_VV  0xfc00707f
#define MATCH_VMSLEU_VV 0x70000057
#define MASK_VMSLEU_VV  0xfc00707f
#define MATCH_VMSLE_VV 0x74000057
#define MASK_VMSLE_VV  0xfc00707f
#define MATCH_VSADDU_VV 0x80000057
#define MASK_VSADDU_VV  0xfc00707f
#define MATCH_VSADD_VV 0x84000057
#define MASK_VSADD_VV  0xfc00707f
#define MATCH_VSSUBU_VV 0x88000057
#define MASK_VSSUBU_VV  0xfc00707f
#define MATCH_VSSUB_VV 0x8c000057
#define MASK_VSSUB_VV  0xfc00707f
#define MATCH_VAADD_VV 0x90000057
#define MASK_VAADD_VV  0xfc00707f
#define MATCH_VSLL_VV 0x94000057
#define MASK_VSLL_VV  0xfc00707f
#define MATCH_VASUB_VV 0x98000057
#define MASK_VASUB_VV  0xfc00707f
#define MATCH_VSMUL_VV 0x9c000057
#define MASK_VSMUL_VV  0xfc00707f
#define MATCH_VSRL_VV 0xa0000057
#define MASK_VSRL_VV  0xfc00707f
#define MATCH_VSRA_VV 0xa4000057
#define MASK_VSRA_VV  0xfc00707f
#define MATCH_VSSRL_VV 0xa8000057
#define MASK_VSSRL_VV  0xfc00707f
#define MATCH_VSSRA_VV 0xac000057
#define MASK_VSSRA_VV  0xfc00707f
#define MATCH_VNSRL_VV 0xb0000057
#define MASK_VNSRL_VV  0xfc00707f
#define MATCH_VNSRA_VV 0xb4000057
#define MASK_VNSRA_VV  0xfc00707f
#define MATCH_VNCLIPU_VV 0xb8000057
#define MASK_VNCLIPU_VV  0xfc00707f
#define MATCH_VNCLIP_VV 0xbc000057
#define MASK_VNCLIP_VV  0xfc00707f
#define MATCH_VWREDSUMU_VS 0xc0000057
#define MASK_VWREDSUMU_VS  0xfc00707f
#define MATCH_VWREDSUM_VS 0xc4000057
#define MASK_VWREDSUM_VS  0xfc00707f
#define MATCH_VDOTU_VV 0xe0000057
#define MASK_VDOTU_VV  0xfc00707f
#define MATCH_VDOT_VV 0xe4000057
#define MASK_VDOT_VV  0xfc00707f
#define MATCH_VWSMACCU_VV 0xf0000057
#define MASK_VWSMACCU_VV  0xfc00707f
#define MATCH_VWSMACC_VV 0xf4000057
#define MASK_VWSMACC_VV  0xfc00707f
#define MATCH_VWSMACCSU_VV 0xf8000057
#define MASK_VWSMACCSU_VV  0xfc00707f
#define MATCH_VADD_VI 0x3057
#define MASK_VADD_VI  0xfc00707f
#define MATCH_VRSUB_VI 0xc003057
#define MASK_VRSUB_VI  0xfc00707f
#define MATCH_VAND_VI 0x24003057
#define MASK_VAND_VI  0xfc00707f
#define MATCH_VOR_VI 0x28003057
#define MASK_VOR_VI  0xfc00707f
#define MATCH_VXOR_VI 0x2c003057
#define MASK_VXOR_VI  0xfc00707f
#define MATCH_VRGATHER_VI 0x30003057
#define MASK_VRGATHER_VI  0xfc00707f
#define MATCH_VSLIDEUP_VI 0x38003057
#define MASK_VSLIDEUP_VI  0xfc00707f
#define MATCH_VSLIDEDOWN_VI 0x3c003057
#define MASK_VSLIDEDOWN_VI  0xfc00707f
#define MATCH_VADC_VIM 0x42003057
#define MASK_VADC_VIM  0xfe00707f
#define MATCH_VMADC_VIM 0x46003057
#define MASK_VMADC_VIM  0xfe00707f
#define MATCH_VMERGE_VIM 0x5c003057
#define MASK_VMERGE_VIM  0xfe00707f
#define MATCH_VMV_V_I 0x5e003057
#define MASK_VMV_V_I  0xfff0707f
#define MATCH_VMSEQ_VI 0x60003057
#define MASK_VMSEQ_VI  0xfc00707f
#define MATCH_VMSNE_VI 0x64003057
#define MASK_VMSNE_VI  0xfc00707f
#define MATCH_VMSLEU_VI 0x70003057
#define MASK_VMSLEU_VI  0xfc00707f
#define MATCH_VMSLE_VI 0x74003057
#define MASK_VMSLE_VI  0xfc00707f
#define MATCH_VMSGTU_VI 0x78003057
#define MASK_VMSGTU_VI  0xfc00707f
#define MATCH_VMSGT_VI 0x7c003057
#define MASK_VMSGT_VI  0xfc00707f
#define MATCH_VSADDU_VI 0x80003057
#define MASK_VSADDU_VI  0xfc00707f
#define MATCH_VSADD_VI 0x84003057
#define MASK_VSADD_VI  0xfc00707f
#define MATCH_VAADD_VI 0x90003057
#define MASK_VAADD_VI  0xfc00707f
#define MATCH_VSLL_VI 0x94003057
#define MASK_VSLL_VI  0xfc00707f
#define MATCH_VSRL_VI 0xa0003057
#define MASK_VSRL_VI  0xfc00707f
#define MATCH_VSRA_VI 0xa4003057
#define MASK_VSRA_VI  0xfc00707f
#define MATCH_VSSRL_VI 0xa8003057
#define MASK_VSSRL_VI  0xfc00707f
#define MATCH_VSSRA_VI 0xac003057
#define MASK_VSSRA_VI  0xfc00707f
#define MATCH_VNSRL_VI 0xb0003057
#define MASK_VNSRL_VI  0xfc00707f
#define MATCH_VNSRA_VI 0xb4003057
#define MASK_VNSRA_VI  0xfc00707f
#define MATCH_VNCLIPU_VI 0xb8003057
#define MASK_VNCLIPU_VI  0xfc00707f
#define MATCH_VNCLIP_VI 0xbc003057
#define MASK_VNCLIP_VI  0xfc00707f
#define MATCH_VREDSUM_VS 0x2057
#define MASK_VREDSUM_VS  0xfc00707f
#define MATCH_VREDAND_VS 0x4002057
#define MASK_VREDAND_VS  0xfc00707f
#define MATCH_VREDOR_VS 0x8002057
#define MASK_VREDOR_VS  0xfc00707f
#define MATCH_VREDXOR_VS 0xc002057
#define MASK_VREDXOR_VS  0xfc00707f
#define MATCH_VREDMINU_VS 0x10002057
#define MASK_VREDMINU_VS  0xfc00707f
#define MATCH_VREDMIN_VS 0x14002057
#define MASK_VREDMIN_VS  0xfc00707f
#define MATCH_VREDMAXU_VS 0x18002057
#define MASK_VREDMAXU_VS  0xfc00707f
#define MATCH_VREDMAX_VS 0x1c002057
#define MASK_VREDMAX_VS  0xfc00707f
#define MATCH_VMV_X_S 0x42002057
#define MASK_VMV_X_S  0xfe0ff07f
#define MATCH_VCOMPRESS_VM 0x5c002057
#define MASK_VCOMPRESS_VM  0xfc00707f
#define MATCH_VMANDNOT_MM 0x60002057
#define MASK_VMANDNOT_MM  0xfc00707f
#define MATCH_VMAND_MM 0x64002057
#define MASK_VMAND_MM  0xfc00707f
#define MATCH_VMOR_MM 0x68002057
#define MASK_VMOR_MM  0xfc00707f
#define MATCH_VMXOR_MM 0x6c002057
#define MASK_VMXOR_MM  0xfc00707f
#define MATCH_VMORNOT_MM 0x70002057
#define MASK_VMORNOT_MM  0xfc00707f
#define MATCH_VMNAND_MM 0x74002057
#define MASK_VMNAND_MM  0xfc00707f
#define MATCH_VMNOR_MM 0x78002057
#define MASK_VMNOR_MM  0xfc00707f
#define MATCH_VMXNOR_MM 0x7c002057
#define MASK_VMXNOR_MM  0xfc00707f
#define MATCH_VMSBF_M 0x5000a057
#define MASK_VMSBF_M  0xfc0ff07f
#define MATCH_VMSOF_M 0x50012057
#define MASK_VMSOF_M  0xfc0ff07f
#define MATCH_VMSIF_M 0x5001a057
#define MASK_VMSIF_M  0xfc0ff07f
#define MATCH_VIOTA_M 0x50082057
#define MASK_VIOTA_M  0xfc0ff07f
#define MATCH_VID_V 0x5008a057
#define MASK_VID_V  0xfdfff07f
#define MATCH_VPOPC_M 0x40082057
#define MASK_VPOPC_M  0xfc0ff07f
#define MATCH_VFIRST_M 0x4008a057
#define MASK_VFIRST_M  0xfc0ff07f
#define MATCH_VDIVU_VV 0x80002057
#define MASK_VDIVU_VV  0xfc00707f
#define MATCH_VDIV_VV 0x84002057
#define MASK_VDIV_VV  0xfc00707f
#define MATCH_VREMU_VV 0x88002057
#define MASK_VREMU_VV  0xfc00707f
#define MATCH_VREM_VV 0x8c002057
#define MASK_VREM_VV  0xfc00707f
#define MATCH_VMULHU_VV 0x90002057
#define MASK_VMULHU_VV  0xfc00707f
#define MATCH_VMUL_VV 0x94002057
#define MASK_VMUL_VV  0xfc00707f
#define MATCH_VMULHSU_VV 0x98002057
#define MASK_VMULHSU_VV  0xfc00707f
#define MATCH_VMULH_VV 0x9c002057
#define MASK_VMULH_VV  0xfc00707f
#define MATCH_VMADD_VV 0xa4002057
#define MASK_VMADD_VV  0xfc00707f
#define MATCH_VNMSUB_VV 0xac002057
#define MASK_VNMSUB_VV  0xfc00707f
#define MATCH_VMACC_VV 0xb4002057
#define MASK_VMACC_VV  0xfc00707f
#define MATCH_VNMSAC_VV 0xbc002057
#define MASK_VNMSAC_VV  0xfc00707f
#define MATCH_VWADDU_VV 0xc0002057
#define MASK_VWADDU_VV  0xfc00707f
#define MATCH_VWADD_VV 0xc4002057
#define MASK_VWADD_VV  0xfc00707f
#define MATCH_VWSUBU_VV 0xc8002057
#define MASK_VWSUBU_VV  0xfc00707f
#define MATCH_VWSUB_VV 0xcc002057
#define MASK_VWSUB_VV  0xfc00707f
#define MATCH_VWADDU_WV 0xd0002057
#define MASK_VWADDU_WV  0xfc00707f
#define MATCH_VWADD_WV 0xd4002057
#define MASK_VWADD_WV  0xfc00707f
#define MATCH_VWSUBU_WV 0xd8002057
#define MASK_VWSUBU_WV  0xfc00707f
#define MATCH_VWSUB_WV 0xdc002057
#define MASK_VWSUB_WV  0xfc00707f
#define MATCH_VWMULU_VV 0xe0002057
#define MASK_VWMULU_VV  0xfc00707f
#define MATCH_VWMULSU_VV 0xe8002057
#define MASK_VWMULSU_VV  0xfc00707f
#define MATCH_VWMUL_VV 0xec002057
#define MASK_VWMUL_VV  0xfc00707f
#define MATCH_VWMACCU_VV 0xf0002057
#define MASK_VWMACCU_VV  0xfc00707f
#define MATCH_VWMACC_VV 0xf4002057
#define MASK_VWMACC_VV  0xfc00707f
#define MATCH_VWMACCSU_VV 0xf8002057
#define MASK_VWMACCSU_VV  0xfc00707f
#define MATCH_VMV_S_X 0x42006057
#define MASK_VMV_S_X  0xfff0707f
#define MATCH_VSLIDE1UP_VX 0x38006057
#define MASK_VSLIDE1UP_VX  0xfc00707f
#define MATCH_VSLIDE1DOWN_VX 0x3c006057
#define MASK_VSLIDE1DOWN_VX  0xfc00707f
#define MATCH_VDIVU_VX 0x80006057
#define MASK_VDIVU_VX  0xfc00707f
#define MATCH_VDIV_VX 0x84006057
#define MASK_VDIV_VX  0xfc00707f
#define MATCH_VREMU_VX 0x88006057
#define MASK_VREMU_VX  0xfc00707f
#define MATCH_VREM_VX 0x8c006057
#define MASK_VREM_VX  0xfc00707f
#define MATCH_VMULHU_VX 0x90006057
#define MASK_VMULHU_VX  0xfc00707f
#define MATCH_VMUL_VX 0x94006057
#define MASK_VMUL_VX  0xfc00707f
#define MATCH_VMULHSU_VX 0x98006057
#define MASK_VMULHSU_VX  0xfc00707f
#define MATCH_VMULH_VX 0x9c006057
#define MASK_VMULH_VX  0xfc00707f
#define MATCH_VMADD_VX 0xa4006057
#define MASK_VMADD_VX  0xfc00707f
#define MATCH_VNMSUB_VX 0xac006057
#define MASK_VNMSUB_VX  0xfc00707f
#define MATCH_VMACC_VX 0xb4006057
#define MASK_VMACC_VX  0xfc00707f
#define MATCH_VNMSAC_VX 0xbc006057
#define MASK_VNMSAC_VX  0xfc00707f
#define MATCH_VWADDU_VX 0xc0006057
#define MASK_VWADDU_VX  0xfc00707f
#define MATCH_VWADD_VX 0xc4006057
#define MASK_VWADD_VX  0xfc00707f
#define MATCH_VWSUBU_VX 0xc8006057
#define MASK_VWSUBU_VX  0xfc00707f
#define MATCH_VWSUB_VX 0xcc006057
#define MASK_VWSUB_VX  0xfc00707f
#define MATCH_VWADDU_WX 0xd0006057
#define MASK_VWADDU_WX  0xfc00707f
#define MATCH_VWADD_WX 0xd4006057
#define MASK_VWADD_WX  0xfc00707f
#define MATCH_VWSUBU_WX 0xd8006057
#define MASK_VWSUBU_WX  0xfc00707f
#define MATCH_VWSUB_WX 0xdc006057
#define MASK_VWSUB_WX  0xfc00707f
#define MATCH_VWMULU_VX 0xe0006057
#define MASK_VWMULU_VX  0xfc00707f
#define MATCH_VWMULSU_VX 0xe8006057
#define MASK_VWMULSU_VX  0xfc00707f
#define MATCH_VWMUL_VX 0xec006057
#define MASK_VWMUL_VX  0xfc00707f
#define MATCH_VWMACCU_VX 0xf0006057
#define MASK_VWMACCU_VX  0xfc00707f
#define MATCH_VWMACC_VX 0xf4006057
#define MASK_VWMACC_VX  0xfc00707f
#define MATCH_VWMACCSU_VX 0xf8006057
#define MASK_VWMACCSU_VX  0xfc00707f
#define MATCH_VWMACCUS_VX 0xfc006057
#define MASK_VWMACCUS_VX  0xfc00707f
#define MATCH_VAMOSWAPW_V 0x800602f
#define MASK_VAMOSWAPW_V  0xf800707f
#define MATCH_VAMOADDW_V 0x602f
#define MASK_VAMOADDW_V  0xf800707f
#define MATCH_VAMOXORW_V 0x2000602f
#define MASK_VAMOXORW_V  0xf800707f
#define MATCH_VAMOANDW_V 0x6000602f
#define MASK_VAMOANDW_V  0xf800707f
#define MATCH_VAMOORW_V 0x4000602f
#define MASK_VAMOORW_V  0xf800707f
#define MATCH_VAMOMINW_V 0x8000602f
#define MASK_VAMOMINW_V  0xf800707f
#define MATCH_VAMOMAXW_V 0xa000602f
#define MASK_VAMOMAXW_V  0xf800707f
#define MATCH_VAMOMINUW_V 0xc000602f
#define MASK_VAMOMINUW_V  0xf800707f
#define MATCH_VAMOMAXUW_V 0xe000602f
#define MASK_VAMOMAXUW_V  0xf800707f
#define MATCH_VAMOSWAPD_V 0x800702f
#define MASK_VAMOSWAPD_V  0xf800707f
#define MATCH_VAMOADDD_V 0x702f
#define MASK_VAMOADDD_V  0xf800707f
#define MATCH_VAMOXORD_V 0x2000702f
#define MASK_VAMOXORD_V  0xf800707f
#define MATCH_VAMOANDD_V 0x6000702f
#define MASK_VAMOANDD_V  0xf800707f
#define MATCH_VAMOORD_V 0x4000702f
#define MASK_VAMOORD_V  0xf800707f
#define MATCH_VAMOMIND_V 0x8000702f
#define MASK_VAMOMIND_V  0xf800707f
#define MATCH_VAMOMAXD_V 0xa000702f
#define MASK_VAMOMAXD_V  0xf800707f
#define MATCH_VAMOMINUD_V 0xc000702f
#define MASK_VAMOMINUD_V  0xf800707f
#define MATCH_VAMOMAXUD_V 0xe000702f
#define MASK_VAMOMAXUD_V  0xf800707f
#define MATCH_VAMOSWAPQ_V 0x800002f
#define MASK_VAMOSWAPQ_V  0xf800707f
#define MATCH_VAMOADDQ_V 0x2f
#define MASK_VAMOADDQ_V  0xf800707f
#define MATCH_VAMOXORQ_V 0x2000002f
#define MASK_VAMOXORQ_V  0xf800707f
#define MATCH_VAMOANDQ_V 0x6000002f
#define MASK_VAMOANDQ_V  0xf800707f
#define MATCH_VAMOORQ_V 0x4000002f
#define MASK_VAMOORQ_V  0xf800707f
#define MATCH_VAMOMINQ_V 0x8000002f
#define MASK_VAMOMINQ_V  0xf800707f
#define MATCH_VAMOMAXQ_V 0xa000002f
#define MASK_VAMOMAXQ_V  0xf800707f
#define MATCH_VAMOMINUQ_V 0xc000002f
#define MASK_VAMOMINUQ_V  0xf800707f
#define MATCH_VAMOMAXUQ_V 0xe000002f
#define MASK_VAMOMAXUQ_V  0xf800707f
#define CSR_FFLAGS 0x1
#define CSR_FRM 0x2
#define CSR_FCSR 0x3
#define CSR_USTATUS 0x0
#define CSR_UIE 0x4
#define CSR_UTVEC 0x5
#define CSR_VSTART 0x8
#define CSR_VXSAT 0x9
#define CSR_VXRM 0xa
#define CSR_USCRATCH 0x40
#define CSR_UEPC 0x41
#define CSR_UCAUSE 0x42
#define CSR_UTVAL 0x43
#define CSR_UIP 0x44
#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02
#define CSR_HPMCOUNTER3 0xc03
#define CSR_HPMCOUNTER4 0xc04
#define CSR_HPMCOUNTER5 0xc05
#define CSR_HPMCOUNTER6 0xc06
#define CSR_HPMCOUNTER7 0xc07
#define CSR_HPMCOUNTER8 0xc08
#define CSR_HPMCOUNTER9 0xc09
#define CSR_HPMCOUNTER10 0xc0a
#define CSR_HPMCOUNTER11 0xc0b
#define CSR_HPMCOUNTER12 0xc0c
#define CSR_HPMCOUNTER13 0xc0d
#define CSR_HPMCOUNTER14 0xc0e
#define CSR_HPMCOUNTER15 0xc0f
#define CSR_HPMCOUNTER16 0xc10
#define CSR_HPMCOUNTER17 0xc11
#define CSR_HPMCOUNTER18 0xc12
#define CSR_HPMCOUNTER19 0xc13
#define CSR_HPMCOUNTER20 0xc14
#define CSR_HPMCOUNTER21 0xc15
#define CSR_HPMCOUNTER22 0xc16
#define CSR_HPMCOUNTER23 0xc17
#define CSR_HPMCOUNTER24 0xc18
#define CSR_HPMCOUNTER25 0xc19
#define CSR_HPMCOUNTER26 0xc1a
#define CSR_HPMCOUNTER27 0xc1b
#define CSR_HPMCOUNTER28 0xc1c
#define CSR_HPMCOUNTER29 0xc1d
#define CSR_HPMCOUNTER30 0xc1e
#define CSR_HPMCOUNTER31 0xc1f
#define CSR_VL 0xc20
#define CSR_VTYPE 0xc21
#define CSR_SSTATUS 0x100
#define CSR_SIE 0x104
#define CSR_STVEC 0x105
#define CSR_SCOUNTEREN 0x106
#define CSR_SSCRATCH 0x140
#define CSR_SEPC 0x141
#define CSR_SCAUSE 0x142
#define CSR_STVAL 0x143
#define CSR_SIP 0x144
#define CSR_SATP 0x180
#define CSR_VSSTATUS 0x200
#define CSR_VSIE 0x204
#define CSR_VSTVEC 0x205
#define CSR_VSSCRATCH 0x240
#define CSR_VSEPC 0x241
#define CSR_VSCAUSE 0x242
#define CSR_VSTVAL 0x243
#define CSR_VSIP 0x244
#define CSR_VSATP 0x280
#define CSR_HSTATUS 0x600
#define CSR_HEDELEG 0x602
#define CSR_HIDELEG 0x603
#define CSR_HCOUNTEREN 0x606
#define CSR_HGATP 0x680
#define CSR_UTVT 0x7
#define CSR_UNXTI 0x45
#define CSR_UINTSTATUS 0x46
#define CSR_USCRATCHCSW 0x48
#define CSR_USCRATCHCSWL 0x49
#define CSR_STVT 0x107
#define CSR_SNXTI 0x145
#define CSR_SINTSTATUS 0x146
#define CSR_SSCRATCHCSW 0x148
#define CSR_SSCRATCHCSWL 0x149
#define CSR_MTVT 0x307
#define CSR_MNXTI 0x345
#define CSR_MINTSTATUS 0x346
#define CSR_MSCRATCHCSW 0x348
#define CSR_MSCRATCHCSWL 0x349
#define CSR_MSTATUS 0x300
#define CSR_MISA 0x301
#define CSR_MEDELEG 0x302
#define CSR_MIDELEG 0x303
#define CSR_MIE 0x304
#define CSR_MTVEC 0x305
#define CSR_MCOUNTEREN 0x306
#define CSR_MSCRATCH 0x340
#define CSR_MEPC 0x341
#define CSR_MCAUSE 0x342
#define CSR_MTVAL 0x343
#define CSR_MIP 0x344
#define CSR_PMPCFG0 0x3a0
#define CSR_PMPCFG1 0x3a1
#define CSR_PMPCFG2 0x3a2
#define CSR_PMPCFG3 0x3a3
#define CSR_PMPADDR0 0x3b0
#define CSR_PMPADDR1 0x3b1
#define CSR_PMPADDR2 0x3b2
#define CSR_PMPADDR3 0x3b3
#define CSR_PMPADDR4 0x3b4
#define CSR_PMPADDR5 0x3b5
#define CSR_PMPADDR6 0x3b6
#define CSR_PMPADDR7 0x3b7
#define CSR_PMPADDR8 0x3b8
#define CSR_PMPADDR9 0x3b9
#define CSR_PMPADDR10 0x3ba
#define CSR_PMPADDR11 0x3bb
#define CSR_PMPADDR12 0x3bc
#define CSR_PMPADDR13 0x3bd
#define CSR_PMPADDR14 0x3be
#define CSR_PMPADDR15 0x3bf
#define CSR_TSELECT 0x7a0
#define CSR_TDATA1 0x7a1
#define CSR_TDATA2 0x7a2
#define CSR_TDATA3 0x7a3
#define CSR_DCSR 0x7b0
#define CSR_DPC 0x7b1
#define CSR_DSCRATCH 0x7b2
#define CSR_MCYCLE 0xb00
#define CSR_MINSTRET 0xb02
#define CSR_MHPMCOUNTER3 0xb03
#define CSR_MHPMCOUNTER4 0xb04
#define CSR_MHPMCOUNTER5 0xb05
#define CSR_MHPMCOUNTER6 0xb06
#define CSR_MHPMCOUNTER7 0xb07
#define CSR_MHPMCOUNTER8 0xb08
#define CSR_MHPMCOUNTER9 0xb09
#define CSR_MHPMCOUNTER10 0xb0a
#define CSR_MHPMCOUNTER11 0xb0b
#define CSR_MHPMCOUNTER12 0xb0c
#define CSR_MHPMCOUNTER13 0xb0d
#define CSR_MHPMCOUNTER14 0xb0e
#define CSR_MHPMCOUNTER15 0xb0f
#define CSR_MHPMCOUNTER16 0xb10
#define CSR_MHPMCOUNTER17 0xb11
#define CSR_MHPMCOUNTER18 0xb12
#define CSR_MHPMCOUNTER19 0xb13
#define CSR_MHPMCOUNTER20 0xb14
#define CSR_MHPMCOUNTER21 0xb15
#define CSR_MHPMCOUNTER22 0xb16
#define CSR_MHPMCOUNTER23 0xb17
#define CSR_MHPMCOUNTER24 0xb18
#define CSR_MHPMCOUNTER25 0xb19
#define CSR_MHPMCOUNTER26 0xb1a
#define CSR_MHPMCOUNTER27 0xb1b
#define CSR_MHPMCOUNTER28 0xb1c
#define CSR_MHPMCOUNTER29 0xb1d
#define CSR_MHPMCOUNTER30 0xb1e
#define CSR_MHPMCOUNTER31 0xb1f
#define CSR_MHPMEVENT3 0x323
#define CSR_MHPMEVENT4 0x324
#define CSR_MHPMEVENT5 0x325
#define CSR_MHPMEVENT6 0x326
#define CSR_MHPMEVENT7 0x327
#define CSR_MHPMEVENT8 0x328
#define CSR_MHPMEVENT9 0x329
#define CSR_MHPMEVENT10 0x32a
#define CSR_MHPMEVENT11 0x32b
#define CSR_MHPMEVENT12 0x32c
#define CSR_MHPMEVENT13 0x32d
#define CSR_MHPMEVENT14 0x32e
#define CSR_MHPMEVENT15 0x32f
#define CSR_MHPMEVENT16 0x330
#define CSR_MHPMEVENT17 0x331
#define CSR_MHPMEVENT18 0x332
#define CSR_MHPMEVENT19 0x333
#define CSR_MHPMEVENT20 0x334
#define CSR_MHPMEVENT21 0x335
#define CSR_MHPMEVENT22 0x336
#define CSR_MHPMEVENT23 0x337
#define CSR_MHPMEVENT24 0x338
#define CSR_MHPMEVENT25 0x339
#define CSR_MHPMEVENT26 0x33a
#define CSR_MHPMEVENT27 0x33b
#define CSR_MHPMEVENT28 0x33c
#define CSR_MHPMEVENT29 0x33d
#define CSR_MHPMEVENT30 0x33e
#define CSR_MHPMEVENT31 0x33f
#define CSR_MVENDORID 0xf11
#define CSR_MARCHID 0xf12
#define CSR_MIMPID 0xf13
#define CSR_MHARTID 0xf14
#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82
#define CSR_HPMCOUNTER3H 0xc83
#define CSR_HPMCOUNTER4H 0xc84
#define CSR_HPMCOUNTER5H 0xc85
#define CSR_HPMCOUNTER6H 0xc86
#define CSR_HPMCOUNTER7H 0xc87
#define CSR_HPMCOUNTER8H 0xc88
#define CSR_HPMCOUNTER9H 0xc89
#define CSR_HPMCOUNTER10H 0xc8a
#define CSR_HPMCOUNTER11H 0xc8b
#define CSR_HPMCOUNTER12H 0xc8c
#define CSR_HPMCOUNTER13H 0xc8d
#define CSR_HPMCOUNTER14H 0xc8e
#define CSR_HPMCOUNTER15H 0xc8f
#define CSR_HPMCOUNTER16H 0xc90
#define CSR_HPMCOUNTER17H 0xc91
#define CSR_HPMCOUNTER18H 0xc92
#define CSR_HPMCOUNTER19H 0xc93
#define CSR_HPMCOUNTER20H 0xc94
#define CSR_HPMCOUNTER21H 0xc95
#define CSR_HPMCOUNTER22H 0xc96
#define CSR_HPMCOUNTER23H 0xc97
#define CSR_HPMCOUNTER24H 0xc98
#define CSR_HPMCOUNTER25H 0xc99
#define CSR_HPMCOUNTER26H 0xc9a
#define CSR_HPMCOUNTER27H 0xc9b
#define CSR_HPMCOUNTER28H 0xc9c
#define CSR_HPMCOUNTER29H 0xc9d
#define CSR_HPMCOUNTER30H 0xc9e
#define CSR_HPMCOUNTER31H 0xc9f
#define CSR_MCYCLEH 0xb80
#define CSR_MINSTRETH 0xb82
#define CSR_MHPMCOUNTER3H 0xb83
#define CSR_MHPMCOUNTER4H 0xb84
#define CSR_MHPMCOUNTER5H 0xb85
#define CSR_MHPMCOUNTER6H 0xb86
#define CSR_MHPMCOUNTER7H 0xb87
#define CSR_MHPMCOUNTER8H 0xb88
#define CSR_MHPMCOUNTER9H 0xb89
#define CSR_MHPMCOUNTER10H 0xb8a
#define CSR_MHPMCOUNTER11H 0xb8b
#define CSR_MHPMCOUNTER12H 0xb8c
#define CSR_MHPMCOUNTER13H 0xb8d
#define CSR_MHPMCOUNTER14H 0xb8e
#define CSR_MHPMCOUNTER15H 0xb8f
#define CSR_MHPMCOUNTER16H 0xb90
#define CSR_MHPMCOUNTER17H 0xb91
#define CSR_MHPMCOUNTER18H 0xb92
#define CSR_MHPMCOUNTER19H 0xb93
#define CSR_MHPMCOUNTER20H 0xb94
#define CSR_MHPMCOUNTER21H 0xb95
#define CSR_MHPMCOUNTER22H 0xb96
#define CSR_MHPMCOUNTER23H 0xb97
#define CSR_MHPMCOUNTER24H 0xb98
#define CSR_MHPMCOUNTER25H 0xb99
#define CSR_MHPMCOUNTER26H 0xb9a
#define CSR_MHPMCOUNTER27H 0xb9b
#define CSR_MHPMCOUNTER28H 0xb9c
#define CSR_MHPMCOUNTER29H 0xb9d
#define CSR_MHPMCOUNTER30H 0xb9e
#define CSR_MHPMCOUNTER31H 0xb9f
#define CAUSE_MISALIGNED_FETCH 0x0
#define CAUSE_FETCH_ACCESS 0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_BREAKPOINT 0x3
#define CAUSE_MISALIGNED_LOAD 0x4
#define CAUSE_LOAD_ACCESS 0x5
#define CAUSE_MISALIGNED_STORE 0x6
#define CAUSE_STORE_ACCESS 0x7
#define CAUSE_USER_ECALL 0x8
#define CAUSE_SUPERVISOR_ECALL 0x9
#define CAUSE_HYPERVISOR_ECALL 0xa
#define CAUSE_MACHINE_ECALL 0xb
#define CAUSE_FETCH_PAGE_FAULT 0xc
#define CAUSE_LOAD_PAGE_FAULT 0xd
#define CAUSE_STORE_PAGE_FAULT 0xf
#endif
#ifdef DECLARE_INSN
DECLARE_INSN(beq, MATCH_BEQ, MASK_BEQ)
DECLARE_INSN(bne, MATCH_BNE, MASK_BNE)
DECLARE_INSN(blt, MATCH_BLT, MASK_BLT)
DECLARE_INSN(bge, MATCH_BGE, MASK_BGE)
DECLARE_INSN(bltu, MATCH_BLTU, MASK_BLTU)
DECLARE_INSN(bgeu, MATCH_BGEU, MASK_BGEU)
DECLARE_INSN(jalr, MATCH_JALR, MASK_JALR)
DECLARE_INSN(jal, MATCH_JAL, MASK_JAL)
DECLARE_INSN(lui, MATCH_LUI, MASK_LUI)
DECLARE_INSN(auipc, MATCH_AUIPC, MASK_AUIPC)
DECLARE_INSN(addi, MATCH_ADDI, MASK_ADDI)
DECLARE_INSN(slli, MATCH_SLLI, MASK_SLLI)
DECLARE_INSN(slti, MATCH_SLTI, MASK_SLTI)
DECLARE_INSN(sltiu, MATCH_SLTIU, MASK_SLTIU)
DECLARE_INSN(xori, MATCH_XORI, MASK_XORI)
DECLARE_INSN(srli, MATCH_SRLI, MASK_SRLI)
DECLARE_INSN(srai, MATCH_SRAI, MASK_SRAI)
DECLARE_INSN(ori, MATCH_ORI, MASK_ORI)
DECLARE_INSN(andi, MATCH_ANDI, MASK_ANDI)
DECLARE_INSN(add, MATCH_ADD, MASK_ADD)
DECLARE_INSN(sub, MATCH_SUB, MASK_SUB)
DECLARE_INSN(sll, MATCH_SLL, MASK_SLL)
DECLARE_INSN(slt, MATCH_SLT, MASK_SLT)
DECLARE_INSN(sltu, MATCH_SLTU, MASK_SLTU)
DECLARE_INSN(xor, MATCH_XOR, MASK_XOR)
DECLARE_INSN(srl, MATCH_SRL, MASK_SRL)
DECLARE_INSN(sra, MATCH_SRA, MASK_SRA)
DECLARE_INSN(or, MATCH_OR, MASK_OR)
DECLARE_INSN(and, MATCH_AND, MASK_AND)
DECLARE_INSN(addiw, MATCH_ADDIW, MASK_ADDIW)
DECLARE_INSN(slliw, MATCH_SLLIW, MASK_SLLIW)
DECLARE_INSN(srliw, MATCH_SRLIW, MASK_SRLIW)
DECLARE_INSN(sraiw, MATCH_SRAIW, MASK_SRAIW)
DECLARE_INSN(addw, MATCH_ADDW, MASK_ADDW)
DECLARE_INSN(subw, MATCH_SUBW, MASK_SUBW)
DECLARE_INSN(sllw, MATCH_SLLW, MASK_SLLW)
DECLARE_INSN(srlw, MATCH_SRLW, MASK_SRLW)
DECLARE_INSN(sraw, MATCH_SRAW, MASK_SRAW)
DECLARE_INSN(lb, MATCH_LB, MASK_LB)
DECLARE_INSN(lh, MATCH_LH, MASK_LH)
DECLARE_INSN(lw, MATCH_LW, MASK_LW)
DECLARE_INSN(ld, MATCH_LD, MASK_LD)
DECLARE_INSN(lbu, MATCH_LBU, MASK_LBU)
DECLARE_INSN(lhu, MATCH_LHU, MASK_LHU)
DECLARE_INSN(lwu, MATCH_LWU, MASK_LWU)
DECLARE_INSN(sb, MATCH_SB, MASK_SB)
DECLARE_INSN(sh, MATCH_SH, MASK_SH)
DECLARE_INSN(sw, MATCH_SW, MASK_SW)
DECLARE_INSN(sd, MATCH_SD, MASK_SD)
DECLARE_INSN(fence, MATCH_FENCE, MASK_FENCE)
DECLARE_INSN(fence_i, MATCH_FENCE_I, MASK_FENCE_I)
DECLARE_INSN(mul, MATCH_MUL, MASK_MUL)
DECLARE_INSN(mulh, MATCH_MULH, MASK_MULH)
DECLARE_INSN(mulhsu, MATCH_MULHSU, MASK_MULHSU)
DECLARE_INSN(mulhu, MATCH_MULHU, MASK_MULHU)
DECLARE_INSN(div, MATCH_DIV, MASK_DIV)
DECLARE_INSN(divu, MATCH_DIVU, MASK_DIVU)
DECLARE_INSN(rem, MATCH_REM, MASK_REM)
DECLARE_INSN(remu, MATCH_REMU, MASK_REMU)
DECLARE_INSN(mulw, MATCH_MULW, MASK_MULW)
DECLARE_INSN(divw, MATCH_DIVW, MASK_DIVW)
DECLARE_INSN(divuw, MATCH_DIVUW, MASK_DIVUW)
DECLARE_INSN(remw, MATCH_REMW, MASK_REMW)
DECLARE_INSN(remuw, MATCH_REMUW, MASK_REMUW)
DECLARE_INSN(amoadd_w, MATCH_AMOADD_W, MASK_AMOADD_W)
DECLARE_INSN(amoxor_w, MATCH_AMOXOR_W, MASK_AMOXOR_W)
DECLARE_INSN(amoor_w, MATCH_AMOOR_W, MASK_AMOOR_W)
DECLARE_INSN(amoand_w, MATCH_AMOAND_W, MASK_AMOAND_W)
DECLARE_INSN(amomin_w, MATCH_AMOMIN_W, MASK_AMOMIN_W)
DECLARE_INSN(amomax_w, MATCH_AMOMAX_W, MASK_AMOMAX_W)
DECLARE_INSN(amominu_w, MATCH_AMOMINU_W, MASK_AMOMINU_W)
DECLARE_INSN(amomaxu_w, MATCH_AMOMAXU_W, MASK_AMOMAXU_W)
DECLARE_INSN(amoswap_w, MATCH_AMOSWAP_W, MASK_AMOSWAP_W)
DECLARE_INSN(lr_w, MATCH_LR_W, MASK_LR_W)
DECLARE_INSN(sc_w, MATCH_SC_W, MASK_SC_W)
DECLARE_INSN(amoadd_d, MATCH_AMOADD_D, MASK_AMOADD_D)
DECLARE_INSN(amoxor_d, MATCH_AMOXOR_D, MASK_AMOXOR_D)
DECLARE_INSN(amoor_d, MATCH_AMOOR_D, MASK_AMOOR_D)
DECLARE_INSN(amoand_d, MATCH_AMOAND_D, MASK_AMOAND_D)
DECLARE_INSN(amomin_d, MATCH_AMOMIN_D, MASK_AMOMIN_D)
DECLARE_INSN(amomax_d, MATCH_AMOMAX_D, MASK_AMOMAX_D)
DECLARE_INSN(amominu_d, MATCH_AMOMINU_D, MASK_AMOMINU_D)
DECLARE_INSN(amomaxu_d, MATCH_AMOMAXU_D, MASK_AMOMAXU_D)
DECLARE_INSN(amoswap_d, MATCH_AMOSWAP_D, MASK_AMOSWAP_D)
DECLARE_INSN(lr_d, MATCH_LR_D, MASK_LR_D)
DECLARE_INSN(sc_d, MATCH_SC_D, MASK_SC_D)
DECLARE_INSN(ecall, MATCH_ECALL, MASK_ECALL)
DECLARE_INSN(ebreak, MATCH_EBREAK, MASK_EBREAK)
DECLARE_INSN(uret, MATCH_URET, MASK_URET)
DECLARE_INSN(sret, MATCH_SRET, MASK_SRET)
DECLARE_INSN(mret, MATCH_MRET, MASK_MRET)
DECLARE_INSN(dret, MATCH_DRET, MASK_DRET)
DECLARE_INSN(sfence_vma, MATCH_SFENCE_VMA, MASK_SFENCE_VMA)
DECLARE_INSN(wfi, MATCH_WFI, MASK_WFI)
DECLARE_INSN(csrrw, MATCH_CSRRW, MASK_CSRRW)
DECLARE_INSN(csrrs, MATCH_CSRRS, MASK_CSRRS)
DECLARE_INSN(csrrc, MATCH_CSRRC, MASK_CSRRC)
DECLARE_INSN(csrrwi, MATCH_CSRRWI, MASK_CSRRWI)
DECLARE_INSN(csrrsi, MATCH_CSRRSI, MASK_CSRRSI)
DECLARE_INSN(csrrci, MATCH_CSRRCI, MASK_CSRRCI)
DECLARE_INSN(hfence_vvma, MATCH_HFENCE_VVMA, MASK_HFENCE_VVMA)
DECLARE_INSN(hfence_gvma, MATCH_HFENCE_GVMA, MASK_HFENCE_GVMA)
DECLARE_INSN(fadd_s, MATCH_FADD_S, MASK_FADD_S)
DECLARE_INSN(fsub_s, MATCH_FSUB_S, MASK_FSUB_S)
DECLARE_INSN(fmul_s, MATCH_FMUL_S, MASK_FMUL_S)
DECLARE_INSN(fdiv_s, MATCH_FDIV_S, MASK_FDIV_S)
DECLARE_INSN(fsgnj_s, MATCH_FSGNJ_S, MASK_FSGNJ_S)
DECLARE_INSN(fsgnjn_s, MATCH_FSGNJN_S, MASK_FSGNJN_S)
DECLARE_INSN(fsgnjx_s, MATCH_FSGNJX_S, MASK_FSGNJX_S)
DECLARE_INSN(fmin_s, MATCH_FMIN_S, MASK_FMIN_S)
DECLARE_INSN(fmax_s, MATCH_FMAX_S, MASK_FMAX_S)
DECLARE_INSN(fsqrt_s, MATCH_FSQRT_S, MASK_FSQRT_S)
DECLARE_INSN(fadd_d, MATCH_FADD_D, MASK_FADD_D)
DECLARE_INSN(fsub_d, MATCH_FSUB_D, MASK_FSUB_D)
DECLARE_INSN(fmul_d, MATCH_FMUL_D, MASK_FMUL_D)
DECLARE_INSN(fdiv_d, MATCH_FDIV_D, MASK_FDIV_D)
DECLARE_INSN(fsgnj_d, MATCH_FSGNJ_D, MASK_FSGNJ_D)
DECLARE_INSN(fsgnjn_d, MATCH_FSGNJN_D, MASK_FSGNJN_D)
DECLARE_INSN(fsgnjx_d, MATCH_FSGNJX_D, MASK_FSGNJX_D)
DECLARE_INSN(fmin_d, MATCH_FMIN_D, MASK_FMIN_D)
DECLARE_INSN(fmax_d, MATCH_FMAX_D, MASK_FMAX_D)
DECLARE_INSN(fcvt_s_d, MATCH_FCVT_S_D, MASK_FCVT_S_D)
DECLARE_INSN(fcvt_d_s, MATCH_FCVT_D_S, MASK_FCVT_D_S)
DECLARE_INSN(fsqrt_d, MATCH_FSQRT_D, MASK_FSQRT_D)
DECLARE_INSN(fadd_q, MATCH_FADD_Q, MASK_FADD_Q)
DECLARE_INSN(fsub_q, MATCH_FSUB_Q, MASK_FSUB_Q)
DECLARE_INSN(fmul_q, MATCH_FMUL_Q, MASK_FMUL_Q)
DECLARE_INSN(fdiv_q, MATCH_FDIV_Q, MASK_FDIV_Q)
DECLARE_INSN(fsgnj_q, MATCH_FSGNJ_Q, MASK_FSGNJ_Q)
DECLARE_INSN(fsgnjn_q, MATCH_FSGNJN_Q, MASK_FSGNJN_Q)
DECLARE_INSN(fsgnjx_q, MATCH_FSGNJX_Q, MASK_FSGNJX_Q)
DECLARE_INSN(fmin_q, MATCH_FMIN_Q, MASK_FMIN_Q)
DECLARE_INSN(fmax_q, MATCH_FMAX_Q, MASK_FMAX_Q)
DECLARE_INSN(fcvt_s_q, MATCH_FCVT_S_Q, MASK_FCVT_S_Q)
DECLARE_INSN(fcvt_q_s, MATCH_FCVT_Q_S, MASK_FCVT_Q_S)
DECLARE_INSN(fcvt_d_q, MATCH_FCVT_D_Q, MASK_FCVT_D_Q)
DECLARE_INSN(fcvt_q_d, MATCH_FCVT_Q_D, MASK_FCVT_Q_D)
DECLARE_INSN(fsqrt_q, MATCH_FSQRT_Q, MASK_FSQRT_Q)
DECLARE_INSN(fle_s, MATCH_FLE_S, MASK_FLE_S)
DECLARE_INSN(flt_s, MATCH_FLT_S, MASK_FLT_S)
DECLARE_INSN(feq_s, MATCH_FEQ_S, MASK_FEQ_S)
DECLARE_INSN(fle_d, MATCH_FLE_D, MASK_FLE_D)
DECLARE_INSN(flt_d, MATCH_FLT_D, MASK_FLT_D)
DECLARE_INSN(feq_d, MATCH_FEQ_D, MASK_FEQ_D)
DECLARE_INSN(fle_q, MATCH_FLE_Q, MASK_FLE_Q)
DECLARE_INSN(flt_q, MATCH_FLT_Q, MASK_FLT_Q)
DECLARE_INSN(feq_q, MATCH_FEQ_Q, MASK_FEQ_Q)
DECLARE_INSN(fcvt_w_s, MATCH_FCVT_W_S, MASK_FCVT_W_S)
DECLARE_INSN(fcvt_wu_s, MATCH_FCVT_WU_S, MASK_FCVT_WU_S)
DECLARE_INSN(fcvt_l_s, MATCH_FCVT_L_S, MASK_FCVT_L_S)
DECLARE_INSN(fcvt_lu_s, MATCH_FCVT_LU_S, MASK_FCVT_LU_S)
DECLARE_INSN(fmv_x_w, MATCH_FMV_X_W, MASK_FMV_X_W)
DECLARE_INSN(fclass_s, MATCH_FCLASS_S, MASK_FCLASS_S)
DECLARE_INSN(fcvt_w_d, MATCH_FCVT_W_D, MASK_FCVT_W_D)
DECLARE_INSN(fcvt_wu_d, MATCH_FCVT_WU_D, MASK_FCVT_WU_D)
DECLARE_INSN(fcvt_l_d, MATCH_FCVT_L_D, MASK_FCVT_L_D)
DECLARE_INSN(fcvt_lu_d, MATCH_FCVT_LU_D, MASK_FCVT_LU_D)
DECLARE_INSN(fmv_x_d, MATCH_FMV_X_D, MASK_FMV_X_D)
DECLARE_INSN(fclass_d, MATCH_FCLASS_D, MASK_FCLASS_D)
DECLARE_INSN(fcvt_w_q, MATCH_FCVT_W_Q, MASK_FCVT_W_Q)
DECLARE_INSN(fcvt_wu_q, MATCH_FCVT_WU_Q, MASK_FCVT_WU_Q)
DECLARE_INSN(fcvt_l_q, MATCH_FCVT_L_Q, MASK_FCVT_L_Q)
DECLARE_INSN(fcvt_lu_q, MATCH_FCVT_LU_Q, MASK_FCVT_LU_Q)
DECLARE_INSN(fmv_x_q, MATCH_FMV_X_Q, MASK_FMV_X_Q)
DECLARE_INSN(fclass_q, MATCH_FCLASS_Q, MASK_FCLASS_Q)
DECLARE_INSN(fcvt_s_w, MATCH_FCVT_S_W, MASK_FCVT_S_W)
DECLARE_INSN(fcvt_s_wu, MATCH_FCVT_S_WU, MASK_FCVT_S_WU)
DECLARE_INSN(fcvt_s_l, MATCH_FCVT_S_L, MASK_FCVT_S_L)
DECLARE_INSN(fcvt_s_lu, MATCH_FCVT_S_LU, MASK_FCVT_S_LU)
DECLARE_INSN(fmv_w_x, MATCH_FMV_W_X, MASK_FMV_W_X)
DECLARE_INSN(fcvt_d_w, MATCH_FCVT_D_W, MASK_FCVT_D_W)
DECLARE_INSN(fcvt_d_wu, MATCH_FCVT_D_WU, MASK_FCVT_D_WU)
DECLARE_INSN(fcvt_d_l, MATCH_FCVT_D_L, MASK_FCVT_D_L)
DECLARE_INSN(fcvt_d_lu, MATCH_FCVT_D_LU, MASK_FCVT_D_LU)
DECLARE_INSN(fmv_d_x, MATCH_FMV_D_X, MASK_FMV_D_X)
DECLARE_INSN(fcvt_q_w, MATCH_FCVT_Q_W, MASK_FCVT_Q_W)
DECLARE_INSN(fcvt_q_wu, MATCH_FCVT_Q_WU, MASK_FCVT_Q_WU)
DECLARE_INSN(fcvt_q_l, MATCH_FCVT_Q_L, MASK_FCVT_Q_L)
DECLARE_INSN(fcvt_q_lu, MATCH_FCVT_Q_LU, MASK_FCVT_Q_LU)
DECLARE_INSN(fmv_q_x, MATCH_FMV_Q_X, MASK_FMV_Q_X)
DECLARE_INSN(flw, MATCH_FLW, MASK_FLW)
DECLARE_INSN(fld, MATCH_FLD, MASK_FLD)
DECLARE_INSN(flq, MATCH_FLQ, MASK_FLQ)
DECLARE_INSN(fsw, MATCH_FSW, MASK_FSW)
DECLARE_INSN(fsd, MATCH_FSD, MASK_FSD)
DECLARE_INSN(fsq, MATCH_FSQ, MASK_FSQ)
DECLARE_INSN(fmadd_s, MATCH_FMADD_S, MASK_FMADD_S)
DECLARE_INSN(fmsub_s, MATCH_FMSUB_S, MASK_FMSUB_S)
DECLARE_INSN(fnmsub_s, MATCH_FNMSUB_S, MASK_FNMSUB_S)
DECLARE_INSN(fnmadd_s, MATCH_FNMADD_S, MASK_FNMADD_S)
DECLARE_INSN(fmadd_d, MATCH_FMADD_D, MASK_FMADD_D)
DECLARE_INSN(fmsub_d, MATCH_FMSUB_D, MASK_FMSUB_D)
DECLARE_INSN(fnmsub_d, MATCH_FNMSUB_D, MASK_FNMSUB_D)
DECLARE_INSN(fnmadd_d, MATCH_FNMADD_D, MASK_FNMADD_D)
DECLARE_INSN(fmadd_q, MATCH_FMADD_Q, MASK_FMADD_Q)
DECLARE_INSN(fmsub_q, MATCH_FMSUB_Q, MASK_FMSUB_Q)
DECLARE_INSN(fnmsub_q, MATCH_FNMSUB_Q, MASK_FNMSUB_Q)
DECLARE_INSN(fnmadd_q, MATCH_FNMADD_Q, MASK_FNMADD_Q)
DECLARE_INSN(c_nop, MATCH_C_NOP, MASK_C_NOP)
DECLARE_INSN(c_addi16sp, MATCH_C_ADDI16SP, MASK_C_ADDI16SP)
DECLARE_INSN(c_jr, MATCH_C_JR, MASK_C_JR)
DECLARE_INSN(c_jalr, MATCH_C_JALR, MASK_C_JALR)
DECLARE_INSN(c_ebreak, MATCH_C_EBREAK, MASK_C_EBREAK)
DECLARE_INSN(c_srli_rv32, MATCH_C_SRLI_RV32, MASK_C_SRLI_RV32)
DECLARE_INSN(c_srai_rv32, MATCH_C_SRAI_RV32, MASK_C_SRAI_RV32)
DECLARE_INSN(c_slli_rv32, MATCH_C_SLLI_RV32, MASK_C_SLLI_RV32)
DECLARE_INSN(c_ld, MATCH_C_LD, MASK_C_LD)
DECLARE_INSN(c_sd, MATCH_C_SD, MASK_C_SD)
DECLARE_INSN(c_addiw, MATCH_C_ADDIW, MASK_C_ADDIW)
DECLARE_INSN(c_ldsp, MATCH_C_LDSP, MASK_C_LDSP)
DECLARE_INSN(c_sdsp, MATCH_C_SDSP, MASK_C_SDSP)
DECLARE_INSN(c_lq, MATCH_C_LQ, MASK_C_LQ)
DECLARE_INSN(c_sq, MATCH_C_SQ, MASK_C_SQ)
DECLARE_INSN(c_lqsp, MATCH_C_LQSP, MASK_C_LQSP)
DECLARE_INSN(c_sqsp, MATCH_C_SQSP, MASK_C_SQSP)
DECLARE_INSN(c_addi4spn, MATCH_C_ADDI4SPN, MASK_C_ADDI4SPN)
DECLARE_INSN(c_fld, MATCH_C_FLD, MASK_C_FLD)
DECLARE_INSN(c_lw, MATCH_C_LW, MASK_C_LW)
DECLARE_INSN(c_flw, MATCH_C_FLW, MASK_C_FLW)
DECLARE_INSN(c_fsd, MATCH_C_FSD, MASK_C_FSD)
DECLARE_INSN(c_sw, MATCH_C_SW, MASK_C_SW)
DECLARE_INSN(c_fsw, MATCH_C_FSW, MASK_C_FSW)
DECLARE_INSN(c_addi, MATCH_C_ADDI, MASK_C_ADDI)
DECLARE_INSN(c_jal, MATCH_C_JAL, MASK_C_JAL)
DECLARE_INSN(c_li, MATCH_C_LI, MASK_C_LI)
DECLARE_INSN(c_lui, MATCH_C_LUI, MASK_C_LUI)
DECLARE_INSN(c_srli, MATCH_C_SRLI, MASK_C_SRLI)
DECLARE_INSN(c_srai, MATCH_C_SRAI, MASK_C_SRAI)
DECLARE_INSN(c_andi, MATCH_C_ANDI, MASK_C_ANDI)
DECLARE_INSN(c_sub, MATCH_C_SUB, MASK_C_SUB)
DECLARE_INSN(c_xor, MATCH_C_XOR, MASK_C_XOR)
DECLARE_INSN(c_or, MATCH_C_OR, MASK_C_OR)
DECLARE_INSN(c_and, MATCH_C_AND, MASK_C_AND)
DECLARE_INSN(c_subw, MATCH_C_SUBW, MASK_C_SUBW)
DECLARE_INSN(c_addw, MATCH_C_ADDW, MASK_C_ADDW)
DECLARE_INSN(c_j, MATCH_C_J, MASK_C_J)
DECLARE_INSN(c_beqz, MATCH_C_BEQZ, MASK_C_BEQZ)
DECLARE_INSN(c_bnez, MATCH_C_BNEZ, MASK_C_BNEZ)
DECLARE_INSN(c_slli, MATCH_C_SLLI, MASK_C_SLLI)
DECLARE_INSN(c_fldsp, MATCH_C_FLDSP, MASK_C_FLDSP)
DECLARE_INSN(c_lwsp, MATCH_C_LWSP, MASK_C_LWSP)
DECLARE_INSN(c_flwsp, MATCH_C_FLWSP, MASK_C_FLWSP)
DECLARE_INSN(c_mv, MATCH_C_MV, MASK_C_MV)
DECLARE_INSN(c_add, MATCH_C_ADD, MASK_C_ADD)
DECLARE_INSN(c_fsdsp, MATCH_C_FSDSP, MASK_C_FSDSP)
DECLARE_INSN(c_swsp, MATCH_C_SWSP, MASK_C_SWSP)
DECLARE_INSN(c_fswsp, MATCH_C_FSWSP, MASK_C_FSWSP)
DECLARE_INSN(custom0, MATCH_CUSTOM0, MASK_CUSTOM0)
DECLARE_INSN(custom0_rs1, MATCH_CUSTOM0_RS1, MASK_CUSTOM0_RS1)
DECLARE_INSN(custom0_rs1_rs2, MATCH_CUSTOM0_RS1_RS2, MASK_CUSTOM0_RS1_RS2)
DECLARE_INSN(custom0_rd, MATCH_CUSTOM0_RD, MASK_CUSTOM0_RD)
DECLARE_INSN(custom0_rd_rs1, MATCH_CUSTOM0_RD_RS1, MASK_CUSTOM0_RD_RS1)
DECLARE_INSN(custom0_rd_rs1_rs2, MATCH_CUSTOM0_RD_RS1_RS2, MASK_CUSTOM0_RD_RS1_RS2)
DECLARE_INSN(custom1, MATCH_CUSTOM1, MASK_CUSTOM1)
DECLARE_INSN(custom1_rs1, MATCH_CUSTOM1_RS1, MASK_CUSTOM1_RS1)
DECLARE_INSN(custom1_rs1_rs2, MATCH_CUSTOM1_RS1_RS2, MASK_CUSTOM1_RS1_RS2)
DECLARE_INSN(custom1_rd, MATCH_CUSTOM1_RD, MASK_CUSTOM1_RD)
DECLARE_INSN(custom1_rd_rs1, MATCH_CUSTOM1_RD_RS1, MASK_CUSTOM1_RD_RS1)
DECLARE_INSN(custom1_rd_rs1_rs2, MATCH_CUSTOM1_RD_RS1_RS2, MASK_CUSTOM1_RD_RS1_RS2)
DECLARE_INSN(custom2, MATCH_CUSTOM2, MASK_CUSTOM2)
DECLARE_INSN(custom2_rs1, MATCH_CUSTOM2_RS1, MASK_CUSTOM2_RS1)
DECLARE_INSN(custom2_rs1_rs2, MATCH_CUSTOM2_RS1_RS2, MASK_CUSTOM2_RS1_RS2)
DECLARE_INSN(custom2_rd, MATCH_CUSTOM2_RD, MASK_CUSTOM2_RD)
DECLARE_INSN(custom2_rd_rs1, MATCH_CUSTOM2_RD_RS1, MASK_CUSTOM2_RD_RS1)
DECLARE_INSN(custom2_rd_rs1_rs2, MATCH_CUSTOM2_RD_RS1_RS2, MASK_CUSTOM2_RD_RS1_RS2)
DECLARE_INSN(custom3, MATCH_CUSTOM3, MASK_CUSTOM3)
DECLARE_INSN(custom3_rs1, MATCH_CUSTOM3_RS1, MASK_CUSTOM3_RS1)
DECLARE_INSN(custom3_rs1_rs2, MATCH_CUSTOM3_RS1_RS2, MASK_CUSTOM3_RS1_RS2)
DECLARE_INSN(custom3_rd, MATCH_CUSTOM3_RD, MASK_CUSTOM3_RD)
DECLARE_INSN(custom3_rd_rs1, MATCH_CUSTOM3_RD_RS1, MASK_CUSTOM3_RD_RS1)
DECLARE_INSN(custom3_rd_rs1_rs2, MATCH_CUSTOM3_RD_RS1_RS2, MASK_CUSTOM3_RD_RS1_RS2)
DECLARE_INSN(vsetvli, MATCH_VSETVLI, MASK_VSETVLI)
DECLARE_INSN(vsetvl, MATCH_VSETVL, MASK_VSETVL)
DECLARE_INSN(vlb_v, MATCH_VLB_V, MASK_VLB_V)
DECLARE_INSN(vlh_v, MATCH_VLH_V, MASK_VLH_V)
DECLARE_INSN(vlw_v, MATCH_VLW_V, MASK_VLW_V)
DECLARE_INSN(vle_v, MATCH_VLE_V, MASK_VLE_V)
DECLARE_INSN(vlbu_v, MATCH_VLBU_V, MASK_VLBU_V)
DECLARE_INSN(vlhu_v, MATCH_VLHU_V, MASK_VLHU_V)
DECLARE_INSN(vlwu_v, MATCH_VLWU_V, MASK_VLWU_V)
DECLARE_INSN(vsb_v, MATCH_VSB_V, MASK_VSB_V)
DECLARE_INSN(vsh_v, MATCH_VSH_V, MASK_VSH_V)
DECLARE_INSN(vsw_v, MATCH_VSW_V, MASK_VSW_V)
DECLARE_INSN(vse_v, MATCH_VSE_V, MASK_VSE_V)
DECLARE_INSN(vlsb_v, MATCH_VLSB_V, MASK_VLSB_V)
DECLARE_INSN(vlsh_v, MATCH_VLSH_V, MASK_VLSH_V)
DECLARE_INSN(vlsw_v, MATCH_VLSW_V, MASK_VLSW_V)
DECLARE_INSN(vlse_v, MATCH_VLSE_V, MASK_VLSE_V)
DECLARE_INSN(vlsbu_v, MATCH_VLSBU_V, MASK_VLSBU_V)
DECLARE_INSN(vlshu_v, MATCH_VLSHU_V, MASK_VLSHU_V)
DECLARE_INSN(vlswu_v, MATCH_VLSWU_V, MASK_VLSWU_V)
DECLARE_INSN(vssb_v, MATCH_VSSB_V, MASK_VSSB_V)
DECLARE_INSN(vssh_v, MATCH_VSSH_V, MASK_VSSH_V)
DECLARE_INSN(vssw_v, MATCH_VSSW_V, MASK_VSSW_V)
DECLARE_INSN(vsse_v, MATCH_VSSE_V, MASK_VSSE_V)
DECLARE_INSN(vlxb_v, MATCH_VLXB_V, MASK_VLXB_V)
DECLARE_INSN(vlxh_v, MATCH_VLXH_V, MASK_VLXH_V)
DECLARE_INSN(vlxw_v, MATCH_VLXW_V, MASK_VLXW_V)
DECLARE_INSN(vlxe_v, MATCH_VLXE_V, MASK_VLXE_V)
DECLARE_INSN(vlxbu_v, MATCH_VLXBU_V, MASK_VLXBU_V)
DECLARE_INSN(vlxhu_v, MATCH_VLXHU_V, MASK_VLXHU_V)
DECLARE_INSN(vlxwu_v, MATCH_VLXWU_V, MASK_VLXWU_V)
DECLARE_INSN(vsxb_v, MATCH_VSXB_V, MASK_VSXB_V)
DECLARE_INSN(vsxh_v, MATCH_VSXH_V, MASK_VSXH_V)
DECLARE_INSN(vsxw_v, MATCH_VSXW_V, MASK_VSXW_V)
DECLARE_INSN(vsxe_v, MATCH_VSXE_V, MASK_VSXE_V)
DECLARE_INSN(vsuxb_v, MATCH_VSUXB_V, MASK_VSUXB_V)
DECLARE_INSN(vsuxh_v, MATCH_VSUXH_V, MASK_VSUXH_V)
DECLARE_INSN(vsuxw_v, MATCH_VSUXW_V, MASK_VSUXW_V)
DECLARE_INSN(vsuxe_v, MATCH_VSUXE_V, MASK_VSUXE_V)
DECLARE_INSN(vlbff_v, MATCH_VLBFF_V, MASK_VLBFF_V)
DECLARE_INSN(vlhff_v, MATCH_VLHFF_V, MASK_VLHFF_V)
DECLARE_INSN(vlwff_v, MATCH_VLWFF_V, MASK_VLWFF_V)
DECLARE_INSN(vleff_v, MATCH_VLEFF_V, MASK_VLEFF_V)
DECLARE_INSN(vlbuff_v, MATCH_VLBUFF_V, MASK_VLBUFF_V)
DECLARE_INSN(vlhuff_v, MATCH_VLHUFF_V, MASK_VLHUFF_V)
DECLARE_INSN(vlwuff_v, MATCH_VLWUFF_V, MASK_VLWUFF_V)
DECLARE_INSN(vfadd_vf, MATCH_VFADD_VF, MASK_VFADD_VF)
DECLARE_INSN(vfsub_vf, MATCH_VFSUB_VF, MASK_VFSUB_VF)
DECLARE_INSN(vfmin_vf, MATCH_VFMIN_VF, MASK_VFMIN_VF)
DECLARE_INSN(vfmax_vf, MATCH_VFMAX_VF, MASK_VFMAX_VF)
DECLARE_INSN(vfsgnj_vf, MATCH_VFSGNJ_VF, MASK_VFSGNJ_VF)
DECLARE_INSN(vfsgnjn_vf, MATCH_VFSGNJN_VF, MASK_VFSGNJN_VF)
DECLARE_INSN(vfsgnjx_vf, MATCH_VFSGNJX_VF, MASK_VFSGNJX_VF)
DECLARE_INSN(vfmv_s_f, MATCH_VFMV_S_F, MASK_VFMV_S_F)
DECLARE_INSN(vfmerge_vfm, MATCH_VFMERGE_VFM, MASK_VFMERGE_VFM)
DECLARE_INSN(vfmv_v_f, MATCH_VFMV_V_F, MASK_VFMV_V_F)
DECLARE_INSN(vmfeq_vf, MATCH_VMFEQ_VF, MASK_VMFEQ_VF)
DECLARE_INSN(vmfle_vf, MATCH_VMFLE_VF, MASK_VMFLE_VF)
DECLARE_INSN(vmford_vf, MATCH_VMFORD_VF, MASK_VMFORD_VF)
DECLARE_INSN(vmflt_vf, MATCH_VMFLT_VF, MASK_VMFLT_VF)
DECLARE_INSN(vmfne_vf, MATCH_VMFNE_VF, MASK_VMFNE_VF)
DECLARE_INSN(vmfgt_vf, MATCH_VMFGT_VF, MASK_VMFGT_VF)
DECLARE_INSN(vmfge_vf, MATCH_VMFGE_VF, MASK_VMFGE_VF)
DECLARE_INSN(vfdiv_vf, MATCH_VFDIV_VF, MASK_VFDIV_VF)
DECLARE_INSN(vfrdiv_vf, MATCH_VFRDIV_VF, MASK_VFRDIV_VF)
DECLARE_INSN(vfmul_vf, MATCH_VFMUL_VF, MASK_VFMUL_VF)
DECLARE_INSN(vfrsub_vf, MATCH_VFRSUB_VF, MASK_VFRSUB_VF)
DECLARE_INSN(vfmadd_vf, MATCH_VFMADD_VF, MASK_VFMADD_VF)
DECLARE_INSN(vfnmadd_vf, MATCH_VFNMADD_VF, MASK_VFNMADD_VF)
DECLARE_INSN(vfmsub_vf, MATCH_VFMSUB_VF, MASK_VFMSUB_VF)
DECLARE_INSN(vfnmsub_vf, MATCH_VFNMSUB_VF, MASK_VFNMSUB_VF)
DECLARE_INSN(vfmacc_vf, MATCH_VFMACC_VF, MASK_VFMACC_VF)
DECLARE_INSN(vfnmacc_vf, MATCH_VFNMACC_VF, MASK_VFNMACC_VF)
DECLARE_INSN(vfmsac_vf, MATCH_VFMSAC_VF, MASK_VFMSAC_VF)
DECLARE_INSN(vfnmsac_vf, MATCH_VFNMSAC_VF, MASK_VFNMSAC_VF)
DECLARE_INSN(vfwadd_vf, MATCH_VFWADD_VF, MASK_VFWADD_VF)
DECLARE_INSN(vfwsub_vf, MATCH_VFWSUB_VF, MASK_VFWSUB_VF)
DECLARE_INSN(vfwadd_wf, MATCH_VFWADD_WF, MASK_VFWADD_WF)
DECLARE_INSN(vfwsub_wf, MATCH_VFWSUB_WF, MASK_VFWSUB_WF)
DECLARE_INSN(vfwmul_vf, MATCH_VFWMUL_VF, MASK_VFWMUL_VF)
DECLARE_INSN(vfwmacc_vf, MATCH_VFWMACC_VF, MASK_VFWMACC_VF)
DECLARE_INSN(vfwnmacc_vf, MATCH_VFWNMACC_VF, MASK_VFWNMACC_VF)
DECLARE_INSN(vfwmsac_vf, MATCH_VFWMSAC_VF, MASK_VFWMSAC_VF)
DECLARE_INSN(vfwnmsac_vf, MATCH_VFWNMSAC_VF, MASK_VFWNMSAC_VF)
DECLARE_INSN(vfadd_vv, MATCH_VFADD_VV, MASK_VFADD_VV)
DECLARE_INSN(vfredsum_vs, MATCH_VFREDSUM_VS, MASK_VFREDSUM_VS)
DECLARE_INSN(vfsub_vv, MATCH_VFSUB_VV, MASK_VFSUB_VV)
DECLARE_INSN(vfredosum_vs, MATCH_VFREDOSUM_VS, MASK_VFREDOSUM_VS)
DECLARE_INSN(vfmin_vv, MATCH_VFMIN_VV, MASK_VFMIN_VV)
DECLARE_INSN(vfredmin_vs, MATCH_VFREDMIN_VS, MASK_VFREDMIN_VS)
DECLARE_INSN(vfmax_vv, MATCH_VFMAX_VV, MASK_VFMAX_VV)
DECLARE_INSN(vfredmax_vs, MATCH_VFREDMAX_VS, MASK_VFREDMAX_VS)
DECLARE_INSN(vfsgnj_vv, MATCH_VFSGNJ_VV, MASK_VFSGNJ_VV)
DECLARE_INSN(vfsgnjn_vv, MATCH_VFSGNJN_VV, MASK_VFSGNJN_VV)
DECLARE_INSN(vfsgnjx_vv, MATCH_VFSGNJX_VV, MASK_VFSGNJX_VV)
DECLARE_INSN(vfmv_f_s, MATCH_VFMV_F_S, MASK_VFMV_F_S)
DECLARE_INSN(vmfeq_vv, MATCH_VMFEQ_VV, MASK_VMFEQ_VV)
DECLARE_INSN(vmfle_vv, MATCH_VMFLE_VV, MASK_VMFLE_VV)
DECLARE_INSN(vmford_vv, MATCH_VMFORD_VV, MASK_VMFORD_VV)
DECLARE_INSN(vmflt_vv, MATCH_VMFLT_VV, MASK_VMFLT_VV)
DECLARE_INSN(vmfne_vv, MATCH_VMFNE_VV, MASK_VMFNE_VV)
DECLARE_INSN(vfdiv_vv, MATCH_VFDIV_VV, MASK_VFDIV_VV)
DECLARE_INSN(vfmul_vv, MATCH_VFMUL_VV, MASK_VFMUL_VV)
DECLARE_INSN(vfmadd_vv, MATCH_VFMADD_VV, MASK_VFMADD_VV)
DECLARE_INSN(vfnmadd_vv, MATCH_VFNMADD_VV, MASK_VFNMADD_VV)
DECLARE_INSN(vfmsub_vv, MATCH_VFMSUB_VV, MASK_VFMSUB_VV)
DECLARE_INSN(vfnmsub_vv, MATCH_VFNMSUB_VV, MASK_VFNMSUB_VV)
DECLARE_INSN(vfmacc_vv, MATCH_VFMACC_VV, MASK_VFMACC_VV)
DECLARE_INSN(vfnmacc_vv, MATCH_VFNMACC_VV, MASK_VFNMACC_VV)
DECLARE_INSN(vfmsac_vv, MATCH_VFMSAC_VV, MASK_VFMSAC_VV)
DECLARE_INSN(vfnmsac_vv, MATCH_VFNMSAC_VV, MASK_VFNMSAC_VV)
DECLARE_INSN(vfcvt_xu_f_v, MATCH_VFCVT_XU_F_V, MASK_VFCVT_XU_F_V)
DECLARE_INSN(vfcvt_x_f_v, MATCH_VFCVT_X_F_V, MASK_VFCVT_X_F_V)
DECLARE_INSN(vfcvt_f_xu_v, MATCH_VFCVT_F_XU_V, MASK_VFCVT_F_XU_V)
DECLARE_INSN(vfcvt_f_x_v, MATCH_VFCVT_F_X_V, MASK_VFCVT_F_X_V)
DECLARE_INSN(vfwcvt_xu_f_v, MATCH_VFWCVT_XU_F_V, MASK_VFWCVT_XU_F_V)
DECLARE_INSN(vfwcvt_x_f_v, MATCH_VFWCVT_X_F_V, MASK_VFWCVT_X_F_V)
DECLARE_INSN(vfwcvt_f_xu_v, MATCH_VFWCVT_F_XU_V, MASK_VFWCVT_F_XU_V)
DECLARE_INSN(vfwcvt_f_x_v, MATCH_VFWCVT_F_X_V, MASK_VFWCVT_F_X_V)
DECLARE_INSN(vfwcvt_f_f_v, MATCH_VFWCVT_F_F_V, MASK_VFWCVT_F_F_V)
DECLARE_INSN(vfncvt_xu_f_v, MATCH_VFNCVT_XU_F_V, MASK_VFNCVT_XU_F_V)
DECLARE_INSN(vfncvt_x_f_v, MATCH_VFNCVT_X_F_V, MASK_VFNCVT_X_F_V)
DECLARE_INSN(vfncvt_f_xu_v, MATCH_VFNCVT_F_XU_V, MASK_VFNCVT_F_XU_V)
DECLARE_INSN(vfncvt_f_x_v, MATCH_VFNCVT_F_X_V, MASK_VFNCVT_F_X_V)
DECLARE_INSN(vfncvt_f_f_v, MATCH_VFNCVT_F_F_V, MASK_VFNCVT_F_F_V)
DECLARE_INSN(vfsqrt_v, MATCH_VFSQRT_V, MASK_VFSQRT_V)
DECLARE_INSN(vfclass_v, MATCH_VFCLASS_V, MASK_VFCLASS_V)
DECLARE_INSN(vfwadd_vv, MATCH_VFWADD_VV, MASK_VFWADD_VV)
DECLARE_INSN(vfwredsum_vs, MATCH_VFWREDSUM_VS, MASK_VFWREDSUM_VS)
DECLARE_INSN(vfwsub_vv, MATCH_VFWSUB_VV, MASK_VFWSUB_VV)
DECLARE_INSN(vfwredosum_vs, MATCH_VFWREDOSUM_VS, MASK_VFWREDOSUM_VS)
DECLARE_INSN(vfwadd_wv, MATCH_VFWADD_WV, MASK_VFWADD_WV)
DECLARE_INSN(vfwsub_wv, MATCH_VFWSUB_WV, MASK_VFWSUB_WV)
DECLARE_INSN(vfwmul_vv, MATCH_VFWMUL_VV, MASK_VFWMUL_VV)
DECLARE_INSN(vfdot_vv, MATCH_VFDOT_VV, MASK_VFDOT_VV)
DECLARE_INSN(vfwmacc_vv, MATCH_VFWMACC_VV, MASK_VFWMACC_VV)
DECLARE_INSN(vfwnmacc_vv, MATCH_VFWNMACC_VV, MASK_VFWNMACC_VV)
DECLARE_INSN(vfwmsac_vv, MATCH_VFWMSAC_VV, MASK_VFWMSAC_VV)
DECLARE_INSN(vfwnmsac_vv, MATCH_VFWNMSAC_VV, MASK_VFWNMSAC_VV)
DECLARE_INSN(vadd_vx, MATCH_VADD_VX, MASK_VADD_VX)
DECLARE_INSN(vsub_vx, MATCH_VSUB_VX, MASK_VSUB_VX)
DECLARE_INSN(vrsub_vx, MATCH_VRSUB_VX, MASK_VRSUB_VX)
DECLARE_INSN(vminu_vx, MATCH_VMINU_VX, MASK_VMINU_VX)
DECLARE_INSN(vmin_vx, MATCH_VMIN_VX, MASK_VMIN_VX)
DECLARE_INSN(vmaxu_vx, MATCH_VMAXU_VX, MASK_VMAXU_VX)
DECLARE_INSN(vmax_vx, MATCH_VMAX_VX, MASK_VMAX_VX)
DECLARE_INSN(vand_vx, MATCH_VAND_VX, MASK_VAND_VX)
DECLARE_INSN(vor_vx, MATCH_VOR_VX, MASK_VOR_VX)
DECLARE_INSN(vxor_vx, MATCH_VXOR_VX, MASK_VXOR_VX)
DECLARE_INSN(vrgather_vx, MATCH_VRGATHER_VX, MASK_VRGATHER_VX)
DECLARE_INSN(vslideup_vx, MATCH_VSLIDEUP_VX, MASK_VSLIDEUP_VX)
DECLARE_INSN(vslidedown_vx, MATCH_VSLIDEDOWN_VX, MASK_VSLIDEDOWN_VX)
DECLARE_INSN(vadc_vxm, MATCH_VADC_VXM, MASK_VADC_VXM)
DECLARE_INSN(vmadc_vxm, MATCH_VMADC_VXM, MASK_VMADC_VXM)
DECLARE_INSN(vsbc_vxm, MATCH_VSBC_VXM, MASK_VSBC_VXM)
DECLARE_INSN(vmsbc_vxm, MATCH_VMSBC_VXM, MASK_VMSBC_VXM)
DECLARE_INSN(vmerge_vxm, MATCH_VMERGE_VXM, MASK_VMERGE_VXM)
DECLARE_INSN(vmv_v_x, MATCH_VMV_V_X, MASK_VMV_V_X)
DECLARE_INSN(vmseq_vx, MATCH_VMSEQ_VX, MASK_VMSEQ_VX)
DECLARE_INSN(vmsne_vx, MATCH_VMSNE_VX, MASK_VMSNE_VX)
DECLARE_INSN(vmsltu_vx, MATCH_VMSLTU_VX, MASK_VMSLTU_VX)
DECLARE_INSN(vmslt_vx, MATCH_VMSLT_VX, MASK_VMSLT_VX)
DECLARE_INSN(vmsleu_vx, MATCH_VMSLEU_VX, MASK_VMSLEU_VX)
DECLARE_INSN(vmsle_vx, MATCH_VMSLE_VX, MASK_VMSLE_VX)
DECLARE_INSN(vmsgtu_vx, MATCH_VMSGTU_VX, MASK_VMSGTU_VX)
DECLARE_INSN(vmsgt_vx, MATCH_VMSGT_VX, MASK_VMSGT_VX)
DECLARE_INSN(vsaddu_vx, MATCH_VSADDU_VX, MASK_VSADDU_VX)
DECLARE_INSN(vsadd_vx, MATCH_VSADD_VX, MASK_VSADD_VX)
DECLARE_INSN(vssubu_vx, MATCH_VSSUBU_VX, MASK_VSSUBU_VX)
DECLARE_INSN(vssub_vx, MATCH_VSSUB_VX, MASK_VSSUB_VX)
DECLARE_INSN(vaadd_vx, MATCH_VAADD_VX, MASK_VAADD_VX)
DECLARE_INSN(vsll_vx, MATCH_VSLL_VX, MASK_VSLL_VX)
DECLARE_INSN(vasub_vx, MATCH_VASUB_VX, MASK_VASUB_VX)
DECLARE_INSN(vsmul_vx, MATCH_VSMUL_VX, MASK_VSMUL_VX)
DECLARE_INSN(vsrl_vx, MATCH_VSRL_VX, MASK_VSRL_VX)
DECLARE_INSN(vsra_vx, MATCH_VSRA_VX, MASK_VSRA_VX)
DECLARE_INSN(vssrl_vx, MATCH_VSSRL_VX, MASK_VSSRL_VX)
DECLARE_INSN(vssra_vx, MATCH_VSSRA_VX, MASK_VSSRA_VX)
DECLARE_INSN(vnsrl_vx, MATCH_VNSRL_VX, MASK_VNSRL_VX)
DECLARE_INSN(vnsra_vx, MATCH_VNSRA_VX, MASK_VNSRA_VX)
DECLARE_INSN(vnclipu_vx, MATCH_VNCLIPU_VX, MASK_VNCLIPU_VX)
DECLARE_INSN(vnclip_vx, MATCH_VNCLIP_VX, MASK_VNCLIP_VX)
DECLARE_INSN(vwsmaccu_vx, MATCH_VWSMACCU_VX, MASK_VWSMACCU_VX)
DECLARE_INSN(vwsmacc_vx, MATCH_VWSMACC_VX, MASK_VWSMACC_VX)
DECLARE_INSN(vwsmaccsu_vx, MATCH_VWSMACCSU_VX, MASK_VWSMACCSU_VX)
DECLARE_INSN(vwsmaccus_vx, MATCH_VWSMACCUS_VX, MASK_VWSMACCUS_VX)
DECLARE_INSN(vadd_vv, MATCH_VADD_VV, MASK_VADD_VV)
DECLARE_INSN(vsub_vv, MATCH_VSUB_VV, MASK_VSUB_VV)
DECLARE_INSN(vminu_vv, MATCH_VMINU_VV, MASK_VMINU_VV)
DECLARE_INSN(vmin_vv, MATCH_VMIN_VV, MASK_VMIN_VV)
DECLARE_INSN(vmaxu_vv, MATCH_VMAXU_VV, MASK_VMAXU_VV)
DECLARE_INSN(vmax_vv, MATCH_VMAX_VV, MASK_VMAX_VV)
DECLARE_INSN(vand_vv, MATCH_VAND_VV, MASK_VAND_VV)
DECLARE_INSN(vor_vv, MATCH_VOR_VV, MASK_VOR_VV)
DECLARE_INSN(vxor_vv, MATCH_VXOR_VV, MASK_VXOR_VV)
DECLARE_INSN(vrgather_vv, MATCH_VRGATHER_VV, MASK_VRGATHER_VV)
DECLARE_INSN(vadc_vvm, MATCH_VADC_VVM, MASK_VADC_VVM)
DECLARE_INSN(vmadc_vvm, MATCH_VMADC_VVM, MASK_VMADC_VVM)
DECLARE_INSN(vsbc_vvm, MATCH_VSBC_VVM, MASK_VSBC_VVM)
DECLARE_INSN(vmsbc_vvm, MATCH_VMSBC_VVM, MASK_VMSBC_VVM)
DECLARE_INSN(vmerge_vvm, MATCH_VMERGE_VVM, MASK_VMERGE_VVM)
DECLARE_INSN(vmv_v_v, MATCH_VMV_V_V, MASK_VMV_V_V)
DECLARE_INSN(vmseq_vv, MATCH_VMSEQ_VV, MASK_VMSEQ_VV)
DECLARE_INSN(vmsne_vv, MATCH_VMSNE_VV, MASK_VMSNE_VV)
DECLARE_INSN(vmsltu_vv, MATCH_VMSLTU_VV, MASK_VMSLTU_VV)
DECLARE_INSN(vmslt_vv, MATCH_VMSLT_VV, MASK_VMSLT_VV)
DECLARE_INSN(vmsleu_vv, MATCH_VMSLEU_VV, MASK_VMSLEU_VV)
DECLARE_INSN(vmsle_vv, MATCH_VMSLE_VV, MASK_VMSLE_VV)
DECLARE_INSN(vsaddu_vv, MATCH_VSADDU_VV, MASK_VSADDU_VV)
DECLARE_INSN(vsadd_vv, MATCH_VSADD_VV, MASK_VSADD_VV)
DECLARE_INSN(vssubu_vv, MATCH_VSSUBU_VV, MASK_VSSUBU_VV)
DECLARE_INSN(vssub_vv, MATCH_VSSUB_VV, MASK_VSSUB_VV)
DECLARE_INSN(vaadd_vv, MATCH_VAADD_VV, MASK_VAADD_VV)
DECLARE_INSN(vsll_vv, MATCH_VSLL_VV, MASK_VSLL_VV)
DECLARE_INSN(vasub_vv, MATCH_VASUB_VV, MASK_VASUB_VV)
DECLARE_INSN(vsmul_vv, MATCH_VSMUL_VV, MASK_VSMUL_VV)
DECLARE_INSN(vsrl_vv, MATCH_VSRL_VV, MASK_VSRL_VV)
DECLARE_INSN(vsra_vv, MATCH_VSRA_VV, MASK_VSRA_VV)
DECLARE_INSN(vssrl_vv, MATCH_VSSRL_VV, MASK_VSSRL_VV)
DECLARE_INSN(vssra_vv, MATCH_VSSRA_VV, MASK_VSSRA_VV)
DECLARE_INSN(vnsrl_vv, MATCH_VNSRL_VV, MASK_VNSRL_VV)
DECLARE_INSN(vnsra_vv, MATCH_VNSRA_VV, MASK_VNSRA_VV)
DECLARE_INSN(vnclipu_vv, MATCH_VNCLIPU_VV, MASK_VNCLIPU_VV)
DECLARE_INSN(vnclip_vv, MATCH_VNCLIP_VV, MASK_VNCLIP_VV)
DECLARE_INSN(vwredsumu_vs, MATCH_VWREDSUMU_VS, MASK_VWREDSUMU_VS)
DECLARE_INSN(vwredsum_vs, MATCH_VWREDSUM_VS, MASK_VWREDSUM_VS)
DECLARE_INSN(vdotu_vv, MATCH_VDOTU_VV, MASK_VDOTU_VV)
DECLARE_INSN(vdot_vv, MATCH_VDOT_VV, MASK_VDOT_VV)
DECLARE_INSN(vwsmaccu_vv, MATCH_VWSMACCU_VV, MASK_VWSMACCU_VV)
DECLARE_INSN(vwsmacc_vv, MATCH_VWSMACC_VV, MASK_VWSMACC_VV)
DECLARE_INSN(vwsmaccsu_vv, MATCH_VWSMACCSU_VV, MASK_VWSMACCSU_VV)
DECLARE_INSN(vadd_vi, MATCH_VADD_VI, MASK_VADD_VI)
DECLARE_INSN(vrsub_vi, MATCH_VRSUB_VI, MASK_VRSUB_VI)
DECLARE_INSN(vand_vi, MATCH_VAND_VI, MASK_VAND_VI)
DECLARE_INSN(vor_vi, MATCH_VOR_VI, MASK_VOR_VI)
DECLARE_INSN(vxor_vi, MATCH_VXOR_VI, MASK_VXOR_VI)
DECLARE_INSN(vrgather_vi, MATCH_VRGATHER_VI, MASK_VRGATHER_VI)
DECLARE_INSN(vslideup_vi, MATCH_VSLIDEUP_VI, MASK_VSLIDEUP_VI)
DECLARE_INSN(vslidedown_vi, MATCH_VSLIDEDOWN_VI, MASK_VSLIDEDOWN_VI)
DECLARE_INSN(vadc_vim, MATCH_VADC_VIM, MASK_VADC_VIM)
DECLARE_INSN(vmadc_vim, MATCH_VMADC_VIM, MASK_VMADC_VIM)
DECLARE_INSN(vmerge_vim, MATCH_VMERGE_VIM, MASK_VMERGE_VIM)
DECLARE_INSN(vmv_v_i, MATCH_VMV_V_I, MASK_VMV_V_I)
DECLARE_INSN(vmseq_vi, MATCH_VMSEQ_VI, MASK_VMSEQ_VI)
DECLARE_INSN(vmsne_vi, MATCH_VMSNE_VI, MASK_VMSNE_VI)
DECLARE_INSN(vmsleu_vi, MATCH_VMSLEU_VI, MASK_VMSLEU_VI)
DECLARE_INSN(vmsle_vi, MATCH_VMSLE_VI, MASK_VMSLE_VI)
DECLARE_INSN(vmsgtu_vi, MATCH_VMSGTU_VI, MASK_VMSGTU_VI)
DECLARE_INSN(vmsgt_vi, MATCH_VMSGT_VI, MASK_VMSGT_VI)
DECLARE_INSN(vsaddu_vi, MATCH_VSADDU_VI, MASK_VSADDU_VI)
DECLARE_INSN(vsadd_vi, MATCH_VSADD_VI, MASK_VSADD_VI)
DECLARE_INSN(vaadd_vi, MATCH_VAADD_VI, MASK_VAADD_VI)
DECLARE_INSN(vsll_vi, MATCH_VSLL_VI, MASK_VSLL_VI)
DECLARE_INSN(vsrl_vi, MATCH_VSRL_VI, MASK_VSRL_VI)
DECLARE_INSN(vsra_vi, MATCH_VSRA_VI, MASK_VSRA_VI)
DECLARE_INSN(vssrl_vi, MATCH_VSSRL_VI, MASK_VSSRL_VI)
DECLARE_INSN(vssra_vi, MATCH_VSSRA_VI, MASK_VSSRA_VI)
DECLARE_INSN(vnsrl_vi, MATCH_VNSRL_VI, MASK_VNSRL_VI)
DECLARE_INSN(vnsra_vi, MATCH_VNSRA_VI, MASK_VNSRA_VI)
DECLARE_INSN(vnclipu_vi, MATCH_VNCLIPU_VI, MASK_VNCLIPU_VI)
DECLARE_INSN(vnclip_vi, MATCH_VNCLIP_VI, MASK_VNCLIP_VI)
DECLARE_INSN(vredsum_vs, MATCH_VREDSUM_VS, MASK_VREDSUM_VS)
DECLARE_INSN(vredand_vs, MATCH_VREDAND_VS, MASK_VREDAND_VS)
DECLARE_INSN(vredor_vs, MATCH_VREDOR_VS, MASK_VREDOR_VS)
DECLARE_INSN(vredxor_vs, MATCH_VREDXOR_VS, MASK_VREDXOR_VS)
DECLARE_INSN(vredminu_vs, MATCH_VREDMINU_VS, MASK_VREDMINU_VS)
DECLARE_INSN(vredmin_vs, MATCH_VREDMIN_VS, MASK_VREDMIN_VS)
DECLARE_INSN(vredmaxu_vs, MATCH_VREDMAXU_VS, MASK_VREDMAXU_VS)
DECLARE_INSN(vredmax_vs, MATCH_VREDMAX_VS, MASK_VREDMAX_VS)
DECLARE_INSN(vmv_x_s, MATCH_VMV_X_S, MASK_VMV_X_S)
DECLARE_INSN(vcompress_vm, MATCH_VCOMPRESS_VM, MASK_VCOMPRESS_VM)
DECLARE_INSN(vmandnot_mm, MATCH_VMANDNOT_MM, MASK_VMANDNOT_MM)
DECLARE_INSN(vmand_mm, MATCH_VMAND_MM, MASK_VMAND_MM)
DECLARE_INSN(vmor_mm, MATCH_VMOR_MM, MASK_VMOR_MM)
DECLARE_INSN(vmxor_mm, MATCH_VMXOR_MM, MASK_VMXOR_MM)
DECLARE_INSN(vmornot_mm, MATCH_VMORNOT_MM, MASK_VMORNOT_MM)
DECLARE_INSN(vmnand_mm, MATCH_VMNAND_MM, MASK_VMNAND_MM)
DECLARE_INSN(vmnor_mm, MATCH_VMNOR_MM, MASK_VMNOR_MM)
DECLARE_INSN(vmxnor_mm, MATCH_VMXNOR_MM, MASK_VMXNOR_MM)
DECLARE_INSN(vmsbf_m, MATCH_VMSBF_M, MASK_VMSBF_M)
DECLARE_INSN(vmsof_m, MATCH_VMSOF_M, MASK_VMSOF_M)
DECLARE_INSN(vmsif_m, MATCH_VMSIF_M, MASK_VMSIF_M)
DECLARE_INSN(viota_m, MATCH_VIOTA_M, MASK_VIOTA_M)
DECLARE_INSN(vid_v, MATCH_VID_V, MASK_VID_V)
DECLARE_INSN(vpopc_m, MATCH_VPOPC_M, MASK_VPOPC_M)
DECLARE_INSN(vfirst_m, MATCH_VFIRST_M, MASK_VFIRST_M)
DECLARE_INSN(vdivu_vv, MATCH_VDIVU_VV, MASK_VDIVU_VV)
DECLARE_INSN(vdiv_vv, MATCH_VDIV_VV, MASK_VDIV_VV)
DECLARE_INSN(vremu_vv, MATCH_VREMU_VV, MASK_VREMU_VV)
DECLARE_INSN(vrem_vv, MATCH_VREM_VV, MASK_VREM_VV)
DECLARE_INSN(vmulhu_vv, MATCH_VMULHU_VV, MASK_VMULHU_VV)
DECLARE_INSN(vmul_vv, MATCH_VMUL_VV, MASK_VMUL_VV)
DECLARE_INSN(vmulhsu_vv, MATCH_VMULHSU_VV, MASK_VMULHSU_VV)
DECLARE_INSN(vmulh_vv, MATCH_VMULH_VV, MASK_VMULH_VV)
DECLARE_INSN(vmadd_vv, MATCH_VMADD_VV, MASK_VMADD_VV)
DECLARE_INSN(vnmsub_vv, MATCH_VNMSUB_VV, MASK_VNMSUB_VV)
DECLARE_INSN(vmacc_vv, MATCH_VMACC_VV, MASK_VMACC_VV)
DECLARE_INSN(vnmsac_vv, MATCH_VNMSAC_VV, MASK_VNMSAC_VV)
DECLARE_INSN(vwaddu_vv, MATCH_VWADDU_VV, MASK_VWADDU_VV)
DECLARE_INSN(vwadd_vv, MATCH_VWADD_VV, MASK_VWADD_VV)
DECLARE_INSN(vwsubu_vv, MATCH_VWSUBU_VV, MASK_VWSUBU_VV)
DECLARE_INSN(vwsub_vv, MATCH_VWSUB_VV, MASK_VWSUB_VV)
DECLARE_INSN(vwaddu_wv, MATCH_VWADDU_WV, MASK_VWADDU_WV)
DECLARE_INSN(vwadd_wv, MATCH_VWADD_WV, MASK_VWADD_WV)
DECLARE_INSN(vwsubu_wv, MATCH_VWSUBU_WV, MASK_VWSUBU_WV)
DECLARE_INSN(vwsub_wv, MATCH_VWSUB_WV, MASK_VWSUB_WV)
DECLARE_INSN(vwmulu_vv, MATCH_VWMULU_VV, MASK_VWMULU_VV)
DECLARE_INSN(vwmulsu_vv, MATCH_VWMULSU_VV, MASK_VWMULSU_VV)
DECLARE_INSN(vwmul_vv, MATCH_VWMUL_VV, MASK_VWMUL_VV)
DECLARE_INSN(vwmaccu_vv, MATCH_VWMACCU_VV, MASK_VWMACCU_VV)
DECLARE_INSN(vwmacc_vv, MATCH_VWMACC_VV, MASK_VWMACC_VV)
DECLARE_INSN(vwmaccsu_vv, MATCH_VWMACCSU_VV, MASK_VWMACCSU_VV)
DECLARE_INSN(vmv_s_x, MATCH_VMV_S_X, MASK_VMV_S_X)
DECLARE_INSN(vslide1up_vx, MATCH_VSLIDE1UP_VX, MASK_VSLIDE1UP_VX)
DECLARE_INSN(vslide1down_vx, MATCH_VSLIDE1DOWN_VX, MASK_VSLIDE1DOWN_VX)
DECLARE_INSN(vdivu_vx, MATCH_VDIVU_VX, MASK_VDIVU_VX)
DECLARE_INSN(vdiv_vx, MATCH_VDIV_VX, MASK_VDIV_VX)
DECLARE_INSN(vremu_vx, MATCH_VREMU_VX, MASK_VREMU_VX)
DECLARE_INSN(vrem_vx, MATCH_VREM_VX, MASK_VREM_VX)
DECLARE_INSN(vmulhu_vx, MATCH_VMULHU_VX, MASK_VMULHU_VX)
DECLARE_INSN(vmul_vx, MATCH_VMUL_VX, MASK_VMUL_VX)
DECLARE_INSN(vmulhsu_vx, MATCH_VMULHSU_VX, MASK_VMULHSU_VX)
DECLARE_INSN(vmulh_vx, MATCH_VMULH_VX, MASK_VMULH_VX)
DECLARE_INSN(vmadd_vx, MATCH_VMADD_VX, MASK_VMADD_VX)
DECLARE_INSN(vnmsub_vx, MATCH_VNMSUB_VX, MASK_VNMSUB_VX)
DECLARE_INSN(vmacc_vx, MATCH_VMACC_VX, MASK_VMACC_VX)
DECLARE_INSN(vnmsac_vx, MATCH_VNMSAC_VX, MASK_VNMSAC_VX)
DECLARE_INSN(vwaddu_vx, MATCH_VWADDU_VX, MASK_VWADDU_VX)
DECLARE_INSN(vwadd_vx, MATCH_VWADD_VX, MASK_VWADD_VX)
DECLARE_INSN(vwsubu_vx, MATCH_VWSUBU_VX, MASK_VWSUBU_VX)
DECLARE_INSN(vwsub_vx, MATCH_VWSUB_VX, MASK_VWSUB_VX)
DECLARE_INSN(vwaddu_wx, MATCH_VWADDU_WX, MASK_VWADDU_WX)
DECLARE_INSN(vwadd_wx, MATCH_VWADD_WX, MASK_VWADD_WX)
DECLARE_INSN(vwsubu_wx, MATCH_VWSUBU_WX, MASK_VWSUBU_WX)
DECLARE_INSN(vwsub_wx, MATCH_VWSUB_WX, MASK_VWSUB_WX)
DECLARE_INSN(vwmulu_vx, MATCH_VWMULU_VX, MASK_VWMULU_VX)
DECLARE_INSN(vwmulsu_vx, MATCH_VWMULSU_VX, MASK_VWMULSU_VX)
DECLARE_INSN(vwmul_vx, MATCH_VWMUL_VX, MASK_VWMUL_VX)
DECLARE_INSN(vwmaccu_vx, MATCH_VWMACCU_VX, MASK_VWMACCU_VX)
DECLARE_INSN(vwmacc_vx, MATCH_VWMACC_VX, MASK_VWMACC_VX)
DECLARE_INSN(vwmaccsu_vx, MATCH_VWMACCSU_VX, MASK_VWMACCSU_VX)
DECLARE_INSN(vwmaccus_vx, MATCH_VWMACCUS_VX, MASK_VWMACCUS_VX)
DECLARE_INSN(vamoswapw_v, MATCH_VAMOSWAPW_V, MASK_VAMOSWAPW_V)
DECLARE_INSN(vamoaddw_v, MATCH_VAMOADDW_V, MASK_VAMOADDW_V)
DECLARE_INSN(vamoxorw_v, MATCH_VAMOXORW_V, MASK_VAMOXORW_V)
DECLARE_INSN(vamoandw_v, MATCH_VAMOANDW_V, MASK_VAMOANDW_V)
DECLARE_INSN(vamoorw_v, MATCH_VAMOORW_V, MASK_VAMOORW_V)
DECLARE_INSN(vamominw_v, MATCH_VAMOMINW_V, MASK_VAMOMINW_V)
DECLARE_INSN(vamomaxw_v, MATCH_VAMOMAXW_V, MASK_VAMOMAXW_V)
DECLARE_INSN(vamominuw_v, MATCH_VAMOMINUW_V, MASK_VAMOMINUW_V)
DECLARE_INSN(vamomaxuw_v, MATCH_VAMOMAXUW_V, MASK_VAMOMAXUW_V)
DECLARE_INSN(vamoswapd_v, MATCH_VAMOSWAPD_V, MASK_VAMOSWAPD_V)
DECLARE_INSN(vamoaddd_v, MATCH_VAMOADDD_V, MASK_VAMOADDD_V)
DECLARE_INSN(vamoxord_v, MATCH_VAMOXORD_V, MASK_VAMOXORD_V)
DECLARE_INSN(vamoandd_v, MATCH_VAMOANDD_V, MASK_VAMOANDD_V)
DECLARE_INSN(vamoord_v, MATCH_VAMOORD_V, MASK_VAMOORD_V)
DECLARE_INSN(vamomind_v, MATCH_VAMOMIND_V, MASK_VAMOMIND_V)
DECLARE_INSN(vamomaxd_v, MATCH_VAMOMAXD_V, MASK_VAMOMAXD_V)
DECLARE_INSN(vamominud_v, MATCH_VAMOMINUD_V, MASK_VAMOMINUD_V)
DECLARE_INSN(vamomaxud_v, MATCH_VAMOMAXUD_V, MASK_VAMOMAXUD_V)
DECLARE_INSN(vamoswapq_v, MATCH_VAMOSWAPQ_V, MASK_VAMOSWAPQ_V)
DECLARE_INSN(vamoaddq_v, MATCH_VAMOADDQ_V, MASK_VAMOADDQ_V)
DECLARE_INSN(vamoxorq_v, MATCH_VAMOXORQ_V, MASK_VAMOXORQ_V)
DECLARE_INSN(vamoandq_v, MATCH_VAMOANDQ_V, MASK_VAMOANDQ_V)
DECLARE_INSN(vamoorq_v, MATCH_VAMOORQ_V, MASK_VAMOORQ_V)
DECLARE_INSN(vamominq_v, MATCH_VAMOMINQ_V, MASK_VAMOMINQ_V)
DECLARE_INSN(vamomaxq_v, MATCH_VAMOMAXQ_V, MASK_VAMOMAXQ_V)
DECLARE_INSN(vamominuq_v, MATCH_VAMOMINUQ_V, MASK_VAMOMINUQ_V)
DECLARE_INSN(vamomaxuq_v, MATCH_VAMOMAXUQ_V, MASK_VAMOMAXUQ_V)
#endif
#ifdef DECLARE_CSR
DECLARE_CSR(fflags, CSR_FFLAGS)
DECLARE_CSR(frm, CSR_FRM)
DECLARE_CSR(fcsr, CSR_FCSR)
DECLARE_CSR(ustatus, CSR_USTATUS)
DECLARE_CSR(uie, CSR_UIE)
DECLARE_CSR(utvec, CSR_UTVEC)
DECLARE_CSR(vstart, CSR_VSTART)
DECLARE_CSR(vxsat, CSR_VXSAT)
DECLARE_CSR(vxrm, CSR_VXRM)
DECLARE_CSR(uscratch, CSR_USCRATCH)
DECLARE_CSR(uepc, CSR_UEPC)
DECLARE_CSR(ucause, CSR_UCAUSE)
DECLARE_CSR(utval, CSR_UTVAL)
DECLARE_CSR(uip, CSR_UIP)
DECLARE_CSR(cycle, CSR_CYCLE)
DECLARE_CSR(time, CSR_TIME)
DECLARE_CSR(instret, CSR_INSTRET)
DECLARE_CSR(hpmcounter3, CSR_HPMCOUNTER3)
DECLARE_CSR(hpmcounter4, CSR_HPMCOUNTER4)
DECLARE_CSR(hpmcounter5, CSR_HPMCOUNTER5)
DECLARE_CSR(hpmcounter6, CSR_HPMCOUNTER6)
DECLARE_CSR(hpmcounter7, CSR_HPMCOUNTER7)
DECLARE_CSR(hpmcounter8, CSR_HPMCOUNTER8)
DECLARE_CSR(hpmcounter9, CSR_HPMCOUNTER9)
DECLARE_CSR(hpmcounter10, CSR_HPMCOUNTER10)
DECLARE_CSR(hpmcounter11, CSR_HPMCOUNTER11)
DECLARE_CSR(hpmcounter12, CSR_HPMCOUNTER12)
DECLARE_CSR(hpmcounter13, CSR_HPMCOUNTER13)
DECLARE_CSR(hpmcounter14, CSR_HPMCOUNTER14)
DECLARE_CSR(hpmcounter15, CSR_HPMCOUNTER15)
DECLARE_CSR(hpmcounter16, CSR_HPMCOUNTER16)
DECLARE_CSR(hpmcounter17, CSR_HPMCOUNTER17)
DECLARE_CSR(hpmcounter18, CSR_HPMCOUNTER18)
DECLARE_CSR(hpmcounter19, CSR_HPMCOUNTER19)
DECLARE_CSR(hpmcounter20, CSR_HPMCOUNTER20)
DECLARE_CSR(hpmcounter21, CSR_HPMCOUNTER21)
DECLARE_CSR(hpmcounter22, CSR_HPMCOUNTER22)
DECLARE_CSR(hpmcounter23, CSR_HPMCOUNTER23)
DECLARE_CSR(hpmcounter24, CSR_HPMCOUNTER24)
DECLARE_CSR(hpmcounter25, CSR_HPMCOUNTER25)
DECLARE_CSR(hpmcounter26, CSR_HPMCOUNTER26)
DECLARE_CSR(hpmcounter27, CSR_HPMCOUNTER27)
DECLARE_CSR(hpmcounter28, CSR_HPMCOUNTER28)
DECLARE_CSR(hpmcounter29, CSR_HPMCOUNTER29)
DECLARE_CSR(hpmcounter30, CSR_HPMCOUNTER30)
DECLARE_CSR(hpmcounter31, CSR_HPMCOUNTER31)
DECLARE_CSR(vl, CSR_VL)
DECLARE_CSR(vtype, CSR_VTYPE)
DECLARE_CSR(sstatus, CSR_SSTATUS)
DECLARE_CSR(sie, CSR_SIE)
DECLARE_CSR(stvec, CSR_STVEC)
DECLARE_CSR(scounteren, CSR_SCOUNTEREN)
DECLARE_CSR(sscratch, CSR_SSCRATCH)
DECLARE_CSR(sepc, CSR_SEPC)
DECLARE_CSR(scause, CSR_SCAUSE)
DECLARE_CSR(stval, CSR_STVAL)
DECLARE_CSR(sip, CSR_SIP)
DECLARE_CSR(satp, CSR_SATP)
DECLARE_CSR(vsstatus, CSR_VSSTATUS)
DECLARE_CSR(vsie, CSR_VSIE)
DECLARE_CSR(vstvec, CSR_VSTVEC)
DECLARE_CSR(vsscratch, CSR_VSSCRATCH)
DECLARE_CSR(vsepc, CSR_VSEPC)
DECLARE_CSR(vscause, CSR_VSCAUSE)
DECLARE_CSR(vstval, CSR_VSTVAL)
DECLARE_CSR(vsip, CSR_VSIP)
DECLARE_CSR(vsatp, CSR_VSATP)
DECLARE_CSR(hstatus, CSR_HSTATUS)
DECLARE_CSR(hedeleg, CSR_HEDELEG)
DECLARE_CSR(hideleg, CSR_HIDELEG)
DECLARE_CSR(hcounteren, CSR_HCOUNTEREN)
DECLARE_CSR(hgatp, CSR_HGATP)
DECLARE_CSR(utvt, CSR_UTVT)
DECLARE_CSR(unxti, CSR_UNXTI)
DECLARE_CSR(uintstatus, CSR_UINTSTATUS)
DECLARE_CSR(uscratchcsw, CSR_USCRATCHCSW)
DECLARE_CSR(uscratchcswl, CSR_USCRATCHCSWL)
DECLARE_CSR(stvt, CSR_STVT)
DECLARE_CSR(snxti, CSR_SNXTI)
DECLARE_CSR(sintstatus, CSR_SINTSTATUS)
DECLARE_CSR(sscratchcsw, CSR_SSCRATCHCSW)
DECLARE_CSR(sscratchcswl, CSR_SSCRATCHCSWL)
DECLARE_CSR(mtvt, CSR_MTVT)
DECLARE_CSR(mnxti, CSR_MNXTI)
DECLARE_CSR(mintstatus, CSR_MINTSTATUS)
DECLARE_CSR(mscratchcsw, CSR_MSCRATCHCSW)
DECLARE_CSR(mscratchcswl, CSR_MSCRATCHCSWL)
DECLARE_CSR(mstatus, CSR_MSTATUS)
DECLARE_CSR(misa, CSR_MISA)
DECLARE_CSR(medeleg, CSR_MEDELEG)
DECLARE_CSR(mideleg, CSR_MIDELEG)
DECLARE_CSR(mie, CSR_MIE)
DECLARE_CSR(mtvec, CSR_MTVEC)
DECLARE_CSR(mcounteren, CSR_MCOUNTEREN)
DECLARE_CSR(mscratch, CSR_MSCRATCH)
DECLARE_CSR(mepc, CSR_MEPC)
DECLARE_CSR(mcause, CSR_MCAUSE)
DECLARE_CSR(mtval, CSR_MTVAL)
DECLARE_CSR(mip, CSR_MIP)
DECLARE_CSR(pmpcfg0, CSR_PMPCFG0)
DECLARE_CSR(pmpcfg1, CSR_PMPCFG1)
DECLARE_CSR(pmpcfg2, CSR_PMPCFG2)
DECLARE_CSR(pmpcfg3, CSR_PMPCFG3)
DECLARE_CSR(pmpaddr0, CSR_PMPADDR0)
DECLARE_CSR(pmpaddr1, CSR_PMPADDR1)
DECLARE_CSR(pmpaddr2, CSR_PMPADDR2)
DECLARE_CSR(pmpaddr3, CSR_PMPADDR3)
DECLARE_CSR(pmpaddr4, CSR_PMPADDR4)
DECLARE_CSR(pmpaddr5, CSR_PMPADDR5)
DECLARE_CSR(pmpaddr6, CSR_PMPADDR6)
DECLARE_CSR(pmpaddr7, CSR_PMPADDR7)
DECLARE_CSR(pmpaddr8, CSR_PMPADDR8)
DECLARE_CSR(pmpaddr9, CSR_PMPADDR9)
DECLARE_CSR(pmpaddr10, CSR_PMPADDR10)
DECLARE_CSR(pmpaddr11, CSR_PMPADDR11)
DECLARE_CSR(pmpaddr12, CSR_PMPADDR12)
DECLARE_CSR(pmpaddr13, CSR_PMPADDR13)
DECLARE_CSR(pmpaddr14, CSR_PMPADDR14)
DECLARE_CSR(pmpaddr15, CSR_PMPADDR15)
DECLARE_CSR(tselect, CSR_TSELECT)
DECLARE_CSR(tdata1, CSR_TDATA1)
DECLARE_CSR(tdata2, CSR_TDATA2)
DECLARE_CSR(tdata3, CSR_TDATA3)
DECLARE_CSR(dcsr, CSR_DCSR)
DECLARE_CSR(dpc, CSR_DPC)
DECLARE_CSR(dscratch, CSR_DSCRATCH)
DECLARE_CSR(mcycle, CSR_MCYCLE)
DECLARE_CSR(minstret, CSR_MINSTRET)
DECLARE_CSR(mhpmcounter3, CSR_MHPMCOUNTER3)
DECLARE_CSR(mhpmcounter4, CSR_MHPMCOUNTER4)
DECLARE_CSR(mhpmcounter5, CSR_MHPMCOUNTER5)
DECLARE_CSR(mhpmcounter6, CSR_MHPMCOUNTER6)
DECLARE_CSR(mhpmcounter7, CSR_MHPMCOUNTER7)
DECLARE_CSR(mhpmcounter8, CSR_MHPMCOUNTER8)
DECLARE_CSR(mhpmcounter9, CSR_MHPMCOUNTER9)
DECLARE_CSR(mhpmcounter10, CSR_MHPMCOUNTER10)
DECLARE_CSR(mhpmcounter11, CSR_MHPMCOUNTER11)
DECLARE_CSR(mhpmcounter12, CSR_MHPMCOUNTER12)
DECLARE_CSR(mhpmcounter13, CSR_MHPMCOUNTER13)
DECLARE_CSR(mhpmcounter14, CSR_MHPMCOUNTER14)
DECLARE_CSR(mhpmcounter15, CSR_MHPMCOUNTER15)
DECLARE_CSR(mhpmcounter16, CSR_MHPMCOUNTER16)
DECLARE_CSR(mhpmcounter17, CSR_MHPMCOUNTER17)
DECLARE_CSR(mhpmcounter18, CSR_MHPMCOUNTER18)
DECLARE_CSR(mhpmcounter19, CSR_MHPMCOUNTER19)
DECLARE_CSR(mhpmcounter20, CSR_MHPMCOUNTER20)
DECLARE_CSR(mhpmcounter21, CSR_MHPMCOUNTER21)
DECLARE_CSR(mhpmcounter22, CSR_MHPMCOUNTER22)
DECLARE_CSR(mhpmcounter23, CSR_MHPMCOUNTER23)
DECLARE_CSR(mhpmcounter24, CSR_MHPMCOUNTER24)
DECLARE_CSR(mhpmcounter25, CSR_MHPMCOUNTER25)
DECLARE_CSR(mhpmcounter26, CSR_MHPMCOUNTER26)
DECLARE_CSR(mhpmcounter27, CSR_MHPMCOUNTER27)
DECLARE_CSR(mhpmcounter28, CSR_MHPMCOUNTER28)
DECLARE_CSR(mhpmcounter29, CSR_MHPMCOUNTER29)
DECLARE_CSR(mhpmcounter30, CSR_MHPMCOUNTER30)
DECLARE_CSR(mhpmcounter31, CSR_MHPMCOUNTER31)
DECLARE_CSR(mhpmevent3, CSR_MHPMEVENT3)
DECLARE_CSR(mhpmevent4, CSR_MHPMEVENT4)
DECLARE_CSR(mhpmevent5, CSR_MHPMEVENT5)
DECLARE_CSR(mhpmevent6, CSR_MHPMEVENT6)
DECLARE_CSR(mhpmevent7, CSR_MHPMEVENT7)
DECLARE_CSR(mhpmevent8, CSR_MHPMEVENT8)
DECLARE_CSR(mhpmevent9, CSR_MHPMEVENT9)
DECLARE_CSR(mhpmevent10, CSR_MHPMEVENT10)
DECLARE_CSR(mhpmevent11, CSR_MHPMEVENT11)
DECLARE_CSR(mhpmevent12, CSR_MHPMEVENT12)
DECLARE_CSR(mhpmevent13, CSR_MHPMEVENT13)
DECLARE_CSR(mhpmevent14, CSR_MHPMEVENT14)
DECLARE_CSR(mhpmevent15, CSR_MHPMEVENT15)
DECLARE_CSR(mhpmevent16, CSR_MHPMEVENT16)
DECLARE_CSR(mhpmevent17, CSR_MHPMEVENT17)
DECLARE_CSR(mhpmevent18, CSR_MHPMEVENT18)
DECLARE_CSR(mhpmevent19, CSR_MHPMEVENT19)
DECLARE_CSR(mhpmevent20, CSR_MHPMEVENT20)
DECLARE_CSR(mhpmevent21, CSR_MHPMEVENT21)
DECLARE_CSR(mhpmevent22, CSR_MHPMEVENT22)
DECLARE_CSR(mhpmevent23, CSR_MHPMEVENT23)
DECLARE_CSR(mhpmevent24, CSR_MHPMEVENT24)
DECLARE_CSR(mhpmevent25, CSR_MHPMEVENT25)
DECLARE_CSR(mhpmevent26, CSR_MHPMEVENT26)
DECLARE_CSR(mhpmevent27, CSR_MHPMEVENT27)
DECLARE_CSR(mhpmevent28, CSR_MHPMEVENT28)
DECLARE_CSR(mhpmevent29, CSR_MHPMEVENT29)
DECLARE_CSR(mhpmevent30, CSR_MHPMEVENT30)
DECLARE_CSR(mhpmevent31, CSR_MHPMEVENT31)
DECLARE_CSR(mvendorid, CSR_MVENDORID)
DECLARE_CSR(marchid, CSR_MARCHID)
DECLARE_CSR(mimpid, CSR_MIMPID)
DECLARE_CSR(mhartid, CSR_MHARTID)
DECLARE_CSR(cycleh, CSR_CYCLEH)
DECLARE_CSR(timeh, CSR_TIMEH)
DECLARE_CSR(instreth, CSR_INSTRETH)
DECLARE_CSR(hpmcounter3h, CSR_HPMCOUNTER3H)
DECLARE_CSR(hpmcounter4h, CSR_HPMCOUNTER4H)
DECLARE_CSR(hpmcounter5h, CSR_HPMCOUNTER5H)
DECLARE_CSR(hpmcounter6h, CSR_HPMCOUNTER6H)
DECLARE_CSR(hpmcounter7h, CSR_HPMCOUNTER7H)
DECLARE_CSR(hpmcounter8h, CSR_HPMCOUNTER8H)
DECLARE_CSR(hpmcounter9h, CSR_HPMCOUNTER9H)
DECLARE_CSR(hpmcounter10h, CSR_HPMCOUNTER10H)
DECLARE_CSR(hpmcounter11h, CSR_HPMCOUNTER11H)
DECLARE_CSR(hpmcounter12h, CSR_HPMCOUNTER12H)
DECLARE_CSR(hpmcounter13h, CSR_HPMCOUNTER13H)
DECLARE_CSR(hpmcounter14h, CSR_HPMCOUNTER14H)
DECLARE_CSR(hpmcounter15h, CSR_HPMCOUNTER15H)
DECLARE_CSR(hpmcounter16h, CSR_HPMCOUNTER16H)
DECLARE_CSR(hpmcounter17h, CSR_HPMCOUNTER17H)
DECLARE_CSR(hpmcounter18h, CSR_HPMCOUNTER18H)
DECLARE_CSR(hpmcounter19h, CSR_HPMCOUNTER19H)
DECLARE_CSR(hpmcounter20h, CSR_HPMCOUNTER20H)
DECLARE_CSR(hpmcounter21h, CSR_HPMCOUNTER21H)
DECLARE_CSR(hpmcounter22h, CSR_HPMCOUNTER22H)
DECLARE_CSR(hpmcounter23h, CSR_HPMCOUNTER23H)
DECLARE_CSR(hpmcounter24h, CSR_HPMCOUNTER24H)
DECLARE_CSR(hpmcounter25h, CSR_HPMCOUNTER25H)
DECLARE_CSR(hpmcounter26h, CSR_HPMCOUNTER26H)
DECLARE_CSR(hpmcounter27h, CSR_HPMCOUNTER27H)
DECLARE_CSR(hpmcounter28h, CSR_HPMCOUNTER28H)
DECLARE_CSR(hpmcounter29h, CSR_HPMCOUNTER29H)
DECLARE_CSR(hpmcounter30h, CSR_HPMCOUNTER30H)
DECLARE_CSR(hpmcounter31h, CSR_HPMCOUNTER31H)
DECLARE_CSR(mcycleh, CSR_MCYCLEH)
DECLARE_CSR(minstreth, CSR_MINSTRETH)
DECLARE_CSR(mhpmcounter3h, CSR_MHPMCOUNTER3H)
DECLARE_CSR(mhpmcounter4h, CSR_MHPMCOUNTER4H)
DECLARE_CSR(mhpmcounter5h, CSR_MHPMCOUNTER5H)
DECLARE_CSR(mhpmcounter6h, CSR_MHPMCOUNTER6H)
DECLARE_CSR(mhpmcounter7h, CSR_MHPMCOUNTER7H)
DECLARE_CSR(mhpmcounter8h, CSR_MHPMCOUNTER8H)
DECLARE_CSR(mhpmcounter9h, CSR_MHPMCOUNTER9H)
DECLARE_CSR(mhpmcounter10h, CSR_MHPMCOUNTER10H)
DECLARE_CSR(mhpmcounter11h, CSR_MHPMCOUNTER11H)
DECLARE_CSR(mhpmcounter12h, CSR_MHPMCOUNTER12H)
DECLARE_CSR(mhpmcounter13h, CSR_MHPMCOUNTER13H)
DECLARE_CSR(mhpmcounter14h, CSR_MHPMCOUNTER14H)
DECLARE_CSR(mhpmcounter15h, CSR_MHPMCOUNTER15H)
DECLARE_CSR(mhpmcounter16h, CSR_MHPMCOUNTER16H)
DECLARE_CSR(mhpmcounter17h, CSR_MHPMCOUNTER17H)
DECLARE_CSR(mhpmcounter18h, CSR_MHPMCOUNTER18H)
DECLARE_CSR(mhpmcounter19h, CSR_MHPMCOUNTER19H)
DECLARE_CSR(mhpmcounter20h, CSR_MHPMCOUNTER20H)
DECLARE_CSR(mhpmcounter21h, CSR_MHPMCOUNTER21H)
DECLARE_CSR(mhpmcounter22h, CSR_MHPMCOUNTER22H)
DECLARE_CSR(mhpmcounter23h, CSR_MHPMCOUNTER23H)
DECLARE_CSR(mhpmcounter24h, CSR_MHPMCOUNTER24H)
DECLARE_CSR(mhpmcounter25h, CSR_MHPMCOUNTER25H)
DECLARE_CSR(mhpmcounter26h, CSR_MHPMCOUNTER26H)
DECLARE_CSR(mhpmcounter27h, CSR_MHPMCOUNTER27H)
DECLARE_CSR(mhpmcounter28h, CSR_MHPMCOUNTER28H)
DECLARE_CSR(mhpmcounter29h, CSR_MHPMCOUNTER29H)
DECLARE_CSR(mhpmcounter30h, CSR_MHPMCOUNTER30H)
DECLARE_CSR(mhpmcounter31h, CSR_MHPMCOUNTER31H)
#endif
#ifdef DECLARE_CAUSE
DECLARE_CAUSE("misaligned fetch", CAUSE_MISALIGNED_FETCH)
DECLARE_CAUSE("fetch access", CAUSE_FETCH_ACCESS)
DECLARE_CAUSE("illegal instruction", CAUSE_ILLEGAL_INSTRUCTION)
DECLARE_CAUSE("breakpoint", CAUSE_BREAKPOINT)
DECLARE_CAUSE("misaligned load", CAUSE_MISALIGNED_LOAD)
DECLARE_CAUSE("load access", CAUSE_LOAD_ACCESS)
DECLARE_CAUSE("misaligned store", CAUSE_MISALIGNED_STORE)
DECLARE_CAUSE("store access", CAUSE_STORE_ACCESS)
DECLARE_CAUSE("user_ecall", CAUSE_USER_ECALL)
DECLARE_CAUSE("supervisor_ecall", CAUSE_SUPERVISOR_ECALL)
DECLARE_CAUSE("hypervisor_ecall", CAUSE_HYPERVISOR_ECALL)
DECLARE_CAUSE("machine_ecall", CAUSE_MACHINE_ECALL)
DECLARE_CAUSE("fetch page fault", CAUSE_FETCH_PAGE_FAULT)
DECLARE_CAUSE("load page fault", CAUSE_LOAD_PAGE_FAULT)
DECLARE_CAUSE("store page fault", CAUSE_STORE_PAGE_FAULT)
#endif
