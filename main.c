#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define mem_capacity (1 << 16)
#define file_capacity (1 << 16)

struct node {
    uint16_t jmp;
    char x;
};

void exec(struct node* mem) {
    struct node* ip = &mem[0];
    struct node* ap = &mem[file_capacity];
    uint_fast8_t lc = 0;

    struct node* opt_loop;

    while (1) {
        switch (ip->x) {
            case '>':
                ap++;
                break;
            case '<':
                ap--;
                break;
            case '+':
                ap->x++;
                break;
            case '-':
                ap->x--;
                break;
            case '.':
                putchar(ap->x);
                break;
            case ',':
                ap->x = getchar();
                break;
            case '[':
                lc = (ap->x == 0);
                while (lc) {
                    ip++;
                    lc += (ip->x == '[');
                    lc -= (ip->x == ']');
                }
                break;
            case ']':
                if (ip->jmp != 0) {
                    ip = &mem[ip->jmp];
                    break;
                }
                opt_loop = ip;
                lc = 1;
                while (lc) {
                    ip--;
                    lc -= (ip->x == '[');
                    lc += (ip->x == ']');
                }
                ip--;
                opt_loop->jmp = ip - mem;
                break;
            case '\0':
                return;
            default:
                break;
        }
        ip++;
    }
}

int main() {
    static char buf[file_capacity];
    static struct node mem[mem_capacity];

    FILE* file_ptr = fopen("data.txt", "r");
    uint32_t file_size = fread(buf, sizeof(char), sizeof(buf), file_ptr);
    for (uint32_t i = 0; buf[i] != '\0'; i++)
        mem[i].x = buf[i];

    exec(mem);
    printf("\n\n%fs\n", ((double)clock()) / CLOCKS_PER_SEC);
}