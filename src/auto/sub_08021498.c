typedef struct {
    unsigned char pad00[0x0c];
    unsigned int f0c;
} Struct_0300368C;

typedef struct {
    unsigned char pad00[0x0c];
    void *fc;
    unsigned char pad10[0x60];
    int f70;
} Struct_030069D8;

extern Struct_0300368C gUnknown_0300368C;
extern Struct_030069D8 *gUnknown_030069D8;
extern unsigned char gUnknown_030069E4;

char *sub_08020B40(unsigned int a);
int sub_08021574(void *r0, void *r1);
int sub_08021358(void);
void sub_080215FC(void *r0, int r1, int r2, int r3);

void sub_08021498(void)
{
    char *s = sub_08020B40(gUnknown_0300368C.f0c);
    int v = sub_08021574(gUnknown_030069D8->fc, s);
    int w = sub_08021358();
    gUnknown_030069D8->f70 = w;
    sub_080215FC(gUnknown_030069D8->fc, v << 16, w, 0xB0000);
    gUnknown_030069E4 = 1;
}
