#include QMK_KEYBOARD_H
#include "debug.h"
#include "led.h"
#include "action_layer.h"
#include "keymap_extras/keymap_neo2.h"

/* #define PERMISSIVE_HOLD */

// Layer names
#define BASE 0 // default layer
#define NEO_L1 1 // neo layer 1 for standard de layout
#define NEO_L3 2 // neo layer 3 for standard de layout
#define NEO_L4 3 // neo layer 4 for standard de layout
#define MDIA 4 // media keys for emulated neo

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   °    |   1  |   2  |   3  |   4  |   5  | Play |           | Next |   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   X  |   V  |   L  |   C  |   W  | Esc  |           | Esc  |   K  |   H  |   G  |   F  |   Q  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Mod3  |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
 * |--------+------+------+------+------+------| MEDIA|           | MEDIA|------+------+------+------+------+--------|
 * | LShift |Ü/Ctrl| Ö/Win| Ä/Alt|   P  |   Z  |      |           |      |   B  |   M  |   ,  |   .  |   J  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Mod4 | Home | PgDn | PgUp | End  |                                       | Right| Down |  Up  | Left | Mod4 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  |NEO-em|       | Alt  |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Enter|       |Delete|        |      |
 *                                 | Space|Backsp|------|       |------|  Enter |Space |
 *                                 |      |ace   | Delet|       | Mod3 |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        NEO_CIRC,        NEO_1,         NEO_2,         NEO_3,         NEO_4,   NEO_5,   KC_MPLY,
        KC_TAB,          NEO_X,         NEO_V,         NEO_L,         NEO_C,   NEO_W,   KC_ESC,
        NEO_MOD3_L,      NEO_U,         NEO_I,         NEO_A,         NEO_E,   NEO_O,
        KC_LSFT,         CTL_T(NEO_UE), GUI_T(NEO_OE), ALT_T(NEO_AE), NEO_P,   NEO_Z,   TG(MDIA),
        NEO_MOD4_L,      KC_HOME,       KC_PGDN,       KC_PGUP,       KC_END,
                                                C_S_T(KC_ESC),TG(NEO_L1),
                                                              KC_ENT,
                                               KC_SPC,KC_BSPC,KC_DELT,
        // right hand
        KC_MNXT,     NEO_6,   NEO_7,   NEO_8,   NEO_9,   NEO_0,   NEO_GRV,
        KC_ESC,      NEO_K,   NEO_H,   NEO_G,   NEO_F,   NEO_Q,   NEO_SS,
                     NEO_S,   NEO_N,   NEO_R,   NEO_T,   NEO_D,   NEO_Y,
        TG(MDIA),    NEO_B,   NEO_M,   NEO_COMM,NEO_DOT, NEO_J,   KC_RSFT,
                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, NEO_MOD4_R,
        KC_LALT,    KC_RGUI,
        KC_DELT,
        NEO_MOD3_R, KC_ENT, KC_SPC
    ),
