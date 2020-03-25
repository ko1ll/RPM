/**
 * @file LoggerWriteType.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "LoggerWriteType.h"
#include <iostream>
#include <ctime>
	/**
	* ������� ������ ����� �������
	* @param what ����� �������
	* @param lvl ������� �������
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
	* ������� ������ ����������� ��������
	* @param what ����� �������
	* @param lvl ������� �������
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