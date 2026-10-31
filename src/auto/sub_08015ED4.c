typedef struct { unsigned char pad[58]; unsigned short unk3a; } Item;
typedef struct { unsigned char pad[40]; Item **tbl[4]; unsigned char cnt[16]; } Mgr;
extern Mgr gUnknown_03004920;
signed char sub_080168F8(Item *p);
int sub_08015ED4(unsigned char a)
{
    unsigned int idx = a;
    int ret = 0;
    int n;
    Item ***pp;
    Item *it;
    if (gUnknown_03004920.cnt[idx] == 0)
        return 0;
    n = gUnknown_03004920.cnt[idx] - 1;
    if (n >= 0) {
        pp = &gUnknown_03004920.tbl[idx];
        do {
            Item **base = *pp;
            int off = n * 4;
            it = *(Item **)((char *)base + off);
            ret = sub_080168F8(it);
            it->unk3a &= 0x7FFF;
            n--;
        } while (n >= 0);
    }
    return ret;
}
