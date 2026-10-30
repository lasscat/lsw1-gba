struct unk
{
    unsigned char unk00[0x0C];
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char unk14[0x2C];
    unsigned int unk40;
    unsigned char unk44[0x24];
    struct unk *unk68;
    unsigned char unk6C[0x70];
    unsigned short unkDC;
};

extern void sub_08002138(void *, unsigned int);

void sub_080359DC(struct unk *this)
{
    struct unk *other = this->unk68;

    this->unk0C = other->unk0C;
    this->unk10 = other->unk10;
    this->unk40 = other->unk40;

    this->unkDC--;
    if (this->unkDC == 0xFFFF)
    {
        sub_08002138(this, 1);
    }
}
