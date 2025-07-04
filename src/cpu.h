#ifndef EXEC_H
#define EXEC_H

#include <stdint.h>

#define MEMORY_SIZE   16384
#define NUM_REGS      16
#define MAX_PROCESSES 64

typedef struct {
  uint16_t pc;
  uint32_t ir;
  uint16_t flags;
  uint16_t regs[NUM_REGS];
  uint8_t* memory;
} risc_gc;
#define SP regs[15]
#define REG(r) cpu->regs[(int)r]

#define FLAG_ZERO  (1 << 0)
#define FLAG_CARRY (1 << 1)
#define FLAG_SIGN  (1 << 2)

int exec(risc_gc* cpu, char debug);
void cpu_dump(risc_gc* cpu);

#endif
