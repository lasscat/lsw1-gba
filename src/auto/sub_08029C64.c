extern unsigned int sub_0800EB2C(void);

struct SubEntry {
    unsigned char unk00[16];
    int unk10;
    unsigned char unk14[68];
    int unk58;
};

struct MainStruct {
    unsigned char unk00[3];
    unsigned char unk03;
    unsigned char unk04[58];
    unsigned char unk3E;
    unsigned char unk3F[17];
    struct SubEntry **unk50;
};

extern struct MainStruct *gUnknown_03006AF8;

void sub_08029C64(void)
{
    unsigned int i;
    unsigned int count = gUnknown_03006AF8->unk03 * 3;

    for (i = 0; i < count + 3; i++) {
        if (i < count) {
            gUnknown_03006AF8->unk50[i]->unk58 &= ~1;
        } else {
            gUnknown_03006AF8->unk50[i]->unk58 |= 1;
            gUnknown_03006AF8->unk50[i]->unk10 = (sub_0800EB2C() * (i - count) + 0x84) << 16;
        }
    }
    gUnknown_03006AF8->unk03++;
    if (gUnknown_03006AF8->unk3E - 3 * gUnknown_03006AF8->unk03 < 0) {
        gUnknown_03006AF8->unk3E = 0;
    }
}
