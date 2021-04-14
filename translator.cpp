#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;


//=================================================
// File translator.cpp
//=================================================



// RE:   * (vowel | vowel n | consonant vowel | consonant vowel n |consonant-pair vowel | consonant-pair vowel n)\^+
bool word(string s)
{
  
  // state: 0, s = 1, t = 2, sa = 3, c = 4, y = 5, 01 = 6, y0 = 7
  // cp = bmknhprg
  // np = dwzyj
  int state = 0;
  int charpos = 0;
  // keep scan until meet the end of the word
  while (s[charpos] != '\0')
    {
      // state = 0
      if (state == 0 && s[charpos] == 's')
	{
	  state = 1;
	}
      else if (state == 0 && s[charpos] == 't')
	{
	  state = 2;
	}
      else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || \
			      s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 0 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'n' || \
			      s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
	{
	  state = 5;
	}
      else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || \
			      s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      // state = 1
      else if (state == 1 && s[charpos] == 'h')
	{
	  state = 3;
	}
      else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || \
			      s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}


      // state = 2
      else if (state == 2 && s[charpos] == 's')
	{
	  state = 3;
	}
      else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || \
			      s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}

      else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s\
			      [charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}

      // state = 4
      else if (state == 4 && s[charpos] == 'h')
	{
	  state = 3;
	}

      // state = 5
      else if (state == 5 && s[charpos] == 'y')
	{
	  state = 3;
	}
      else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || s\
			      [charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      // state = 6
      else if (state == 6 && s[charpos] == 's')
	{
	  state = 1;
	}
      else if (state == 6 && s[charpos] == 't')
	{
	  state = 2;
	}
      else if (state == 6 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || \
			      s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 6 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 6 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'h' || \
			      s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
	{
	  state = 5;
	}
      else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || \
			      s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      else if (state == 6 && s[charpos] == 'n')
	{
	  state = 7;
	}

      // state = 7
      else if (state == 7 && s[charpos] == 's')
	{
	  state = 1;
	}
      else if (state == 7 && s[charpos] == 't')
	{
	  state = 2;
	}
      else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || \
			      s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 7 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'h' || \
			      s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'n'))
	{
	  state = 5;
	}
      else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' || \
			      s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      else
	{
	  break;
	}

      charpos++;
    }// end of while loop

  // check the final state
  if (state == 6 || state == 7)
    {
      return true;
    }
  else
    {
      return false;
    }

}



// PERIOD DFA

bool period(string s)
{  // complete this **

  if (s == ".")
    {
      return true;
    }
  else
    {
      return false;
    }
}

// ------ Three  Tables -------------------------------------



// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype
  {
    ERROR, WORD1, WORD2, PERIOD, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT\
    , DESTINATION, PRONOUN, CONNECTOR
  };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG"\
			 , "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" };

//  Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// reserve word list table
string reserveTable[19][2]
{
  {"masu", "VERB"},
    {"masen", "VERBNEG"},
      {"mashita", "VERBPAST"},
	{"masendeshita", "VERBPASTNEG"},
	  {"desu", "IS"},
	    {"deshita", "WAS"},
	      {"o", "OBJECT"},
		{"wa", "SUBJECT"},
		  {"ni", "DESTINATION"},
		    {"watashi", "PRONOUN"},
		      {"anata", "PRONOUN"},
			{"kare", "PRONOUN"},
			  {"kanojo", "PRONOUN"},
			    {"sore", "PRONOUN"},
			      {"mata", "CONNECTOR"},
				{"soshite", "CONNECTOR"},
				  {"shikashi", "CONNECTOR"},
				    {"dakara", "CONNECTOR"},
				      {"eofm", "EOFM"}
};



// ------------ Scanner and Driver -----------------------

ifstream fin, file;  // global stream for reading from the input file
ofstream fout;       // global stream for writing on a new file


// Scanner processes only one word each time it is called
// Gives back the token type and the word itself

