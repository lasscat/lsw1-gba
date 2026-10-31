struct Sub0800E410Item {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char field3;
    unsigned short field4;
    unsigned short field6;
};

extern int gUnknown_030031D4;
extern struct Sub0800E410Item *gUnknown_030031D0;

void sub_0800E410(unsigned char a0, unsigned short a1, unsigned short a2, unsigned char a3)
{
    gUnknown_030031D0[gUnknown_030031D4].field0 = a0;
    gUnknown_030031D0[gUnknown_030031D4].field1 = 0;
    gUnknown_030031D0[gUnknown_030031D4].field2 = 1;
    gUnknown_030031D0[gUnknown_030031D4].field3 = a3;
    gUnknown_030031D0[gUnknown_030031D4].field4 = a1;
    gUnknown_030031D0[gUnknown_030031D4].field6 = a2;
    gUnknown_030031D4++;
}
