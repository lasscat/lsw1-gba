struct S03004980 {
    char pad_00[0xd];
    unsigned char lo : 2;
    unsigned char hi : 6;
    char pad_0e[0x38 - 0xe];
    int w38;
};

extern struct S03004980 gUnknown_03004980;

int sub_08017C38(int);
int sub_08017EE8(int);
int sub_08017F30(int);
int sub_08017F70(int);
void sub_0801BD2C(void);
void sub_0801BD50(void);

int sub_08017BC4(int a)
{
    struct S03004980 *p = &gUnknown_03004980;
    int v;

    p->lo = a + 1;
    sub_08017C38(a);
    sub_0801BD2C();
    if (sub_08017F70(a) == 0) {
        sub_0801BD50();
        return 0;
    }
    if (sub_08017F30(a) == 0) {
        sub_0801BD50();
        return 0;
    }
    sub_0801BD50();
    v = sub_08017EE8(a);
    if (v == 0)
        return 0;
    p->w38 = a;
    return v;
}