void scanner(tokentype& tt, string& w)
{
  //  cout << "Scanner called using word: " << w << endl;

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.

  while (fin) {
    // read the word to w
    fin >> w;
    cout << "Scanner called using word: " << w << endl;

    if (w == "eofm")
      {
	tt = EOFM;
	break;
      }
    else
      {
	bool result1, result2;
	// call word and period
	result1 = word(w);
	result2 = period(w);

	//	cout << "Scanner called using word: " << w << endl;


	if (result1 == false && result2 == false)
	  {
	    tt = ERROR;
	    cout << endl;
	    cout << "Lexical error: " << w << " is not a valid token" << endl;
	    break;
	  }
	else if (result1 == false && result2 == true)
	  {
	    tt = PERIOD;
	    break;
	  }
	else if (result1 == true)
	  {
	    int flag = 0;
	    // check reserveTable
	    for (int i = 0; i < 19; i++)
	      {
		if (w == reserveTable[i][0])
		  {
		    switch (i)
		      {
		      case 0:
			tt = VERB;
			flag = 1;
			break;
		      case 1:
			tt = VERBNEG;
			flag = 1;
			break;
		      case 2:
			tt = VERBPAST;
			flag = 1;
			break;
		      case 3:
			tt = VERBPASTNEG;
			flag = 1;
			break;
		      case 4:
			tt = IS;
			flag = 1;
			break;
		      case 5:
			tt = WAS;
			flag = 1;
			break;
		      case 6:
			tt = OBJECT;
			flag = 1;
			break;
		      case 7:
			tt = SUBJECT;
			flag = 1;
			break;
		      case 8:
			tt = DESTINATION;
			flag = 1;
			break;
		      case 9:
		      case 10:
		      case 11:
		      case 12:
		      case 13:
			tt = PRONOUN;
			flag = 1;
			break;
		      case 14:
		      case 15:
		      case 16:
		      case 17:
			tt = CONNECTOR;
			flag = 1;
			break;
		      case 18:
			tt = EOFM;
			flag = 1;
			break;

		      }
		  }
	      }
	    // if the word is a reserved word
	    if (flag == 1)
	      {
		break;
	      }
	    // it the word is not a reserved word
	    else
	      {
		int j = 0;
		// check the last charactor
		while (w[j + 1] != '\0')
		  {
		    j++;
		  }
		// word1
		if (w[j] == 'a' || w[j] == 'e' || w[j] == 'i' || w[j] == 'o' || w[j] == 'u' || w[j] == 'n')
  {
    tt = WORD1;
    break;
  }
// word2
else if (w[j] == 'I' || w[j] == 'E')
  {
    tt = WORD2;
    break;
  }
      }
  }

      }

  } // end of the while
  //  cout << "Scanner called using word: " << w << endl;
}

//=================================================
// File parser.cpp written by Group Number: 13
//=================================================

/* INSTRUCTION:  copy your parser.cpp here
        cp ../ParserFiles/parser.cpp .
           Then, insert or append its contents into this file and edit.
              Complete all ** parts.
*/
//------------------------------PARSER-----------------------------------------
/* INSTRUCTION:  Complete all ** parts.
      You may use any method to connect this file to scanner.cpp
         that you had written.
           e.g. You can copy scanner.cpp here by:
             cp ../ScannerFiles/scanner.cpp .
                  and then append the two files into one:
                        cat scanner.cpp parser.cpp > myparser.cpp
                              // WORD DFA

                              */
// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.

// Type of error: Mismatch token value and the input value
// if a word isn't a valid token cout error


void syntaxerror1(tokentype expected, string saved_lexeme)
{
  cout << "SYNTAX ERROR: expected " << tokenName[expected] << " but found " << saved_lexeme << endl; //Get the token name expected and print the actual token found
}
// Type of error: default switch statement

