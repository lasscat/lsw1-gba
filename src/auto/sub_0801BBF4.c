extern unsigned int gUnknown_03004E34[];
extern unsigned int gUnknown_03004E74[];
extern unsigned char gUnknown_03004E24[];
extern int sub_03000BA4_veneer(int, int);

void sub_0801BBF4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    unsigned int b34;
    int off;
    unsigned int pbase;
    unsigned int b24;
    unsigned int vram;
    unsigned int a3;
    int tile;
    unsigned short *dst;
    unsigned int t;
    unsigned int pal;

    b34 = (unsigned int)gUnknown_03004E34;
    off = arg2 * 4;
    b34 += 16;
    pbase = *(unsigned int *)(b34 + off) + *(unsigned int *)((unsigned int)gUnknown_03004E74 + arg2 * 4) + (arg5 << 4);
    b24 = (unsigned int)gUnknown_03004E24;
    vram = ((((unsigned int)((unsigned char *)(b24 + arg2 * 4))[1] << 27) >> 16) + 0x06000000);
    vram += (arg4 & 0x1F) << 6;
    a3 = arg3 & 0x1F;
    tile = sub_03000BA4_veneer(arg0, arg1);
    dst = (unsigned short *)((a3 << 1) + vram);
    *dst = tile;
    arg4 &= 3;
    t = arg4 << 2;
    arg3 &= 3;
    pal = ((unsigned char *)pbase)[t + arg3];
    *dst = (pal << 10) | tile;
}
