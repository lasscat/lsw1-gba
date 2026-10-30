extern struct {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
} gUnknown_03002E74[];

void sub_080087DC(int arg0)
{
    arg0 <<= 2;
    gUnknown_03002E74[arg0].unk0 |= 2;
    gUnknown_03002E74[arg0].unk3 = 1;
}
