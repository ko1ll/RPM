/**
 * @file LoggerWriteType.h
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "Enum.h"
using namespace std;

class LoggerWriteType
{
public:
	virtual std::string write(const std::string& , const lvls&) = 0;

};

class WriteOneLine : public LoggerWriteType {
public:
	std::string write(const std::string&, const lvls&) override;
private:
};


class WriteManyLines : public LoggerWriteType {
public:
	std::string write(const std::string&, const lvls&) override;
};

