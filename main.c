<<<<<<< HEAD
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define bfsize (1 << 14)
#define bfint uint32_t
#define bfalign 4

enum bfinst_kind {
    bfinst_kind_nop,
};
struct bfinst{
    enum bfinst_kind inst;
    bfint val;
};

int main() {
    clock_t clock_start = clock();

    bfint bf_ap = 0;
    bfint bf_ip = 0;
    bfint nest = 1;

    __attribute__((aligned(bfalign))) char file_data[bfsize];
    __attribute__((aligned(bfalign))) char bf_mem[bfsize];

    FILE* file_ptr = fopen("data.txt", "r");
    bfint file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';
    fclose(file_ptr);

    memset(bf_mem, 0, sizeof(bf_mem));
    while (1) {
        if (file_data[bf_ip] == '>') {
            bf_ap++;
        } else if (file_data[bf_ip] == '<') {
            bf_ap--;
        } else if (file_data[bf_ip] == '+') {
            bf_mem[bf_ap]++;
        } else if (file_data[bf_ip] == '-') {
            bf_mem[bf_ap]--;
        } else if (file_data[bf_ip] == '[') {
            if (bf_mem[bf_ap] == 0) {
                nest = 1;
                while (nest) {
                    bf_ip++;
                    if (file_data[bf_ip] == '[') {
                        nest++;
                    }
                    if (file_data[bf_ip] == ']') {
                        nest--;
                    }
                }
            }
        } else if (file_data[bf_ip] == ']') {
            nest = 1;
            while (nest) {
                bf_ip--;
                if (file_data[bf_ip] == '[') {
                    nest--;
                }
                if (file_data[bf_ip] == ']') {
                    nest++;
                }
            }
            bf_ip--;
        } else if (file_data[bf_ip] == '.') {
            putchar(bf_mem[bf_ap]);
        } else if (file_data[bf_ip] == ',') {
            bf_mem[bf_ap] = getchar();
        } else if (file_data[bf_ip] == '\0') {
            break;
        }
        bf_ip++;
    }
    printf("%f\n", (double)(clock() - clock_start) / CLOCKS_PER_SEC);
=======
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <string.h>
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
    inst_opt_ptr_add,
    inst_opt_ptr_sub,
    inst_opt_val_add,
    inst_opt_val_sub,
    inst_opt_zero,
};

struct node {
    enum inst inst;
    char x;
    uint16_t opt;
};

void exec(struct node* mem) {
    struct node* ip = &mem[0];
    struct node* ap = &mem[0];

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
                    ip = &mem[ip->opt];
                }
                break;
            case inst_while_end:
                ip = &mem[ip->opt];
                break;
            case inst_nop:
                ip++;
                break;
            case inst_finish:
                return;
            case inst_opt_ptr_add:
                ap += ip->opt;
                ip++;
                break;
            case inst_opt_ptr_sub:
                ap -= ip->opt;
                ip++;
                break;
            case inst_opt_val_add:
                ap->x += ip->opt;
                ip++;
                break;
            case inst_opt_val_sub:
                ap->x -= ip->opt;
                ip++;
                break;
            case inst_opt_zero:
                ap->x = 0;
                ip++;
                break;
        }
    }
}
void optimize(char* src, struct node* dst) {
    uint32_t i = 0;
    uint32_t i_compress = 0;
    uint32_t clean_i = 0;
    uint32_t clean_j = 0;
    uint32_t jmptable_stack[file_capacity];
    uint32_t jmptable_stack_size = 0;
    while (1) {
        switch (dst[i].x) {
            case '>':
                dst[i].inst = inst_ptr_inc;
                if (dst[i + 1].x == '>') {
                    i_compress = i;
                    dst[i_compress].opt = 1;
                    dst[i_compress].inst = inst_opt_ptr_add;
                    while (dst[i + 1].x == '>') {
                        dst[i_compress].opt++;
                        i++;
                    }
                }
                break;
            case '<':
                dst[i].inst = inst_ptr_dec;
                if (dst[i + 1].x == '<') {
                    i_compress = i;
                    dst[i_compress].opt = 1;
                    dst[i_compress].inst = inst_opt_ptr_sub;
                    while (dst[i + 1].x == '<') {
                        dst[i_compress].opt++;
                        i++;
                    }
                }
                break;
            case '+':
                dst[i].inst = inst_val_inc;
                if (dst[i + 1].x == '+') {
                    i_compress = i;
                    dst[i_compress].opt = 1;
                    dst[i_compress].inst = inst_opt_val_add;
                    while (dst[i + 1].x == '+') {
                        dst[i_compress].opt++;
                        i++;
                    }
                }
                break;
            case '-':
                dst[i].inst = inst_val_dec;
                if (dst[i + 1].x == '-') {
                    i_compress = i;
                    dst[i_compress].opt = 1;
                    dst[i_compress].inst = inst_opt_val_sub;
                    while (dst[i + 1].x == '-') {
                        dst[i_compress].opt++;
                        i++;
                    }
                }
                break;
            case '.':
                dst[i].inst = inst_out;
                break;
            case ',':
                dst[i].inst = inst_in;
                break;
            case '[':
                dst[i].inst = inst_while_start;
                if (memcmp(&src[i], "[-]", 3) == 0) {
                    dst[i].inst = inst_opt_zero;
                    i += 2;
                }
                break;
            case ']':
                dst[i].inst = inst_while_end;
                break;
            case '\0':
                dst[i].inst = inst_finish;
                break;
            default:
                dst[i].inst = inst_nop;
                break;
        }
        if (dst[i].inst == inst_finish)
            break;
        i++;
    }

    while (1) {
        switch (dst[clean_j].inst) {
            case inst_null:
            case inst_nop:
                break;
            case inst_finish:
                dst[clean_i++] = dst[clean_j];
                break;
            default:
                dst[clean_i++] = dst[clean_j];
                break;
        }
        if (dst[clean_j].inst == inst_finish)
            break;
        clean_j++;
    }
    for (uint32_t i = 0; dst[i].inst != inst_finish; i++) {
        switch (dst[i].inst) {
            case inst_while_start:
                jmptable_stack[jmptable_stack_size++] = i;
                break;
            case inst_while_end:
                dst[jmptable_stack[jmptable_stack_size - 1]].opt = i + 1;
                dst[i].opt = jmptable_stack[--jmptable_stack_size];
                break;
            default:
                break;
        }
    }
}

int main() {
    static char src[file_capacity];
    static struct node nodes[mem_capacity];

    FILE* file_ptr = fopen("data.txt", "r");
    uint32_t file_size = fread(src, sizeof(char), sizeof(src), file_ptr);

    for (uint32_t i = 0; src[i] != '\0'; i++)
        nodes[i].x = src[i];

    optimize(src, nodes);

    for (uint32_t i = 0; src[i] != '\0'; i++)
        nodes[i].x = 0;

    exec(nodes);

    printf("\n\n%fs\n", ((double)clock()) / CLOCKS_PER_SEC);
>>>>>>> 12ab673 (連続する命令を圧縮)
}