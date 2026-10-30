extern unsigned int gUnknown_030031C4;
extern unsigned int sub_08004A5C(unsigned char, unsigned char);

struct Unk_0800B524
{
    unsigned char pad[0x128];
    unsigned char field7;
    unsigned char field1;
    unsigned char field6;
};

void sub_0800B524(unsigned char *p)
{
    struct Unk_0800B524 *q;

    if (gUnknown_030031C4 == 1)
        gUnknown_030031C4 = 2;

    q = (struct Unk_0800B524 *)sub_08004A5C(p[4], p[5]);
    if (q) {
        q->field7 = p[7];
        q->field1 = 1;
        q->field6 = p[6];
    }
}
