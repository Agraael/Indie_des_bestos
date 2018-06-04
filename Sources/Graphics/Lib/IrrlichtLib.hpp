//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#ifndef IRRLICHTLIB_HPP
#define IRRLICHTLIB_HPP

#include <iostream>
#include <map>
#include <irrlicht/irrlicht.h>
//#include <EventManager.hpp>
#include <string>
#include <irrlicht/irrlicht.h>
#include <memory>
#include "LibEventManager.hpp"

struct vec3df {
	double	x;
	double	y;
	double	z;
};

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

namespace graphic {
	typedef struct infos_s
	{
		size_t _x;
		size_t _y;
		size_t _w;
		size_t _h;
		size_t _maxW;
		size_t _maxH;
		std::string _path;
		std::string _name;
		std::string _desc;
		graphic::controllerUser _type;
	} infos_t;
	const wchar_t *convertStringToWString(const std::string &);
	class IrrlichtLib {
	public:
		IrrlichtLib();
		~IrrlichtLib();
		irr::video::ITexture *findTextureOrCreate(const std::string &path);
		irr::gui::IGUIImage *drawImage(const infos_t &infos);
		irr::IrrlichtDevice *getDevice() { return _device; }
		void displayAll();
		irr::scene::ISceneNode *createCube(const vec3df &, const std::string &);
		irr::scene::ISceneNode *createSphere();
		void setCamera(irr::scene::ISceneNode *parent);
		void setCamera(const vec3df &pos, const vec3df &target);
		void drawEditBox(graphic::infos_t infos);
		irr::gui::IGUIButton *printButton(const infos_t &infos);
		void drawText(size_t x, size_t y, size_t fontSize, std::string const&);
        irr::gui::IGUIScrollBar *scrollBarButton(const infos_t &infos);
		std::shared_ptr<LibEventManager> const& getEventManager() const;
	private:
		irr::video::IVideoDriver* _driver;
		irr::scene::ISceneManager* _managerScene;
		irr::IrrlichtDevice *_device;
		irr::gui::IGUIEnvironment* _guiEnv;
		std::map<std::string, irr::video::ITexture *> _mapTexture;
		std::shared_ptr<graphic::LibEventManager> _eventManager{nullptr};
	};
	void driverChoiceConsole(irr::video::E_DRIVER_TYPE &);
}
#endif //IRRLICHTLIB_HPP
