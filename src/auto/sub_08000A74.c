/* Placeholder names: the struct and the meaning of the flag bits are not known yet. */

struct unk
{
    unsigned char unk00[0xc4];
    unsigned char unkC4;
};

void sub_08000A74(struct unk *unk, int idx)
{
    unsigned char *ptr = (unsigned char *)unk + idx * 12 + 0xc4;
    *ptr |= 1;
}
