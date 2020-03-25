/**
 * @file Observer.h
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#pragma once
#include <string>
#include "Logger.h"
class Observer
{
public:
	virtual void update(const std::string& what, const lvls& lvl) = 0;
};

