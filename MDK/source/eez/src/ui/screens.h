#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_POWER_BANK = 2,
    SCREEN_ID_SYSTEM = 3,
    _SCREEN_ID_LAST = 3
};

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *power_bank;
    lv_obj_t *system;
    lv_obj_t *vol;
    lv_obj_t *cur;
    lv_obj_t *obj0;
    lv_obj_t *pow;
    lv_obj_t *obj1;
    lv_obj_t *dc_flag;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *pow_1;
    lv_obj_t *temp;
    lv_obj_t *temp_1;
    lv_obj_t *temp_2;
    lv_obj_t *temp_3;
    lv_obj_t *obj5;
    lv_obj_t *eef;
    lv_obj_t *fc;
    lv_obj_t *p_vol;
    lv_obj_t *p_cou;
    lv_obj_t *obj6;
    lv_obj_t *pow_2;
    lv_obj_t *obj7;
    lv_obj_t *p_chg;
    lv_obj_t *p_dsg;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *pow_3;
    lv_obj_t *temp_4;
    lv_obj_t *temp_5;
    lv_obj_t *temp_6;
    lv_obj_t *temp_7;
    lv_obj_t *bat1;
    lv_obj_t *bat2;
    lv_obj_t *bat3;
    lv_obj_t *bat4;
    lv_obj_t *bat5;
    lv_obj_t *bat3_1;
    lv_obj_t *err;
    lv_obj_t *cap;
    lv_obj_t *hea;
    lv_obj_t *wf;
    lv_obj_t *cpv;
    lv_obj_t *bat5_7;
    lv_obj_t *bat5_6;
    lv_obj_t *bat5_8;
    lv_obj_t *bat5_9;
    lv_obj_t *bat5_10;
    lv_obj_t *bat5_11;
    lv_obj_t *its;
} objects_t;

extern objects_t objects;

void create_screen_main();
void tick_screen_main();

void create_screen_power_bank();
void tick_screen_power_bank();

void create_screen_system();
void tick_screen_system();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/