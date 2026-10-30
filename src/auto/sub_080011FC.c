typedef struct {
    void *p0;
    int f4;
    int f8;
} Item;

typedef struct {
    unsigned char unk00[0xCC];
    Item table[8];
} Main;

typedef struct {
    unsigned char unk00[12];
    unsigned short arr[64];
} Data;

int sub_080026B4(void *arg0, void *arg1, unsigned char arg2);

void sub_080011FC(Main *arg0, unsigned int *arg1, unsigned int arg2)
{
    void *p = arg0->table[arg2].p0;
    unsigned char *q = ((unsigned char **)p)[1];
    int v = sub_080026B4(arg0, q, arg2);
    unsigned short off = ((Data *)q)->arr[v];
    q += off + 12;
    arg1[0] = q[2];
    arg1[1] = q[3];
}
