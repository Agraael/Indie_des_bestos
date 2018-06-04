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
		SETTINGS,
		BRIGTHNESS_DOWN,
		BRIGTHNESS_UP,
		SOUND_DOWN,
		SOUND_UP,
		ENTER_NAME1,
		ENTER_NAME2,
		EXIT_MAINMENU,
		START_SOLO,
		START_LOCAL,
		PLAYER_DOWN,
		PLAYER_UP,
		IA_DOWN,
		IA_UP,
		NORMAL_MAP,
		DEMOLITON_MAP,
		START_LOCAL_GAME,
		EXIT_SETTINGS,
		EXIT_LOCAL,
		ARROW_DOWN,
		ARROW_UP,
		ARROW_LEFT,
		ARROW_RIGHT,
		SPACEBAR,
		KEY_Z,
		KEY_Q,
		KEY_S,
		KEY_D,
		ENTER,
		ECHAP,
		RESTART,
		CONTINUE,
		MENU,
		QUIT,
		GUI_ID_NO_BUTTON
	};

	class LibEventManager
		: public irr::IEventReceiver
	{
	public:
		explicit LibEventManager(t_contextRecEvnt const& context);
		~LibEventManager() override = default;
		bool OnEvent(const irr::SEvent& event) override;
		virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
		bool IsButtonClicked(graphic::controllerUser) const;
	private:
		bool KeyIsDown[irr::KEY_KEY_CODES_COUNT]{};
		mutable irr::s32 _pressedButton{GUI_ID_NO_BUTTON};
		t_contextRecEvnt _context;
    };
}

#endif //LIBEVENTMANAGER_HPP
