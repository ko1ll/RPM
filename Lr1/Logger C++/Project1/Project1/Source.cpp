/**
 * @file Source.cpp
 * @brief
 * @author Kirpichenko Daniil <ko1lmain4@gmail.com>
 */
#include <iostream>
#include "Factory.h"
#include "Single.h"
using namespace std;
int main() {
	
	FactoryConsole fac;

	auto single = Single::getinstance();

	auto b = fac.create(lvls::notice, lvls::fatal);
	b->ChangeType(new WriteOneLine());
	single->addLogger(b);
	single->info("Log");
	cin.get();
}