extern void sub_08005674(int arg0);
extern void sub_08013DB4(unsigned int arg0);
extern void sub_080187F8(unsigned short a, int b);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_08022FD8(int a);
extern void sub_08031644(int, int);
extern int sub_080316D4(int idx);

extern unsigned int gUnknown_0300368C[];
extern unsigned char gUnknown_03006B1C[];

typedef struct {
    int unk0;
    int unk4;
} TableEntry;

extern TableEntry gUnknown_0804CBB0[];

void sub_08022ED0(void)
{
    unsigned int *p = gUnknown_0300368C;

    switch (p[4]) {
    case 0:
        if (sub_080316D4(0) != 0) {
            sub_08018840(0x3f, 2);
            p[4] = 1;
        }
        break;
    case 1: {
        unsigned char *t;
        unsigned int i;
        int off;
        unsigned int *kp;
        sub_08005674(1);
        t = (unsigned char *)gUnknown_0804CBB0;
        i = gUnknown_03006B1C[0x283];
        off = i << 3;
        kp = (unsigned int *)(t + 4);
        sub_08022FD8(*(unsigned int *)((unsigned char *)kp + off));
        sub_080187F8(0x3f, 2);
        sub_08031644(0, 0x1e);
        p[4] = 2;
        break;
    }
    case 2:
        if (sub_080316D4(0) != 0) {
            sub_08013DB4(1);
        }
        break;
    }
}
