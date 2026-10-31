typedef struct {
    unsigned char pad00[0x0c];
    unsigned int f0c;
    unsigned int f10;
} Struct_0300368C;

extern Struct_0300368C gUnknown_0300368C;
extern void *gUnknown_030069D8;
extern unsigned char gUnknown_030069E8;
extern unsigned char gUnknown_030069EC;
extern int gUnknown_030069DC;

int sub_080316D4(int idx);

void sub_08021294(void)
{
    if (sub_080316D4(1) != 0) {
        *(unsigned int *)((unsigned char *)gUnknown_030069D8 + 0x64) = 0;
        gUnknown_030069E8 = 1;
        gUnknown_030069EC = 1;
        if (gUnknown_030069DC < 0)
            gUnknown_0300368C.f10 = 0;
    }
}
