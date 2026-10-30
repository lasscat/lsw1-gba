extern unsigned int sub_08004A5C(unsigned char, unsigned char);

typedef struct {
    unsigned char unk_00[88];
    unsigned int unk_58;
    unsigned int unk_5C;
    unsigned int unk_60;
    unsigned char unk_64[125];
    unsigned char unk_E1;
} Struct0800AF80;

typedef struct {
    unsigned char unk_00[4];
    unsigned char unk_04;
    unsigned char unk_05;
} Arg0800AF80;

void sub_0800AF80(Arg0800AF80 *a)
{
    Struct0800AF80 *p = (Struct0800AF80 *)sub_08004A5C(a->unk_04, a->unk_05);
    if (p == 0)
        return;
    if (p->unk_60 == 0)
        p->unk_58 |= 2;
    else {
        p->unk_E1 = 1;
        p->unk_58 |= 8;
    }
}
