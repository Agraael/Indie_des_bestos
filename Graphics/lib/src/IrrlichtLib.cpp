//
// Created by Ludovica Pagliarani on 07/05/2018.
//

#include "LibEventManager.hpp"
#include "IrrlichtLib.hpp"

const wchar_t *graphic::convertStringToWString(const std::string &text)
{
    std::wstring wideStr = std::wstring(text.begin(), text.end());
    return (wideStr.c_str());
}
//deviceType: Type of the device, windowSize,
//bits: Amount of color bits per pixel. This should be 16 or 32, fullscreen,
// stencil buffer: Specifies if we want to use the stencil buffer (for drawing shadows).
//vsync: Specifies if we want to have vsync enabled, this is only useful in fullscreen mode.
//eventReceiver: An object to receive events. We do not want to use this parameter here, and set it to 0.

graphic::IrrlichtLib::IrrlichtLib() {
    irr::video::E_DRIVER_TYPE driverType;
    graphic::driverChoiceConsole(driverType);
    _device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
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
    irr::gui::IGUIImage *img = _guiEnv->addImage(texture, irr::core::position2d<int>(posx,posy));
    img->setScaleImage(true);
    img->setMinSize(irr::core::dimension2du(w, h));
    img->setMaxSize(irr::core::dimension2du(w + 100, h + 100));
    return (img);
}

irr::gui::IGUIButton *graphic::IrrlichtLib::printButton(const infos_t &infos)
{
    const wchar_t *nameToPrint = graphic::convertStringToWString(infos._name);
    const wchar_t *descriptionToPrint = graphic::convertStringToWString(infos._desc);
    irr::gui::IGUIButton *butCustom = _guiEnv->addButton(irr::core::rect<irr::s32>(infos._x, infos._y, infos._w, infos._h), 0, infos._type, nameToPrint, descriptionToPrint);
    butCustom->setImage(_driver->getTexture(infos._path.c_str()));
    butCustom->setUseAlphaChannel(true);
    return (butCustom);

}

void    graphic::IrrlichtLib::drawText(size_t x, size_t y, size_t fontSize, const std::string &text)
{
    const wchar_t* wideCStr = graphic::convertStringToWString(text);
    _guiEnv->addStaticText(wideCStr, irr::core::rect<irr::s32>(x,y, 100,22), true);
}

void    graphic::driverChoiceConsole(irr::video::E_DRIVER_TYPE &driverType)
{
    printf("Please select the driver you want for this project:\n"\
        " (a) OpenGL 1.5\n (b) Direct3D 9.0c\n (c) Direct3D 8.1\n"\
        " (d) Burning's Software Renderer\n (e) Software Renderer\n"\
        " (f) NullDevice\n (otherKey) exit\n\n");

    char i;
    std::cin >> i;

    switch(i)
    {
        case 'a': driverType = irr::video::EDT_OPENGL;   break;
        case 'b': driverType = irr::video::EDT_DIRECT3D9;break;
        case 'c': driverType = irr::video::EDT_DIRECT3D8; break;
        case 'd': driverType = irr::video::EDT_BURNINGSVIDEO;break;
        case 'e': driverType = irr::video::EDT_SOFTWARE; break;
        case 'f': driverType = irr::video::EDT_NULL;     break;
        default: break;
    }
}
