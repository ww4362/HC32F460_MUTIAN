/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font resource\ChillBitmap_7px.ttf --symbols 电压 --range 32-127 --format lvgl
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

#ifndef UI_FONT_7PX__
#define UI_FONT_7PX__ 1
#endif

#if UI_FONT_7PX__

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xc3, 0xc0,

    /* U+0022 "\"" */
    0xde, 0xf6,

    /* U+0023 "#" */
    0x33, 0x19, 0xbf, 0xff, 0xf3, 0x37, 0xff, 0xfe,
    0x66, 0x33, 0x0,

    /* U+0024 "$" */
    0x18, 0xc, 0xf, 0x87, 0xcd, 0x86, 0xc0, 0xf8,
    0x7c, 0x19, 0xff, 0x3f, 0x83, 0x1, 0x80,

    /* U+0025 "%" */
    0x30, 0x63, 0x6, 0xc9, 0x8c, 0x98, 0x36, 0x3,
    0x60, 0x6, 0x60, 0x99, 0x9, 0x93, 0x6, 0x30,
    0x60,

    /* U+0026 "&" */
    0x38, 0x73, 0x6, 0x3, 0x79, 0x32, 0x7b, 0xf6,

    /* U+0027 "'" */
    0x33, 0xcc,

    /* U+0028 "(" */
    0x33, 0xcc, 0xcc, 0xcc, 0xcc, 0xc3, 0x30,

    /* U+0029 ")" */
    0xcc, 0x33, 0x33, 0x33, 0x33, 0x3c, 0xc0,

    /* U+002A "*" */
    0x31, 0xbf, 0xf3, 0x67, 0x20,

    /* U+002B "+" */
    0x37, 0xfe, 0x63, 0x0,

    /* U+002C "," */
    0x33, 0xcc,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0x42, 0x3, 0x18, 0xc0, 0xc6, 0x30,

    /* U+0030 "0" */
    0x39, 0xf7, 0xbd, 0xef, 0x7e, 0xf0,

    /* U+0031 "1" */
    0x33, 0xff, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0xf7, 0x82, 0x13, 0x7b, 0x1f, 0xf8,

    /* U+0033 "3" */
    0xf7, 0x82, 0x13, 0x4, 0x3e, 0xf0,

    /* U+0034 "4" */
    0x31, 0xb1, 0x8c, 0xff, 0xe1, 0x8,

    /* U+0035 "5" */
    0xff, 0xf1, 0x8f, 0xfc, 0x3e, 0xf0,

    /* U+0036 "6" */
    0x31, 0xb1, 0x8f, 0xff, 0x3e, 0xf0,

    /* U+0037 "7" */
    0xff, 0xc2, 0x13, 0x18, 0xd8, 0xc0,

    /* U+0038 "8" */
    0x39, 0xf3, 0x93, 0x67, 0x3e, 0xf0,

    /* U+0039 "9" */
    0x39, 0xf3, 0x9f, 0xfc, 0x26, 0x30,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0x33, 0x0, 0x3, 0x3c, 0xc0,

    /* U+003C "<" */
    0x8, 0x4c, 0x6c, 0x18, 0xc1, 0x8,

    /* U+003D "=" */
    0xff, 0xc0, 0xf, 0xfc,

    /* U+003E ">" */
    0xc6, 0xc, 0x60, 0x98, 0xd8, 0xc0,

    /* U+003F "?" */
    0x31, 0xb3, 0x90, 0x80, 0xc6, 0x1, 0x8c,

    /* U+0040 "@" */
    0x3e, 0x1f, 0x36, 0x7b, 0x3d, 0xfe, 0xff, 0x0,
    0x7f, 0x3f, 0x80,

    /* U+0041 "A" */
    0x8, 0x10, 0xd9, 0xbc, 0x7f, 0xff, 0xe3, 0xc6,

    /* U+0042 "B" */
    0xf9, 0xf3, 0x1e, 0x3f, 0x98, 0xf1, 0xfc, 0xf8,

    /* U+0043 "C" */
    0x38, 0x73, 0x1e, 0x3c, 0x18, 0xf1, 0x9c, 0x38,

    /* U+0044 "D" */
    0xf9, 0xf3, 0x1e, 0x3c, 0x7b, 0x36, 0x78, 0xf0,

    /* U+0045 "E" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x3f, 0xfc,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xc0,

    /* U+0047 "G" */
    0x3e, 0x7f, 0x6, 0xd, 0xfb, 0xf1, 0x9c, 0x38,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xff, 0xf1, 0xe3, 0xc6,

    /* U+0049 "I" */
    0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0x3e, 0x7c, 0x20, 0x40, 0x99, 0x32, 0x18, 0x30,

    /* U+004B "K" */
    0xc7, 0x8f, 0x66, 0xcf, 0x1b, 0x36, 0x63, 0xc6,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x3f, 0xfc,

    /* U+004D "M" */
    0xc1, 0xe0, 0xfd, 0xfe, 0xfd, 0x9e, 0xcf, 0x67,
    0x83, 0xc1, 0x80,

    /* U+004E "N" */
    0xc7, 0x8f, 0xdf, 0xbd, 0xfb, 0xf1, 0xe3, 0xc6,

    /* U+004F "O" */
    0x38, 0x73, 0x1e, 0x3c, 0x78, 0xf1, 0x9c, 0x38,

    /* U+0050 "P" */
    0xf9, 0xf3, 0x1e, 0x3f, 0xff, 0xf0, 0x60, 0xc0,

    /* U+0051 "Q" */
    0x38, 0x73, 0x1f, 0xbf, 0x79, 0x32, 0x1b, 0x36,

    /* U+0052 "R" */
    0xf9, 0xf3, 0x1e, 0x3f, 0x9f, 0x36, 0x63, 0xc6,

    /* U+0053 "S" */
    0x3e, 0x7f, 0x6, 0x3, 0x80, 0xc1, 0xfc, 0xf8,

    /* U+0054 "T" */
    0xff, 0xcc, 0x63, 0x18, 0xc6, 0x30,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0x9c, 0x38,

    /* U+0056 "V" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x79, 0x32, 0x18, 0x30,

    /* U+0057 "W" */
    0xc1, 0xe0, 0xf2, 0x79, 0x3c, 0x98, 0x0, 0xd8,
    0x6c, 0x36, 0x0,

    /* U+0058 "X" */
    0xc7, 0x8f, 0x18, 0x3, 0x87, 0x31, 0xe3, 0xc6,

    /* U+0059 "Y" */
    0xc7, 0x8f, 0x18, 0x3, 0x87, 0x2, 0x78, 0xf0,

    /* U+005A "Z" */
    0xff, 0xc2, 0x13, 0x7b, 0x1f, 0xf8,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf, 0xf0,

    /* U+005C "\\" */
    0xc6, 0x30, 0x3, 0x18, 0xc0, 0x8, 0x42,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x3f, 0xf0,

    /* U+005E "^" */
    0x31, 0xb3, 0x90,

    /* U+005F "_" */
    0xff, 0xc0,

    /* U+0060 "`" */
    0xcc, 0x33,

    /* U+0061 "a" */
    0x39, 0xf7, 0xbd, 0x9c, 0xe0,

    /* U+0062 "b" */
    0xc6, 0x31, 0x8f, 0x7b, 0x7b, 0xdf, 0xbc,

    /* U+0063 "c" */
    0x39, 0xf1, 0x8c, 0x1c, 0xe0,

    /* U+0064 "d" */
    0x18, 0xc6, 0x33, 0x9f, 0x7b, 0xd9, 0xce,

    /* U+0065 "e" */
    0x3c, 0xfc, 0xff, 0xf0, 0xf3, 0xc0,

    /* U+0066 "f" */
    0x33, 0xcc, 0xff, 0xcc, 0xcc, 0xc0,

    /* U+0067 "g" */
    0x39, 0xf7, 0xbf, 0xfc, 0x7e, 0xf0,

    /* U+0068 "h" */
    0xc6, 0x31, 0x8f, 0x7b, 0x7b, 0xde, 0xf6,

    /* U+0069 "i" */
    0xf0, 0xff, 0xfc,

    /* U+006A "j" */
    0x33, 0x0, 0x33, 0x33, 0x33, 0x3c, 0xc0,

    /* U+006B "k" */
    0xc6, 0x31, 0x8d, 0xef, 0xde, 0xde, 0xf6,

    /* U+006C "l" */
    0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xf6, 0x7b, 0x36, 0x7b, 0x3d, 0x9e, 0xf, 0x6,

    /* U+006E "n" */
    0xf7, 0xb7, 0xbd, 0xef, 0x60,

    /* U+006F "o" */
    0x31, 0xb3, 0x9c, 0x98, 0xc0,

    /* U+0070 "p" */
    0xf7, 0xb7, 0xbd, 0xfb, 0xd8, 0xc0,

    /* U+0071 "q" */
    0x39, 0xf7, 0xbd, 0x9c, 0xe3, 0x18,

    /* U+0072 "r" */
    0x33, 0xcc, 0xcc, 0xc0,

    /* U+0073 "s" */
    0x7b, 0xfc, 0xf7, 0xfb, 0xc0,

    /* U+0074 "t" */
    0xcc, 0xff, 0xcc, 0xc3, 0x30,

    /* U+0075 "u" */
    0xde, 0xf7, 0xbd, 0x9c, 0xe0,

    /* U+0076 "v" */
    0xde, 0xf7, 0xef, 0x63, 0x0,

    /* U+0077 "w" */
    0xc1, 0xe0, 0xf6, 0x7f, 0xcf, 0xe6, 0xc3, 0x60,

    /* U+0078 "x" */
    0xce, 0x4c, 0x6c, 0xe7, 0x20,

    /* U+0079 "y" */
    0xde, 0xf6, 0x33, 0x9c, 0x7e, 0xf0,

    /* U+007A "z" */
    0xff, 0xc2, 0x73, 0x7f, 0xe0,

    /* U+007B "{" */
    0x8, 0x4c, 0x63, 0x3, 0x18, 0x31, 0x8c, 0x10,
    0x80,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xc6, 0xc, 0x63, 0x0, 0x21, 0x31, 0x8d, 0x8c,
    0x0,

    /* U+007E "~" */
    0x36, 0x6f, 0x26, 0x40,

    /* U+538B "压" */
    0x3f, 0xf3, 0xff, 0x20, 0x2, 0x0, 0x21, 0x2,
    0x7c, 0x27, 0xc2, 0x13, 0x21, 0x32, 0x10, 0x21,
    0xd, 0xff, 0xdf, 0xf0,

    /* U+7535 "电" */
    0x18, 0x0, 0xc0, 0x3f, 0xf9, 0xff, 0xcd, 0x86,
    0x6c, 0x33, 0xff, 0x9f, 0xfc, 0xd8, 0x67, 0xfc,
    0xff, 0xe6, 0x3f, 0xc1, 0xfe, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 84, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 112, .box_w = 2, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 168, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 32, .adv_w = 224, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 84, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 59, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 66, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 73, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 78, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 82, .adv_w = 84, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 84, .adv_w = 112, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 86, .adv_w = 56, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 84, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 112, .box_w = 2, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 112, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 160, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 112, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 170, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 56, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 168, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 403, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 112, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 417, .adv_w = 112, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 420, .adv_w = 112, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 422, .adv_w = 112, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 424, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 84, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 466, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 56, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 476, .adv_w = 84, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 483, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 56, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 168, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 517, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 523, .adv_w = 84, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 84, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 168, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 566, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 112, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 580, .adv_w = 112, .box_w = 2, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 584, .adv_w = 112, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 593, .adv_w = 140, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 597, .adv_w = 224, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 617, .adv_w = 224, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x21aa
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 21387, .range_length = 8619, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 2, 2, 2, 0, 2, 2,
    2, 2, 2, 2, 3, 3, 3, 3,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 3, 3, 2, 3, 3,
    2, 2, 0, 0, 0, 4, 0, 5,
    0, 0, 0, 6, 0, 7, 0, 0,
    0, 0, 0, 0, 0, 8, 0, 0,
    0, 0, 0, 0, 2, 2, 2, 2,
    2, 2, 4, 9, 4, 0, 4, 0,
    4, 4, 0, 0, 4, 0, 4, 4,
    9, 9, 4, 9, 9, 4, 4, 9,
    9, 4, 4, 4, 2, 2, 2, 2,
    0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 2, 3, 2, 2,
    2, 2, 4, 0, 5, 0, 0, 0,
    4, 0, 0, 0, 0, 0, 0, 0,
    4, 0, 4, 0, 0, 6, 0, 0,
    7, 0, 0, 0, 2, 2, 2, 2,
    2, 2, 4, 0, 4, 4, 4, 0,
    4, 0, 0, 8, 0, 0, 5, 4,
    4, 5, 4, 4, 4, 0, 5, 5,
    5, 5, 5, 5, 2, 2, 2, 2,
    0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -28, -28, 0, 0, -28, 0, -28,
    -28, 0, 0, 0, 0, 0, 0, 0,
    -28, 0, 0, 0, 0, -28, 0, 0,
    0, 0, 0, 0, 0, -28, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -28,
    0, 0, 0, -28, 0, 0, 0, -28,
    0, 0, 0, 0, 0, -28, -28, 0,
    0, 0, -28, -28, -28, 0, 0, -28,
    0, 0, 0, 0, 0, -28, 0, -28
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 9,
    .right_class_cnt     = 8,
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
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
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
const lv_font_t ui_font_7px__ = {
#else
lv_font_t ui_font_7px__ = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if UI_FONT_7PX__*/

