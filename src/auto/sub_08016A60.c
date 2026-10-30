struct Sub08016A60Inner
{
    unsigned char pad[6];
    unsigned short count;
};

struct Sub08016A60Mid
{
    unsigned char pad[4];
    struct Sub08016A60Inner *inner;
};

struct Sub08016A60Obj
{
    unsigned char pad00[8];
    struct Sub08016A60Mid *mid;
    int x;
    int y;
    unsigned char pad14[8];
    int vx;
    int vy;
    unsigned char pad24[22];
    unsigned short flags;
    unsigned char pad3c[2];
    short timer;
    unsigned char pad40[12];
    signed char limit;
    signed char frame;
};

void sub_08016A60(struct Sub08016A60Obj *p)
{
    if (++p->timer >= p->limit) {
        if (p->frame < p->mid->inner->count - 1) {
            p->frame++;
        } else if (p->flags & 4) {
            p->frame = 0;
        }
        p->timer = 0;
    }
    p->x += p->vx;
    p->y += p->vy;
}
