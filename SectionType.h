#ifndef SECTIONTYPE_H
#define SECTIONTYPE_H

#include "storytokenizer.h"
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, bool> sets;
unordered_map<string, int> links; //needed forward declaration

class Set : public SectionToken
{
private:
	bool truth;
public:

};

class Link : public SectionToken
{
	
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
