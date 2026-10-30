struct BoxState
{
    int field_00;
    int field_04;
    int x1;
    int y1;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int x2;
    int y2;
};

extern struct BoxState gUnknown_03006960;

extern void sub_0801EABC(int idx, int x1, int y1, int x2, int y2);
extern void sub_0801EB1C(int idx, int sub, int a, int b, unsigned short c);
extern void sub_08005648(unsigned short a);

void sub_0801ECD0(unsigned short a)
{
    int midX = (gUnknown_03006960.x2 - gUnknown_03006960.x1) / 2 + gUnknown_03006960.x1;
    int midY = (gUnknown_03006960.y2 - gUnknown_03006960.y1) / 2 + gUnknown_03006960.y1;

    sub_0801EABC(0, midX, midY, midX, midY);
    sub_0801EB1C(0, 0, gUnknown_03006960.x1, gUnknown_03006960.y1, a);
    sub_0801EB1C(0, 1, gUnknown_03006960.x2, gUnknown_03006960.y2, a);
    sub_08005648(0x6000);
}
