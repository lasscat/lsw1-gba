int sub_08004A5C(unsigned int, unsigned int);
void sub_08036AF0(unsigned int, unsigned int);

struct unk {
    char pad[4];
    unsigned char b4;
    unsigned char b5;
};

void sub_0800CEEC(struct unk *r0)
{
    unsigned int r2 = r0->b4;
    unsigned int r1 = r0->b5;
    unsigned int ret = sub_08004A5C(r2, r1);
    if (ret != 0) {
        sub_08036AF0(ret, 0);
    }
}
