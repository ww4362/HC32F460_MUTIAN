/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font resource\Rajdhani-Bold.ttf --range 32-127 --format lvgl
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

#ifndef UI_FONT_RAJDHANI_BOLD_14
#define UI_FONT_RAJDHANI_BOLD_14 1
#endif

#if UI_FONT_RAJDHANI_BOLD_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xc0, 0xc0,

    /* U+0022 "\"" */
    0x55, 0x50,

    /* U+0023 "#" */
    0x1b, 0xd, 0x9f, 0xe2, 0x43, 0x61, 0xb3, 0xfc,
    0x48, 0x6c, 0x0,

    /* U+0024 "$" */
    0x31, 0xef, 0xf3, 0xc3, 0xe7, 0xc3, 0xcd, 0xe3,
    0xc,

    /* U+0025 "%" */
    0xf4, 0x4a, 0x27, 0x1f, 0x0, 0x80, 0xbc, 0x52,
    0x69, 0x27, 0x80,

    /* U+0026 "&" */
    0x38, 0x6c, 0x6c, 0x60, 0x70, 0xdf, 0xdc, 0xcc,
    0x7e,

    /* U+0027 "'" */
    0x40,

    /* U+0028 "(" */
    0x7b, 0x6d, 0xb6, 0xcc,

    /* U+0029 ")" */
    0xe3, 0x33, 0x33, 0x33, 0x3e,

    /* U+002A "*" */
    0xd6, 0xf0,

    /* U+002B "+" */
    0x30, 0xc3, 0x3f, 0x30, 0xc0,

    /* U+002C "," */
    0xf8,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x8, 0xc4, 0x63, 0x11, 0x8c, 0xc0,

    /* U+0030 "0" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78,

    /* U+0031 "1" */
    0x3f, 0x33, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0x7b, 0x3c, 0xc7, 0x3d, 0xee, 0x30, 0xfc,

    /* U+0033 "3" */
    0x7b, 0x3c, 0xc3, 0x38, 0x3c, 0xf3, 0x78,

    /* U+0034 "4" */
    0x1c, 0x78, 0xf3, 0x66, 0xd9, 0xbf, 0x86, 0xc,

    /* U+0035 "5" */
    0xff, 0xc, 0x3e, 0xcc, 0x3c, 0xf3, 0x78,

    /* U+0036 "6" */
    0x7b, 0xc, 0x30, 0xfb, 0x3c, 0xf3, 0x78,

    /* U+0037 "7" */
    0xf8, 0xc6, 0x63, 0x19, 0x8c, 0xc0,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xf3, 0x7b, 0x3c, 0xf3, 0x78,

    /* U+0039 "9" */
    0x7b, 0x3c, 0xf3, 0xcd, 0xf0, 0xc3, 0xf8,

    /* U+003A ":" */
    0xc0, 0xc,

    /* U+003B ";" */
    0xc0, 0xf8,

    /* U+003C "<" */
    0xd, 0xec, 0x1e, 0xc,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xc3, 0xe0, 0xde, 0xc0,

    /* U+003F "?" */
    0x7b, 0x3c, 0xc7, 0x38, 0xc3, 0x0, 0x30,

    /* U+0040 "@" */
    0x3f, 0x60, 0x67, 0xb6, 0xdb, 0x6d, 0xb6, 0xfd,
    0x80, 0x7c, 0x0,

    /* U+0041 "A" */
    0x38, 0x3c, 0x3c, 0x3c, 0x64, 0x66, 0x7e, 0x46,
    0xc2,

    /* U+0042 "B" */
    0xfb, 0x3c, 0xf3, 0xfb, 0x3c, 0xf3, 0xf8,

    /* U+0043 "C" */
    0x7b, 0x3c, 0xf0, 0xc3, 0xc, 0xf3, 0x78,

    /* U+0044 "D" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xf8,

    /* U+0045 "E" */
    0xfe, 0x31, 0x8f, 0xe3, 0x18, 0xf8,

    /* U+0046 "F" */
    0xfe, 0x31, 0x8f, 0xe3, 0x18, 0xc0,

    /* U+0047 "G" */
    0x7b, 0x3c, 0xf0, 0xdf, 0x3c, 0xf3, 0x78,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0x3c, 0xf3, 0xcc,

    /* U+0049 "I" */
    0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xf, 0x3c, 0xf3, 0x78,

    /* U+004B "K" */
    0xcd, 0x9b, 0x67, 0x8f, 0x1f, 0x33, 0x66, 0xc6,

    /* U+004C "L" */
    0xc6, 0x31, 0x8c, 0x63, 0x18, 0xf8,

    /* U+004D "M" */
    0xe7, 0xe7, 0xe7, 0xef, 0xdb, 0xdb, 0xdb, 0xc3,
    0xc3,

    /* U+004E "N" */
    0xcf, 0x3e, 0xfb, 0xff, 0x7d, 0xf3, 0xcc,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78,

    /* U+0050 "P" */
    0xfb, 0x3c, 0xf3, 0xcf, 0xec, 0x30, 0xc0,

    /* U+0051 "Q" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78, 0x41,
    0x80,

    /* U+0052 "R" */
    0xfb, 0x3c, 0xf3, 0xcf, 0xed, 0xb2, 0xcc,

    /* U+0053 "S" */
    0x7b, 0x3c, 0xfc, 0xfd, 0xfc, 0xf3, 0x78,

    /* U+0054 "T" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78,

    /* U+0056 "V" */
    0xc6, 0x8d, 0x9b, 0x66, 0xc5, 0x8a, 0x1c, 0x38,

    /* U+0057 "W" */
    0xcc, 0xf9, 0xdb, 0x3b, 0x25, 0x65, 0xac, 0xf5,
    0x9c, 0xa3, 0x9c, 0x73, 0x80,

    /* U+0058 "X" */
    0x66, 0xcc, 0xb1, 0xe3, 0x87, 0x9b, 0x33, 0xc6,

    /* U+0059 "Y" */
    0x66, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18,
    0x18,

    /* U+005A "Z" */
    0xfc, 0x31, 0xce, 0x31, 0xc6, 0x30, 0xfc,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdc,

    /* U+005C "\\" */
    0x43, 0x18, 0x43, 0x18, 0x43, 0x8,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0x7c,

    /* U+005E "^" */
    0x38, 0x51, 0xb2, 0x20,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0xc0,

    /* U+0061 "a" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+0062 "b" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0063 "c" */
    0x7e, 0x31, 0x8c, 0x61, 0xe0,

    /* U+0064 "d" */
    0xc, 0x30, 0xdf, 0xcf, 0x3c, 0xf3, 0xcd, 0xf0,

    /* U+0065 "e" */
    0x7b, 0x3c, 0xff, 0xc3, 0x7, 0xc0,

    /* U+0066 "f" */
    0x36, 0x6f, 0x66, 0x66, 0x66,

    /* U+0067 "g" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xf8,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0xc3, 0xff, 0xf0,

    /* U+006A "j" */
    0x30, 0x3, 0x33, 0x33, 0x33, 0x3e,

    /* U+006B "k" */
    0xc3, 0xc, 0x33, 0xdb, 0x6f, 0x36, 0xdb, 0x30,

    /* U+006C "l" */
    0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xff, 0xb3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcc,

    /* U+006E "n" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0070 "p" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc0,

    /* U+0071 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc,

    /* U+0072 "r" */
    0xfc, 0xcc, 0xcc, 0xc0,

    /* U+0073 "s" */
    0xfe, 0x38, 0xe3, 0x8f, 0xc0,

    /* U+0074 "t" */
    0x63, 0x3c, 0xc6, 0x31, 0x8c, 0x38,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+0076 "v" */
    0xcd, 0x36, 0xda, 0x68, 0xe3, 0x80,

    /* U+0077 "w" */
    0xcd, 0x93, 0x65, 0xd9, 0xf6, 0x77, 0x9c, 0xc3,
    0x30,

    /* U+0078 "x" */
    0xcd, 0xa3, 0x8c, 0x79, 0xbc, 0xc0,

    /* U+0079 "y" */
    0x46, 0xd9, 0xb3, 0x62, 0x87, 0xe, 0xc, 0x70,

    /* U+007A "z" */
    0xf8, 0xcc, 0xe6, 0x73, 0xe0,

    /* U+007B "{" */
    0x36, 0x66, 0xc6, 0x66, 0x63,

    /* U+007C "|" */
    0xff, 0x80,

    /* U+007D "}" */
    0xc6, 0x66, 0x36, 0x66, 0x6c,

    /* U+007E "~" */
    0xe6, 0x70
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 49, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 53, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 79, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 118, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 166, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 42, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 47, .adv_w = 69, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 51, .adv_w = 69, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 56, .adv_w = 89, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 58, .adv_w = 127, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 63, .adv_w = 46, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 64, .adv_w = 70, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 65, .adv_w = 46, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 75, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 114, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 113, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 97, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 46, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 46, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 126, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 148, .adv_w = 127, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 151, .adv_w = 127, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 155, .adv_w = 104, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 167, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 173, .adv_w = 125, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 124, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 124, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 107, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 101, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 122, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 129, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 60, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 117, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 125, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 101, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 163, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 124, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 119, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 127, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 292, .adv_w = 123, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 99, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 125, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 117, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 181, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 116, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 117, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 72, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 369, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 72, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 379, .adv_w = 114, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 383, .adv_w = 83, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 384, .adv_w = 67, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 385, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 118, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 118, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 111, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 79, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 430, .adv_w = 117, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 438, .adv_w = 55, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 55, .box_w = 4, .box_h = 12, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 447, .adv_w = 106, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 55, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 179, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 117, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 114, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 118, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 486, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 493, .adv_w = 78, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 98, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 79, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 117, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 105, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 156, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 103, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 106, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 543, .adv_w = 101, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 553, .adv_w = 52, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 71, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 560, .adv_w = 127, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4}
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
const lv_font_t ui_font_rajdhani_bold_14 = {
#else
lv_font_t ui_font_rajdhani_bold_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
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

#endif /*#if UI_FONT_RAJDHANI_BOLD_14*/