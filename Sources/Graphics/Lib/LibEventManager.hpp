//
// Created by Ludovica Pagliarani on 09/05/2018.
//

#ifndef LIBEVENTMANAGER_HPP
#define LIBEVENTMANAGER_HPP

#ifdef _WIN32
#include <irrlicht.h>
#else
#include <irrlicht/irrlicht.h>
#endif

namespace graphic
{
	typedef struct s_contextRecEvnt
	{
		irr::IrrlichtDevice	*device;
		irr::s32		counter;
		irr::gui::IGUIListBox*	listbox;
	}             t_contextRecEvnt;
	enum controllerUser
	{
		SETTINGS,
		BRIGTHNESS_DOWN,
		BRIGTHNESS_UP,
		SOUND_DOWN,
		SOUND_UP,
		MORE_PLAYER,
		LESS_PLAYER,
		MORE_IA,
		LESS_IA,
		DIST_MAP,
		STAND_MAP,
		SMALL_MAP,
		MEDIUM_MAP,
		LARGE_MAP,
		ENTER_NAME1,
		ENTER_NAME2,
		EXIT_MAINMENU,
		START_SOLO,
		START_LOCAL,
		PLAYER_DOWN,
		PREV_FILE,
		NEXT_FILE,
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
		ENTER,
		KEY_Z,
		KEY_Q,
		KEY_S,
		KEY_D,
		SPACEBAR,
		ECHAP,
		SAVE,
		CONTINUE,
		MENU,
		QUIT,
		RESUME_GAME,
		MAP_NEXT,
		MAP_PREV,
		MAP_SIZE_UP,
		MAP_SIZE_DOWN,
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
