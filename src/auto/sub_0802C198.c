extern void sub_08017A20(void *src, int len);
extern void sub_08017A6C(void *src, int len);
extern void sub_0802C910(void);

extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_03004980[];
extern unsigned int gUnknown_03006B14;

void sub_0802C198(void)
{
    unsigned int i;

    sub_08017A20(&gUnknown_03006B1C[0x296], 3);
    sub_08017A20(&gUnknown_03006B1C[0x3AC], 4);
    sub_08017A20(&gUnknown_03006B1C[0x295], 1);
    for (i = 0; i <= 2; i++)
        sub_08017A20(&gUnknown_03006B1C[0x3B6 + i * 2], 2);
    for (i = 0; i <= 2; i++)
        sub_08017A20(&gUnknown_03006B1C[0x3BC + i * 2], 2);
    for (i = 0; i <= 2; i++)
        sub_08017A20(&gUnknown_03006B1C[0x3C2 + i * 2], 2);
    for (i = 0; i <= 13; i++)
        sub_08017A6C(&gUnknown_03006B1C[0x3DC + i], 1);
    for (i = 0; i <= 13; i++)
        sub_08017A20(&gUnknown_03006B1C[0x3EA + i * 2], 2);
    for (i = 0; i <= 13; i++)
        sub_08017A20(&gUnknown_03006B1C[0x406 + i * 2], 2);
    for (i = 0; i <= 13; i++)
        sub_08017A20(&gUnknown_03006B1C[0x422 + i * 2], 2);
    sub_08017A20(&gUnknown_03006B1C[0x440], 4);
    sub_08017A20(&gUnknown_03006B1C[0x3CE], 0xe);
    sub_08017A20(&gUnknown_03006B1C[0x446], 2);
    sub_08017A20(&gUnknown_03006B1C[0x448], 2);
    gUnknown_03006B1C[0x281] = gUnknown_03004980[9];
    gUnknown_03006B1C[0x280] = gUnknown_03004980[8];
    sub_0802C910();
    if (gUnknown_03004980[0xd] & 0x40)
        gUnknown_03006B14 |= 0x400;
    else
        gUnknown_03006B14 &= ~0x400;
}
