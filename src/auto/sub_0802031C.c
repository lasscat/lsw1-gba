typedef struct {
    void *object;
    int value1;
    int value2;
} Camera;

extern Camera gUnknown_030069AC;
extern void sub_08006988(int, int, int);

void sub_0802031C(unsigned char flag)
{
    /* FAKE: the original code materialises the base of gUnknown_030069AC twice
       (two literal-pool entries for 0x030069AC).  agbcc folds a plain symbol
       reference into one materialisation, so the first block spells the base
       address out to keep the two materialisations apart. */
    Camera *cam = (Camera *)0x030069AC;
    int value = cam->value2;

    cam->value2 = flag ? value - 64 : value + 64;
    gUnknown_030069AC.value2 %= 512;
    sub_08006988(1, 0, gUnknown_030069AC.value2 << 16);
    sub_08006988(0, 0, gUnknown_030069AC.value2 << 16);
}
