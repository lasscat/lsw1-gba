extern unsigned int sub_08011F3C(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sub_0802626C(void);

extern unsigned int gUnknown_03003694;
extern unsigned char gUnknown_0300332C[];

void sub_08026184(void)
{
    if (sub_08011F3C(&gUnknown_03003694, 0, 2, 0, gUnknown_0300332C[0xB9]) != 0) {
        sub_0802626C();
    }
}
