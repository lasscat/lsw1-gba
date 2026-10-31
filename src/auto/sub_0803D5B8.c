struct unk {
    unsigned char pad00[0xE8];
    void *slots[4];
    unsigned short unkF8;
    unsigned char padFA[9];
    unsigned char unk103;
    unsigned char unk104;
    unsigned char unk105;
    unsigned char pad106[3];
    unsigned char unk109;
};

struct unk2 {
    unsigned char pad00[0xF2];
    unsigned short unkF2;
};

unsigned int sub_0803D744(struct unk *obj);
void *sub_0803D654(unsigned short id, struct unk *obj);

int sub_0803D5B8(struct unk *obj)
{
    unsigned short v = obj->unkF8;
    unsigned int idx = (unsigned char)sub_0803D744(obj);
    void *p;

    if (idx != 4) {
        p = sub_0803D654(v, obj);
        if (p != 0) {
            if (obj->unk109 != 0)
                ((struct unk2 *)p)->unkF2 |= 0x4000;
            obj->slots[idx] = p;
            if (obj->unk105 == 0)
                obj->unk103--;
            obj->unk104--;
            return 1;
        }
    }
    return 0;
}
