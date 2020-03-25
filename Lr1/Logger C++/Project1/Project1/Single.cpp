/**
 * @file Single.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "Single.h"
#include <algorithm>
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::notice(const std::string& what)
{
	this->update(what, lvls::notice);
}
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::info(const std::string& what)
{
	this->update(what, lvls::info);
}
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::warning(const std::string& what)
{
	this->update(what, lvls::warning);
}
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::error(const std::string& what)
{
	this->update(what, lvls::error);
}
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::critical(const std::string& what)
{
	this->update(what, lvls::critical);
}
	/**
	* Функция записи в логгеры
	* @param what текст логгера
	*/
void Single::fatal(const std::string& what)
{
	this->update(what, lvls::fatal);
}
	/**
	* Функция возвращает экземпляр
	*/
Single* Single::getinstance()
{
	static Single* logger = new Single();
	return logger;
}
	/**
	* Функция добавления логгера
	* @param logger логеер
	*/
void Single::addLogger(Loggable * logger)
{
	loggables.push_back(logger);
}
	/**
	* Функция обновления всех логгеров
	* @param what текст логгера
	* @param lvl уровень записи
	*/
void Single::update(const std::string& what,const lvls& lvl) {
	for_each(loggables.begin(), loggables.end(), [what,lvl](Loggable* log) {
		log->log(what,lvl);
		});
};