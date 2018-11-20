#ifndef SECTIONTYPE_H
#define SECTIONTYPE_H

#include "storytokenizer.h"
#include <unordered_map>
#include <utility>
#include <string>
using namespace std;


class Set : public SectionToken
{
private:
	bool truth;
	string name;
public:
	Set(const string&); //moved to cpp
	section_t getType() const { return SET; }
	void setVariable(const string&);
};

class Link : public SectionToken
{
private:
	string destination;
	string display;
public:
	Link(const string& str); //moved to cpp
	section_t getType() const { return LINK; }
};

class GoTo : public SectionToken
{
private:
	string destination;
public:
	GoTo(const string&);
	section_t getType() const override { return GOTO; }
};

class If : public SectionToken
{
private:

public:

	section_t getType() const override { return IF; }
};

class ElseIf : public SectionToken
{
private:

public:

	section_t getType() const override { return ELSEIF; }
};

class Else : public SectionToken
{
private:

public:

	section_t getType() const override { return ELSE; }
};

class Block : public SectionToken
{
private:
	bool ifTrue; //if a previous if condition was true, block is executed
public:

	section_t getType() const override { return BLOCK; }
};

class Text : public SectionToken
{
private:

public:

	section_t getType() const override { return TEXT; }
};
#endif
