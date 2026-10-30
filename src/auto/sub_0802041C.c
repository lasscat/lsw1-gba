typedef struct {
    unsigned int unused0[2];
    unsigned int value;
    unsigned int unused1;
    unsigned int ready;
} State;
typedef struct {
    unsigned int unused0;
    unsigned short flags;
} Flags;
extern State gUnknown_0300368C;
extern unsigned char gUnknown_030069BC[];
extern Flags gUnknown_03003430;
extern int sub_08012008(void *, int, int, int, int);
extern void sub_080204CC(void);
extern void sub_08013DEC(unsigned int, unsigned int, unsigned int);

void sub_0802041C(void)
{
    if (gUnknown_0300368C.ready != 0)
        return;
    if (sub_08012008(gUnknown_030069BC, 0, 0x1C, 1, 0) != 0)
        sub_080204CC();
    if (gUnknown_03003430.flags & 1)
        sub_08013DEC(7, 0, gUnknown_0300368C.value);
    else if (gUnknown_03003430.flags & 2)
        sub_08013DEC(7, 0, gUnknown_0300368C.value);
}
