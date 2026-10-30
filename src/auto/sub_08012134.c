typedef struct {
    unsigned char pad[0xa];
    unsigned short flags[5];
    unsigned int count;
    unsigned int total;
    unsigned int other;
} Unk;

extern Unk gUnknown_03003430;
extern void sub_08011F3C(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int sub_08012134(unsigned int a, unsigned int b, unsigned int c)
{
    if (gUnknown_03003430.count != 0) {
        if (gUnknown_03003430.count <= a) {
            sub_08011F3C(&gUnknown_03003430.other, 0, gUnknown_03003430.count - 1, b, c);
        } else {
            if (gUnknown_03003430.flags[c] & 0x40) {
                if (gUnknown_03003430.other >= (a >> 1)) {
                    gUnknown_03003430.other--;
                } else if (gUnknown_03003430.total != 0) {
                    gUnknown_03003430.total--;
                } else if (gUnknown_03003430.other != 0) {
                    gUnknown_03003430.other--;
                }
            } else {
                if (gUnknown_03003430.other < (a >> 1)) {
                    gUnknown_03003430.other++;
                } else if (gUnknown_03003430.total < gUnknown_03003430.count - a) {
                    gUnknown_03003430.total++;
                } else if (gUnknown_03003430.other < a - 1) {
                    gUnknown_03003430.other++;
                }
            }
        }
    }
    return gUnknown_03003430.total + gUnknown_03003430.other;
}
