extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_0300332C[];

typedef struct {
    unsigned char a[12];
    unsigned short b;
    unsigned char c[110];
} S758;

void sub_0802C758(void)
{
    gUnknown_03006B1C[0x299] = 0;
    ((S758 *)gUnknown_0300332C)[gUnknown_0300332C[0xB9]].b = 0;
}
