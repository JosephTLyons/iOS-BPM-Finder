/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== BPM Finder Notes.rtf ==================
static const unsigned char temp_binary_data_0[] =
"{\\rtf1\\ansi\\ansicpg1252\\cocoartf1504\\cocoasubrtf810\r\n"
"{\\fonttbl\\f0\\fswiss\\fcharset0 Helvetica;}\r\n"
"{\\colortbl;\\red255\\green255\\blue255;}\r\n"
"{\\*\\expandedcolortbl;;}\r\n"
"\\margl1440\\margr1440\\vieww10800\\viewh8400\\viewkind0\r\n"
"\\pard\\tx0\\tx720\\tx1440\\tx2160\\tx2880\\tx3600\\tx4320\\tx5040\\tx5760\\tx6480\\tx7200\\tx7920\\tx8640\\pardirnatural\\partightenfactor0\r\n"
"\r\n"
"\\f0\\fs24 \\cf0 1) Add Beep\\\r\n"
"2) Increase font size in button text by overriding look and feel class (JUCE forum)\\\r\n"
"3) Make fonts consistent with  sans serif and serif\\\r\n"
"4) Make status bar white\\\r\n"
"5) Scaling GUIs? Double Check This.\\\r\n"
"\\pard\\tx720\\tx1440\\tx2160\\tx2880\\tx3600\\tx4320\\tx5040\\tx5760\\tx6480\\tx7200\\tx7920\\tx8640\\pardirnatural\\partightenfactor0\r\n"
"\\cf0 6) Where to place AppIcons so they aren't removed by Projucer ?\\\r\n"
"7) Fix Width of AppIcon \"Finder\" is too close to the edges\\\r\n"
"8) Add division lines between buttons and counters and title and counters\\\r\n"
"9) Spacing issues\\\r\n"
"10) Turn off highlighting of toggle buttons when pressed\\\r\n"
"\\\r\n"
"Refactor\\\r\n"
"-Pull calculation into my class or simply just pull them into their own functions in the tapWindow.cpp misc function area and remove \"misc functions\"}";

const char* BPM_Finder_Notes_rtf = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xae17858d:  numBytes = 1147; return BPM_Finder_Notes_rtf;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "BPM_Finder_Notes_rtf"
};

}
