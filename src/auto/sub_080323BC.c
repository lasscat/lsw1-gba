/* Object state machine: dispatches on the state byte at offset 0xe2.
   Field names and offsets follow the neighbouring reconstructions. */

struct unk {
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x86];
    unsigned char unkE2;
    unsigned char unkE3[0x39];
    unsigned short unk11C;
};

extern void sub_080020FC(struct unk *obj, int val);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_080323BC(struct unk *arg0)
{
    struct unk *r4 = arg0;
    unsigned int state = arg0->unkE2;

    switch (state) {
    case 0:
        sub_080020FC(r4, 8);
        break;
    case 2:
    case 8:
        if (r4->unk11C == 0) {
            r4->flags &= ~0x20;
            sub_08036AF0((unsigned int)r4, 0);
        } else {
            r4->unk11C--;
        }
        break;
    default:
        sub_0803ABE0(r4);
        break;
    }
}
