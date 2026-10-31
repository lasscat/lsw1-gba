extern void *gUnknown_03007014;
extern unsigned char gUnknown_0804FB00[];

void sub_08037548(void *arg0, int arg1, void *arg2, int arg3);
void sub_08000F50(void *arg);
void sub_080020FC(void *obj, int val);
void sub_080013F4(void *arg0, unsigned int arg1, unsigned char arg2, void *arg3);

typedef struct
{
    unsigned int v;
    unsigned char _04[0x2c];
} Row;

typedef struct
{
    unsigned char _00[0x10];
    Row _10[0];
} Table;

void sub_080390A8(void *arg0)
{
    void *r4 = arg0;
    void *r2 = gUnknown_03007014;
    sub_08037548(r4, 10, r2, 0);
    sub_08000F50(r4);
    sub_080020FC(r4, 12);
    *(unsigned int *)(r4 + 0x44) = ((Table *)gUnknown_0804FB00)->_10[*(unsigned char *)(r4 + 0xe0)].v;
    sub_080013F4(r4 + 0x24, 0x80000000, *(unsigned char *)(r4 + 0x5f), *(void **)(r4 + 8));
}
