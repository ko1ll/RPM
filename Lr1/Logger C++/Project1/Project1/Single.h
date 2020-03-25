/**
 * @file Single.h
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#pragma once
#include <list>
#include "Logger.h"
#include "Observer.h"
class Single : public Observer
{
public:
	void notice(const std::string&);
	void info(const std::string&);
	void warning(const std::string&);
	void error(const std::string&);
	void critical(const std::string&);
	void fatal(const std::string&);



	static Single* getinstance();

	void addLogger(Loggable*);

private:


	void update(const std::string& what, const lvls& lvl) override;
	std::list<Loggable*> loggables;
};
