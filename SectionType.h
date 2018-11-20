#ifndef SECTIONTYPE_H
#define SECTIONTYPE_H

#include "storytokenizer.h"
#include <unordered_map>
#include <utility>
#include <string>
using namespace std;

unordered_map<string, bool> sets;
unordered_map<string, int> links; //needed forward declaration

class Set : public SectionToken
{
private:
	bool truth;
	string name;
public:
	Set(string str) : SectionToken(str, SET)
	{
		
		name = str.substr(str.find(SET_START, 0), str.find(" to ",0));
		if(str.substr(str.find(" to ", 0), str.find(')', 0)) == "true")
		{
			truth = true;
		}
		else truth = false;
	}
};

class Link : public SectionToken
{
private:

public:
	Link(string str): SectionToken(str, LINK)
	{
		
	}
};

class GoTo : public SectionToken
{

};

class If : public SectionToken
{

};

class ElseIf : public SectionToken
{

};

class Else : public SectionToken
{

};

class Block : public SectionToken
{

};

class Text : public SectionToken
{

};
#endif
