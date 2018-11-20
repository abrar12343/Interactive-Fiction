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
	Set(const string& str) : SectionToken(str, SET)
	{
		
		name = str.substr(str.find(SET_START, 0)+7, str.find(" to ",0, 4));
		//if(str.substr(str.find(" to ", 0) + 4, str.find(')', 0)) == "true")
		if(str.rfind("false)") == string::npos)
		{
			truth = true;
		}
		else truth = false;
	}
	section_t getType() const { return SET; }

};

class Link : public SectionToken
{
private:
	string destination;
	string display;
public:
	Link(const string& str): SectionToken(str, LINK)
	{
		if(str.find(LINK_SEPARATOR) != string::npos)
		{
			display = str.substr(str.find(LINK_START) + 2, str.find(LINK_SEPARATOR));
			destination = str.substr(str.find(LINK_SEPARATOR) + 5, str.find(LINK_END));
		}
		else
		{
			destination = str.substr(str.find(LINK_START)+2, str.find(LINK_END));
			display = destination;
		}
	}
	section_t getType() const { return LINK; }
};

class GoTo : public SectionToken
{
private:

public:

};

class If : public SectionToken
{
private:

public:

};

class ElseIf : public SectionToken
{
private:

public:

};

class Else : public SectionToken
{
private:

public:

};

class Block : public SectionToken
{
private:

public:

};

class Text : public SectionToken
{
private:

public:

};
#endif
