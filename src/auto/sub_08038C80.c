extern unsigned int gUnknown_03007014;

void sub_08037548(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
void sub_08000F50(void *arg);

typedef struct
{
    unsigned char _00[0x58];
    unsigned int unk58;
} Struct08038C80;

void sub_08038C80(Struct08038C80 *arg0)
{
    sub_08037548((unsigned int)arg0, 5, gUnknown_03007014, 1);
    arg0->unk58 &= 0xFFFBFFFF;
    sub_08000F50(arg0);
}
