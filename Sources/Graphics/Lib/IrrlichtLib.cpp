//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include "LibEventManager.hpp"
#include "IrrlichtLib.hpp"

const wchar_t *graphic::convertStringToWString(const std::string &text)
{
	std::wstring wideStr = std::wstring(text.begin(), text.end());
	const wchar_t *stringConverted = wideStr.c_str();
	return (stringConverted);
}

graphic::IrrlichtLib::IrrlichtLib() {
    _device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
    if (!_device)
        std::cout << "error device" << std::endl;
    _device->setWindowCaption(L"INDIE DES BESTOS");
    _driver = _device->getVideoDriver();
    _managerScene = _device->getSceneManager();
    _guiEnv = _device->getGUIEnvironment();
    _eventManager = std::make_shared<graphic::LibEventManager>(t_contextRecEvnt{_device, 0, nullptr});
	_device->setEventReceiver(_eventManager.get());
}

graphic::IrrlichtLib::~IrrlichtLib()
{
	_device->drop();
}

void    graphic::IrrlichtLib::displayAll(bool td)
{
	_driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
	if (td == true)
		_guiEnv->drawAll();
	else
		_managerScene->drawAll();
	_driver->endScene();
}

irr::video::ITexture *graphic::IrrlichtLib::findTextureOrCreate(const std::string &path)
{
	auto it = _mapTexture.find(path);
	if (it == _mapTexture.end()) {
		auto texture = _driver->getTexture(path.c_str());
		_mapTexture[path] = texture;
		return texture;
	}
	return it->second;

}

irr::gui::IGUIImage *graphic::IrrlichtLib::drawImage(const infos_t &infos)
{
    auto texture = findTextureOrCreate(infos._path);
    _driver->enableMaterial2D();
    irr::gui::IGUIImage *img = _guiEnv->addImage(texture, irr::core::position2d<int>(infos._x, infos._y));
    img->setScaleImage(true);
    img->setMinSize(irr::core::dimension2du(infos._w, infos._h));
    img->setMaxSize(irr::core::dimension2du(infos._maxW, infos._maxH));
    return (img);
}

irr::gui::IGUIButton *graphic::IrrlichtLib::printButton(const infos_t &infos)
{
	std::wstring wideStr = std::wstring(infos._name.begin(), infos._name.end());
	const wchar_t *nameToPrint = wideStr.c_str();
	std::wstring wideStrDesc = std::wstring(infos._desc.begin(), infos._desc.end());
	const wchar_t *descriptionToPrint = wideStrDesc.c_str();
	irr::gui::IGUIButton *butCustom = _guiEnv->addButton(irr::core::rect<irr::s32>(infos._x, infos._y, infos._w, infos._h), 0, infos._type, nameToPrint, descriptionToPrint);
	butCustom->setImage(_driver->getTexture(infos._path.c_str()));
	butCustom->setUseAlphaChannel(true);
	return (butCustom);

}

irr::gui::IGUIScrollBar *graphic::IrrlichtLib::scrollBarButton(const infos_t &infos)
{
   drawText(200, 200, 30, "Brightness Control");
    irr::gui::IGUIScrollBar* scrollbar = _guiEnv->addScrollBar(true,
                                                           irr::core::rect<irr::s32>(150, 55, 350, 60), 0, infos._type);
    scrollbar->setMax(255);
    // met la position de la barre de défilement à la valeur alpha d'un élément choisi arbitrairement
    scrollbar->setPos(_guiEnv->getSkin()->getColor(irr::gui::EGDC_WINDOW).getAlpha());
    return (scrollbar);
}

void graphic::IrrlichtLib::setCamera(irr::scene::ISceneNode * child)
{
	irr::scene::ICameraSceneNode *cam= _managerScene->addCameraSceneNode();
	cam->setPosition(irr::core::vector3df(10, -10,-10));
	cam->setParent(child);
}

void graphic::IrrlichtLib::setCamera(const vec3df &pos, const vec3df &target)
{
	irr::scene::ICameraSceneNode *cam= _managerScene->addCameraSceneNode();
	cam->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
	cam->setTarget(irr::core::vector3df(target.x, target.y, target.z));
}

//"./media/red_brick.jpg"
irr::scene::ISceneNode    *graphic::IrrlichtLib::createCube(const vec3df &pos, const std::string &path)
{
	irr::scene::ISceneNode *n = _managerScene->addCubeSceneNode(1);

	if (n) {
		n->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
		n->setMaterialTexture(0, _driver->getTexture(path.c_str()));
		n->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}
	return (n);
}

void  graphic::IrrlichtLib::drawEditBox(graphic::infos_t infos)
{
	std::wstring wideStr = std::wstring(infos._name.begin(), infos._name.end());
	const wchar_t *nameToPrint = wideStr.c_str();
	_guiEnv->addEditBox(nameToPrint, irr::core::rect<irr::s32>(infos._x, infos._y, infos._w, infos._h));
}

irr::scene::ISceneNode  *graphic::IrrlichtLib::createSphere()
{
	irr::scene::ISceneNode * node = _managerScene->addSphereSceneNode();
	if (node)
	{
		node->setPosition(irr::core::vector3df(-10,-10,30));
		node->setMaterialTexture(0, _driver->getTexture("./media/red_brick.jpg"));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}
	return (node);
}

void    graphic::IrrlichtLib::drawText(size_t x, size_t y, size_t fontSize, const std::string &text)
{
    std::wstring wideStr = std::wstring(text.begin(), text.end());
    const wchar_t *wideCStr = wideStr.c_str();
    _guiEnv->addStaticText(wideCStr, irr::core::rect<irr::s32>(x,y, x + 100, y + 100), true);
    (void)(fontSize);
}

std::shared_ptr<graphic::LibEventManager> const& graphic::IrrlichtLib::getEventManager() const
{
		return _eventManager;
}
