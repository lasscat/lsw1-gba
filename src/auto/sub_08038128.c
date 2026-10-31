typedef void (*Fn38128)(void *, unsigned int, int);

struct Tbl38128A {
    unsigned char pad[20];
    unsigned char sel;
    unsigned char pad2[3];
};

struct Tbl38128B {
    Fn38128 fn;
    unsigned char pad[20];
};

struct Tbl38128BH {
    unsigned char hdr[20];
    struct Tbl38128B items[1];
};

extern struct Tbl38128BH gUnknown_08056D30;
extern struct Tbl38128A gUnknown_08056D60[];

void sub_08038128(void *a, unsigned int b, int c)
{
    if (((unsigned char *)a)[0xe2] != 0x19) {
        struct Tbl38128BH *p2 = &gUnknown_08056D30;
        struct Tbl38128A *p1 = gUnknown_08056D60;
        unsigned char i = ((unsigned char *)a)[0x119];
        unsigned char j = p1[i].sel;
        p2->items[j].fn(a, b, c);
    }
}
