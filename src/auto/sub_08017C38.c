struct S03004980
{
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    int unk_30;
    int unk_34;
    int unk_38;
    int unk_3C;
    int unk_40;
    int unk_44;
    int unk_48;
};

extern struct S03004980 gUnknown_03004980;

void sub_08017948(void);
void sub_0802C2F8(void);
int sub_08047BE4(int, int);
unsigned short sub_08018028(const unsigned short *arr, int count);

void sub_08017C38(void)
{
    struct S03004980 *p;
    int base;
    unsigned short *buf;
    int v;

    sub_08017948();
    p = &gUnknown_03004980;
    base = p->unk_10;
    buf = (unsigned short *)base;
    p->unk_3C = base;
    p->unk_40 = 0;
    sub_0802C2F8();
    v = p->unk_3C - base;
    p->unk_44 = v;
    p->unk_48 = sub_08047BE4(v * 100, 160);
    buf[79] = 0;
    buf[79] = -sub_08018028(buf, 160);
}
