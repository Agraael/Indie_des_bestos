/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Created by kraken, 08/06/18
*/

#ifndef INDIESTUDIO_TIMEMANAGER_HPP
#define INDIESTUDIO_TIMEMANAGER_HPP

#include <unordered_map>
#include <chrono>
#include <thread>

namespace Singleton
{
	using ChronoId = unsigned int;

	class TimeManager
	{
	public:
		static TimeManager& Instance();

		void delay(unsigned int) const;
		void fpsDelay(unsigned int) const;
		ChronoId createChrono();
		double getChronoDuration(ChronoId);
		bool resetChrono(ChronoId id);
	private:
		TimeManager& operator= (const TimeManager&){return *this;};
		TimeManager (const TimeManager&) = default;
		static TimeManager _instance;
		static unsigned int _chronoNb;
		std::unordered_map<ChronoId, std::chrono::steady_clock::time_point> _chronoMap{};
		TimeManager() = default;
		~TimeManager() = default;
	};
}

#endif //INDIESTUDIO_TIMEMANAGER_HPP
