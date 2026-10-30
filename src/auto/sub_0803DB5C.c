extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_0803DA74(unsigned int arg0, unsigned int arg1);
extern void sub_08000BF4(void *arg0, unsigned int arg1);

/* Placeholder names: the struct and the meaning of the flag bits are not known yet. */

struct Object
{
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5c[0xb5 - 0x5c];
    unsigned char unkB5;
    unsigned char unkB6[0x106 - 0xb6];
    unsigned char unk106;
    unsigned char unk107;
};

struct Entry
{
    unsigned char unk00[0x0e];
    unsigned char unk0e;
    unsigned char unk0f;
};

void *sub_0803DB5C(unsigned int arg0, unsigned int arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *object = sub_0803DA74(arg0, arg1);

    object->unk106 = entry->unk0e;
    object->unk107 = 1;
    if (entry->unk0f != 0) {
        /* the object gets the address of the IWRAM block at 0x03000138 */
        sub_08000BF4(object, 0x03000138);
        object->unk58 |= 0x01000001;
        object->unkB5 = (object->unkB5 & 0x0f) | 0x30;
    }
    return object;
}