void syntaxerror2(string saved_lexeme, tokentype saved_token)
{
  cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << tokenName[saved_token] << endl; // Get the tokenName from the saved token
  //terminate the program nothing else to do, probably major problem has occurred
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

tokentype saved_token; // global buffer for the token the scanner returned.

string saved_lexeme;  // saved the word from the scanner after being scan

bool token_available;  // global flag indicating whether
// we have saved a token to eat up or not

// Purpose: Looks ahead to see what token comes next from the scanner

tokentype next_token()
{
  //string saved_lexeme;
  if (!token_available)   // if there is no saved token yet
    {

      scanner(saved_token, saved_lexeme);  // call scanner to grab a new token
      token_available = true;              // mark that fact that you have saved it
    }
  return saved_token;    // return the saved token
}


// Purpose: Checks and eats up the expected token

bool match(tokentype expected)
{
  if (next_token() != expected)   // mismatch has occurred with the next token
    {
      //maybe add another variable to make the input more confortable
      syntaxerror1(expected, saved_lexeme); // calls a syntax error function here to generate a syntax error message here and do recovery
    }
  else  // match has occurred
    {
      cout << "Matched " << tokenName[expected] << endl;  // print the value of the expected matched value
      token_available = false;   // eat up the token
      return true;                        // say there was a match
    }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

/* Grammar:
   1 <story>::= <s>{<s>}
   2 <s>::= [CONNECTOR]<noun> SUBJECT <after subject>
   3 <after subject>::= <verb><tense> PERIOD |<noun><after noun>
   4 <after noun>::= DESTINATION <verb> <tense> PERIOD | <be> PERIOD | OBJECT <after object>
   5 <after object>::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
   6 <noun> ::= WORD1 | PRONOUN
   7 <verb> ::= WORD2
   8 <be> ::=   IS | WAS
   9 <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
*/


/*


  //Grammar rule 9: <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG

  void tense()  //Making nonterminal tense() to a functions
  {
  cout << "Processing <tense>" << endl;
  switch (next_token())
  {
  case VERB:
  match(VERB);
  break;
  case VERBNEG:
  match(VERBNEG);
  break;
  case VERBPAST:
  match(VERBPAST);
  break;
  case VERBPASTNEG:
  match(VERBPASTNEG);
  break;
  default:
  syntaxerror2(saved_lexeme, saved_token);
  break;
  }
  }
  
  
  
  //Grammar rule 8: <be> ::=   IS | WAS
  
  void be() //Making nonterminal be() to a functions
  {
  cout << "Processing <be>" << endl;
  switch (next_token())
  {
  case IS:
  match(IS);
  break;
  case WAS:
  match(WAS);
  break;
  default:
  syntaxerror2(saved_lexeme, saved_token);
  break;//syntax error2
  }
  }
  

  
  //Grammar rule 7: <verb> ::= WORD2
  
  void verb()   //Making nonterminal verb() to a functions
  {
  cout << "Processing <verb>" << endl;
  switch (next_token())
  {
  case WORD2:
  match(WORD2);
  break;
  default:
  cout << "Stock at Verb" << endl;
  break;
  //syntax error2
  }
  }

  
  //Grammar rule 6: <noun> ::= WORD1 | PRONOUN

  void noun()           //Making nonterminal noun() to a functions
  {
  cout << "Processing <noun>" << endl;
  switch (next_token())
  {
  case WORD1:
  match(e CONNECTOR:content type and the translated word

  }
  }



*/

//------------- PARSER Driver ---------------------------
/*
// The new test driver to start the parser

int main()
{

tokentype thetype;
string theword;
string filename;

cout << "Enter the input file name: ";
cin >> filename;
fin.open(filename.c_str());

//** calls the <story> to start parsing
story();
//** closes the input file
cout << "End of file is encountered." << endl;
fin.close();
return 0;

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
*/

//----------------------------PARSER END---------------------------------------

//***PART3***

//=================================================
// File translator.cpp written by Group Number: 13
//=================================================

// ----- Additions to the parser.cpp ---------------------
// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt


struct dictionary   //creating a struct to connect the Japanese word with the English word
{
  string J_word; // Japanese word
  string E_word; // English word
};

vector <dictionary> Lexicon; // creating vector to make a list of our saved dictionary, this is our Lexicon Dictionary


// Make sure it is easy and fast to look up the translation.

// Do not change the format or content of lexicon.txt

// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result
//                 in saved_E_word



string saved_E_word;  // variable of the saved English word after translatation was found

void  getEword()   // searching for a translation of the Japanese and storing it on saved_E_word
{
  int tracker =0; //tracking if translation was found

  for (int i = 0; i < Lexicon.size(); i++)  // searching our dictionary for a translation
    {
      if (saved_lexeme == Lexicon[i].J_word)  // checking every word on the dictionary
	{
	  saved_E_word = Lexicon[i].E_word;  // found saved it on saved_E_word
	  tracker++;                         // if found add one
	}
    }

  if(tracker == 0)                    // if no translation was found in the dicationary than used the saved_lexeme value
    {
      saved_E_word = saved_lexeme;
    }

}

//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)


void gen(string line_type)//sending the translation to the translated.txt file
{
  if(line_type == "TENSE") // if the line_type is TENSE then we just going out put the the saved_token named since we were not able to tranlstated.
    {
      fout << line_type << ": " << tokenName[saved_token] <<  endl; //printing out the content type and the token not able to translate
      fout << endl;

    }
  else
    {
      fout << line_type << ": " << saved_E_word << endl;  // printing out the content type and the translated word

    }
}


  
  // ----- Changes to the parser.cpp content ---------------------

  // ** Comment update: Be sure to put the corresponding grammar
//    rule with semantic routine calls
//    above each non-terminal function

// ** Each non-terminal function should be calling
//    getEword and/or gen now.

/*
Translator grammar

<story>::= <s> {<s>}
<s>::= [CONNECTOR#getEword# #gen(CONNECTOR)#]<noun> #getEword#SUBJECT #gen(ACTOR)#<after subject>
        <after subject>::= <verb>#getEword# #gen(ACTION)#<tense>#gen(TENSE)# PERIOD |<noun>#getEword# <after noun>
	<after noun>::= DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <be> #gen(DESCRIPTION)# #gen(TENSE)# PERIOD | OBJECT #gen(OBJECT)# <after object>
	<after object>::= <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <noun> #getEword# DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD
	<noun> ::= WORD1 | PRONOUN
	<verb> ::= WORD2
		  <be> ::=   IS | WAS
		  <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG

		  
*/



//Grammar rule 9: <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG

void tense()  //Making nonterminal tense() to a functions
{
  cout << "Processing <tense>" << endl;
  switch (next_token())
    {
    case VERB:    // VERB
      match(VERB);
      break;
    case VERBNEG:  // VERBNEG
      match(VERBNEG);
      break;
    case VERBPAST:  // VERBPAST
      match(VERBPAST);
      break;
    case VERBPASTNEG:  // VERBPASTNEG
      match(VERBPASTNEG);
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);
      break;
    }
}


//Grammar rule 8: <be> ::=   IS | WAS

void be() //Making nonterminal be() to a functions
{
  cout << "Processing <be>" << endl;
  switch (next_token())
    {
    case IS:
      match(IS);
      break;
    case WAS:
      match(WAS);
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token); //syntax error2
      break;
    }
}



