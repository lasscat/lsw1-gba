typedef struct Entry {
    unsigned char f0;
    unsigned char f1;
    unsigned char rest[6];
} Entry;

extern Entry *gUnknown_03003774;

void sub_080154D4(int arg0)
{
    int t;
    Entry *p = gUnknown_03003774;
    Entry *q;
    p += arg0;
    t = p->f1;
    t = (t & -4) | 2;
    p->f1 = t;
    q = (Entry *)((unsigned char *)gUnknown_03003774 + 1024);
    q += arg0;
    t = q->f1;
    t = (t & -4) | 2;
    q->f1 = t;
}
