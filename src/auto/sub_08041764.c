extern int sub_0803F438(void *a, int b, int c);

struct unk {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    void *ptr[10];
};

void sub_08041764(struct unk *p)
{
    unsigned char tmp;
    struct unk *q = p;
    void **pp;
    unsigned int i;
    tmp = q->b1;
    if (tmp != 0)
        return;
    i = 0;
    pp = q->ptr;
    do {
        sub_0803F438(*pp++, 2, 2);
        i++;
    } while (i <= 9);
    q->b2 = 0;
    q->b0 = 5;
}
