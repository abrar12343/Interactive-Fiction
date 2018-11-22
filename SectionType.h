#ifndef SECTIONTYPE_H
#define SECTIONTYPE_H

#include "storytokenizer.h"
#include <unordered_map>
#include <utility>
#include <string>
#include <fstream>
using namespace std;


class Set : public SectionToken
{
private:
	bool truth;
	string name;
public:
	Set(const string&); //moved to cpp
	section_t getType() const { return SET; }
	pair<string, bool> mapSet();

};

/**
 * \brief links must be added to unordered map <int , GOTO>
 * for user input of int and redirect to GOTO's passage name
 */
class Link : public SectionToken
{
private:
	string destination;
	string display;
public:
	Link(const string& str); //moved to cpp
	section_t getType() const { return LINK; }
	string getDestination() { return destination; }
	string getDisplay() { return display; }
};

class GoTo : public SectionToken
{
private:
	string destination;
public:
	GoTo(const string&);
	section_t getType() const override { return GOTO; }
	string getDestination() { return destination; }
};

/**
 * \brief skip to blocks if condition is met
 */
class If : public SectionToken
{
private:
	bool condition;
	string name;
public:
	If(string);
	section_t getType() const override { return IF; }
	bool getCondition() const { return condition; }
	string getName() const { return name; }
};

class ElseIf : public SectionToken
{
private:
	bool condition;
	string name;
	bool prevMet; //previous condition met -> skip this block
public:
	ElseIf(bool, string);
	bool getCondition() const { return condition; }
	string getName() const { return name; }
	bool getPrevious() const { return prevMet; }
	section_t getType() const override { return ELSEIF; }

};

class Else : public SectionToken
{
private:
	bool prevMet;
public:
	Else(bool k) : SectionToken("", ELSE) { prevMet = k; }
	section_t getType() const override { return ELSE; }
	bool getPrevious() { return prevMet; }
};

/**
 * \brief give block its own passagetokenizer, write to a file,
 * read that file, execute those changes to output.txt
 */
class Block : public SectionToken
{
private:
	bool ifTrue; //if a previous if condition was true, block is executed
public:
	Block(string str, bool k) : SectionToken(str, BLOCK) {ifTrue = k;}
	section_t getType() const override { return BLOCK; }
	PassageTokenizer BlockTokenize(int);
};

class Text : public SectionToken
{
private:

public:
	Text(string str) : SectionToken(str, TEXT) {}
	section_t getType() const override { return TEXT; }
};
#endif
