
struct unk
{
    unsigned char pad[0x9c];
    int unk9c;
    int unka0;
};

int sub_080019C8(struct unk *arg)
{
    return (arg->unk9c - arg->unka0) >> 1;
}
