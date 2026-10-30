typedef struct {
    unsigned char pad00[0x0c];
    unsigned int f0c;
    unsigned int f10;
} Struct_0300368C;

typedef struct Struct_Node {
    struct Struct_Node *next;
    unsigned char pad04[0x70];
    unsigned int f74;
    unsigned char pad78[0x66];
    unsigned short fde;
} Struct_Node;

extern Struct_0300368C gUnknown_0300368C;
extern void *gUnknown_030069D8;
extern unsigned char gUnknown_030069E4;
extern int gUnknown_030069DC;

void sub_08020B40(unsigned int arg);
void sub_080212F0(void);
void sub_08031644(int arg1, int arg2);
void sub_08031750(int arg1);

void sub_08020FF0(void)
{
    if (gUnknown_0300368C.f0c > 592)
        return;

    sub_08020B40(gUnknown_0300368C.f0c);

    if (((Struct_Node *)gUnknown_030069D8)->next->fde == 0
        || gUnknown_030069E4 == 1
        || (gUnknown_030069E4 == 0 && gUnknown_030069DC < 0))
    {
        if (((Struct_Node *)gUnknown_030069D8)->f74 == 4)
        {
            sub_08031644(1, 0x50);
            sub_08031750(1);
            gUnknown_0300368C.f10 = 3;
        }
        else
        {
            sub_080212F0();
        }
    }
}
