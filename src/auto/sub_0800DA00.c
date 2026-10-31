extern int gUnknown_0300340C;
void *sub_08033374(int a, int b);

struct G {
    unsigned char pad0[0x29A];
    unsigned char f29A;
    unsigned char pad1[0x44C - 0x29B];
    unsigned int f44C[3];
    unsigned char f458[3];
    unsigned char f45B;
    unsigned char f45C;
};
extern struct G gUnknown_03006B1C;

void sub_0800DA00(unsigned char *a0)
{
    gUnknown_03006B1C.f44C[gUnknown_03006B1C.f45C] = (unsigned int)(a0[4] << 19);
    gUnknown_03006B1C.f458[gUnknown_03006B1C.f45C] = a0[5];
    if (gUnknown_03006B1C.f458[gUnknown_03006B1C.f45C] == 2 && gUnknown_03006B1C.f45B == 0) {
        sub_08033374(gUnknown_0300340C, 0x3C);
        gUnknown_03006B1C.f45B = 1;
    } else {
        if ((unsigned char)(gUnknown_03006B1C.f458[gUnknown_03006B1C.f45C] - 3) <= 1) {
            if (gUnknown_03006B1C.f45B == 0) {
                sub_08033374(gUnknown_0300340C, 0x3D);
                gUnknown_03006B1C.f45B = 1;
                if (gUnknown_03006B1C.f458[gUnknown_03006B1C.f45C] == 3)
                    gUnknown_03006B1C.f29A |= 0x20;
            }
        }
    }
    gUnknown_03006B1C.f45C++;
}
