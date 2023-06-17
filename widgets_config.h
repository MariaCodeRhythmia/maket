#ifndef WIDGETS_CONFIG_H
#define WIDGETS_CONFIG_H
#include "widgets.h"
#include <iostream>
#include <unordered_map>


using namespace std;

#define widgetMapCombobox std::vector<std::pair<int, string>>

//widgetMapBtn  number  widgetText, tool, objectName
typedef unordered_map<int, tuple< string, string, string>> widgetMapBtn;

//widgetMapIO  number  widgetText, tool, objectName,decimal, manimum, maximum
typedef unordered_map<int, tuple< string, string, string, int, int, int>> widgetMapIO;


widgetMapCombobox Code = {
    { 0," Name combobox"},//name combobox
    { 1," N1"},
    { 2," N2"},
    { 3," N3"},
    { 4," N4"},
    { 5," N5"}
};

widgetMapCombobox combo1_w2 = {
    {-1," Name combobox"},//name combobox
    { 0, "00 - item"},//items
    { 1," 01 - item"},//items
    { 2," 10 - item"},//items
    { 3," 11 - item"},//items
};
widgetMapCombobox combo2_w2 = {
    {-1," Name combobox"},//name combobox
    { 0," 00 - item"},//items
    { 1," 01 - item"},//items
    { 2," 10 - item"},//items
    { 3," 11 - item"},//items
    { 4," 100 - item"},//items

};
widgetMapCombobox combo3_w2 = {
    {-1, " Name combobox"},//name combobox
    { 7,  " 7 - item"},//items
    { 11, " B - item"},//items
    { 243," F3 - item"},//items
    { 1,  " 1 - item"},//items
    { 4,  " 4 - item"},//items
    { 34, " 22 - item"},//items

};
widgetMapCombobox combo4_w2 = {
    {-1," Name combobox"},//name combobox
    { 0," 00 - item"},//items
    { 1," 01 - item"},//items
    { 2," 10 - item"},//items
    { 3," 11 - item"},//items
    { 4," 100 - item"},//items
    { 5," 101 - item"},//items
    { 6," 110 - item"},//items
};
widgetMapCombobox combo5_w2 = {
    {-1," Name combobox"},//name combobox
    { 0," 00 - item"},//items
    { 1," 01 - item"},//items
    { 2," 10 - item"},//items
    { 3," 11 - item"},//items
    { 4," 100 - item"},//items
    { 5," 101 - item"},//items
    { 6," 110 - item"},//items
    { 7," 111 - item"},//items
};
widgetMapCombobox combo6_w2 = {
    {-1," Name combobox"},//name combobox
    { 0,"  0000 - 0"},//items
    { 1,"  0001 - 1"},//items
    { 2,"  0010 - 2"},//items
    { 3,"  0011 - 3"},//items
    { 4,"  0100 - 4"},//items
    { 5,"  0101 - 5"},//items
    { 6,"  0110 - 6"},//items
    { 7,"  0111 - 7"},//items
    { 8,"  1000 - 8"},//items
    { 9,"  1001 - 9"},//items
    { 10," 1010 - A"},//items
    { 11," 1011 - B"},//items
    { 12," 1100 - C"},//items
    { 13," 1101 - D"},//items
    { 14," 1110 - E"},//items
    { 15," 1111 - F"},//items

};
widgetMapCombobox combo5_w3 = {
    {-1," Name combobox"},//name combobox
    { 0," 00 - item"},//items
    { 1," 01 - item"},//items
    { 2," 10 - item"},//items
    { 3," 11 - item"},//items
    { 4," 100 - item"},//items
    { 5," 101 - item"},//items
    { 6," 110 - item"},//items
    { 7," 111 - item"},//items
};
widgetMapCombobox combo6_w3 = {
    {-1," Name combobox"},//name combobox
    { 0," 0000 - 0"},//items
    { 1," 0001 - 1"},//items
    { 2," 0010 - 2"},//items
    { 3," 0011 - 3"},//items
    { 4," 0100 - 4"},//items
    { 5," 0101 - 5"},//items
    { 6," 0110 - 6"},//items
    { 7," 0111 - 7"},//items
    { 8," 1000 - 8"},//items
    { 9," 1001 - 9"},//items
    { 10," 1010 - A"},//items
    { 11," 1011 - B"},//items
    { 12," 1100 - C"},//items
    { 13," 1101 - D"},//items
    { 14," 1110 - E"},//items
    { 15," 1111 - F"},//items

};
widgetMapBtn head_btn_name  = {
    {0, {"",        "green",    "green"}},
    {1, {"",        "blue",     "blue"}},
    {3, {"",        "dark",     "dark"}},
    {4, {"",        "light",    "light"}},
    {2, {" ",       "yellow",   "yellow"}},
    {5, {"Выход",   "close" ,   "close"}},
};
widgetMapBtn wgt_btn_w1  = {
    {0, {"Set data",      "", "updateOutput"}},
};
widgetMapBtn wgt_btn_w2  = {
    {0, {" Set data",     "", "updateOutput"}},
    {1, {" Save data ",   "", "fileMaster"}},
};
widgetMapBtn wgt_btn_w3  = {
    {0, {" Set data",        "", "updateOutput"}},
    {1, {" Save data",       "", "fileMaster"}},
    {2, {"example button",   "", "btn1"}},
    {3, {"example button",   "", "btn2"}},
    {4, {"example button",   "", "btn3"}},
    {5, {"example button",   "", "btn4"}},
};
widgetMapBtn wgt_btn_w4  = {
    {0, {" System time",      "", "getSystemTime"}},
    {1, {" Start",            "", "allowRS"}},
    {2, {" Set data",         "", "updateOutput"}},
    {4, {" example button",   "", ""}},
    {3, {" Save data",        "", "FileMaster"}},

};
widgetMapBtn wgt_btn_w5  = {
    {0, {" Set data", "", "updateOutput"}},
};

