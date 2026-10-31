typedef struct
{
    unsigned char _00[0x24];
    unsigned int unk24;
    unsigned char _28[0x140];
} Struct0805D6CC;

extern Struct0805D6CC gUnknown_0805D6CC[];
extern unsigned int gUnknown_03007014;
void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_08037548(void *arg0, int arg1, unsigned int arg2, int arg3);
void sub_08000F50(void *arg);

void sub_08038F10(void *arg0)
{
    if (gUnknown_0805D6CC[((unsigned char *)arg0)[0xE0]].unk24 == 0)
        sub_08036AF0((unsigned int)arg0, 0);
    else
    {
        sub_08037548(arg0, 3, gUnknown_03007014, 1);
        sub_08000F50(arg0);
    }
}
