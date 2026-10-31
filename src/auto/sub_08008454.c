extern unsigned char gUnknown_03002E70;
extern void *gUnknown_03002EB4[];
void sub_080072A4(unsigned char *info, void *src, int size, void *dst);
int sub_08017484(int x);

typedef struct {
    unsigned char *data;
    int param;
} Ent;

typedef struct {
    unsigned char flags;
    unsigned char unk1;
    unsigned char idx;
    unsigned char timer;
    unsigned char unk4[4];
    unsigned char *ptr;
    unsigned char unkC[4];
} Item;

extern Item gUnknown_03002E74[];

void sub_08008454(void)
{
    unsigned int i = 0;

    if (i < gUnknown_03002E70) {
        Item *p = gUnknown_03002E74;
        do {
            if (p->flags & 1) {
                Ent *e = (Ent *)(p->ptr + 12) + p->idx;
                if (--p->timer == 0) {
                    int v = e->param;
                    if (v != 0 && (p->flags & 2)) {
                        if (v & 0x80) {
                            v &= 0x7f;
                            p->timer = sub_08017484(v);
                        } else {
                            p->timer = v;
                        }
                        if (++p->idx >= p->ptr[1])
                            p->idx = 0;
                    }
                }
                {
                    unsigned char *d = e->data;
                    int size = *(unsigned short *)(d + 2);
                    sub_080072A4(d, d + 4, size, gUnknown_03002EB4[i]);
                }
                p->flags |= 4;
            }
            p++;
            i++;
        } while (i < gUnknown_03002E70);
    }
}
