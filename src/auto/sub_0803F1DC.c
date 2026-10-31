void sub_08033374(int a, int b);

struct Sub0803F1DC {
    unsigned char _00[225];
    unsigned char unk_E1;
    unsigned char _E2[18];
    unsigned char unk_F4;
    unsigned char _F5;
    unsigned char unk_F6;
    unsigned char _F7[13];
    unsigned char unk_104;
    unsigned char unk_105;
};

void sub_0803F1DC(struct Sub0803F1DC *p)
{
    if (p->unk_E1 == 0) {
        p->unk_104 = 1;
        p->unk_F4 = 100;
        p->unk_E1 = 4;
        if (p->unk_F6 != 0) {
            if (p->unk_F6 == 1)
                sub_08033374((int)p, 52);
        }
        p->unk_105 = 0;
    }
}
