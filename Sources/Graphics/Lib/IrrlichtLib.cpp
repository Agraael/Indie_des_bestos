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
}

graphic::IrrlichtLib::~IrrlichtLib()
{
	_device->drop();
}

void    graphic::IrrlichtLib::displayAll()
{
	_driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
	_managerScene->drawAll();
	_guiEnv->drawAll();
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

irr::gui::IGUIImage *graphic::IrrlichtLib::drawImage(int posx, int posy, int w, int h, const std::string &path)
{
	auto texture = findTextureOrCreate(path);
	_driver->enableMaterial2D();
	irr::gui::IGUIImage *img = _guiEnv->addImage(texture, irr::core::position2d<int>(posx,posy));
	img->setScaleImage(true);
	img->setMinSize(irr::core::dimension2du(w, h));
	img->setMaxSize(irr::core::dimension2du(w + 100, h + 100));
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
	const wchar_t* wideCStr = graphic::convertStringToWString(text);
	_guiEnv->addStaticText(wideCStr, irr::core::rect<irr::s32>(x,y, 100,22), true);
	(void)(fontSize);
}
