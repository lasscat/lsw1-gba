struct Obj {
    unsigned char pad0[0x58];
    unsigned int flags;
    unsigned char pad1[0xb3 - 0x5c];
    unsigned char b3;
};

struct Holder {
    unsigned int o0;
    unsigned int o4;
    unsigned int o8;
    unsigned int oC;
    unsigned int o10;
    unsigned char pad[0x4c - 0x14];
    unsigned int o4c;
    unsigned int o50;
};

extern struct Holder *gUnknown_030069FC;
extern unsigned char gUnknown_030000C8[];
extern unsigned char gUnknown_030000D8[];
extern unsigned char gUnknown_030000D0[];
extern unsigned char gUnknown_030000E0[];
extern unsigned char gUnknown_030000E8[];
extern unsigned char gUnknown_030000F0[];
extern unsigned char gUnknown_08E010BC[];
extern unsigned char gUnknown_08E02A60[];
extern unsigned char gUnknown_08E01BF4[];
extern unsigned char gUnknown_08E010DC[];
extern unsigned char gUnknown_08E0306C[];
extern unsigned char gUnknown_08E02A80[];
extern unsigned char gUnknown_08EBA390[];
extern unsigned char gUnknown_08E00BA4[];
extern unsigned char gUnknown_08E00A58[];
extern unsigned char gUnknown_0804CC5C[];
extern unsigned char gUnknown_0804CC6C[];
extern unsigned char gUnknown_0804CC7C[];

extern unsigned int sub_0802D28C(int arg0, int arg1, int arg2, int arg3);
extern void sub_08009F98(int a, int b, int c);
extern void sub_0800074C(unsigned int arg0, void *arg1);
extern void sub_08000C7C(unsigned int arg0, void *arg1, void *arg2, int arg3);

void sub_080237B8(void)
{
    gUnknown_030069FC->o0 = sub_0802D28C(0x3B, 0x11C, (int)gUnknown_030000C8, 2);
    sub_08009F98((int)gUnknown_08E010BC, 0x20, 0x10);
    sub_0800074C(gUnknown_030069FC->o0, gUnknown_0804CC5C);
    ((struct Obj *)gUnknown_030069FC->o0)->flags |= 0x10;
    ((struct Obj *)gUnknown_030069FC->o0)->flags &= ~1;

    gUnknown_030069FC->o8 = sub_0802D28C(0x92, 0x11C, (int)gUnknown_030000D8, 3);
    sub_08009F98((int)gUnknown_08E02A60, 0x30, 0x10);
    sub_0800074C(gUnknown_030069FC->o8, gUnknown_0804CC6C);
    ((struct Obj *)gUnknown_030069FC->o8)->flags |= 0x10;
    ((struct Obj *)gUnknown_030069FC->o8)->flags &= ~1;

    gUnknown_030069FC->o4 = sub_0802D28C(0x73, 0x11C, (int)gUnknown_030000D0, 4);
    sub_08009F98((int)gUnknown_08E01BF4, 0x40, 0x10);
    sub_08000C7C(gUnknown_030069FC->o4, gUnknown_030000D0, gUnknown_08E010DC, 0);
    ((struct Obj *)gUnknown_030069FC->o4)->flags |= 0x10;
    ((struct Obj *)gUnknown_030069FC->o4)->flags &= ~1;

    gUnknown_030069FC->oC = sub_0802D28C(0xAD, 0x11C, (int)gUnknown_030000E0, 5);
    sub_08009F98((int)gUnknown_08E0306C, 0x50, 0x10);
    sub_08000C7C(gUnknown_030069FC->oC, gUnknown_030000E0, gUnknown_08E02A80, 0);
    ((struct Obj *)gUnknown_030069FC->oC)->flags |= 0x10;
    ((struct Obj *)gUnknown_030069FC->oC)->flags &= ~1;

    gUnknown_030069FC->o10 = sub_0802D28C(0xC7, 0x112, (int)gUnknown_030000E8, 6);
    sub_08009F98((int)gUnknown_08EBA390, 0x60, 0x10);
    sub_0800074C(gUnknown_030069FC->o10, gUnknown_0804CC7C);
    ((struct Obj *)gUnknown_030069FC->o10)->flags |= 0x10;
    ((struct Obj *)gUnknown_030069FC->o10)->flags &= ~1;

    sub_08009F98((int)gUnknown_08E00BA4, 0x70, 0x10);
    gUnknown_030069FC->o4c = sub_0802D28C(-0x14, 0x4C, (int)gUnknown_030000F0, 7);
    sub_08000C7C(gUnknown_030069FC->o4c, gUnknown_030000F0, gUnknown_08E00A58, 0);
    ((struct Obj *)gUnknown_030069FC->o4c)->flags |= 0x10;

    gUnknown_030069FC->o50 = sub_0802D28C(0x104, 0x4C, (int)gUnknown_030000F0, 7);
    sub_08000C7C(gUnknown_030069FC->o50, gUnknown_030000F0, gUnknown_08E00A58, 0);
    *(unsigned char *)(gUnknown_030069FC->o50 + 0xB3) |= 0x10;
    ((struct Obj *)gUnknown_030069FC->o50)->flags |= 0x10;
}