//Grammar rule 7: <verb> ::= WORD2

void verb()   //Making nonterminal verb() to a functions
{
  cout << "Processing <verb>" << endl;
  switch (next_token())
    {
    case WORD2:  //WORD2
      match(WORD2);
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);    //syntax error2
      break;

    }
}



//Grammar rule 6: <noun> ::= WORD1 | PRONOUN

void noun()           //Making nonterminal noun() to a functions
{
  cout << "Processing <noun>" << endl;
  switch (next_token())
    {
    case WORD1:   //WORD1
      match(WORD1);
      break;
    case PRONOUN:   //PRONOUN
      match(PRONOUN);
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);  //syntax error2
      break;
    }
}



//Grammar rule 5: <after object>::= <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <noun> #getEword# DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD

void after_object()            //Making nonterminal after_object() to a functions
{
  cout << "Processing <after object>" << endl;
  switch (next_token())
    {
    case WORD2:    //<verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD
      verb();
      getEword();
      gen("ACTION");
      tense();
      gen("TENSE");
      match(PERIOD);
      break;

    case WORD1:    //<noun> #getEword# DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD where <noun> can be either WORD1 or PRONOUN
    case PRONOUN:
      noun();
      getEword();
      match(DESTINATION);
      gen("TO");
      verb();
      getEword();
      gen("ACTION");
      tense();
      gen("TENSE");
      match(PERIOD);
      break;

    default:
      syntaxerror2(saved_lexeme, saved_token);  //syntax error 2
      break;
    }
}



//Grammar rule 4: <after noun>::= DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD | <be> #gen(DESCRIPTION)# #gen(TENSE)# PERIOD | OBJECT #gen(OBJECT)# <after object>