widgetMapIO wgt_io_w1  = {
    //  { key  {name, tool, decimal, manimum, maximum}}
    {0, {"  Name", "more detailed info", "objName1",        0, -2000, 50000}},
    {3, {"  Name", "more detailed info", "objName4",        4, -2000, 50000}},
    {1, {"  Name", "more detailed info", "objName2",        2, -2000, 50000}},
    {2, {"  Name", "more detailed info", "objName3",        1, -2000, 50000}},
    {4, {"  Name", "more detailed info", "objName5",        3, -2000, 50000}},
    {5, {"  Name", "more detailed info", "objName6",        2, -2000, 50000}},

};
widgetMapIO wgt_io_w2  = {
    //  { key  {name, tool, decimal, manimum, maximum}}
    {0, {"  Name", "more detailed info", "objName1",        0, -2000, 50000}},
    {3, {"  Name", "more detailed info", "objName4",        4, -200,  50000}},
    {1, {"  Name", "more detailed info", "objName2",        2, -10,   10}},
    {2, {"  Name", "more detailed info", "objName3",        1, -10,   100}},
    {4, {"  Name", "more detailed info", "objName5",        3, -2000, 30}},
    {5, {"  Name", "more detailed info", "objName6",        2, -1000, 5000}},
    {6, {"  Name", "more detailed info", "objName7",        2, -300,  1000}},
    {8, {"  Name", "more detailed info", "objName9",        0, -100,  50000}},
    {9, {"  Name", "more detailed info", "objName10",       0, -900,  50000}},
    {7, {"  Name", "more detailed info", "objName8",        1, -100,  10}},


};
widgetMapIO wgt_io_w3  = {
    //  { key  {name, tool, decimal, manimum, maximum}}
    {0, {"  Name", "more detailed info", "objName1",        0, -2000, 50000}},
    {3, {"  Name", "more detailed info", "objName4",        4, -200,  50000}},
    {1, {"  Name", "more detailed info", "objName2",        2, -10,   10}},
    {2, {"  Name", "more detailed info", "objName3",        1, -10,   100}},
    {4, {"  Name", "more detailed info", "objName5",        3, -2000, 30}},
    {5, {"  Name", "more detailed info", "objName6",        2, -1000, 5000}},
    {6, {"  Name", "more detailed info", "objName7",        2, -300,  1000}},

};
widgetMapIO wgt_io_w4  = {
    //  { key  {  Name, tool, decimal, manimum, maximum}}
    {0, {" Hour",                " more detailed info ",             "",    0,  0, 24}},
    {1, {" Minute",              " more detailed info ",             "",    0,  0, 59}},
    {2, {" Second",              " more detailed info ",             "",    0,  0, 59}},
    {3, {" Msecond",             " more detailed info ",             "",    0,  0, 1000}},
    {4, {" Day",                 " more detailed info ",             "",    0,  0, 7}},
    {5, {" Month",               " more detailed info ",             "",    0,  0, 12}},
    {6, {" Year",                " more detailed info ",             "",    0,  0, 3000}},
    {7, {" Correction_hour",     " more detailed info ",             "",    0,-13, 13}},
    {8, {" Correction_minute",   " more detailed info ",             "",    0,  0, 59}},
};
widgetMapIO wgt_io_w5  = {
    //  { key  {name, tool, decimal, manimum, maximum}}
    {0, {"name", "tool", "objName1",        0, -2000, 50000}},
    {3, {"name", "tool", "objName4",        4, -200,  50000}},
    {1, {"name", "tool", "objName2",        2, -10,   10}},
    {2, {"name", "tool", "objName3",        1, -10,   100}},
    {4, {"name", "tool", "objName5",        3, -2000, 30}},
    {5, {"name", "tool", "objName6",        2, -1000, 5000}},
    {6, {"name", "tool", "objName7",        2, -300,  1000}},

};

#endif // ALL_NAME_WИDGET_H
