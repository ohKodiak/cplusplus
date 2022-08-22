/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"
using namespace std;
#include <iostream>
#include <string>

TemperatureData::TemperatureData(): id(""), year(0), month(0), temperature(0.0) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature): id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	/*First ordered by location
Then by date (i.e. by year and then by month)*/
	if (this->id > b.id)	{return false;}
	if (this->id < b.id)	{return true;}
	if (this->id == b.id)	{
		if (this->year > b.year)	{return false;}
		if (this->year < b.year)	{return true;}
		if (this->year == b.year)	{
			if (this->month > b.month)	{return false;}
			if (this->month < b.month)	{return true;}
			if (this->month == b.month)	{return false;}}}
	return false;}

