/**
 * @file Single.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "Single.h"
#include <algorithm>
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::notice(const std::string& what)
{
	this->update(what, lvls::notice);
}
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::info(const std::string& what)
{
	this->update(what, lvls::info);
}
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::warning(const std::string& what)
{
	this->update(what, lvls::warning);
}
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::error(const std::string& what)
{
	this->update(what, lvls::error);
}
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::critical(const std::string& what)
{
	this->update(what, lvls::critical);
}
	/**
	* ������� ������ � �������
	* @param what ����� �������
	*/
void Single::fatal(const std::string& what)
{
	this->update(what, lvls::fatal);
}
	/**
	* ������� ���������� ���������
	*/
Single* Single::getinstance()
{
	static Single* logger = new Single();
	return logger;
}
	/**
	* ������� ���������� �������
	* @param logger ������
	*/
void Single::addLogger(Loggable * logger)
{
	loggables.push_back(logger);
}
	/**
	* ������� ���������� ���� ��������
	* @param what ����� �������
	* @param lvl ������� ������
	*/
void Single::update(const std::string& what,const lvls& lvl) {
	for_each(loggables.begin(), loggables.end(), [what,lvl](Loggable* log) {
		log->log(what,lvl);
		});
};