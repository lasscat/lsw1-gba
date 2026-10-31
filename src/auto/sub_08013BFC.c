struct S08013BFC {
    int a[6];
};
extern struct S08013BFC gUnknown_0300368C;
extern struct S08013BFC gUnknown_030036A4;
extern struct S08013BFC gUnknown_030036BC;
extern unsigned char gUnknown_03004980[];
void sub_08013DB4(unsigned int arg0);

void sub_08013BFC(void)
{
    gUnknown_0300368C.a[0] = 0;
    gUnknown_030036A4 = gUnknown_0300368C;
    gUnknown_030036BC = gUnknown_0300368C;
    if (gUnknown_03004980[0xb])
        sub_08013DB4(0xd);
    else
        sub_08013DB4(2);
}
