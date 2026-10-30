struct UnkStruct_080169F8_Data
{
    unsigned char unk00[0x06];
    unsigned short unk6;
};

struct UnkStruct_080169F8_Info
{
    unsigned char unk00[0x04];
    struct UnkStruct_080169F8_Data *unk4;
};

struct UnkStruct_080169F8
{
    unsigned char unk00[0x08];
    struct UnkStruct_080169F8_Info *unk8;
    unsigned char unk0C[0x2E];
    unsigned short unk3A;
    unsigned short unk3C;
    unsigned short unk3E;
    unsigned char unk40[0x0C];
    unsigned char unk4C;
    signed char unk4D;
};

void sub_080169F8(struct UnkStruct_080169F8 *arg0)
{
    int timer = arg0->unk3E + 1;

    arg0->unk3E = timer;
    if ((signed short)timer < (signed char)arg0->unk4C)
        return;

    if (arg0->unk4D < arg0->unk8->unk4->unk6 - 1)
    {
        *(unsigned char *)&arg0->unk4D = *(unsigned char *)&arg0->unk4D + 1;
    }
    else if (arg0->unk3A & 4)
    {
        *(unsigned char *)&arg0->unk4D = 0;
    }
    arg0->unk3E = 0;
}
