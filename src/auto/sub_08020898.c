/* Draws the first two lines of a text block and leaves the rest of the block
 * to sub_08020814.
 *
 * sub_08005870 fills a rectangle of 16 bit cells in the cell buffer whose
 * base is the word at 0x03002C54 + 0xc (the page argument selects a 100 cell
 * page of it), so the first call wipes the block at page 1, column 21, row 5
 * (4 cells wide, 12 rows tall) with 0.
 *
 * Both strings are looked up in the string table by index with sub_0801D0AC
 * (0x43 and 0x44). The index is a table offset, not a pointer: sub_08011850
 * scales it by four and uses it to index the string table.
 *
 * sub_0800EDD8 draws one string and returns the x pixel position behind its
 * last glyph, so the second line continues where the first one stopped: the
 * first call starts at x = 1, the second one at the returned position + 1.
 * The lines are drawn with the placement arguments 0x50 and 0x64, at line
 * positions 50 and 68 (the second line sits 18 further down).
 *
 * The final x position is kept in the state block at 0x030069C0 + 0x10.
 * sub_08020814 reads that word back and draws the next string of the block
 * (index 0x45) behind it.
 */
extern void sub_08005870(int page, int column, int row, int width, int height, int value);
extern void *sub_0801D0AC(const char *index);
extern int sub_0800EDD8(int start_x, int place_x, int line_y, int place_y, const char *text, int mode);
extern void sub_08020814(void);
extern int gUnknown_030069C0[];

enum {
    CELL_PAGE = 1,
    CELL_COLUMN = 0x15,
    CELL_ROW = 5,
    CELL_WIDTH = 4,
    CELL_HEIGHT = 12,
    TEXT_INDEX_FIRST = 0x43,
    TEXT_PLACE_X = 0x50,
    TEXT_PLACE_Y = 0x64,
    TEXT_LINE_Y = 0x32,
    TEXT_LINE_STEP = 0x12,
    LAST_TEXT_INDEX = 1,
    TEXT_X_SLOT = 4
};

void sub_08020898(void)
{
    int text_index;
    int line_y;
    int text_x = 0;

    sub_08005870(CELL_PAGE, CELL_COLUMN, CELL_ROW, CELL_WIDTH, CELL_HEIGHT, 0);
    for (text_index = 0, line_y = TEXT_LINE_Y; text_index <= LAST_TEXT_INDEX; text_index++) {
        const char *text = sub_0801D0AC((const char *)(text_index + TEXT_INDEX_FIRST));
        text_x = sub_0800EDD8(text_x + 1, TEXT_PLACE_X, line_y, TEXT_PLACE_Y, text, 0);
        line_y += TEXT_LINE_STEP;
    }
    gUnknown_030069C0[TEXT_X_SLOT] = text_x;
    sub_08020814();
}
