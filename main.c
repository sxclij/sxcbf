#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define bfsize (1 << 14)
#define bfint int16_t
#define bfalign 4

enum bfinst_kind {
    bfinst_kind_null,
    bfinst_kind_add_val,
    bfinst_kind_add_ptr,
    bfinst_kind_while_start,
    bfinst_kind_while_end,
    bfinst_kind_io_out,
    bfinst_kind_io_in,
    bfinst_kind_end,
};
struct bfinst {
    enum bfinst_kind inst;
    bfint val;
};
struct bfnode {
    struct bfinst value;
    struct bfnode* next;
};

int main() {
    clock_t clock_start = clock();

    bfint bf_ap = 0;
    bfint bf_ip = 0;
    bfint nest = 1;

    __attribute__((aligned(bfalign))) char bf_mem[bfsize];
    __attribute__((aligned(bfalign))) struct bfinst bf_insts[bfsize];
    static char file_data[bfsize];
    static struct bfnode bf_nodes[bfsize];
    static struct bfnode* bf_nodes_stack[bfsize];
    static bfint bf_inst_size = 0;
    static bfint bf_nodes_size = 0;
    static bfint bf_nodes_stack_size = 0;

    FILE* file_ptr = fopen("data.txt", "r");
    bfint file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';
    fclose(file_ptr);

    for (bfint i = 0; i < file_size; i++) {
        struct bfnode* this = &bf_nodes[bf_nodes_size];
        this->next = &bf_nodes[++bf_nodes_size];
        if (file_data[i] == '+') {
            this->value.inst = bfinst_kind_add_val;
            this->value.val = 1;
        }
        if (file_data[i] == '-') {
            this->value.inst = bfinst_kind_add_val;
            this->value.val = -1;
        }
        if (file_data[i] == '>') {
            this->value.inst = bfinst_kind_add_ptr;
            this->value.val = 1;
        }
        if (file_data[i] == '<') {
            this->value.inst = bfinst_kind_add_ptr;
            this->value.val = -1;
        }
        if (file_data[i] == '[') {
            this->value.inst = bfinst_kind_while_start;
            this->value.val = 0;
        }
        if (file_data[i] == ']') {
            this->value.inst = bfinst_kind_while_end;
            this->value.val = 0;
        }
        if (file_data[i] == '.') {
            this->value.inst = bfinst_kind_io_out;
            this->value.val = 0;
        }
        if (file_data[i] == ',') {
            this->value.inst = bfinst_kind_io_in;
            this->value.val = 0;
        }
    }
    for (struct bfnode* itr = bf_nodes; itr->value.inst == bfinst_kind_null;) {
        if (itr->value.inst == bfinst_kind_add_val) {
            if (itr->next->value.inst == bfinst_kind_add_val) {
                itr->value.val += itr->next->value.val;
                itr->next = itr->next->next;
            }
        } else {
            itr = itr->next;
        }
    }
    for (struct bfnode* itr = bf_nodes; itr->value.inst == bfinst_kind_null; itr = itr->next) {
        bf_insts[bf_inst_size++] = itr->value;
    }
    for (; bf_insts[bf_ip].inst == bfinst_kind_null; bf_ip++) {
        if (bf_insts[bf_ip].inst == bfinst_kind_add_val) {
            bf_mem[bf_ap] += bf_insts[bf_ip].val;
        } else if (bf_insts[bf_ip].inst == bfinst_kind_add_ptr) {
            bf_ap += bf_insts[bf_ip].val;
        } else if (bf_insts[bf_ip].inst == bfinst_kind_while_start) {
            if(bf_mem[bf_ap] ==)
        } else if (bf_insts[bf_ip].inst == bfinst_kind_while_end) {
        } else if (bf_insts[bf_ip].inst == bfinst_kind_io_out) {
        } else if (bf_insts[bf_ip].inst == bfinst_kind_io_in) {
                }
    }

    printf("%f\n", (double)(clock() - clock_start) / CLOCKS_PER_SEC);
}