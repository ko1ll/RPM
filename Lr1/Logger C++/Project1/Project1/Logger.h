/**
 * @file Logger.h
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Logger.h"
#include "LoggerWriteType.h"
#include "Enum.h"
using namespace std;




class Loggable {

public:
	/**
	* Конструктор логгера
	*/
	Loggable(const lvls& min, const lvls& max,LoggerWriteType* type) :
		lvlmin(min), lvlmax(max), type_(type){};
	virtual void log(const std::string&, const lvls&) = 0;
	void ChangeType(LoggerWriteType* type);
protected:
	lvls lvlmin,lvlmax;
	LoggerWriteType* type_;
};

class LoggableConsole : public Loggable {
public:
	LoggableConsole(const lvls& min, const lvls& max) :
		Loggable(min,max,new WriteOneLine())  {};

	void log(const std::string&, const lvls&) override;

};	

class LoggableFile : public Loggable {
public:

	

	LoggableFile(const lvls& min, const lvls& max) :
		Loggable(min, max, new WriteManyLines()) {};
	
	void log(const std::string&, const lvls&) override;

	void setFileName(const std::string&);

private:
	std::string fileName;
};




