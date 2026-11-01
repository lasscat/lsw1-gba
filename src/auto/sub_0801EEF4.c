struct Sub0801EEF4Entry {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char unk4;
    unsigned char pad[3];
};

struct Sub0801EEF4A {
    unsigned char pad0[0x95];
    unsigned char unk95;
    unsigned char pad96[2];
    int unk98;
};

struct Sub0801EEF4C {
    unsigned char pad0[0xC];
    unsigned short unkC;
    unsigned char pad[0x7C - 0xE];
};

struct Sub0801EEF4B {
    unsigned char pad0[0xC];
    unsigned short unkC;
    unsigned char pad1[0xB0 - 0xE];
    unsigned char padB0[9];
    unsigned char unkB9;
    unsigned char padBA[6];
    unsigned char unkC0;
    unsigned char unkC1;
    unsigned char unkC2;
    unsigned char unkC3;
};

extern struct Sub0801EEF4A *gUnknown_0300699C;
extern struct Sub0801EEF4A gUnknown_03006A2C;
extern int gUnknown_03006AFC[];
extern unsigned int gUnknown_0804C7A0;
extern unsigned int gUnknown_0804C7A4;
extern unsigned char gUnknown_0892B018[];
extern unsigned char gUnknown_08E007D8[];
extern struct Sub0801EEF4Entry gUnknown_080716E0[];
extern unsigned char gUnknown_03006B1C[];
extern struct Sub0801EEF4B gUnknown_0300332C;
extern int gUnknown_0300368C[];

extern void sub_0801E458(unsigned char a);
extern void sub_0801E224(void);
extern void sub_0802534C(void);
extern void sub_0800554C(unsigned short mode);
extern void sub_08005648(unsigned short a);
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_08006988(int index, int x, int y);
extern void sub_08005870(int, int, int, int, int, int);
extern void sub_080054F4(unsigned char);
extern void sub_08005470(int, int);
extern int sub_08005DCC(unsigned char *a, int b, int c);
extern void sub_0800E9B4(unsigned int a);
extern void sub_0801F5F8(void);
extern void sub_0801F4FC(void);
extern void sub_08009F98(unsigned char *a, int b, int c);
extern void sub_08029D14(void);
extern void sub_080187F8(unsigned short a, int b);

void sub_0801EEF4(void)
{
    unsigned int v;
    int w; // FAKE: int-typed temp avoids a zero-extend of the first table byte
    struct Sub0801EEF4B *s;
    struct Sub0801EEF4Entry *e;
    unsigned int i;
    struct Sub0801EEF4A **q; // FAKE: alias of pp copied just before the loop (register copy placement)
    unsigned char *p;
    struct Sub0801EEF4A **pp;

    sub_0801E458(0);
    sub_0801E224();
    pp = &gUnknown_0300699C;
    *pp = &gUnknown_03006A2C;
    sub_0802534C();
    if (gUnknown_03006AFC[1] == 0) {
        sub_0800554C(0);
        sub_08005648(0x1000);
    }
    sub_080053D4(1, gUnknown_0804C7A0);
    v = gUnknown_0804C7A4;
    sub_080053D4(0, v);
    sub_08006988(0, 0, 0);
    sub_08006988(1, 0, 0);
    sub_08005870(0, 0, 0, 0x20, 0x40, 0);
    sub_08005870(1, 0, 0, 0x20, 0x40, 0);
    sub_080054F4(0);
    sub_08005470(0, 0);
    sub_08005470(1, 2);
    sub_08005DCC(gUnknown_0892B018, 0, 0x10);
    sub_0800E9B4(v);
    s = &gUnknown_0300332C;
    e = gUnknown_080716E0;
    w = e[gUnknown_03006B1C[0x293]].unk1;
    s->unkC0 = w;
    s->unkC1 = e[gUnknown_03006B1C[0x293]].unk2;
    s->unkC2 = e[gUnknown_03006B1C[0x293]].unk3;
    s->unkC3 = e[gUnknown_03006B1C[0x293]].unk4;
    for (i = 0, q = pp, p = &s->unkC0; i < 4; p++, i++) {
        if (*p == 0x69) {
            (*q)->unk95 = i;
            break;
        }
    }
    sub_0801F5F8();
    sub_0801F4FC();
    sub_08009F98(gUnknown_08E007D8, 0, 0x10);
    gUnknown_0300368C[4] = 0;
    gUnknown_0300368C[5] = 1;
    gUnknown_03006B1C[0x29D] = 0;
    if (gUnknown_03006AFC[1] == 0) {
        sub_08029D14();
        sub_080187F8(0x3F, 2);
    }
    ((struct Sub0801EEF4C *)&gUnknown_0300332C)[gUnknown_0300332C.unkB9].unkC = 0;
    gUnknown_0300699C->unk98 = 0;
}
