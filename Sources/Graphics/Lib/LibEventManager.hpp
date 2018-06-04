//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#ifndef LIBEVENTMANAGER_HPP
#define LIBEVENTMANAGER_HPP

#include <irrlicht/irrlicht.h>

namespace graphic
{
    typedef struct s_contextRecEvnt
    {
        irr::IrrlichtDevice *device;
        irr::s32             counter;
        irr::gui::IGUIListBox*    listbox;
    }             t_contextRecEvnt;
    enum controllerUser
    {
        GUI_ID_QUIT_BUTTON = 101,
        GUI_ID_NEW_WINDOW_BUTTON,
        GUI_ID_FILE_OPEN_BUTTON,
        GUI_ID_TRANSPARENCY_SCROLL_BAR
    };
    class LibEventManager : public irr::IEventReceiver
    {
    public:
        LibEventManager(t_contextRecEvnt const& context);
        ~LibEventManager() = default;
        virtual bool OnEvent(const irr::SEvent& event);
        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
        bool eventGetter();
    private:
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
        t_contextRecEvnt _context;
    };
}

#endif //LIBEVENTMANAGER_HPP
