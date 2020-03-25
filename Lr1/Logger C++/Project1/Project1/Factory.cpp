/**
 * @file Factory.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include "Factory.h"
LoggableFile * FactoryFile::create(const lvls& min, const lvls& max)
{
    /**
    * ���������� ������ �����
    */  
	return new LoggableFile(min,max);
}
LoggableConsole * FactoryConsole::create(const lvls & min, const lvls & max)
{   
    /**
    * ���������� ������ �������
    */
	return new LoggableConsole(min, max);
}
