#include "SectionType.h"
using namespace std;

Set::Set(const string& str): SectionToken(str, SET)
{
	name = str.substr(str.find(SET_START, 0) + 7, str.find(" to ", 0, 4));
	//if(str.substr(str.find(" to ", 0) + 4, str.find(')', 0)) == "true")
	if (str.rfind("false)") == string::npos)
	{
		truth = true;
	}
	else truth = false;
	sets[name] = truth;
}

/**
 * need iterator in interpreter to see if variable to set already exists. if 
 * it exists, use this function instead of setVariable in order to 
 * morph truth value, then morph pair
 */
void Set::setVariable(const string& str) 
{						
	if (str.rfind("false)") == string::npos)
	{
		truth = true;
	}
	else truth = false;
	sets[name] = truth;
}


Link::Link(const string& str): SectionToken(str, LINK)
{
	if (str.find(LINK_SEPARATOR) != string::npos)
	{
		display = str.substr(str.find(LINK_START) + 2, str.find(LINK_SEPARATOR));
		destination = str.substr(str.find(LINK_SEPARATOR) + 5, str.find(LINK_END));
	}
	else
	{
		destination = str.substr(str.find(LINK_START) + 2, str.find(LINK_END));
		display = destination;
	}
}
