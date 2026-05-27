/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --no-compress --font resource\Rajdhani-Medium.ttf --range 32-127 --format lvgl
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl.h"
#endif

#ifndef UI_FONT_RAJDHANI_MEDIUM_20
#define UI_FONT_RAJDHANI_MEDIUM_20 1
#endif

#if UI_FONT_RAJDHANI_MEDIUM_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x38,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0xc, 0x41, 0x8, 0x23, 0x4, 0x47, 0xfe, 0x21,
    0x4, 0x60, 0x88, 0x21, 0x1f, 0xf8, 0x88, 0x31,
    0x4, 0x20,

    /* U+0024 "$" */
    0x8, 0x11, 0xf6, 0x18, 0x30, 0x60, 0x40, 0x7c,
    0x4, 0xc, 0x18, 0x30, 0xdf, 0x4, 0x8,

    /* U+0025 "%" */
    0x70, 0x88, 0x88, 0x89, 0x8, 0x90, 0x8b, 0x7,
    0x20, 0x2, 0x0, 0x4e, 0x5, 0x10, 0xd1, 0x9,
    0x10, 0x91, 0x10, 0xe0,

    /* U+0026 "&" */
    0x3c, 0x21, 0x10, 0x88, 0x44, 0x3, 0x1, 0xc1,
    0x3f, 0x9c, 0x47, 0x21, 0x90, 0xe7, 0xd8,

    /* U+0027 "'" */
    0xe8,

    /* U+0028 "(" */
    0x7c, 0x88, 0x88, 0x88, 0x88, 0x88, 0xc7,

    /* U+0029 ")" */
    0xcc, 0x92, 0x49, 0x24, 0x97, 0x80,

    /* U+002A "*" */
    0x21, 0x3e, 0xc5, 0x0,

    /* U+002B "+" */
    0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10,

    /* U+002C "," */
    0xf0,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xe0,

    /* U+002F "/" */
    0xc, 0x30, 0x86, 0x10, 0x43, 0x8, 0x21, 0x84,
    0x30, 0xc0,

    /* U+0030 "0" */
    0x7e, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+0031 "1" */
    0x37, 0x91, 0x11, 0x11, 0x11, 0x11, 0x10,

    /* U+0032 "2" */
    0x7d, 0x6, 0xc, 0x10, 0x20, 0xc3, 0x18, 0x61,
    0x82, 0x4, 0xf, 0xe0,

    /* U+0033 "3" */
    0x7d, 0x6, 0xc, 0x10, 0x20, 0x47, 0x1, 0x3,
    0x6, 0xc, 0x17, 0xc0,

    /* U+0034 "4" */
    0x6, 0x7, 0x2, 0x83, 0x43, 0x21, 0x91, 0x88,
    0x84, 0xc2, 0x7f, 0xc0, 0x80, 0x40, 0x20,

    /* U+0035 "5" */
    0xff, 0x2, 0x4, 0x8, 0x1f, 0xb0, 0x81, 0x3,
    0x6, 0xc, 0x17, 0xc0,

    /* U+0036 "6" */
    0x7f, 0x80, 0x80, 0x80, 0x80, 0xfe, 0x83, 0x81,
    0x81, 0x81, 0x81, 0xc3, 0x7e,

    /* U+0037 "7" */
    0xfe, 0xc, 0x18, 0x20, 0xc1, 0x6, 0xc, 0x10,
    0x60, 0xc1, 0x6, 0x0,

    /* U+0038 "8" */
    0x7e, 0x81, 0x81, 0x81, 0x81, 0x81, 0x7e, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+0039 "9" */
    0x7e, 0xc3, 0x81, 0x81, 0x81, 0x81, 0xc1, 0x7f,
    0x1, 0x1, 0x1, 0x1, 0xfe,

    /* U+003A ":" */
    0xe1, 0xc0,

    /* U+003B ";" */
    0xe1, 0xe0,

    /* U+003C "<" */
    0x1, 0xf, 0x78, 0xc0, 0xf0, 0x1e, 0x3,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x80, 0xf0, 0x1e, 0x3, 0xf, 0x78, 0xc0,

    /* U+003F "?" */
    0x7d, 0x6, 0xc, 0x10, 0x61, 0x84, 0x8, 0x10,
    0x0, 0x40, 0x81, 0x0,

    /* U+0040 "@" */
    0x1f, 0xe6, 0x3, 0x40, 0x18, 0xf9, 0x90, 0x99,
    0x9, 0x90, 0x99, 0x9, 0x91, 0x98, 0xee, 0x40,
    0x6, 0x0, 0x1f, 0x80,

    /* U+0041 "A" */
    0xe, 0x3, 0x80, 0xa0, 0x68, 0x1b, 0x4, 0xc3,
    0x10, 0xc6, 0x21, 0x8f, 0xe6, 0xd, 0x3, 0x40,
    0x40,

    /* U+0042 "B" */
    0xfe, 0x83, 0x81, 0x81, 0x81, 0x83, 0xfe, 0x81,
    0x81, 0x81, 0x81, 0x81, 0xfe,

    /* U+0043 "C" */
    0x7e, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x81, 0x81, 0x81, 0x7e,

    /* U+0044 "D" */
    0xfe, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0xfe,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0xfc,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0x80,

    /* U+0047 "G" */
    0x7e, 0x83, 0x81, 0x81, 0x80, 0x80, 0x80, 0x87,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xf8,

    /* U+004A "J" */
    0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+004B "K" */
    0x83, 0x86, 0x8c, 0x88, 0x98, 0xb0, 0xf0, 0xd8,
    0x8c, 0x84, 0x86, 0x82, 0x81,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+004D "M" */
    0xc0, 0x7c, 0x1f, 0x83, 0xd0, 0x5b, 0x1b, 0x22,
    0x66, 0xcc, 0xd9, 0x8a, 0x31, 0xc6, 0x0, 0xc0,
    0x18, 0x2,

    /* U+004E "N" */
    0xc1, 0xc1, 0xe1, 0xe1, 0xb1, 0xb1, 0x99, 0x8d,
    0x8d, 0x87, 0x87, 0x83, 0x83,

    /* U+004F "O" */
    0x7e, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+0050 "P" */
    0xfe, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xfe,
    0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x7e, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x7e, 0xc, 0x6, 0x2,

    /* U+0052 "R" */
    0xfe, 0x41, 0xa0, 0x50, 0x28, 0x14, 0xa, 0xd,
    0xfc, 0x86, 0x43, 0x20, 0xd0, 0x68, 0x18,

    /* U+0053 "S" */
    0x7e, 0xc3, 0x81, 0x81, 0x80, 0xf0, 0x7e, 0x7,
    0x1, 0x81, 0x81, 0x83, 0x7e,

    /* U+0054 "T" */
    0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x7e,

    /* U+0056 "V" */
    0x40, 0xd0, 0x26, 0x19, 0x86, 0x21, 0x8, 0x43,
    0x30, 0x4c, 0x12, 0x6, 0x81, 0xe0, 0x30, 0xc,
    0x0,

    /* U+0057 "W" */
    0x41, 0x82, 0x83, 0x5, 0x8e, 0x1b, 0x1e, 0x36,
    0x24, 0x64, 0x48, 0x88, 0x91, 0x1b, 0x36, 0x34,
    0x2c, 0x68, 0x58, 0x50, 0xa0, 0xe1, 0xc1, 0x81,
    0x80,

    /* U+0058 "X" */
    0xc1, 0x61, 0x98, 0x84, 0xc3, 0x40, 0xe0, 0x60,
    0x78, 0x24, 0x33, 0x10, 0x98, 0x68, 0x18,

    /* U+0059 "Y" */
    0xc1, 0xa0, 0x98, 0xc4, 0x43, 0x60, 0xa0, 0x70,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80,

    /* U+005A "Z" */
    0xff, 0x3, 0x6, 0x6, 0xc, 0xc, 0x18, 0x30,
    0x30, 0x60, 0x40, 0xc0, 0xff,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x49, 0xc0,

    /* U+005C "\\" */
    0xc3, 0x4, 0x18, 0x20, 0x83, 0x4, 0x10, 0x60,
    0x83, 0xc,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x93, 0xc0,

    /* U+005E "^" */
    0x10, 0x38, 0x2c, 0x64, 0x46, 0xc2,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xcc, 0x80,

    /* U+0061 "a" */
    0x7f, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x86,
    0xfc,

    /* U+0062 "b" */
    0x81, 0x2, 0x4, 0xf, 0xd8, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x3f, 0x80,

    /* U+0063 "c" */
    0x7e, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81, 0xf0,

    /* U+0064 "d" */
    0x2, 0x4, 0x8, 0x17, 0xf0, 0xe0, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x6f, 0xc0,

    /* U+0065 "e" */
    0x7d, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0x40, 0x80,
    0xfc,

    /* U+0066 "f" */
    0x19, 0x8, 0x4f, 0x90, 0x84, 0x21, 0x8, 0x42,
    0x10,

    /* U+0067 "g" */
    0x7f, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc3, 0x7e,
    0x4, 0x8, 0x1f, 0xc0,

    /* U+0068 "h" */
    0x81, 0x2, 0x4, 0xf, 0xd8, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x30, 0x40,

    /* U+0069 "i" */
    0xcf, 0xfc,

    /* U+006A "j" */
    0x11, 0x0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0xe0,

    /* U+006B "k" */
    0x81, 0x2, 0x4, 0x8, 0x51, 0xa6, 0x48, 0xb1,
    0x62, 0x64, 0x48, 0xd0, 0xc0,

    /* U+006C "l" */
    0xff, 0xfc,

    /* U+006D "m" */
    0xfd, 0xf6, 0x18, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41, 0x82, 0xc, 0x10,
    0x40,

    /* U+006E "n" */
    0xfd, 0x86, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x4,

    /* U+006F "o" */
    0x7d, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,
    0xf8,

    /* U+0070 "p" */
    0xfd, 0x86, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xc3,
    0xfa, 0x4, 0x8, 0x0,

    /* U+0071 "q" */
    0x7f, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x86,
    0xfc, 0x8, 0x10, 0x20,

    /* U+0072 "r" */
    0xfc, 0x88, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x7d, 0x2, 0x6, 0x7, 0x83, 0x80, 0x81, 0x2,
    0xf8,

    /* U+0074 "t" */
    0x20, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x20, 0x82,
    0x8, 0x1c,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x86,
    0xfc,

    /* U+0076 "v" */
    0xc1, 0x43, 0x63, 0x62, 0x22, 0x26, 0x34, 0x14,
    0x1c, 0x18,

    /* U+0077 "w" */
    0xc3, 0xa, 0x18, 0xd1, 0xc6, 0xcb, 0x22, 0x49,
    0x12, 0x58, 0xb2, 0xc7, 0x1c, 0x18, 0x60, 0xc3,
    0x0,

    /* U+0078 "x" */
    0x43, 0x62, 0x26, 0x34, 0x18, 0x1c, 0x34, 0x26,
    0x62, 0x43,

    /* U+0079 "y" */
    0x41, 0xa0, 0x98, 0x44, 0x62, 0x21, 0x90, 0xd8,
    0x28, 0x1c, 0x6, 0x2, 0x3, 0x7, 0x0,

    /* U+007A "z" */
    0xfe, 0xc, 0x30, 0x61, 0x86, 0xc, 0x30, 0xc1,
    0xfc,

    /* U+007B "{" */
    0x34, 0x44, 0x44, 0x48, 0x44, 0x44, 0x43,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0xc2, 0x22, 0x22, 0x21, 0x22, 0x22, 0x2c,

    /* U+007E "~" */
    0xf1, 0x8f
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 81, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 76, .box_w = 1, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 108, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 5, .adv_w = 216, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 164, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 38, .adv_w = 232, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 193, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 60, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 74, .adv_w = 93, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 81, .adv_w = 93, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 87, .adv_w = 129, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 91, .adv_w = 171, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 99, .adv_w = 62, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 100, .adv_w = 100, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 101, .adv_w = 62, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 166, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 103, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 154, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 168, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 156, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 126, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 168, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 62, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 62, .box_w = 1, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 238, .adv_w = 169, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 245, .adv_w = 173, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 250, .adv_w = 173, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 257, .adv_w = 151, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 240, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 289, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 176, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 178, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 154, .box_w = 6, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 146, .box_w = 6, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 183, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 77, .box_w = 1, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 172, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 226, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 186, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 177, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 168, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 179, .box_w = 8, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 504, .adv_w = 172, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 178, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 137, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 177, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 162, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 255, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 164, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 158, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 95, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 649, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 95, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 665, .adv_w = 153, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 671, .adv_w = 119, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 672, .adv_w = 89, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 674, .adv_w = 162, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 163, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 163, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 157, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 726, .adv_w = 102, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 163, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 747, .adv_w = 164, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 71, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 71, .box_w = 4, .box_h = 17, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 771, .adv_w = 142, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 71, .box_w = 1, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 786, .adv_w = 249, .box_w = 13, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 164, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 812, .adv_w = 160, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 163, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 833, .adv_w = 162, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 845, .adv_w = 103, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 850, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 112, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 164, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 220, .box_w = 13, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 137, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 148, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 930, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 939, .adv_w = 97, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 946, .adv_w = 68, .box_w = 1, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 97, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 955, .adv_w = 171, .box_w = 8, .box_h = 2, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_rajdhani_medium_20 = {
#else
lv_font_t ui_font_rajdhani_medium_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if UI_FONT_RAJDHANI_MEDIUM_20*/