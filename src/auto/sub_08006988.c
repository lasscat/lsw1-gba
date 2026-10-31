typedef struct {
    char pad1[24];
    int field18;
    int field1c;
    int field20;
    int field24;
    char pad2[28];
    unsigned short flag44;
    char pad3[30];
} Entry;

extern Entry gUnknown_03002C50[];

void sub_08006988(int index, int x, int y)
{
    gUnknown_03002C50[index].field20 = x;
    gUnknown_03002C50[index].field24 = y;
    gUnknown_03002C50[index].field18 = x;
    gUnknown_03002C50[index].field1c = y;
    gUnknown_03002C50[index].flag44 |= 0x8000;
}
