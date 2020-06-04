#ifndef MenuItem_H
#define MenuItem_H

typedef void (*fptr)();
//
// menu item types
//
const byte MENU_ITEM_MAIN_MENU_HEADER = 0;
const byte MENU_ITEM_SUB_MENU_HEADER = 1;
const byte MENU_ITEM_SUB_MENU = 2;
const byte MENU_ITEM_COMMAND = 3;
const byte MENU_ITEM_INPUT = 4;
const byte MENU_ITEM_NONE = 5;
const byte MENU_ITEM_TOGGLE = 6;
const byte MENU_ITEM_END_OF_MENU = 7;
//
// the MenuItem class
//
class MenuItem {
   private:
    char* text = "";
    fptr callback = NULL;
    std::vector<MenuItem> subMenu;
    byte type = MENU_ITEM_NONE;

   public:
    //
    // constructors
    //
    MenuItem(byte type)
        : type(type) {}
    MenuItem(char* text)
        : text(text) {}
    MenuItem(char* text, fptr callback, byte type)
        : text(text), callback(callback), type(type) {}
    MenuItem(char* text, fptr callback, std::vector<MenuItem> subMenu,byte type)
        : text(text), callback(callback), subMenu(subMenu), type(type) {}
    MenuItem(std::vector<MenuItem> subMenu, byte type)
        : subMenu(subMenu), type(type) {}
    MenuItem(char* text, std::vector<MenuItem> subMenu, byte type)
        : text(text), subMenu(subMenu), type(type) {}
    MenuItem(char* text, char* value, fptr callbac, byte type)
        : text(text), value(value), callback(callback), type(type) {}
    //
    // getters
    //
    char* getText() { return text; }
    fptr getCallback() { return callback; }
    std::vector<MenuItem> getSubMenu() { return subMenu; }
    byte getType() { return type; }
    //
    // setters
    //
    void setText(char* text) { this->text = text; }
    void setCallBack(fptr callback) { this->callback = callback; }
    void setSubMenu(std::vector<MenuItem> subMenu) { this->subMenu = subMenu; }
    //
    //
    //
    boolean isOn = false;
    char* textOn = "ON";
    char* textOff = "OFF";
    String value = "";
};

class ItemHeader : public MenuItem {
   public:
    ItemHeader(std::vector<MenuItem> parent)
        : MenuItem(parent, MENU_ITEM_MAIN_MENU_HEADER) {}
};

class ItemSubHeader : public MenuItem {
   public:
    ItemSubHeader(std::vector<MenuItem> parent)
        : MenuItem(parent, MENU_ITEM_SUB_MENU_HEADER) {}
};

class ItemFooter : public MenuItem {
   public:
    ItemFooter() : MenuItem(MENU_ITEM_END_OF_MENU) {}
};

class ItemInput : public MenuItem {
   public:
    ItemInput(char* text, char* value, fptr callback)
        : MenuItem(text, value, callback, MENU_ITEM_INPUT) {}
};

class ItemSubMenu : public MenuItem {
   public:
    ItemSubMenu(char* text, std::vector<MenuItem> parent)
        : MenuItem(text, parent, MENU_ITEM_SUB_MENU) {}
};

class ItemToggle : public MenuItem {
   public:
    ItemToggle(char* key, fptr callback)
        : MenuItem(key, callback, MENU_ITEM_TOGGLE) {}
    ItemToggle(char* key, char* textOn, char* textOff, fptr callback)
        : MenuItem(key, callback, MENU_ITEM_TOGGLE) {}
};

#endif