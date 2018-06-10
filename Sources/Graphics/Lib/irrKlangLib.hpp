//
// Created by Ludovica Pagliarani on 10/06/2018.
//

#ifndef PROJECT_IRRKLANGLIB_HPP
#define PROJECT_IRRKLANGLIB_HPP

#include <iostream>
#include <string>
#include "IrrKlang.h"

namespace graphic
{
    class irrKlangLib
    {
    public:
        irrKlangLib();
        ~irrKlangLib() = default;
        void playSound(const std::string &sound);
        void setVolume(float vol) { _volume = vol; };
        float getVolume() { return _volume; };
        void dropSound() { _engine->drop(); }
    private:
        irrklang::ISoundEngine* _engine;
        float _volume;
    };
}

#endif //PROJECT_IRRKLANGLIB_HPP