/* Keymap 1: Neo layer for standard en layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    °   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   X  |   V  |   L  |   C  |   W  |      |           |      |   K  |   H  |   G  |   F  |   Q  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Mod3  |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
 * |--------+------+------+------+------+------|      |           | MEDIA|------+------+------+------+------+--------|
 * | LShift |Ü/Ctrl| Ö/Win| Ä/Alt|   P  |   Z  |      |           |      |   B  |   M  |   ,  |   .  |   J  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Mod4 |      |      |      |      |                                       |      |      |      |      | Mod4 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       | Mod3 |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NEO_L1] = KEYMAP(
        // left hand
        KC_CIRC,      KC_1,         KC_2,         KC_3,         KC_4,   KC_5,   KC_TRNS,
        KC_TAB,       KC_X,         KC_V,         KC_L,         KC_C,   KC_W,   KC_TRNS,
        MO(NEO_L3),   KC_U,         KC_I,         KC_A,         KC_E,   KC_O,
        KC_LSFT,      CTL_T(DE_UE), GUI_T(DE_OE), ALT_T(DE_AE), KC_P,   KC_Z,   KC_TRNS,
        MO(NEO_L4),   KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,
                                                KC_TRNS,   KC_TRNS,
                                                           KC_TRNS,
                                     KC_TRNS,   KC_TRNS,   KC_TRNS,
        // right hand
        KC_TRNS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_GRV,
        KC_TRNS,     KC_K,   KC_H,   KC_G,   KC_F,   KC_Q,   DE_SS,
                     KC_S,   KC_N,   KC_R,   KC_T,   KC_D,   KC_Y,
        TG(MDIA),    KC_B,   KC_M,   KC_COMM,KC_DOT, KC_J,   KC_TRNS,
                             KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,MO(NEO_L4),
        KC_TRNS,   KC_TRNS,
        KC_TRNS,
        MO(NEO_L3),KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Neo layer 3 for standard de layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   ¹  |   ²  |   ³  |   ›  |   ‹  |      |           |      |   ¢  |   ¥  |   ‚  |   ‘  |   ’  |   °    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   …  |   _  |   [  |   ]  |   ^  |      |           |      |   !  |   <  |   >  |   =  |   &  |   ſ    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   :  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   |  |   ~  |   `  |      |           |      |   +  |   %  |   "  |   '  |   ;  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NEO_L3] = KEYMAP(
        // left hand
        KC_TRNS,      UC(0x00B9),   DE_SQ2,       DE_SQ3,       UC(0x203A),UC(0x2039), KC_TRNS,
        KC_TRNS,      UC(0x2026),   KC_UNDS,      KC_LBRC,      KC_RBRC,   KC_CIRC,    KC_TRNS,
        KC_TRNS,      KC_BSLS,      KC_SLSH,      KC_LCBR,      KC_RCBR,   KC_ASTR,
        KC_TRNS,      KC_HASH,      KC_DLR,       KC_PIPE,      KC_TILD,   UC(0x0060), KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                          KC_TRNS,   KC_TRNS,
                                                                                     KC_TRNS,
                                                               KC_TRNS,   KC_TRNS,   KC_TRNS,
        // right hand
        KC_TRNS,      UC(0x00A2),   UC(0x00A5),   KC_COMM,      UC(0x02BB),UC(0x02BC), KC_GRV,
        KC_TRNS,      KC_EXLM,      KC_LABK,      KC_RABK,      KC_EQL,    KC_AMPR,  UC(0x017F),
                      KC_QUES,      KC_LPRN,      KC_RPRN,      KC_MINS,   KC_COLN,  KC_AT,
        KC_TRNS,      KC_PLUS,      KC_PERC,      KC_DQUO,      KC_QUOT,   KC_SCLN,  KC_TRNS,
                                    KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,
        KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
/* Keymap 3: Neo layer 4 for standard de layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Home |  BS  |  UP  |  DEL |  End |      |           |      |   ¡  |   7  |   8  |   9  |   +  |   −    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | PGUP | RIGHT| DOWN | LEFT | PGDN |------|           |------|   ¿  |   4  |   5  |   6  |   ,  |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  TAB |      | Enter|      |      |           |      |   :  |   1  |   2  |   3  |   ;  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NEO_L4] = KEYMAP(
        // left hand
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,      KC_HOME,      KC_BSPC,      KC_UP,        KC_DEL,    KC_END,   KC_TRNS,
        KC_TRNS,      KC_PGUP,      KC_RGHT,      KC_DOWN,      KC_LEFT,   KC_PGDN,
        KC_TRNS,      KC_TRNS,      KC_TAB,       KC_TRNS,      KC_ENT,    KC_TRNS,  KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                          KC_TRNS,   KC_TRNS,
                                                                                     KC_TRNS,
                                                               KC_TRNS,   KC_TRNS,   KC_TRNS,
        // right hand
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  DE_GRV,
        KC_TRNS,      UC(0x00A1),   DE_7,         DE_8,         DE_8,      DE_PLUS,  DE_MINS,
                      UC(0x00BF),   DE_4,         DE_5,         DE_6,      DE_COMM,  DE_DOT,
        KC_TRNS,      DE_COLN,      DE_1,         DE_2,         DE_3,      DE_SCLN,  KC_TRNS,
                                    KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,
        KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    ),
/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |VolDwn| Mute |VolUp |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn4 |MsLeft|MsDown|MsRght| Btn5 |------|           |------|      | Prev | Stop | Play | Next |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WhRght|WhDown| WhUp |WhLeft|WhClk |      |           |      |BwSrch|BwBack|BwHome|BwRefr|BwFwd |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |MsAcl0|MsAcl1|MsAcl2|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,
       KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
       KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_F12,
                KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS,
       KC_TRNS, KC_WSCH, KC_WBAK, KC_WHOM, KC_WREF, KC_WFWD, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
)
};


const uint16_t PROGMEM fn_actions[] = {
    /* [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols) */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    /* MACRODOWN only works in this function
    switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    */
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    uint8_t emulate_neo = layer_state & (1L << NEO_L1);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_board_led_off();

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    }

    if (emulate_neo) {
        ergodox_right_led_1_on();
    }

    switch (layer) {
        case MDIA:
            ergodox_right_led_2_on();
            break;
    }

};
