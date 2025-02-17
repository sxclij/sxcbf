#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define data_size 65536
#define data_align 16

int main() {
    clock_t clock_start = clock();

    int32_t ap;
    int32_t ip;

    static __attribute__((aligned(data_align))) int8_t mem[data_size] = {0};

    FILE* file_ptr = fopen("data.txt", "r");
    int32_t file_size = fread(mem, sizeof(int8_t), data_size - 1, file_ptr);
    mem[file_size] = '\0';
    fclose(file_ptr);

    ip = 0;
    ap = file_size;

    while (1) {
        int8_t ch = mem[ip];

        if (ch == '\0') {
            break;
        } else if (ch == '.') {
            putchar(mem[ap]);
            ip++;
        } else if (ch == ',') {
            mem[ap] = getchar();
            ip++;
        } else if (ch == '[') {
            if (mem[ap] == 0) {
                int bracket_nest = 1;
                while (bracket_nest) {
                    ip++;
                    if (mem[ip] == '[') {
                        bracket_nest++;
                    } else if (mem[ip] == ']') {
                        bracket_nest--;
                    }
                }
                ip++;
            } else {
                ip++;
            }
        } else if (ch == ']') {
            if (mem[ap] != 0) {
                int bracket_nest = 1;
                while (bracket_nest) {
                    ip--;
                    if (mem[ip] == ']')
                        bracket_nest++;
                    else if (mem[ip] == '[')
                        bracket_nest--;
                }
                ip++;
            } else {
                ip++;
            }
        } else if (ch == '<') {
            ap--;
            ip++;
        } else if (ch == '>') {
            ap++;
            ip++;
        } else if (ch == '-') {
            mem[ap]--;
            ip++;
        } else if (ch == '+') {
            mem[ap]++;
            ip++;
        } else {
            ip++;
        }
    }

    clock_t clock_end = clock();
    double time_spent = (double)(clock_end - clock_start) / CLOCKS_PER_SEC;
    fprintf(stderr, "\nExecution time: %f seconds\n", time_spent);

    return 0;
}