void after_noun()           //Making nonterminal after_noun() to a functions
{
  cout << "Processing <after noun>" << endl;
  switch (next_token())
    {

    case DESTINATION:   //DESTINATION #gen(TO)# <verb> #getEword# #gen(ACTION)# <tense> #gen(TENSE)# PERIOD
      match(DESTINATION);
      gen("TO");
      verb();
      getEword();
      gen("ACTION");
      tense();
      gen("TENSE");
      match(PERIOD);
      break;

    case IS:   //<be> #gen(DESCRIPTION)# #gen(TENSE)# PERIOD  where <be> can be either IS or WAS
    case WAS:
      be();
      gen("DESCRIPTION");
      gen("TENSE");
      match(PERIOD);
      break;

    case OBJECT:  //OBJECT #gen(OBJECT)# <after object>
      match(OBJECT);
      gen("OBJECT");
      after_object();
      break;

    default:
      syntaxerror2(saved_lexeme, saved_token);  //syntax error 2
      break;
    }
}



//Grammar rule 3: <after subject>::= <verb>#getEword# #gen(ACTION)#<tense>#gen(TENSE)# PERIOD |<noun>#getEword# <after noun>

void after_subject()           //Making nonterminal after_subject() to a functions
{
  cout << "Processing <after subject>" << endl;

  switch (next_token())
    {
    case WORD2:    //<verb>#getEword# #gen(ACTION)#<tense>#gen(TENSE)# PERIOD
      verb();
      getEword();
      gen("ACTION");
      tense();
      gen("TENSE");
      match(PERIOD);
      break;
    case WORD1:   //<noun>#getEword# <after noun>  where <noun> can be either WORD1 or PRONOUN
    case PRONOUN:
      noun();
      getEword();
      after_noun();
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);    //syntax error 2
      break;
    }
}



//Grammar rule 2; <s>::= [CONNECTOR#getEword# #gen(CONNECTOR)#]<noun> #getEword#SUBJECT #gen(ACTOR)#<after subject>

void s()           //Making nonterminal s() to a functions
{

  cout << "Processing <s>" << endl;

  switch (next_token())
    {
      cout << "Scanner called using word: " << saved_lexeme << endl;
    case CONNECTOR:   //[CONNECTOR#getEword# #gen(CONNECTOR)#]<noun> #getEword#SUBJECT #gen(ACTOR)#<after subject> where [] happens if we have a CONNECTOR
      match(CONNECTOR);
      getEword();
      gen("CONNECTOR");
      noun();
      getEword();
      match(SUBJECT);
      gen("ACTOR");
      after_subject();
      break;
    case WORD1:  //<noun> #getEword#SUBJECT #gen(ACTOR)#<after subject> where <noun> can be either WORD1 or PRONOUN
    case PRONOUN:
      noun();
      getEword();
      match(SUBJECT);
      gen("ACTOR");
      after_subject();
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token); //syntax error 2
      break;
    }
  cout << endl;
  cout << endl;
}



//Grammar rule 1:  <story>::= <s>{<s>}

void story()           //Making nonterminal story() to a functions
{
  cout << "Processing <story>" << endl;
  cout << " " << endl;
  s();//process at least first token

  while (token_available == false)  // while there is still more tokens available after a stence continue
    {

      switch (next_token())  //checking which is the next token to procede accordinly, CONNECTOR or <noun> where <noun> can be either WORD1 or PRONOUN
	{
	case CONNECTOR:
	case WORD1:
	case PRONOUN:
	  s();
	  break;
	default:
	  return;

	}
    }
}

// ---------------- Driver ---------------------------

// The final test driver to start the translator

int main()
{

  string word;
  //** opens the lexicon.txt file and reads it into Lexicon
  file.open("lexicon.txt");

  while (file)
    {
      // adding words to our dictionary lexicon,
      dictionary trw;  //creating a new translated word in the dictionary
      file >> word;  // first word inputed Japanase word
      trw.J_word = word;  // stored as the Japanese word in out dictionary struct
      file >> word;   // second word inputed English word
      trw.E_word = word;   // stored as the Japanese word in out dictionary struct
      Lexicon.push_back(trw);  // adding the trasnlated words to our dictionary called Lexicon


    }
  file.close();
  //** closes lexicon.txt

  file.clear();//supposedly helps prevent bugs

  string filename;
  cout << "Enter the input file name: "; //asking the user for a file name to be translated
  cin >> filename;    // taking the input file name from the user
  fin.open(filename.c_str());  //open the file name given by the user

  fout.open("translated.txt");   // opens the output file translated.txt

  // calls the <story> to start parsing
  story();

  // closes the input file
  fin.close();
  // closes traslated.txt
  fout.close();
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
