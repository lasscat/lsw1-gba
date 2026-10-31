struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x60];
    unsigned short unkBC;
};

extern struct Node *gUnknown_030024F8[];
extern unsigned int gUnknown_03002730;

void sub_08015F4C(void);
int sub_08002D90(struct Node *node);
void sub_08002D24(void);
void sub_080153F0(void);

int sub_08002778(void)
{
    int flag = 0;
    int i;
    struct Node **pp;

    sub_08015F4C();
    i = 0;
    if (flag < gUnknown_03002730) {
        pp = gUnknown_030024F8;
        do {
            if (sub_08002D90(*pp++) != 0)
                flag = 1;
            i++;
        } while (i < gUnknown_03002730);
    }
    sub_08002D24();
    sub_080153F0();
    return flag;
}
