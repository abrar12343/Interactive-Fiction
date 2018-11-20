#include "SectionType.h"
using namespace std;

Set::Set(const string& str): SectionToken(str, SET) //Set:  (set: $mbedroom to false)
{
	//substr takes starting point and length
	name = str.substr(str.find(SET_START, 0) + 7, (str.find(" to ", 0, 4) - str.find(SET_START, 0) + 7)); 
	//if(str.substr(str.find(" to ", 0) + 4, str.find(')', 0)) == "true")
	if (str.rfind("false)") == string::npos)
	{
		truth = true;
	}
	else truth = false;
	sets[name] = truth; //find a way to resolve this error. find out where to keep sets and passages
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


Link::Link(const string& str): SectionToken(str, LINK) //  Link:  [[climb out the window]]
{
	if (str.find(LINK_SEPARATOR) != string::npos)
	{
		display = str.substr(str.find(LINK_START) + 2, str.find(LINK_SEPARATOR) - (str.find(LINK_START) + 2));
		destination = str.substr(str.find(LINK_SEPARATOR) + 5, str.find(LINK_END) - (str.find(LINK_SEPARATOR) + 5));
	}
	else
	{
		destination = str.substr(str.find(LINK_START) + 2, str.find(LINK_END) - (str.find(LINK_START) + 2));
		display = destination;
	}
}

GoTo::GoTo(const string& str) : SectionToken(str, GOTO) //(go-to: &quot;EPILOGUE&quot;)
{
	destination = str.substr(str.find(GOTO_NAME_START) + 7, str.find(GOTO_NAME_END, str.find(GOTO_NAME_START) + 7) - (str.find(GOTO_NAME_START) + 7));
	
}
