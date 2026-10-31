struct unk_sub6 {
    unsigned short unk00[3];
    unsigned short value;
};

struct unk_sub4 {
    unsigned char unk00[4];
    struct unk_sub6 *next;
};

struct unk {
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x3c];
    struct unk_sub4 *unk98;
    unsigned char unk9C[0x46];
    unsigned char unkE2;
    unsigned char unkE3;
};

extern void sub_0802AF4C(void *arg0);
extern void sub_08037798(struct unk *obj, int val);
extern void sub_080020FC(struct unk *obj, int val);
extern void sub_0802A758(struct unk *obj, int val);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_08031F4C(struct unk *arg0)
{
    struct unk *r4 = arg0;
    unsigned int state = arg0->unkE2;

    switch (state) {
    case 0:
        sub_0802AF4C(r4);
        sub_08037798(r4, 0);
        sub_080020FC(r4, 0x37);
        sub_0802A758(r4, 0);
        r4->flags &= 0xFFFBFFFF;
        break;
    case 2:
    case 0x37:
        if (!(r4->flags & 0x40000) && r4->unk98->next->value != 1)
            break;
        sub_08036AF0((unsigned int)r4, 0);
        break;
    default:
        sub_0803ABE0(r4);
        break;
    }
}
