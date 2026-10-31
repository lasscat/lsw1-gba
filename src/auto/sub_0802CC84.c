extern unsigned char gUnknown_03006B1C[];

void sub_0802CC84(unsigned int arg0)
{
    if (arg0 > (&gUnknown_03006B1C[0x3DC])[gUnknown_03006B1C[0x292]])
        (&gUnknown_03006B1C[0x3DC])[gUnknown_03006B1C[0x292]] = arg0;
    if (*(unsigned short *)(gUnknown_03006B1C + 0x3B0) > *(unsigned short *)(gUnknown_03006B1C + 0x3EA + (gUnknown_03006B1C[0x292] << 1)))
        *(unsigned short *)(gUnknown_03006B1C + 0x3EA + (gUnknown_03006B1C[0x292] << 1)) = *(unsigned short *)(gUnknown_03006B1C + 0x3B0);
    if (*(unsigned short *)(gUnknown_03006B1C + 0x3B2) > *(unsigned short *)(gUnknown_03006B1C + 0x406 + (gUnknown_03006B1C[0x292] << 1)))
        *(unsigned short *)(gUnknown_03006B1C + 0x406 + (gUnknown_03006B1C[0x292] << 1)) = *(unsigned short *)(gUnknown_03006B1C + 0x3B2);
    if (*(unsigned short *)(gUnknown_03006B1C + 0x3B4) > *(unsigned short *)(gUnknown_03006B1C + 0x422 + (gUnknown_03006B1C[0x292] << 1)))
        *(unsigned short *)(gUnknown_03006B1C + 0x422 + (gUnknown_03006B1C[0x292] << 1)) = *(unsigned short *)(gUnknown_03006B1C + 0x3B4);
}
