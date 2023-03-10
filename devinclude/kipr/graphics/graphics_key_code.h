/*!
* \file graphics_key_code.h
* \brief Key codes used in the graphics window
* \copyright KISS Insitute for Practical Robotics
* \defgroup graphics Graphics
*/

#ifndef _KIPR_GRAPHICS_GRAPHICS_KEY_CODE_H_
#define _KIPR_GRAPHICS_GRAPHICS_KEY_CODE_H_

#ifdef __cplusplus
extern "C" {
#endif

//! All Key Codes
enum KeyCode
{
  KeyEnter = '\n',      ///< enter key
  KeyBackSpace = '\b',      ///< backspace key
  KeyTab = '\t',      ///< tab key
  KeyCancel = 0x03,      ///< cancel key
  KeyClear = 0x0C,      ///< clear key
  KeyShift = 0x10,      ///< shift key
  KeyControl = 0x11,      ///< control key
  KeyAlt = 0x12,      ///< alt key
  KeyPause = 0x13,      ///< pause key
  KeyCapsLock = 0x14,      ///< capslock key
  KeyEscape = 0x1B,      ///< escape key
  KeySpace = 0x20,      ///< space key
  KeyPageUp = 0x21,      ///< page up key
  KeyPageDown = 0x22,      ///< page down key
  KeyEnd = 0x23,      ///< end key
  KeyHome = 0x24,      ///< home key
  KeyLeft = 0x25,      ///< left key
  KeyUp = 0x26,      ///< up arrow key
  KeyRight = 0x27,      ///< right arrow key
  KeyDown = 0x28,      ///< down arrow key
  KeyComma = 0x2C,      ///< comma key ','
  KeyPeriod = 0x2E,      ///< period key '.'
  KeySlash = 0x2F,      ///< slash key '/'
  KeyZero = 0x30,      ///< zero key
  KeyOne = 0x31,      ///< one key
  KeyTwo = 0x32,      ///< two key
  KeyThree = 0x33,      ///< three key
  KeyFour = 0x34,      ///< four key
  KeyFive = 0x35,      ///< five key
  KeySix = 0x36,      ///< six key
  KeySeven = 0x37,      ///< seven key
  KeyEight = 0x38,      ///< eight key
  KeyNine = 0x39,      ///< nine key
  KeySemiColon = 0x3B,      ///< semicolon key ';'
  KeyEquals = 0x3D,      ///< equals key '='
  KeyA = 0x41,      ///< a key
  KeyB = 0x42,      ///< b key
  KeyC = 0x43,      ///< c key
  KeyD = 0x44,      ///< d key
  KeyE = 0x45,      ///< e key
  KeyF = 0x46,      ///< f key
  KeyG = 0x47,      ///< g key
  KeyH = 0x48,      ///< h key
  KeyI = 0x49,      ///< i key
  KeyJ = 0x4A,      ///< j key
  KeyK = 0x4B,      ///< k key
  KeyL = 0x4C,      ///< l key
  KeyM = 0x4D,      ///< m key
  KeyN = 0x4E,      ///< n key
  KeyO = 0x4F,      ///< o key
  KeyP = 0x50,      ///< p key
  KeyQ = 0x51,      ///< q key
  KeyR = 0x52,      ///< r key
  KeyS = 0x53,      ///< s key
  KeyT = 0x54,      ///< t key
  KeyU = 0x55,      ///< u key
  KeyV = 0x56,      ///< v key
  KeyW = 0x57,      ///< w key
  KeyX = 0x58,      ///< x key
  KeyY = 0x59,      ///< y key
  KeyZ = 0x5A,      ///< z key
  KeyOpenBracket = 0x5B,      ///< open bracket key '['
  KeyBackSlash = 0x5C,      ///< back slash key '\'
  KeyCloseBracket = 0x5D,      ///< close bracket key ']'
  KeyNumPad0 = 0x60,      ///< numpad 0 key
  KeyNumPad1 = 0x61,      ///< numpad 1 key
  KeyNumPad2 = 0x62,      ///< numpad 2 key
  KeyNumPad3 = 0x63,      ///< numpad 3 key
  KeyNumPad4 = 0x64,      ///< numpad 4 key
  KeyNumPad5 = 0x65,      ///< numpad 5 key
  KeyNumPad6 = 0x66,      ///< numpad 6 key
  KeyNumPad7 = 0x67,      ///< numpad 7 key
  KeyNumPad8 = 0x68,      ///< numpad 8 key
  KeyNumPad9 = 0x69,      ///< numpad 9 key
  KeyMultiply = 0x6A,      ///< multiply key '*'
  KeyAdd = 0x6B,      ///< add key '+'
  KeySeparator = 0x6C,      ///< separator key '-'
  KeySubtract = 0x6D,      ///< subtract key '-'
  KeyDecimal = 0x6E,      ///< decimal key '.'
  KeyDivide = 0x6F,      ///< divide key '/'
  KeyF1 = 0x70,      ///< F1 key
  KeyF2 = 0x71,      ///< F2 key
  KeyF3 = 0x72,      ///< F3 key
  KeyF4 = 0x73,      ///< F4 key
  KeyF5 = 0x74,      ///< F5 key
  KeyF6 = 0x75,      ///< F6 key
  KeyF7 = 0x76,      ///< F7 key
  KeyF8 = 0x77,      ///< F8 key
  KeyF9 = 0x78,      ///< F9 key
  KeyF10 = 0x79,      ///< F10 key
  KeyF11 = 0x7A,      ///< F11 key
  KeyF12 = 0x7B,      ///< F12 key
  KeyDelete = 0x7F,      ///< delete key
  KeyNumLock = 0x90,      ///< numlock key
  KeyScrollLock = 0x91,      ///< scroll lock key
  KeyPrintScreen = 0x9A,      ///< print screen key
  KeyInsert = 0x9B,      ///< insert key
  KeyHelp = 0x9C,      ///< help key
  KeyMeta = 0x9D,      ///< meta key
  KeyBackQuote = 0xC0,      ///< backquote key
  KeyQuote = 0xDE,      ///< quote key
  KeyFinal = 0x18,      ///< final key
  KeyConvert = 0x1C,      ///< convert key
  KeyNonConvert = 0x1D,      ///< non convert key
  KeyAccept = 0x1E,      ///< accept key
  KeyModeChange = 0x1F,      ///< mode change key
  KeyKana = 0x15,      ///< kana key
  KeyKanji = 0x19,      ///< kanji key
  KeyUndefined = 0x0        ///< undefined key
};

#ifdef __cplusplus
}
#endif


#endif
