#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// #define atcoder

#define bfoutsize (1 << 20)
#define bfinsize (1 << 16)
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
    bfinst_kind_vp,
    bfinst_kind_pv,
    bfinst_kind_vpvp,
    bfinst_kind_pvpv,
    bfinst_kind_distribution1,
    bfinst_kind_distribution2,
    bfinst_kind_distribution3,
    bfinst_kind_forshift,
};
struct bfinst {
    enum bfinst_kind inst;
    bfint data;
};
struct bfnode {
    struct bfinst value;
    struct bfnode* next;
};
struct bfmem {
    uint32_t data;
};

int main() {
    clock_t clock_start = clock();

    bfint bf_ap = 0;
    bfint bf_ip = 0;

    static __attribute__((aligned(bfalign))) struct bfmem bf_mem[bfsize];
    bf_mem[bf_ap].data += 13;
    while (bf_mem[bf_ap].data) {
        bf_mem[bf_ap].data += -1;
        bf_ap += 1;
        bf_mem[bf_ap].data += 2;
        bf_ap += 3;
        bf_ip += 3;
        bf_mem[bf_ap].data += 5;
        bf_ap += 1;
        bf_mem[bf_ap].data += 2;
        bf_ap += 1;
        bf_ip += 3;
        bf_mem[bf_ap].data += 1;
        bf_ap += -6;
        bf_ip += 1;
    }
    bf_ap += 5;
    bf_mem[bf_ap].data += 6;
    bf_ap += 1;
    bf_mem[bf_ap].data += -3;
    bf_ip += 3;
    bf_ap += 10;
    bf_mem[bf_ap].data += 15;
    bf_ip += 1;
    while (bf_mem[bf_ap].data) {
        while (bf_mem[bf_ap].data) {
            bf_ap += 9;
        }
        bf_mem[bf_ap].data += 1;
        while (bf_mem[bf_ap].data) {
            bf_ap += -9;
        }
        bf_ap += 9;
        bf_mem[bf_ap].data += -1;
        bf_ip += 1;
    }
    bf_mem[bf_ap].data += 1;
    while (bf_mem[bf_ap].data) {
        bf_ap += 8;
        bf_mem[bf_ap].data = 0;
        bf_ap += 1;
    }
    bf_ap += -9;
    while (bf_mem[bf_ap].data) {
        bf_ap += -9;
    }
    bf_ap += 8;
    bf_mem[bf_ap].data = 0;
    bf_mem[bf_ap].data += 1;
    bf_ap += -7;
    bf_ip += 1;
    bf_mem[bf_ap].data += 5;
    while (bf_mem[bf_ap].data) {
        bf_mem[bf_ap].data += -1;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += 9;
            bf_mem[bf_ap].data += 1;
            bf_ap += -9;
            bf_ip += 3;
        }
        bf_ap += 9;
    }
    bf_ap += 7;
    bf_mem[bf_ap].data += 1;
    bf_ap += 27;
    bf_mem[bf_ap].data += 1;
    bf_ip += 3;
    bf_ap += -17;
    while (bf_mem[bf_ap].data) {
        bf_ap += -9;
    }
    bf_ap += 3;
    bf_mem[bf_ap].data = 0;
    bf_mem[bf_ap].data += 1;
    while (bf_mem[bf_ap].data) {
        bf_ap += 6;
        while (bf_mem[bf_ap].data) {
            bf_ap += 7;
            bf_mem[bf_ap].data = 0;
            bf_ap += 2;
        }
        bf_ap += -9;
        while (bf_mem[bf_ap].data) {
            bf_ap += -9;
        }
        bf_ap += 7;
        bf_mem[bf_ap].data = 0;
        bf_mem[bf_ap].data += 1;
        bf_ap += -6;
        bf_ip += 1;
        bf_mem[bf_ap].data += 4;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 9;
                bf_mem[bf_ap].data += 1;
                bf_ap += -9;
                bf_ip += 3;
            }
            bf_ap += 9;
        }
        bf_ap += 6;
        bf_mem[bf_ap].data += 1;
        bf_ap += -6;
        bf_mem[bf_ap].data += 7;
        bf_ip += 3;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 9;
                bf_mem[bf_ap].data += 1;
                bf_ap += -9;
                bf_ip += 3;
            }
            bf_ap += 9;
        }
        bf_ap += 6;
        bf_mem[bf_ap].data += 1;
        bf_ip += 1;
        bf_ap += -16;
        while (bf_mem[bf_ap].data) {
            bf_ap += -9;
        }
        bf_ap += 3;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data = 0;
            bf_ap += 6;
            while (bf_mem[bf_ap].data) {
                bf_ap += 7;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -6;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 6;
                    bf_ip += 3;
                }
                bf_ap += -6;
                bf_mem[bf_ap + 6].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap].data = 0;
                bf_ip += 5;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 8;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -7;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 7;
                    bf_ip += 3;
                }
                bf_ap += -7;
                bf_mem[bf_ap + 7].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap].data = 0;
                bf_ip += 5;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 7;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -7;
                bf_mem[bf_ap].data += 1;
                bf_ap += 7;
                bf_ip += 3;
            }
            bf_ap += -7;
            bf_mem[bf_ap + 7].data += bf_mem[bf_ap].data * 1;
            bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
            bf_mem[bf_ap].data = 0;
            bf_ip += 3;
            bf_ap += 9;
            bf_mem[bf_ap].data += 15;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 1;
                bf_ip += 1;
                for (bfint i = 0; i < 9; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += 9 - 1;
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
            }
            bf_mem[bf_ap].data += 1;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_ap += -4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -5;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 2;
                            bf_ip += 3;
                        }
                        bf_ap += -2;
                        bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap].data = 0;
                        bf_ip += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 9;
                        bf_ip += 1;
                    }
                    bf_ap += -8;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -10;
                }
                bf_ap += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 9;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -9;
                    bf_ip += 3;
                }
                bf_ap += -1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += -1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -1;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += -1;
                        bf_ip += 3;
                        bf_ap += -6;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 6;
                    }
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 3;
                    }
                    bf_ap += 4;
                }
                bf_ap += -3;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 3;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -3;
                    bf_ip += 3;
                }
                bf_ap += -1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -5;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 5;
                    bf_ip += 3;
                }
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -6;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_ap += -3;
                        bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap].data = 0;
                        bf_ip += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 9;
                        bf_ip += 1;
                    }
                    bf_ap += -8;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -11;
                }
                bf_ap += 2;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 9;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -9;
                    bf_ip += 3;
                }
                bf_ap += -2;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += -1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -1;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += -1;
                        bf_ip += 3;
                        bf_ap += -6;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 6;
                    }
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 3;
                    }
                    bf_ap += 4;
                }
                bf_ap += -3;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 3;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -3;
                    bf_ip += 3;
                }
                bf_ap += -1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -36;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 36;
                    bf_ip += 3;
                }
                bf_ap += 5;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            bf_mem[bf_ap].data += 15;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_ap += -9;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
            }
            bf_mem[bf_ap].data += 1;
            bf_ap += 21;
            bf_mem[bf_ap].data += 1;
            bf_ap += -3;
            bf_ip += 3;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 3;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -3;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 3;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -3;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 3;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -13;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                        bf_ap += 4;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                    }
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 4;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -4;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 3;
                        bf_ip += 3;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -12;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                        bf_ap += 3;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += 1;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 1;
                    }
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 1;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -8;
                }
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += -7;
            bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
            bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * -1;
            bf_mem[bf_ap].data = 0;
            bf_ip += 3;
            bf_ap += 9;
            bf_mem[bf_ap].data += 26;
            bf_ip += 1;
            bf_ap += 2;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -4;
                bf_mem[bf_ap].data += 1;
                bf_ap += 4;
                bf_ip += 3;
            }
            bf_ap += -4;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 4;
                bf_mem[bf_ap].data += 1;
                bf_ap += -2;
                bf_ip += 3;
                bf_mem[bf_ap].data = 0;
                bf_ap += -2;
            }
            bf_ap += 2;
            while (bf_mem[bf_ap].data) {
                bf_ap += -7;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -2;
                    bf_ip += 1;
                    bf_mem[bf_ap].data = 0;
                }
                bf_ap += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -2;
                    bf_ip += 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * -1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 3;
                }
                bf_ap += 13;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 2;
                    for (bfint i = 0; i < 3; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 3 - 1;
                    bf_ap += 5;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 3;
                bf_mem[bf_ap].data = 0;
                bf_ap += 6;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 9;
                        bf_ip += 3;
                    }
                    bf_ap += 7;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                    }
                    bf_ap += 1;
                    for (bfint i = 0; i < 8; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 8 - 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -6;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 9;
                            bf_ip += 1;
                        }
                        bf_ap += -8;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                    }
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 9;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -9;
                            bf_ip += 3;
                        }
                        bf_ap += -10;
                    }
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -7;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 7;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 3;
                    }
                    bf_ap += -2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -5;
                    bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -6;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 9;
                            bf_ip += 1;
                        }
                        bf_ap += -8;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                    }
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 9;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -9;
                            bf_ip += 3;
                        }
                        bf_ap += -10;
                    }
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -6;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 6;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 4;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -3;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -36;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 36;
                        bf_ip += 3;
                    }
                    bf_ap += 5;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -36;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 36;
                        bf_ip += 3;
                    }
                    bf_ap += 6;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 8;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -7;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 7;
                        bf_ip += 3;
                    }
                    bf_ap += -7;
                    bf_mem[bf_ap + 7].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 6;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += 3;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 4;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 1;
                bf_mem[bf_ap + -1].data += bf_mem[bf_ap].data * -1;
                bf_mem[bf_ap + -5].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap].data = 0;
                bf_ip += 3;
                bf_ap += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -6;
                    bf_ip += 1;
                    bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 2;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 3;
                    bf_ap += 1;
                }
                bf_ap += -1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -1;
                    bf_ip += 3;
                }
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -5;
                    bf_ip += 3;
                }
                bf_ap += 6;
                bf_mem[bf_ap].data = 0;
                bf_ap += -6;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -4;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 3;
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 3;
                                bf_ip += 3;
                            }
                            bf_ap += -3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -12;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += -9;
                                }
                                bf_ap += 3;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 6;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += 9;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap].data += 1;
                                bf_ip += 1;
                                bf_ap += -1;
                            }
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 3;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -3;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -11;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += -9;
                                }
                                bf_ap += 4;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 5;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += 9;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -1;
                                bf_ip += 1;
                            }
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += -8;
                        }
                        bf_ap += 8;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -2;
                                bf_ip += 3;
                            }
                            bf_ap += 8;
                        }
                        bf_ap += -8;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 5;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -4;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 4;
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -14;
                                    bf_ip += 3;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 11;
                                    bf_ip += 1;
                                    while (bf_mem[bf_ap].data) {
                                        bf_mem[bf_ap].data += -1;
                                        bf_ap += 3;
                                        bf_mem[bf_ap].data += 1;
                                        bf_ap += -3;
                                        bf_ip += 3;
                                    }
                                    bf_ap += -1;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -2;
                            }
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 4;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                                bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -1;
                            }
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                            }
                            bf_ap += -12;
                        }
                        bf_ap += 4;
                        bf_mem[bf_ap].data = 0;
                        bf_ap += -4;
                    }
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 3;
                        bf_ip += 3;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -1;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 1;
                                bf_ip += 3;
                            }
                            bf_ap += -1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 1;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -1;
                                bf_ip += 3;
                            }
                            bf_ap += 8;
                        }
                        bf_ap += -8;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 5;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 3;
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -14;
                                    bf_ip += 3;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 10;
                                    bf_ip += 1;
                                    while (bf_mem[bf_ap].data) {
                                        bf_mem[bf_ap].data += -1;
                                        bf_ap += 4;
                                        bf_mem[bf_ap].data += 1;
                                        bf_ap += -4;
                                        bf_ip += 3;
                                    }
                                    bf_ap += 1;
                                }
                                bf_ap += -1;
                                bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -10].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -1;
                            }
                            bf_ap += 2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -4;
                                bf_ip += 3;
                                bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -10].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += 1;
                            }
                            bf_ap += -1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 4;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -4;
                                bf_ip += 3;
                            }
                            bf_ap += -11;
                        }
                        bf_ap += 6;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -6;
                    }
                }
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_ap += -4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 5;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 5;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -4;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 4;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -14;
                                bf_ip += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 11;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 3;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += -3;
                                    bf_ip += 3;
                                }
                                bf_ap += -1;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -2;
                        }
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -3;
                            bf_ip += 3;
                            bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -1;
                        }
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -3;
                            bf_ip += 3;
                        }
                        bf_ap += -12;
                    }
                }
                bf_ap += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += 2;
                for (bfint i = 0; i < 2; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += 2 - 1;
                bf_ap += 5;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 2;
                    for (bfint i = 0; i < 2; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 2 - 1;
                    bf_ap += 6;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    for (bfint i = 0; i < 9; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 9 - 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -5;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 9;
                            bf_ip += 1;
                        }
                        bf_ap += -8;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                    }
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 9;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -9;
                            bf_ip += 3;
                        }
                        bf_ap += -10;
                    }
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -7;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 7;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 3;
                    }
                    bf_ap += -2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -36;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 36;
                        bf_ip += 3;
                    }
                    bf_ap += 6;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 5;
                bf_mem[bf_ap].data = 0;
                bf_ap += 4;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -3;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 4;
                            bf_ip += 3;
                        }
                        bf_ap += -4;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -13;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 4;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 5;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += -1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -4;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_ap += -3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -12;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 3;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 6;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -1;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += -8;
                    }
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 3;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -3;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 3;
                    bf_ip += 3;
                }
                bf_ap += -3;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 3;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 6;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_ap += -3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -3;
                            bf_ip += 3;
                        }
                        bf_ap += 8;
                    }
                    bf_ap += -8;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 1;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -1;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -10;
                                bf_ip += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 12;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -2;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 2;
                                    bf_ip += 3;
                                }
                                bf_ap += -1;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap + -2].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -12].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -3;
                        }
                        bf_ap += 2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 2;
                            bf_ip += 3;
                            bf_mem[bf_ap + -2].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -12].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -1;
                        }
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 2;
                            bf_ip += 3;
                        }
                        bf_ap += -13;
                    }
                }
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_ap += -4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 5;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 3;
                        }
                        bf_ap += -2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -2;
                            bf_ip += 3;
                        }
                        bf_ap += 8;
                    }
                    bf_ap += -8;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 2;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -10;
                                bf_ip += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 11;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -1;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 1;
                                    bf_ip += 3;
                                }
                                bf_ap += 1;
                            }
                            bf_ap += -1;
                            bf_mem[bf_ap + -1].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -2;
                        }
                        bf_ap += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 1;
                            bf_ip += 3;
                            bf_mem[bf_ap + -1].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += 1;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 1;
                            bf_ip += 3;
                        }
                        bf_ap += -12;
                    }
                    bf_ap += 5;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -5;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 3;
                    for (bfint i = 0; i < 3; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 3 - 1;
                    bf_ap += 4;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 3;
                for (bfint i = 0; i < 2; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += 2 - 1;
                bf_ap += 5;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 7;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 3;
                    }
                    bf_ap += -6;
                    bf_mem[bf_ap + 6].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 4;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 1;
                bf_mem[bf_ap + -1].data += bf_mem[bf_ap].data * -1;
                bf_mem[bf_ap + -5].data += bf_mem[bf_ap].data * 1;
                bf_mem[bf_ap].data = 0;
                bf_ip += 3;
                bf_ap += 2;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -7;
                    bf_ip += 1;
                    bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 2;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 3;
                    bf_ap += 2;
                }
                bf_ap += -2;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 2;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -2;
                    bf_ip += 3;
                }
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -5;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 4;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -4;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -3;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -11;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += -9;
                                }
                                bf_ap += 4;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 5;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += 9;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap].data += 1;
                                bf_ip += 1;
                                bf_ap += -1;
                            }
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 2;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -2;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 3;
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 3;
                                bf_ip += 3;
                            }
                            bf_ap += -3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -12;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += -9;
                                }
                                bf_ap += 3;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 6;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_ap += 9;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap].data = 0;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -1;
                                bf_ip += 1;
                            }
                        }
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -1;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += -8;
                        }
                        bf_ap += 8;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 3;
                        bf_ip += 3;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -1;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 1;
                                bf_ip += 3;
                            }
                            bf_ap += -1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 1;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -1;
                                bf_ip += 3;
                            }
                            bf_ap += 8;
                        }
                        bf_ap += -8;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 4;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -2;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 2;
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -13;
                                    bf_ip += 3;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 10;
                                    bf_ip += 1;
                                    while (bf_mem[bf_ap].data) {
                                        bf_mem[bf_ap].data += -1;
                                        bf_ap += 3;
                                        bf_mem[bf_ap].data += 1;
                                        bf_ap += -3;
                                        bf_ip += 3;
                                    }
                                    bf_ap += 1;
                                }
                                bf_ap += -1;
                                bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -10].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -1;
                            }
                            bf_ap += 2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                                bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -10].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += 1;
                            }
                            bf_ap += -1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                            }
                            bf_ap += -11;
                        }
                        bf_ap += 5;
                        bf_mem[bf_ap].data = 0;
                        bf_ap += 2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -7;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 7;
                            bf_ip += 3;
                        }
                        bf_ap += -7;
                        bf_mem[bf_ap + 7].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                        bf_mem[bf_ap].data = 0;
                        bf_ip += 3;
                    }
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -2;
                                bf_ip += 3;
                            }
                            bf_ap += 8;
                        }
                        bf_ap += -8;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 4;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -3;
                                bf_ip += 3;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 3;
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += -13;
                                    bf_ip += 3;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += 11;
                                    bf_ip += 1;
                                    while (bf_mem[bf_ap].data) {
                                        bf_mem[bf_ap].data += -1;
                                        bf_ap += 2;
                                        bf_mem[bf_ap].data += 1;
                                        bf_ap += -2;
                                        bf_ip += 3;
                                    }
                                    bf_ap += -1;
                                }
                                bf_ap += 1;
                                bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -2;
                            }
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -2;
                                bf_ip += 3;
                                bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * -1;
                                bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                                bf_mem[bf_ap].data = 0;
                                bf_ip += 3;
                                bf_ap += -1;
                            }
                            bf_ap += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += -2;
                                bf_ip += 3;
                            }
                            bf_ap += -12;
                        }
                    }
                    bf_ap += 4;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -4;
                }
                bf_ap += 4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_ap += -4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 3;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += 2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -7;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 7;
                        bf_ip += 3;
                    }
                    bf_ap += -7;
                    bf_mem[bf_ap + 7].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -3;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += 3;
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -13;
                                bf_ip += 3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 11;
                                bf_ip += 1;
                                while (bf_mem[bf_ap].data) {
                                    bf_mem[bf_ap].data += -1;
                                    bf_ap += 2;
                                    bf_mem[bf_ap].data += 1;
                                    bf_ap += -2;
                                    bf_ip += 3;
                                }
                                bf_ap += -1;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -2;
                        }
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -2;
                            bf_ip += 3;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * -1;
                            bf_mem[bf_ap + -11].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_ap += -1;
                        }
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -2;
                            bf_ip += 3;
                        }
                        bf_ap += -12;
                    }
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 2;
                    for (bfint i = 0; i < 2; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 2 - 1;
                    bf_ap += 6;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 3;
                for (bfint i = 0; i < 2; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += 2 - 1;
                bf_ap += 5;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 1].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -5;
                    bf_mem[bf_ap + 5].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ip += 3;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    for (bfint i = 0; i < 9; i++) {
                        bf_mem[bf_ap + i].data = 0;
                    }
                    bf_ap += 9 - 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -5;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 2;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -2;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 2;
                                bf_ip += 3;
                            }
                            bf_ap += -2;
                            bf_mem[bf_ap + 2].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 9;
                            bf_ip += 1;
                        }
                        bf_ap += -8;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                    }
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 9;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -9;
                            bf_ip += 3;
                        }
                        bf_ap += -10;
                    }
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -6;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 6;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 4;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -3;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_ap += -5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 5;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -6;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_mem[bf_ap].data += -1;
                                bf_ap += -3;
                                bf_mem[bf_ap].data += 1;
                                bf_ap += 3;
                                bf_ip += 3;
                            }
                            bf_ap += -3;
                            bf_mem[bf_ap + 3].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap + 4].data += bf_mem[bf_ap].data * 1;
                            bf_mem[bf_ap].data = 0;
                            bf_ip += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 9;
                            bf_ip += 1;
                        }
                        bf_ap += -8;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                    }
                    bf_ap += 9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 2;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 9;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -9;
                            bf_ip += 3;
                        }
                        bf_ap += -11;
                    }
                    bf_ap += 2;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += -2;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -6;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 6;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 4;
                    }
                    bf_ap += -3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -3;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -36;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 36;
                        bf_ip += 3;
                    }
                    bf_ap += 5;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                bf_mem[bf_ap].data += 15;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += -9;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 9;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 21;
                bf_mem[bf_ap].data += 1;
                bf_ap += -3;
                bf_ip += 3;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -3;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -3;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 3;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 4;
                            bf_ip += 3;
                        }
                        bf_ap += -4;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 4;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -13;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 4;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 5;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += -1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -4;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 3;
                            bf_ip += 3;
                        }
                        bf_ap += -3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 3;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -12;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 3;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 6;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -1;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += -8;
                    }
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 2;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 2;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 4;
                    bf_ip += 3;
                }
                bf_ap += -4;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 4;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -2;
                    bf_ip += 3;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -2;
                }
                bf_ap += 2;
            }
            bf_ap += -2;
            bf_mem[bf_ap].data += 1;
            bf_ip += 1;
            bf_ap += 4;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -4;
                bf_mem[bf_ap].data += -1;
                bf_ap += 4;
                bf_ip += 3;
            }
            bf_mem[bf_ap].data += 1;
            bf_ap += -4;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 4;
                bf_mem[bf_ap].data += -1;
                bf_ap += -6;
                bf_ip += 3;
                putchar(bf_mem[bf_ap].data);
                bf_ap += 2;
            }
            bf_ap += 4;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -7;
                bf_ip += 1;
                putchar(bf_mem[bf_ap].data);
                bf_ap += 7;
            }
            bf_ap += -3;
            for (bfint i = 0; i < 6; i++) {
                bf_mem[bf_ap + i].data = 0;
            }
            bf_ap += 6 - 1;
            bf_ap += 3;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                for (bfint i = 0; i < 6; i++) {
                    bf_mem[bf_ap + i].data = 0;
                }
                bf_ap += 6 - 1;
                bf_ap += 3;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 5;
                bf_mem[bf_ap].data = 0;
                bf_ap += 4;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 1;
            bf_mem[bf_ap].data += 11;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 9;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -9;
                    bf_ip += 3;
                }
                bf_ap += 9;
            }
            bf_ap += 4;
            bf_mem[bf_ap].data += 1;
            bf_ap += 9;
            bf_mem[bf_ap].data += 1;
            bf_ip += 3;
            bf_ap += -14;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 7;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -7;
                bf_mem[bf_ap].data += 1;
                bf_ap += 7;
                bf_ip += 3;
            }
            bf_ap += -7;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 7;
                bf_ip += 1;
                bf_mem[bf_ap].data += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += 2;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 7;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 3;
                    }
                    bf_ap += -6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -7;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                        bf_ap += 7;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 3;
                        bf_ip += 1;
                    }
                    bf_ap += -10;
                }
            }
            bf_ap += 7;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -7;
                bf_mem[bf_ap].data += 1;
                bf_ap += 7;
                bf_ip += 3;
            }
            bf_ap += -7;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 7;
                bf_mem[bf_ap].data += 1;
                bf_ap += 2;
                bf_ip += 3;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += 4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -4;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_ip += 3;
                    }
                    bf_ap += -4;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 4;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -4;
                        bf_ip += 3;
                    }
                    bf_ap += 8;
                }
                bf_ap += -2;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -7;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 3;
                    }
                    bf_ap += -14;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 9;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 7;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -7;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 3;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 7;
                    }
                    bf_ap += -6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -6;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 7;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += -4;
                bf_mem[bf_ap].data = 0;
                bf_mem[bf_ap].data += 1;
                bf_ap += -3;
                bf_ip += 1;
            }
            bf_mem[bf_ap].data += 1;
            bf_ap += 7;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += -7;
                bf_mem[bf_ap].data += -1;
                bf_ap += 7;
                bf_ip += 3;
            }
            bf_mem[bf_ap].data += 1;
            bf_ap += -7;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 7;
                bf_mem[bf_ap].data += -1;
                bf_ap += 2;
                bf_ip += 3;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -2;
                        bf_ip += 3;
                    }
                    bf_ap += 4;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 1;
                    bf_mem[bf_ap].data = 0;
                    bf_ap += -1;
                    bf_mem[bf_ap].data += -1;
                    bf_ip += 1;
                    bf_ap += 7;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -7;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 1;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -1;
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += -1;
                            bf_ip += 3;
                            bf_ap += -3;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += 3;
                        }
                        bf_ap += -1;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 3;
                        }
                        bf_ap += 7;
                    }
                    bf_ap += -6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -6;
                        bf_ip += 3;
                    }
                    bf_ap += -1;
                    bf_mem[bf_ap].data += 1;
                    bf_ip += 1;
                    bf_ap += -9;
                }
                bf_ap += 1;
                bf_mem[bf_ap].data += 5;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += 9;
                }
                bf_ap += 4;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += 5;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -5;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 5;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -5;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 5;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 2;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -7;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 7;
                            bf_ip += 3;
                        }
                        bf_ap += -7;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 7;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -16;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 4;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 5;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data += 1;
                            bf_ip += 1;
                            bf_ap += -1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 7;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -7;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 7;
                        bf_ip += 3;
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -7;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 7;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -2;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += -5;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 5;
                            bf_ip += 3;
                        }
                        bf_ap += -5;
                        while (bf_mem[bf_ap].data) {
                            bf_mem[bf_ap].data += -1;
                            bf_ap += 5;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -14;
                            bf_ip += 3;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += -9;
                            }
                            bf_ap += 3;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += 6;
                            bf_ip += 1;
                            while (bf_mem[bf_ap].data) {
                                bf_ap += 9;
                            }
                            bf_ap += 1;
                            bf_mem[bf_ap].data = 0;
                            bf_mem[bf_ap].data += 1;
                            bf_ap += -1;
                            bf_ip += 1;
                        }
                    }
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -1;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += -8;
                    }
                    bf_ap += 8;
                }
                bf_ap += -9;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
                bf_ap += 4;
                bf_mem[bf_ap].data = 0;
                bf_ap += -3;
                bf_mem[bf_ap].data += 5;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 9;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -9;
                        bf_ip += 3;
                    }
                    bf_ap += 9;
                }
                bf_ap += 4;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_ap += -9;
                }
            }
            bf_ap += 3;
        }
        bf_ap += -4;
        putchar(bf_mem[bf_ap].data);
        bf_ap += 10;
        while (bf_mem[bf_ap].data) {
            bf_ap += 6;
            bf_mem[bf_ap].data = 0;
            bf_ap += 3;
        }
        bf_ap += -9;
        while (bf_mem[bf_ap].data) {
            bf_ap += -9;
        }
        bf_ap += 1;
        bf_mem[bf_ap].data += 10;
        bf_ip += 1;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                bf_ap += 9;
                bf_mem[bf_ap].data += 1;
                bf_ap += -9;
                bf_ip += 3;
            }
            bf_ap += 9;
        }
        bf_ap += 5;
        bf_mem[bf_ap].data += 1;
        bf_ap += 9;
        bf_mem[bf_ap].data += 1;
        bf_ip += 3;
        bf_ap += -15;
        while (bf_mem[bf_ap].data) {
            bf_ap += -9;
        }
        bf_ap += 8;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += -8;
            bf_mem[bf_ap].data += 1;
            bf_ap += 8;
            bf_ip += 3;
        }
        bf_ap += -8;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += 8;
            bf_ip += 1;
            bf_mem[bf_ap].data += 1;
            bf_mem[bf_ap].data = 0;
            bf_ap += 1;
            while (bf_mem[bf_ap].data) {
                bf_ap += 9;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 8;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -7;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 7;
                    bf_ip += 3;
                }
                bf_ap += -7;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 7;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -8;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -9;
                    }
                    bf_ap += 8;
                    bf_mem[bf_ap].data = 0;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 2;
                    bf_ip += 1;
                }
                bf_ap += -10;
            }
        }
        bf_ap += 8;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += -8;
            bf_mem[bf_ap].data += 1;
            bf_ap += 8;
            bf_ip += 3;
        }
        bf_ap += -8;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += 8;
            bf_mem[bf_ap].data += 1;
            bf_ap += 1;
            bf_ip += 3;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += 5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -5;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_ip += 3;
                }
                bf_ap += -5;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 5;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -5;
                    bf_ip += 3;
                }
                bf_ap += 8;
            }
            bf_ap += -1;
            bf_mem[bf_ap].data += 1;
            bf_ip += 1;
            bf_ap += -8;
            while (bf_mem[bf_ap].data) {
                bf_ap += 6;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 2;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -2;
                    bf_ip += 3;
                }
                bf_ap += -15;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 9;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += -1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 8;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -8;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -1;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += -1;
                        bf_ip += 3;
                        bf_ap += -2;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 2;
                    }
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 3;
                    }
                    bf_ap += 8;
                }
                bf_ap += -7;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 7;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -7;
                    bf_ip += 3;
                }
                bf_ap += -1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -9;
            }
            bf_ap += 8;
            bf_mem[bf_ap].data += -1;
            bf_ip += 1;
            bf_ap += -5;
            bf_mem[bf_ap].data = 0;
            bf_mem[bf_ap].data += 1;
            bf_ap += -3;
            bf_ip += 1;
        }
        bf_mem[bf_ap].data += 1;
        bf_ap += 8;
        bf_ip += 1;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += -8;
            bf_mem[bf_ap].data += -1;
            bf_ap += 8;
            bf_ip += 3;
        }
        bf_mem[bf_ap].data += 1;
        bf_ap += -8;
        bf_ip += 1;
        while (bf_mem[bf_ap].data) {
            bf_mem[bf_ap].data += -1;
            bf_ap += 8;
            bf_mem[bf_ap].data += -1;
            bf_ap += 1;
            bf_ip += 3;
            while (bf_mem[bf_ap].data) {
                bf_ap += 6;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 2;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -2;
                    bf_ip += 3;
                }
                bf_ap += 3;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 1;
                bf_mem[bf_ap].data = 0;
                bf_ap += -1;
                bf_mem[bf_ap].data += -1;
                bf_ip += 1;
                bf_ap += 8;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -8;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += 1;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += -1;
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += -1;
                        bf_ip += 3;
                        bf_ap += -2;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += 2;
                    }
                    bf_ap += -1;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 3;
                    }
                    bf_ap += 8;
                }
                bf_ap += -7;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 7;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -7;
                    bf_ip += 3;
                }
                bf_ap += -1;
                bf_mem[bf_ap].data += 1;
                bf_ip += 1;
                bf_ap += -9;
            }
            bf_ap += 1;
            bf_mem[bf_ap].data += 5;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 9;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -9;
                    bf_ip += 3;
                }
                bf_ap += 9;
            }
            bf_ap += 5;
            bf_mem[bf_ap].data += 1;
            bf_ap += 27;
            bf_mem[bf_ap].data += 1;
            bf_ip += 3;
            bf_ap += -6;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 9;
            while (bf_mem[bf_ap].data) {
                bf_ap += 6;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -6;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 6;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -6;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 6;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 2;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -8;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 8;
                        bf_ip += 3;
                    }
                    bf_ap += -8;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 8;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -17;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                        bf_ap += 4;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 5;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += 1;
                        bf_mem[bf_ap].data += 1;
                        bf_ip += 1;
                        bf_ap += -1;
                    }
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 8;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -8;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 8;
                    bf_ip += 3;
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += -8;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 8;
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -2;
                    bf_ip += 3;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += -6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 3;
                    }
                    bf_ap += -6;
                    while (bf_mem[bf_ap].data) {
                        bf_mem[bf_ap].data += -1;
                        bf_ap += 6;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -15;
                        bf_ip += 3;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += -9;
                        }
                        bf_ap += 3;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += 6;
                        bf_ip += 1;
                        while (bf_mem[bf_ap].data) {
                            bf_ap += 9;
                        }
                        bf_ap += 1;
                        bf_mem[bf_ap].data = 0;
                        bf_mem[bf_ap].data += 1;
                        bf_ap += -1;
                        bf_ip += 1;
                    }
                }
                bf_mem[bf_ap].data += 1;
                bf_ap += 1;
                bf_ip += 1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += -1;
                    bf_ip += 1;
                    while (bf_mem[bf_ap].data) {
                        bf_ap += 9;
                    }
                    bf_ap += -8;
                }
                bf_ap += 8;
            }
            bf_ap += -9;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
            bf_ap += 4;
            bf_mem[bf_ap].data = 0;
            bf_ap += -3;
            bf_mem[bf_ap].data += 5;
            bf_ip += 1;
            while (bf_mem[bf_ap].data) {
                bf_mem[bf_ap].data += -1;
                while (bf_mem[bf_ap].data) {
                    bf_mem[bf_ap].data += -1;
                    bf_ap += 9;
                    bf_mem[bf_ap].data += 1;
                    bf_ap += -9;
                    bf_ip += 3;
                }
                bf_ap += 9;
            }
            bf_ap += 5;
            bf_mem[bf_ap].data += -1;
            bf_ap += 27;
            bf_mem[bf_ap].data += -1;
            bf_ip += 3;
            bf_ap += -6;
            while (bf_mem[bf_ap].data) {
                bf_ap += -9;
            }
        }
        bf_ap += 3;
    }
    printf("%f\n", (double)(clock() - clock_start) / CLOCKS_PER_SEC);
}