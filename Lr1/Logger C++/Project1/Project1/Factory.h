/**
 * @file Factory.h
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#pragma once
#include "Logger.h"
class Factory
{
public:
	/**
	* Функция создания логгера
	* @param min минимальный уровень
	* @param max максимальный уровень
	*/
	virtual Loggable* create(const lvls& min, const lvls& max) = 0;
};
class FactoryFile : public Factory {
public:
	/**
	* Функция создания логгера
	* @param min минимальный уровень
	* @param max максимальный уровень
	*/
	LoggableFile* create(const lvls& min, const lvls& max);
};

class FactoryConsole : public Factory {
public:
	/**
	* Функция создания логгера
	* @param min минимальный уровень
	* @param max максимальный уровень
	*/
	LoggableConsole* create(const lvls& min, const lvls& max);
};