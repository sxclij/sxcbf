#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define mem_capacity (1 << 16)
#define file_capacity (1 << 16)

enum inst {
    inst_null,
    inst_nop,
    inst_ptr_inc,
    inst_ptr_dec,
    inst_val_inc,
    inst_val_dec,
    inst_out,
    inst_in,
    inst_while_start,
    inst_while_end,
    inst_finish,
    inst_opt_ptr_add2,
    inst_opt_ptr_add3,
    inst_opt_ptr_add4,
    inst_opt_ptr_sub2,
    inst_opt_ptr_sub3,
    inst_opt_ptr_sub4,
    inst_opt_val_add2,
    inst_opt_val_add3,
    inst_opt_val_add4,
    inst_opt_val_sub2,
    inst_opt_val_sub3,
    inst_opt_val_sub4,
    inst_opt_zero,
};

struct node {
    enum inst inst;
    char x;
    uint16_t jmp;
};

void exec(struct node* mem) {
    struct node* ip = &mem[0];
    struct node* ap = &mem[file_capacity];

    while (1) {
        switch (ip->inst) {
            case inst_ptr_inc:
                ap++;
                ip++;
                break;
            case inst_ptr_dec:
                ap--;
                ip++;
                break;
            case inst_val_inc:
                ap->x++;
                ip++;
                break;
            case inst_val_dec:
                ap->x--;
                ip++;
                break;
            case inst_out:
                putchar(ap->x);
                ip++;
                break;
            case inst_in:
                ap->x = getchar();
                ip++;
                break;
            case inst_while_start:
                if (ap->x != 0) {
                    ip++;
                } else {
                    ip = &mem[ip->jmp];
                }
                break;
            case inst_while_end:
                ip = &mem[ip->jmp];
                break;
            case inst_nop:
                ip++;
                break;
            case inst_finish:
                return;
            case inst_opt_ptr_add2:
                ap += 2;
                ip += 2;
                break;
            case inst_opt_ptr_add3:
                ap += 3;
                ip += 3;
                break;
            case inst_opt_ptr_add4:
                ap += 4;
                ip += 4;
                break;
            case inst_opt_ptr_sub2:
                ap -= 2;
                ip += 2;
                break;
            case inst_opt_ptr_sub3:
                ap -= 3;
                ip += 3;
                break;
            case inst_opt_ptr_sub4:
                ap -= 4;
                ip += 4;
                break;
            case inst_opt_val_add2:
                ap->x += 2;
                ip += 2;
                break;
            case inst_opt_val_add3:
                ap->x += 3;
                ip += 3;
                break;
            case inst_opt_val_add4:
                ap->x += 4;
                ip += 4;
                break;
            case inst_opt_val_sub2:
                ap->x -= 2;
                ip += 2;
                break;
            case inst_opt_val_sub3:
                ap->x -= 3;
                ip += 3;
                break;
            case inst_opt_val_sub4:
                ap->x -= 4;
                ip += 4;
                break;
            case inst_opt_zero:
                ap->x = 0;
                ip += 3;
                break;
        }
    }
}
void optimize(struct node* mem) {
    uint16_t i = 0;
    uint16_t jmptable_stack[file_capacity];
    uint16_t jmptable_stack_size = 0;
    while (1) {
        switch (mem[i].x) {
            case '>':
                mem[i].inst = inst_ptr_inc;
                if (mem[i + 1].x == '>') {
                    mem[i].inst = inst_opt_ptr_add2;
                    if (mem[i + 2].x == '>') {
                        mem[i].inst = inst_opt_ptr_add3;
                        if (mem[i + 3].x == '>') {
                            mem[i].inst = inst_opt_ptr_add4;
                        }
                    }
                }
                break;
            case '<':
                mem[i].inst = inst_ptr_dec;
                if (mem[i + 1].x == '<') {
                    mem[i].inst = inst_opt_ptr_sub2;
                    if (mem[i + 2].x == '<') {
                        mem[i].inst = inst_opt_ptr_sub3;
                        if (mem[i + 3].x == '<') {
                            mem[i].inst = inst_opt_ptr_sub4;
                        }
                    }
                }
                break;
            case '+':
                mem[i].inst = inst_val_inc;
                if (mem[i + 1].x == '+') {
                    mem[i].inst = inst_opt_val_add2;
                    if (mem[i + 2].x == '+') {
                        mem[i].inst = inst_opt_val_add3;
                        if (mem[i + 3].x == '+') {
                            mem[i].inst = inst_opt_val_add4;
                        }
                    }
                }
                break;
            case '-':
                mem[i].inst = inst_val_dec;
                if (mem[i + 1].x == '-') {
                    mem[i].inst = inst_opt_val_sub2;
                    if (mem[i + 2].x == '-') {
                        mem[i].inst = inst_opt_val_sub3;
                        if (mem[i + 3].x == '-') {
                            mem[i].inst = inst_opt_val_sub4;
                        }
                    }
                }
                break;
            case '.':
                mem[i].inst = inst_out;
                break;
            case ',':
                mem[i].inst = inst_in;
                break;
            case '[':
                mem[i].inst = inst_while_start;
                jmptable_stack[jmptable_stack_size++] = i;
                if (mem[i + 1].x == '-' && mem[i + 2].x == ']') {
                    mem[i].inst = inst_opt_zero;
                }
                break;
            case ']':
                mem[i].inst = inst_while_end;
                mem[jmptable_stack[jmptable_stack_size - 1]].jmp = i + 1;
                mem[i].jmp = jmptable_stack[--jmptable_stack_size];
                break;
            case '\0':
                mem[i].inst = inst_finish;
                return;
            default:
                mem[i].inst = inst_nop;
                break;
        }
        i++;
    }
}

int main() {
    static char buf[file_capacity];
    static struct node mem[mem_capacity];

    FILE* file_ptr = fopen("data.txt", "r");
    uint32_t file_size = fread(buf, sizeof(char), sizeof(buf), file_ptr);
    for (uint32_t i = 0; buf[i] != '\0'; i++)
        mem[i].x = buf[i];

    optimize(mem);
    exec(mem);
    printf("\n\n%fs\n", ((double)clock()) / CLOCKS_PER_SEC);
}