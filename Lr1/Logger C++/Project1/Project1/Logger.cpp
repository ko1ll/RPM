/**
 * @file Logger.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "Logger.h"
#include <fstream>
	/**
	* ������� ����
	* @param what ����� �������
	* @param lvl ������� �������
	*/
void LoggableConsole::log(const std::string & what,const lvls & lvl)
{
	if (lvl <= lvlmax && lvl >= lvlmin) {
		std::string str = type_->write(what, lvl);
		cout << str;
	}
}
	/**
	* ������� ����
	* @param what ����� �������
	* @param lvl ������� �������
	*/
void LoggableFile::log(const std::string & what, const lvls & lvl)
{
	if (lvl <= lvlmax && lvl >= lvlmin) {
		std::string str = type_->write(what,lvl);
		ofstream file(this->fileName,ios::app);
		if (file.is_open()) {
			file << str;
		}
		else cout << "error 1 " << endl;
	}
}
	/**
	* ������� ����� �����
	* @param name ���� � �����
	*/
void LoggableFile::setFileName(const std::string & name)
{
	fileName = name;
}
	/**
	* ������� ����� ���� ������
	* @param type ��� ������
	*/
void Loggable::ChangeType(LoggerWriteType* type)
{
	type_ = type;
}
