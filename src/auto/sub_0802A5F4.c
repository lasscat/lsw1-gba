typedef struct {
    signed char unk0;
    signed char unk1;
    signed char unk2;
    unsigned char unk3;
    unsigned char unk4;
    unsigned char unk5;
} Sub0802A5F4;

void sub_0802A5F4(Sub0802A5F4 *p)
{
    p->unk4 = 0;
    if (p->unk5 != 0)
        return;
    if (p->unk3 == 0) {
        if ((*(unsigned *)p & 0xFFFFFF) != 0x1D3B09)
            p->unk2++;
    } else {
        if ((*(unsigned *)p & 0xFFFFFF) != 0)
            p->unk2--;
    }
    if (p->unk2 > 29) {
        p->unk2 = 0;
        p->unk1++;
        p->unk4 = 1;
    } else if (p->unk2 < 0) {
        p->unk2 = 29;
        p->unk1--;
        p->unk4 = 1;
    }
    if (p->unk1 > 59) {
        p->unk1 = 0;
        p->unk0++;
    } else if (p->unk1 < 0) {
        p->unk1 = 59;
        p->unk0--;
    }
    if (p->unk0 > 9)
        p->unk0 = 9;
    else if (p->unk0 < 0)
        p->unk0 = 0;
}
