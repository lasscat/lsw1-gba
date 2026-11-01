struct unk_struct {
    unsigned char unk0[4];
    unsigned char unk4;
    unsigned char unk5;
};

extern int sub_0802E4DC(int, int, int);

void sub_0800C7E0(struct unk_struct *r0)
{
    unsigned char r1 = r0->unk4;
    unsigned int r2 = (unsigned int)r0->unk5;
    if (r1 > 0x18 && r1 != 0x1a) {
        r2 <<= 8;
    }
    sub_0802E4DC(0, r1, r2);
}
