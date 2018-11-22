#ifndef __STORYTOKENIZER_H
#define __STORYTOKENIZER_H

#include <unordered_map>
#include <string>
using namespace std;


enum section_t { LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, TEXT };

const string PASSAGE_START_TAG = "<tw-passagedata";
const string PASSAGE_START_TAG_CLOSE = ">";
const string PASSAGE_END_TAG = "</tw-passagedata>";
const string LINK_START = "[[";
const string LINK_SEPARATOR = "-&gt;";
const string LINK_END = "]]";
const string GOTO_START = "(go-to:";
const string SET_START = "(set:";
const string IF_START = "(if:";
const string ELSEIF_START = "(else-if:";
const string ELSE_START = "(else:";
const string COMMAND_END = ")";
const string BLOCK_START = "[";
const string BLOCK_END = "]";

const string PASSAGE_NAME_START = "name=\"";
const string PASSAGE_NAME_END = "\"";
const string GOTO_NAME_START = "&quot;";
const string GOTO_NAME_END = "&quot;";

//interpreter section starters
const string IPASSAGE = "Passage "; 
const string ILINK = "  Link:  "; 
const string ISET = "  Set:  "; 
const string IGOTO = "  Go-to: "; 
const string IIF = "  If:  ";
const string IELSEIF = "  Else-if: ";
const string IELSE = "  Else:  ";
const string IBLOCK = "  Block:  ";
const string ITEXT = "  Text:  ";

/**
 * \brief 
 * \param str check if _Equal is appropriate
 * \return 
 */
inline bool isStart(const string& str) 
{
	if (str._Equal(IPASSAGE) || str._Equal(ILINK)|| str._Equal(ISET)
		|| str._Equal(IGOTO) || str._Equal(IIF) || str._Equal(IELSEIF) 
		|| str._Equal(IELSE) || str._Equal(IBLOCK) || str._Equal(ITEXT))
	{
		return true;
	}
	else return false;
}

class PassageToken
{
private:
	string pass;
	string name;
public:
	PassageToken() {}
	PassageToken(const string& str) : pass(str) {}
	PassageToken(const string& n, const string& p) : name(n), pass(p) {}
	const string& getName() const { return name; }
	const string& getText() const { return pass; }
	//void linkPassage(int x);
};

class SectionToken
{
private:
	string text;
	section_t type;
public:
	virtual ~SectionToken() = default;
	SectionToken() : type(TEXT) {}
	SectionToken(string str, section_t t) : text(str), type(t) {}
	virtual section_t getType() const { return type; }
	virtual const string& getText() const { return text; }
};

class PassageTokenizer
{
private:
	string pass;
	unsigned int pos;
	section_t lastsect;
public:
	PassageTokenizer() : pos(0) {}
	PassageTokenizer(string str) : pass(str), pos(0), lastsect(TEXT) {}
	bool hasNextSection() const;
	SectionToken nextSection();
};

class StoryTokenizer
{
	friend class Link;
private:
	string story;
	unsigned int pos;
public:
	StoryTokenizer() : pos(0) {}
	StoryTokenizer(const string& s) : story(s), pos(0) {}
	bool hasNextPassage() const;
	PassageToken nextPassage();
};

#endif