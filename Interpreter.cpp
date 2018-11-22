#include <iostream>
#include <string>
#include <fstream>
#include "storytokenizer.h"
#include <unordered_map>
#include <limits> // cin.ignore(numeric_limits<streamsize>::max());
using namespace std;


int main()
{
	unordered_map<string, bool> sets;
	unordered_map<string, int> links; //needed forward declaration
	unordered_map<string, int> passages;


	ofstream out("output.txt");
	ifstream in("if.html");

	string line, story;

	//getline(cin, line);
	getline(in, line);

	//while (cin && line != "</html>")
	while (in && line != "</html>")
	{
		story += line + '\n';
		//getline(cin, line);
		getline(in, line);
	}

	StoryTokenizer st(story);
	int passnumber = 0;
	while (st.hasNextPassage())
	{
		PassageToken ptok = st.nextPassage();
		passnumber++;
		//ptok.linkPassage(passnumber);
		passages[ptok.getName()] = passnumber;
		//cout << "Passage " << pass << ":  " << endl;
		out << "Passage " << passnumber << ":  " << endl;
		
		PassageTokenizer pt(ptok.getText());
		while (pt.hasNextSection())
		{
			SectionToken stok = pt.nextSection();
			switch (stok.getType())
			{
			case LINK:
				//cout << "  Link:  ";
				out << "  Link:  ";
				break;
			case SET:
				//cout << "  Set:  ";
				out << "  Set:  ";
				break;
			case GOTO:
				//cout << "  Go-to:  ";
				out << "  Go-to:  ";
				break;
			case IF:
				//cout << "  If:  ";
				out << "  If:  ";
				break;
			case ELSEIF:
				//cout << "  Else-if:  ";
				out << "  Else-if:  ";
				break;
			case ELSE:
				//cout << "  Else:  ";
				out << "  Else:  ";
				break;
			case BLOCK:
				//cout << "  Block:  ";
				out << "  Block:  ";
				break;
			case TEXT:
				//cout << "  Text:  ";
				out << "  Text:  ";
				break;
			default:
				//cout << "  Unknown token:  ";
				out << "  Unknown token:  ";
			}
			//cout << stok.getText() << endl;
			out << stok.getText() << endl;
		}
	}

	out.close();
	in.close();


	 //interpreter of the output.txt
	ifstream inFile("output.txt");
	int location = 0;
	string iLine, iStory;

	//getline(cin, line);
	getline(inFile, iLine);

	//while (cin)
	while (inFile)
	{
		iStory += iLine + '\n';
		//getline(cin, line);
		getline(inFile, iLine);
	}
	//for blocks, we can look for the closest "  SectionToken:  ", substr that,
	//put it in a passagetokenizer, and execute from there. we 
	//should learn how to do this "recursively?" because there can be blocks
	//within blocks
	unsigned int pos = 0;
	while(iStory.at(pos) != '\0')
	{
		unsigned int nextset = iStory.find(ISET, pos);
		unsigned int nextgoto = iStory.find(IGOTO, pos);
		unsigned int nextlink = iStory.find(ILINK, pos);
		unsigned int nextif = iStory.find(IIF, pos);
		unsigned int nextelseif = iStory.find(IELSEIF, pos);
		unsigned int nextelse = iStory.find(IELSE, pos);

		unsigned int nexttok = nextset;
		if (nextset < nexttok)
			nexttok = nextset;
		if (nextgoto < nexttok)
			nexttok = nextgoto;
		if (nextlink < nexttok)
			nexttok = nextlink;
		if (nextif < nexttok)
			nexttok = nextif;
		if (nextelseif < nexttok)
			nexttok = nextelseif;
		if (nextelse < nexttok)
			nexttok = nextelse;
	}

	return 0;
}