// See LICENSE for details.

#ifndef _ELF_H
#define _ELF_H

#include <stdint.h>

#define IS_ELF(hdr) \
  ((hdr).e_ident[0] == 0x7f && (hdr).e_ident[1] == 'E' && \
   (hdr).e_ident[2] == 'L'  && (hdr).e_ident[3] == 'F')

#define IS_ELF32(hdr) (IS_ELF(hdr) && (hdr).e_ident[4] == 1)
#define IS_ELF64(hdr) (IS_ELF(hdr) && (hdr).e_ident[4] == 2)

#define PT_LOAD 1

#define SHT_NOBITS 8

typedef struct {
  uint8_t  e_ident[16]; //lxj// Magic: 7f 'E' 'L' 'F' ...
  uint16_t e_type; //lxj// Type: EXEC
  uint16_t e_machine; //lxj// Machine
  uint32_t e_version; //lxj// Version
  uint32_t e_entry; //lxj// Entry point address 程序执行起始地址
  uint32_t e_phoff; //lxj// Start of program headers
  uint32_t e_shoff; //lxj// Start of section headers
  uint32_t e_flags; //lxj// Flags
  uint16_t e_ehsize; //lxj// Size of this header ELF头字节数
  uint16_t e_phentsize; //lxj// Size of program headers
  uint16_t e_phnum; //lxj// Number of program headers
  uint16_t e_shentsize; //lxj// Size of section headers
  uint16_t e_shnum; //lxj// Number of program headers
  uint16_t e_shstrndx; //lxj// Section header string table index
} Elf32_Ehdr; //lxj// ELF header

typedef struct {
  uint32_t sh_name; //lxj// Name: .text, .data, .bss, ...
  uint32_t sh_type; //lxj// Type
  uint32_t sh_flags; //lxj// Flags
  uint32_t sh_addr; //lxj// Address 此段在硬盘中的起始地址
  uint32_t sh_offset; //lxj// Offest 此段在硬盘中相对程序起始地址的偏移量
  uint32_t sh_size; //lxj// Size 此段在硬盘中的字节数
  uint32_t sh_link; //lxj// Link
  uint32_t sh_info; //lxj// Info
  uint32_t sh_addralign;
  uint32_t sh_entsize;
} Elf32_Shdr; //lxj// Section header

typedef struct
{
  uint32_t p_type; //lxj// Type: PHDR, LOAD, INTERP, ...
  uint32_t p_offset; //lxj// Offset 此程序头表的起始地址
  uint32_t p_vaddr; //lxj// Virtual address 虚拟内存地址
  uint32_t p_paddr; //lxj// Physical address 物理内存地址
  uint32_t p_filesz; //lxj// File size 此程序头表在硬盘中的字节数
  uint32_t p_memsz; //lxj// Memory size 此程序头表读取到内存后的字节数
  uint32_t p_flags; //lxj// Flags: R, W, E
  uint32_t p_align; //lxj// Align 对齐的字节数
} Elf32_Phdr; // Program header

typedef struct
{
  uint32_t st_name;
  uint32_t st_value;
  uint32_t st_size;
  uint8_t  st_info;
  uint8_t  st_other;
  uint16_t st_shndx;
} Elf32_Sym;

typedef struct {
  uint8_t  e_ident[16];
  uint16_t e_type;
  uint16_t e_machine;
  uint32_t e_version;
  uint64_t e_entry;
  uint64_t e_phoff;
  uint64_t e_shoff;
  uint32_t e_flags;
  uint16_t e_ehsize;
  uint16_t e_phentsize;
  uint16_t e_phnum;
  uint16_t e_shentsize;
  uint16_t e_shnum;
  uint16_t e_shstrndx;
} Elf64_Ehdr;

typedef struct {
  uint32_t sh_name;
  uint32_t sh_type;
  uint64_t sh_flags;
  uint64_t sh_addr;
  uint64_t sh_offset;
  uint64_t sh_size;
  uint32_t sh_link;
  uint32_t sh_info;
  uint64_t sh_addralign;
  uint64_t sh_entsize;
} Elf64_Shdr;

typedef struct {
  uint32_t p_type;
  uint32_t p_flags;
  uint64_t p_offset;
  uint64_t p_vaddr;
  uint64_t p_paddr;
  uint64_t p_filesz;
  uint64_t p_memsz;
  uint64_t p_align;
} Elf64_Phdr;

typedef struct {
  uint32_t st_name;
  uint8_t  st_info;
  uint8_t  st_other;
  uint16_t st_shndx;
  uint64_t st_value;
  uint64_t st_size;
} Elf64_Sym;

#endif
