extern void sub_080020FC(void *, int);
extern void sub_08004458(unsigned char, unsigned char);
extern int sub_0801BEB8(int);
extern void sub_0802B450(void *);
extern void sub_0802B7C8(void);
extern int sub_0802B814(void *);
extern void sub_0802B88C(void *);
extern void sub_0802B99C(void *);
extern void sub_0802BA5C(void *);
extern void sub_080393C4(void *, int);
struct Global { unsigned char pad[0xa8]; int sound; };
extern struct Global gUnknown_0300332C;
extern unsigned short gUnknown_03003430;

struct Node {
    unsigned char pad00[0x58];
    unsigned int unk58;
    unsigned char pad5c[0xd4 - 0x5c];
    unsigned int unkD4;
    unsigned char padD8[0xdc - 0xd8];
    unsigned short unkDC;
    unsigned char padDE[0xe1 - 0xde];
    unsigned char unkE1;
    unsigned char unkE2;
    unsigned char padE3[0xf1 - 0xe3];
    unsigned char unkF1;
    unsigned char padF2[0x104 - 0xf2];
    unsigned char unk104;
    unsigned char unk105;
    unsigned char pad106[0x108 - 0x106];
    unsigned short unk108;
};

void sub_0803D86C(struct Node *node)
{
    switch (node->unkE1) {
    case 3:
        switch (node->unkE2) {
        case 0:
            if (sub_0802B814(node)) {
                sub_0802BA5C(node);
                sub_080020FC(node, 0x14);
                node->unkDC = 0x2d;
                {
                    int sound = sub_0801BEB8(0x23);
                    gUnknown_0300332C.sound = sound;
                }
            } else {
                sub_0802B88C(node);
            }
            break;
        case 0x14:
            if (node->unkDC == 0) {
                if (node->unk108 != 0)
                    sub_080393C4(node, node->unk108);
                sub_080020FC(node, 0x49);
            } else if (!(gUnknown_03003430 & 0x200) && !(node->unkD4 & 8)) {
                sub_080020FC(node, 0);
                sub_0802B7C8();
            } else {
                node->unkDC--;
            }
            break;
        case 0x49:
            sub_0802B7C8();
            node->unkF1 = 1;
            sub_0801BEB8(0x25);
            node->unkD4 &= ~8;
            sub_0802B450(node);
            sub_08004458(node->unk105, node->unk104);
            sub_080020FC(node, 6);
            break;
        case 6:
            node->unk58 |= 2;
            sub_0802BA5C(node);
            break;
        }
        break;
    case 1:
        sub_0802B99C(node);
        break;
    case 0:
        break;
    }
}
