/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Created by kraken, 10/06/18
*/

#ifndef INDIESTUDIO_SOUNDMANAGER_HPP
#define INDIESTUDIO_SOUNDMANAGER_HPP

#include "TimeManager.hpp"
#include <string>
#include <irrKlang.h>
#include <map>

namespace Singleton
{
	class SoundManager
	{
	public:
		static SoundManager& Instance();
		void playSound(std::string const& file);
		void playLoop(std::string const& file);
		void stopLoop(std::string const& file);
		void setVolume(irrklang::ik_f32 value);
		irrklang::ik_f32 getVolume() const;
	private:
		SoundManager& operator= (const SoundManager&){return *this;};
		SoundManager (const SoundManager&) = default;
		static SoundManager _instance;
		irrklang::ISoundEngine* _engine;
		SoundManager();
		~SoundManager();
		std::map<std::string, irrklang::ISound*> _loops{};
	};
}

#endif //INDIESTUDIO_SOUNDMANAGER_HPP
