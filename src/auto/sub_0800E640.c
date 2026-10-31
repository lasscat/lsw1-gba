extern void *gUnknown_030031D0;
extern unsigned int gUnknown_030031D4;

struct E640Entry {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned int unk4;
};

extern void sub_0800E6F8(struct E640Entry *);

void sub_0800E640(void)
{
    unsigned int i = 0;
    if (i < gUnknown_030031D4) {
        do {
            if (((struct E640Entry *)gUnknown_030031D0)[i].unk2 != 0
                && (((struct E640Entry *)gUnknown_030031D0)[i].unk3 & 1) == 0) {
                if (--((struct E640Entry *)gUnknown_030031D0)[i].unk2 == 0)
                    sub_0800E6F8(&((struct E640Entry *)gUnknown_030031D0)[i]);
            }
            i = i + 1;
        } while (i < gUnknown_030031D4);
    }
}
