#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: 自定义按键编码，与 GLFW 相同
*************************************************/

namespace SandEngine {

    using InputCodeSize = unsigned short;

    namespace InputCode {
        /* 与 glfw3.h 中的编码值相同 */
        enum : InputCodeSize
        {
            SE_MOUSE_BTN_0              = 0,
            SE_MOUSE_BTN_1              = 1,
            SE_MOUSE_BTN_2              = 2,
            SE_MOUSE_BTN_3              = 3,
            SE_MOUSE_BTN_4              = 4,
            SE_MOUSE_BTN_5              = 5,
            SE_MOUSE_BTN_6              = 6,
            SE_MOUSE_BTN_7              = 7,

            SE_MOUSE_BTNN_LAST          = SE_MOUSE_BTN_7,
            SE_MOUSE_BTNN_LEFT          = SE_MOUSE_BTN_0,
            SE_MOUSE_BTNN_RIGHT         = SE_MOUSE_BTN_1,
            SE_MOUSE_BTNN_MIDDLE        = SE_MOUSE_BTN_2,

            SE_KEY_SPACE                = 32, /*   */
            SE_KEY_APOSTROPHE           = 39, /* ' */
            SE_KEY_COMMA                = 44, /* , */
            SE_KEY_MINUS                = 45, /* - */
            SE_KEY_PERIOD               = 46, /* . */
            SE_KEY_SLASH                = 47, /* / */

            SE_KEY_D0                   = 48, /* 0 */
            SE_KEY_D1                   = 49, /* 1 */
            SE_KEY_D2                   = 50, /* 2 */
            SE_KEY_D3                   = 51, /* 3 */
            SE_KEY_D4                   = 52, /* 4 */
            SE_KEY_D5                   = 53, /* 5 */
            SE_KEY_D6                   = 54, /* 6 */
            SE_KEY_D7                   = 55, /* 7 */
            SE_KEY_D8                   = 56, /* 8 */
            SE_KEY_D9                   = 57, /* 9 */

            SE_KEY_SEMICOLON            = 59, /* ; */
            SE_KEY_EQUAL                = 61, /* = */

            SE_KEY_A                    = 65,
            SE_KEY_B                    = 66,
            SE_KEY_C                    = 67,
            SE_KEY_D                    = 68,
            SE_KEY_E                    = 69,
            SE_KEY_F                    = 70,
            SE_KEY_G                    = 71,
            SE_KEY_H                    = 72,
            SE_KEY_I                    = 73,
            SE_KEY_J                    = 74,
            SE_KEY_K                    = 75,
            SE_KEY_L                    = 76,
            SE_KEY_M                    = 77,
            SE_KEY_N                    = 78,
            SE_KEY_O                    = 79,
            SE_KEY_P                    = 80,
            SE_KEY_Q                    = 81,
            SE_KEY_R                    = 82,
            SE_KEY_S                    = 83,
            SE_KEY_T                    = 84,
            SE_KEY_U                    = 85,
            SE_KEY_V                    = 86,
            SE_KEY_W                    = 87,
            SE_KEY_X                    = 88,
            SE_KEY_Y                    = 89,
            SE_KEY_Z                    = 90,

            SE_KEY_LEFT_BRACKET         = 91, /* [ */
            SE_KEY_BACKSLASH            = 92, /* \ */
            SE_KEY_RIGHT_BRACKET        = 93, /* ] */
            SE_KEY_GRAVE_ACCENT         = 96, /* ` */

            SE_KEY_WORLD_1              = 161, /* non-US #1 */
            SE_KEY_WORLD_2              = 162, /* non-US #2 */

            SE_KEY_ESCAPE               = 256,
            SE_KEY_ENTER                = 257,
            SE_KEY_TAB                  = 258,
            SE_KEY_BACKSPACE            = 259,
            SE_KEY_INSERT               = 260,
            SE_KEY_DELETE               = 261,
            SE_KEY_RIGHT                = 262,
            SE_KEY_LEFT                 = 263,
            SE_KEY_DOWN                 = 264,
            SE_KEY_UP                   = 265,
            SE_KEY_PAGE_UP              = 266,
            SE_KEY_PAGE_DOWN            = 267,
            SE_KEY_HOME                 = 268,
            SE_KEY_END                  = 269,
            SE_KEY_CAPS_LOCK            = 280,
            SE_KEY_SCROLL_LOCK          = 281,
            SE_KEY_NUM_LOCK             = 282,
            SE_KEY_PRINT_SCREEN         = 283,
            SE_KEY_PAUSE                = 284,
            SE_KEY_F1                   = 290,
            SE_KEY_F2                   = 291,
            SE_KEY_F3                   = 292,
            SE_KEY_F4                   = 293,
            SE_KEY_F5                   = 294,
            SE_KEY_F6                   = 295,
            SE_KEY_F7                   = 296,
            SE_KEY_F8                   = 297,
            SE_KEY_F9                   = 298,
            SE_KEY_F10                  = 299,
            SE_KEY_F11                  = 300,
            SE_KEY_F12                  = 301,
            SE_KEY_F13                  = 302,
            SE_KEY_F14                  = 303,
            SE_KEY_F15                  = 304,
            SE_KEY_F16                  = 305,
            SE_KEY_F17                  = 306,
            SE_KEY_F18                  = 307,
            SE_KEY_F19                  = 308,
            SE_KEY_F20                  = 309,
            SE_KEY_F21                  = 310,
            SE_KEY_F22                  = 311,
            SE_KEY_F23                  = 312,
            SE_KEY_F24                  = 313,
            SE_KEY_F25                  = 314,

            SE_KEY_KP_0                 = 320,
            SE_KEY_KP_1                 = 321,
            SE_KEY_KP_2                 = 322,
            SE_KEY_KP_3                 = 323,
            SE_KEY_KP_4                 = 324,
            SE_KEY_KP_5                 = 325,
            SE_KEY_KP_6                 = 326,
            SE_KEY_KP_7                 = 327,
            SE_KEY_KP_8                 = 328,
            SE_KEY_KP_9                 = 329,
            SE_KEY_KP_DECIMAL           = 330,
            SE_KEY_KP_DIVIDE            = 331,
            SE_KEY_KP_MULTIPLY          = 332,
            SE_KEY_KP_SUBTRACT          = 333,
            SE_KEY_KP_ADD               = 334,
            SE_KEY_KP_ENTER             = 335,
            SE_KEY_KP_EQUAL             = 336,

            SE_KEY_LEFT_SHIFT           = 340,
            SE_KEY_LEFT_CONTROL         = 341,
            SE_KEY_LEFT_ALT             = 342,
            SE_KEY_LEFT_SUPER           = 343,
            SE_KEY_RIGHT_SHIFT          = 344,
            SE_KEY_RIGHT_CONTROL        = 345,
            SE_KEY_RIGHT_ALT            = 346,
            SE_KEY_RIGHT_SUPER          = 347,
            SE_KEY_MENU                 = 348,
        };
    }
}