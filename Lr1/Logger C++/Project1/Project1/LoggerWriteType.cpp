/**
 * @file LoggerWriteType.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "LoggerWriteType.h"
#include <iostream>
#include <ctime>
	/**
	* Функция записи одной строкой
	* @param what текст логгера
	* @param lvl уровень логгера
	*/
std::string WriteOneLine::write(const std::string& what, const lvls& lvl) {
	time_t now = time(0);
	return 
		std::string(
			"lvl: " + to_string(static_cast<int>(lvl)) + " "
			+ what + " "
			+ string(ctime(&now))
		);
}
	/**
	* Функция записи несколькими строками
	* @param what текст логгера
	* @param lvl уровень логгера
	*/
std::string WriteManyLines::write(const std::string& what,const lvls& lvl) {
	time_t now = time(0);
	return
		std::string(
			"lvl: " + to_string(static_cast<int>(lvl)) + "\n"
			+ what + "\n"
			+ string(ctime(&now))
		);
}