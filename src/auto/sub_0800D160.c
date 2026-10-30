extern unsigned char *gUnknown_0300340C;
extern unsigned int gUnknown_0300332C[];
extern unsigned char gUnknown_03006B1C[];

extern unsigned char sub_08042934(unsigned char arg);
extern void sub_08042808(void);

struct Unk {
    unsigned char pad0[0x8c];
    unsigned int flags;
    unsigned char pad1[0x2f];
    unsigned char byte_bf;
    unsigned char table[1];
};

void sub_0800D160(unsigned char *arg)
{
    short *sp = (short *)(gUnknown_0300340C + 0xd8);

    if (sp[0] > 0 || (gUnknown_0300332C[0x23] & 1)) {
        gUnknown_03006B1C[0x293] = sub_08042934(arg[4]);
        gUnknown_03006B1C[0x299] = arg[5];
        {
            struct Unk *b = (struct Unk *)gUnknown_0300332C;
            gUnknown_03006B1C[0x29D] = b->table[(signed char)b->byte_bf];
        }
        *(unsigned int *)(gUnknown_0300340C + 0xd4) |= 0x01000000;
        sub_08042808();
    }
}
