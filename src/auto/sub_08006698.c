void sub_08006698(int w, int h, int sx, int sy, int srcPitch, unsigned short *src, int dx, int dy, int dstPitch, unsigned short *dst)
{
    int i, j;

    src += sy * srcPitch + sx;
    dst += dy * dstPitch + dx;

    for (i = h; i > 0; i--) {
        for (j = w; j > 0; j--) {
            *dst++ = *src++;
        }
        src += srcPitch - w;
        dst += dstPitch - w;
    }
}
