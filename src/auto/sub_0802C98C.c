struct SaveFlags
{
    unsigned char pad[0x446];
    unsigned char bits[0x40];
};
extern struct SaveFlags gUnknown_03006B1C;

void sub_0802C98C(unsigned int a, unsigned int b)
{
    unsigned int x = a >> 3;
    unsigned int bit = a & 7;
    gUnknown_03006B1C.bits[x] = (gUnknown_03006B1C.bits[x] & ~(1 << bit)) + (b << bit);
}
