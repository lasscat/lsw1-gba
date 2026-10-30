extern int sub_0803F438(void *a, int b, int c);

struct unk {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    void *ptr;
};

void sub_08041958(struct unk *p)
{
    unsigned char tmp;
    struct unk *q = p;
    tmp = q->b1;
    if (tmp == 0) {
        sub_0803F438(q->ptr, 0x14, 1);
        q->b2 = tmp;
        q->b0 = 5;
    }
}
