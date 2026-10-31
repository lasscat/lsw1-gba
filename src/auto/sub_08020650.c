extern int gUnknown_0300368C[];
extern int gUnknown_030069C4[];
extern int gUnknown_030069C0[];
extern unsigned short gUnknown_03003430[];
extern int sub_08011F80(int *, unsigned int, unsigned int, unsigned int, int);
extern int sub_08012008(int *, unsigned int, unsigned int, unsigned int, int);
extern void sub_08000FF4(void *, unsigned short, unsigned int, unsigned int);
extern void sub_08020814(void);
extern void sub_0801C3BC(void);
extern void sub_0801C210(int);
extern void sub_0801C1D8(void);
extern void sub_0801BEB8(int);
extern void sub_0801C314(void);
extern void sub_08013DEC(unsigned int, unsigned int, unsigned int);

void sub_08020650(void)
{
    int initial = gUnknown_0300368C[4];
    if (initial != 0)
        return;
    {
        int *counter = gUnknown_030069C4;
        int *state;
        int *values;
        if (sub_08011F80(counter, 0, 1, 1, initial)) {
            int *record = counter - 1;
            sub_08000FF4((void *)record[0], 0x46, record[1] * 18 + 0x3a, 5);
        }
        state = counter - 1;
        {
            int choice = state[1];
            int scaled = choice * 4;
            int *selected;
            int limit;
            values = counter + 1;
            selected = (int *)((char *)values + scaled);
            limit = 0xb8;
            if (choice != 0)
                limit = 0x11;
            if (sub_08012008(selected, 0, limit, 1, initial)) {
                sub_08020814();
                if (state[1] == 1) {
                    if (state[5] != 0) {
                        sub_0801C3BC();
                        sub_0801C210(values[state[1]]);
                    }
                } else {
                    sub_0801C1D8();
                }
            }
        }
    }
    {
        unsigned short *buttons = gUnknown_03003430;
        if ((buttons[2] & 0x300) != 0) {
            int *base = gUnknown_030069C0;
            if (base[1] == 0) {
                sub_0801C1D8();
                if (buttons[2] & 0x200) {
                    int index = base[1] * 4;
                    int *values = base + 2;
                    *(int *)((char *)values + index) -= 10;
                    if (values[base[1]] < 0)
                        values[base[1]] = 0xb8;
                    sub_08020814();
                } else {
                    int index = base[1] * 4;
                    int *values = base + 2;
                    *(int *)((char *)values + index) += 10;
                    if (values[base[1]] > 0xb8)
                        values[base[1]] = 0;
                    sub_08020814();
                }
            }
        }
    }
    if (gUnknown_03003430[2] & 1) {
        int *state = gUnknown_030069C0;
        switch (state[1]) {
        case 0:
            sub_0801BEB8(state[2]);
            break;
        case 1:
            if (state[5] == 0) {
                sub_0801C210(state[3]);
                state[5] = 1;
            } else {
                sub_0801C314();
                state[5] = 0;
            }
            break;
        default:
            break;
        }
    } else if (gUnknown_03003430[2] & 2) {
        sub_08013DEC(7, 0, gUnknown_0300368C[2]);
    }
}
