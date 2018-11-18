#pragma once
#include "storytokenizer.h"
#include <unordered_map>
class GoTo;
using namespace std;

unordered_map<string, bool> sets; 
unordered_map<unsigned int, GoTo> links; //needed forward declaration

class Link
{
	string text;
public:
	Link(const string& str) : text(str){}
	string getPName() const; //do distinction about -gt&; in cpp
	string getText() const { return text; }
	section_t getType() const {return LINK; }
};


class Set
{
private:
	bool truth;
	string name;
public:
	Set(bool value, string identifier) : truth(value), name(identifier) {}
	void setThis()
	{
		sets[name] = truth;
	}
	bool getThis()
	{
		return sets[name];
	}

	section_t getType() const { return SET; }
};

class If
{
private:
	bool truth;
public:
	If(string name)
	{
		sets[name] = truth;
	}

	section_t getType() const { return IF; }
	
};

class ElseIf
{
private:
	bool truth;
public:
	ElseIf(Set);
	section_t getType() const { return ELSEIF; };

};

class Else
{
private:
	bool truth = true;
public:
	Else();
	section_t getType() const { return ELSE; };

};

class GoTo
{
private:
	string passName;
public:
	GoTo(string);
	section_t getType() const { return GOTO; }
	int getDestination() const;
};

class Block
{
public:
	
	section_t getType() const { return BLOCK; }
};

class Text
{
private:
	string text;
public:
	string getText() { return text; }
	section_t getType() const { return TEXT; }
};