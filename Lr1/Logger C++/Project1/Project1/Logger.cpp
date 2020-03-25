/**
 * @file Logger.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "Logger.h"
#include <fstream>
	/**
	* Функция лога
	* @param what текст логгера
	* @param lvl уровень логгера
	*/
void LoggableConsole::log(const std::string & what,const lvls & lvl)
{
	if (lvl <= lvlmax && lvl >= lvlmin) {
		std::string str = type_->write(what, lvl);
		cout << str;
	}
}
	/**
	* Функция лога
	* @param what текст логгера
	* @param lvl уровень логгера
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
	* Функция смены файла
	* @param name путь к файлу
	*/
void LoggableFile::setFileName(const std::string & name)
{
	fileName = name;
}
	/**
	* Функция смены типа записи
	* @param type тип записи
	*/
void Loggable::ChangeType(LoggerWriteType* type)
{
	type_ = type;
}
