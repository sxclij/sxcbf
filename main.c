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
    bfinst_kind_nop,
    bfinst_kind_add_val,
    bfinst_kind_add_ptr,
    bfinst_kind_while_start,
    bfinst_kind_while_end,
    bfinst_kind_io_out,
    bfinst_kind_io_in,
    bfinst_kind_zero,
    bfinst_kind_zeros,
    bfinst_kind_pseq,
    bfinst_kind_ngeq,
    bfinst_kind_forshift,
    bfinst_kind_vp,
    bfinst_kind_pv,
};
struct bfinst {
    enum bfinst_kind inst;
    union {
        bfint i16;
        int8_t i8[2];
    } data;
};
struct bfnode {
    struct bfinst value;
    struct bfnode* next;
};
struct bfmem {
    uint8_t data;
    uint8_t jit;
};

struct bfinst bfnode_provide(struct bfnode* this, bfint n) {
    struct bfnode* result = this;
    for (bfint i = 0; i < n && result != NULL; i++) {
        result = result->next;
    }
    if (result == NULL) {
        struct bfinst failed;
        return failed;
    } else {
        return result->value;
    }
}
void bfnode_skip(struct bfnode* this, bfint n) {
    for (bfint i = 0; i < n; i++) {
        this->next = this->next->next;
    }
}
int main() {
    clock_t clock_start = clock();

    bfint bf_ap = 0;
    bfint bf_ip = 0;
    bfint nest = 1;

    __attribute__((aligned(bfalign))) struct bfmem bf_mem[bfsize];
    __attribute__((aligned(bfalign))) struct bfinst bf_inst[bfsize];
    static char file_data[bfsize];
    static struct bfnode bf_nodes[bfsize];
    static bfint bf_nodes_stack[bfsize];
    static bfint bf_inst_size = 0;
    static bfint bf_nodes_size = 0;
    static bfint bf_nodes_stack_size = 0;

    FILE* file_ptr = fopen("data.txt", "r");
    bfint file_size = fread(file_data, sizeof(char), sizeof(file_data), file_ptr);
    file_data[file_size] = '\0';
    fclose(file_ptr);

    // to original inst
    for (bfint i = 0; i < file_size; i++) {
        struct bfnode* this = &bf_nodes[bf_nodes_size];
        this->next = &bf_nodes[++bf_nodes_size];
        if (file_data[i] == '+') {
            this->value.inst = bfinst_kind_add_val;
            this->value.data.i16 = 1;
        } else if (file_data[i] == '-') {
            this->value.inst = bfinst_kind_add_val;
            this->value.data.i16 = -1;
        } else if (file_data[i] == '>') {
            this->value.inst = bfinst_kind_add_ptr;
            this->value.data.i16 = 1;
        } else if (file_data[i] == '<') {
            this->value.inst = bfinst_kind_add_ptr;
            this->value.data.i16 = -1;
        } else if (file_data[i] == '[') {
            this->value.inst = bfinst_kind_while_start;
            this->value.data.i16 = 0;
        } else if (file_data[i] == ']') {
            this->value.inst = bfinst_kind_while_end;
            this->value.data.i16 = 0;
        } else if (file_data[i] == '.') {
            this->value.inst = bfinst_kind_io_out;
            this->value.data.i16 = 0;
        } else if (file_data[i] == ',') {
            this->value.inst = bfinst_kind_io_in;
            this->value.data.i16 = 0;
        } else {
            this->value.inst = bfinst_kind_nop;
            this->value.data.i16 = 0;
        }
    }

    // optimize
    for (struct bfnode* itr = bf_nodes; itr->value.inst != bfinst_kind_null;) {
        struct bfinst itr0 = bfnode_provide(itr, 0);
        struct bfinst itr1 = bfnode_provide(itr, 1);
        struct bfinst itr2 = bfnode_provide(itr, 2);
        struct bfinst itr3 = bfnode_provide(itr, 3);
        struct bfinst itr4 = bfnode_provide(itr, 4);
        struct bfinst itr5 = bfnode_provide(itr, 5);
        if (itr->next->value.inst == bfinst_kind_nop) {
            bfnode_skip(itr, 1);
        } else if (itr0.inst == bfinst_kind_add_val &&
                   itr1.inst == bfinst_kind_add_val) {
            itr->value.data.i16 += itr->next->value.data.i16;
            bfnode_skip(itr, 1);
        } else if (itr0.inst == bfinst_kind_add_ptr &&
                   itr1.inst == bfinst_kind_add_ptr) {
            itr->value.data.i16 += itr->next->value.data.i16;
            bfnode_skip(itr, 1);
        } else if (itr0.inst == bfinst_kind_while_start &&
                   itr1.inst == bfinst_kind_add_val &&
                   itr2.inst == bfinst_kind_while_end) {
            itr->value.inst = bfinst_kind_zero;
            itr->value.data.i16 = 1;
            bfnode_skip(itr, 2);
        } else if ((itr0.inst == bfinst_kind_zero || itr0.inst == bfinst_kind_zeros) &&
                   itr1.inst == bfinst_kind_add_ptr &&
                   itr2.inst == bfinst_kind_while_start &&
                   itr3.inst == bfinst_kind_add_val &&
                   itr4.inst == bfinst_kind_while_end &&
                   itr1.data.i16 == 1) {
            itr->value.inst = bfinst_kind_zeros;
            itr->value.data.i16++;
            bfnode_skip(itr, 4);
        } else {
            itr = itr->next;
        }
    }
    for (struct bfnode* itr = bf_nodes; itr->value.inst != bfinst_kind_null;) {
        struct bfinst itr0 = bfnode_provide(itr, 0);
        struct bfinst itr1 = bfnode_provide(itr, 1);
        struct bfinst itr2 = bfnode_provide(itr, 2);
        struct bfinst itr3 = bfnode_provide(itr, 3);
        struct bfinst itr4 = bfnode_provide(itr, 4);
        struct bfinst itr5 = bfnode_provide(itr, 5);
        if (itr0.inst == bfinst_kind_while_start &&
            itr1.inst == bfinst_kind_add_ptr &&
            itr2.inst == bfinst_kind_while_end) {
            itr->value.inst = bfinst_kind_forshift;
            itr->value.data.i16 = itr1.data.i16;
            bfnode_skip(itr, 2);
        } else if (itr0.inst == bfinst_kind_while_start &&
                   itr1.inst == bfinst_kind_add_val &&
                   itr2.inst == bfinst_kind_add_ptr &&
                   itr3.inst == bfinst_kind_add_val &&
                   itr4.inst == bfinst_kind_add_ptr &&
                   itr5.inst == bfinst_kind_while_end &&
                   itr2.data.i16 + itr4.data.i16 == 0 &&
                   itr1.data.i16 + itr3.data.i16 == 0) {
            itr->value.inst = bfinst_kind_pseq;
            itr->value.data.i16 = itr2.data.i16;
            bfnode_skip(itr, 5);
        } else if (itr0.inst == bfinst_kind_while_start &&
                   itr1.inst == bfinst_kind_add_val &&
                   itr2.inst == bfinst_kind_add_ptr &&
                   itr3.inst == bfinst_kind_add_val &&
                   itr4.inst == bfinst_kind_add_ptr &&
                   itr5.inst == bfinst_kind_while_end &&
                   itr2.data.i16 + itr4.data.i16 == 0 &&
                   itr1.data.i16 < 0 &&
                   itr3.data.i16 < 0) {
            itr->value.inst = bfinst_kind_ngeq;
            itr->value.data.i16 = itr2.data.i16;
            bfnode_skip(itr, 5);
        } else {
            itr = itr->next;
        }
    }

    // inst to mem
    for (struct bfnode* itr = bf_nodes; itr->value.inst != bfinst_kind_null; itr = itr->next) {
        bf_inst[bf_inst_size++] = itr->value;
    }

    // link
    for (bfint i = 0; bf_inst[i].inst != bfinst_kind_null; i++) {
        if (bf_inst[i].inst == bfinst_kind_while_start) {
            bf_nodes_stack[bf_nodes_stack_size++] = i;
        }
        if (bf_inst[i].inst == bfinst_kind_while_end) {
            bf_inst[i].data.i16 = bf_nodes_stack[--bf_nodes_stack_size] - 1;
            bf_inst[bf_nodes_stack[bf_nodes_stack_size]].data.i16 = i;
        }
    }

    // execute
    for (;; bf_ip++) {
        switch (bf_inst[bf_ip].inst) {
            case bfinst_kind_add_val:
                bf_mem[bf_ap].data += bf_inst[bf_ip].data.i16;
                break;
            case bfinst_kind_add_ptr:
                bf_ap += bf_inst[bf_ip].data.i16;
                break;
            case bfinst_kind_while_start:
                if (bf_mem[bf_ap].data == 0) {
                    bf_ip = bf_inst[bf_ip].data.i16;
                }
                break;
            case bfinst_kind_while_end:
                bf_ip = bf_inst[bf_ip].data.i16;
                break;
            case bfinst_kind_io_out:
                putchar(bf_mem[bf_ap].data);
                break;
            case bfinst_kind_io_in:
                bf_mem[bf_ap].data = getchar();
                break;
            case bfinst_kind_zero:
                bf_mem[bf_ap].data = 0;
                break;
            case bfinst_kind_pseq:
                bf_mem[bf_ap + bf_inst[bf_ip].data.i16].data += bf_mem[bf_ap].data;
                bf_mem[bf_ap].data = 0;
                break;
            case bfinst_kind_ngeq:
                bf_mem[bf_ap + bf_inst[bf_ip].data.i16].data -= bf_mem[bf_ap].data;
                bf_mem[bf_ap].data = 0;
                break;
            case bfinst_kind_forshift:
                while (bf_mem[bf_ap].data) {
                    bf_ap += bf_inst[bf_ip].data.i16;
                }
                break;
            case bfinst_kind_zeros:
                for (bfint i = 0; i < bf_inst[bf_ip].data.i16; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += bf_inst[bf_ip].data.i16 - 1;
                break;
            case bfinst_kind_null:
                printf("%f\n", (double)(clock() - clock_start) / CLOCKS_PER_SEC);
                return 0;
        }
    }
}