struct S35EC0 {
    unsigned char filler0[0x5f];
    unsigned char unk5F;
    unsigned char filler1[0x81];
    unsigned char unkE1;
    unsigned char filler2[0x3a];
    unsigned short unk11C;
};

void sub_080020FC(struct S35EC0 *obj, int val);
int sub_08017400(int a, int b);
int sub_08017484(int x);

void sub_08035EC0(struct S35EC0 *arg)
{
    unsigned int v;
    arg->unkE1 = 0x1f;
    sub_080020FC(arg, 0);
    arg->unk11C = sub_08017400(0x19, 0x5a);
    v = (unsigned short)sub_08017484(0x64);
    if (v > 0x13)
        return;
    arg->unk5F = (unsigned char)sub_08017484(0xff);
}
