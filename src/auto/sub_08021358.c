extern char *sub_08020B40(unsigned int a);

typedef struct {
    unsigned char pad[0x74];
    int f74;
} Struct_030069D8;

extern Struct_030069D8 *gUnknown_030069D8;
extern int gUnknown_0300368C[];

unsigned int sub_08021358(void)
{
    unsigned int n = 0;
    int *p;

    gUnknown_0300368C[2] = gUnknown_0300368C[3];
    p = gUnknown_0300368C;
    do {
        sub_08020B40(p[2]);
        if (gUnknown_030069D8->f74 == 3)
            n++;
        p[2]++;
    } while (gUnknown_030069D8->f74 != 5);
    return ((0xA0 - n * 9) / 2) << 16;
}
