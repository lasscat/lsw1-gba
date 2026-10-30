extern void sub_080020FC(struct unk *obj, int val);

struct unk
{
    unsigned char unk00[0xe1];
    unsigned char unkE1;
};

void sub_08037280(struct unk *arg)
{
    struct unk *r4 = arg;
    r4->unkE1 = 0x2c;
    sub_080020FC(r4, 0);
}
