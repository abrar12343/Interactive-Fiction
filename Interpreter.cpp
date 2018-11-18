#include <iostream>
#include <string>
#include <fstream>
#include "storytokenizer.h"
#include <unordered_map>
using namespace std;

int passnumber = 0;

int main()
{
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
	//int passnumber = 0;
	while (st.hasNextPassage())
	{
		PassageToken ptok = st.nextPassage();
		passnumber++;
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

	ifstream inFile("output.txt");


	return 0;
}