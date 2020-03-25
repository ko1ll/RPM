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
	* ������� �������� �������
	* @param min ����������� �������
	* @param max ������������ �������
	*/
	virtual Loggable* create(const lvls& min, const lvls& max) = 0;
};
class FactoryFile : public Factory {
public:
	/**
	* ������� �������� �������
	* @param min ����������� �������
	* @param max ������������ �������
	*/
	LoggableFile* create(const lvls& min, const lvls& max);
};

class FactoryConsole : public Factory {
public:
	/**
	* ������� �������� �������
	* @param min ����������� �������
	* @param max ������������ �������
	*/
	LoggableConsole* create(const lvls& min, const lvls& max);
};