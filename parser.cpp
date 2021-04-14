#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;


//=================================================
// File parser.cpp
//=================================================


/* 
// RE:   * (vowel | vowel n | consonant vowel | consonant vowel n |consonant-pair vowel | consonant-pair vowel n)\
^+ */
bool word(string s)
{
  // state: 0, s = 1, t = 2, sa = 3, c = 4, y = 5, 01 = 6, y0 = 7
  // cp = bmknhprg
  // np = dwzyj


  int state = 0;
  int charpos = 0;
  /* replace the following todo the word dfa  **
        while (s[charpos] != '\0')
	   {
	      if (state == 0 && s[charpos] == 'a')
	         state = 1;
		    else
		       if (state == 1 && s[charpos] == 'b')
		          state = 2;
			     else
			        if (state == 2 && s[charpos] == 'b')
				   state = 2;
				      else
				         return(false);
					    charpos++;
					       }//end of while


					        // where did I end up????
						 if (state == 2) return(true);  // end in a final state
						  else return(false);
  */

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
// Done by: *Eduardo and JuiYu Huang *
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

// TABLES Done by: *Devin Ferre and JuiYu Huang *

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

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Eduardo Mariscal and JuiYu Huang
void scanner(tokentype& tt, string& w)
{
  //  cout << "Scanner called using word: " << w << endl;
// ** Grab the next word from the file via fin
// 1. If it is eofm, return right now.

while (fin) {
// read the word to w
fin >> w;

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


if (result1 == false && result2 == false)
{
tt = ERROR;
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
 cout << "Scanner called using word: " << w << endl;
}

//=================================================
// File parser.cpp written by Group Number: 13
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: Mismatch token value and the input value
// if a word isn't a valid token cout error
// Done by: Devin Ferre 
void syntaxerror1(tokentype expected, string saved_lexeme)
{
  cout << "SYNTAX ERROR: expected " << tokenName[expected] << " but found " << saved_lexeme << endl;
}
// Type of error: default switch statement
// Done by: Devin Ferre
void syntaxerror2(string saved_lexeme, tokentype saved_token)
{
  cout << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << tokenName[saved_token] << endl;//?????
  //return 0;  //terminate the program nothing else to do, probably major problem has occurred
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
// Done by: Eduardo Mariscal and JuiYu Huang
tokentype saved_token; // global buffer for the token the scanner returned.

string saved_lexeme;

bool token_available;  // global flag indicating whether
// we have saved a token to eat up or not

// Purpose: Looks ahead to see what token comes next from the scanner
// Done by: Eduardo Mariscal
tokentype next_token()
{
  //string saved_lexeme;
  if (!token_available)   // if there is no saved token yet
    {
      scanner(saved_token, saved_lexeme);  // call scanner to grab a new token
      token_available = true;                              // mark that fact that you have saved it
    }
  //  cout << "Scanner called using word: " << saved_lexeme << endl;
  return saved_token;    // return the saved token
}


// Purpose: Checks and eats up the expected token
// Done by: Eduardo Mariscal
bool match(tokentype expected)
{
  if (next_token() != expected)   // mismatch has occurred with the next token
    {
      //maybe add another variable to make the input more confortable
      syntaxerror1(expected, saved_lexeme); // calls a syntax error function here to generate a syntax error message here and do recovery
    }
  else  // match has occurred
    {
      cout << "Matched " << tokenName[expected] << endl;
      token_available = false;   // eat up the token
      return true;                        // say there was a match
    }
}
// write another

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

// Done by: JuiYu Huang and Devin Ferre

//Grammar rule 9: <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
void tense()
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
      //syntax error2
    }
}

//Done by: JuiYu Huang and Devin Ferre
//Grammar rule 8: <be> ::=   IS | WAS
void be()
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
//Done by: Eduardo Mariscal and Devin Ferre
void verb()
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
//Done by: Devin Ferre
void noun()
{
  cout << "Processing <noun>" << endl;
  switch (next_token())
    {
    case WORD1:
      match(WORD1);
      break;
    case PRONOUN:
      match(PRONOUN);
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);
      break;
    }
}
//Grammar rule 5: <after object>::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
//Done by: JuiYu Huang and Devin Ferre
void after_object()
{
  cout << "Processing <after object>" << endl;
  switch (next_token())
    {
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;

    case WORD1:
    case PRONOUN:
      noun();
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;

    default:
      syntaxerror2(saved_lexeme, saved_token);
      break;//syntax error2
    }
}
//Grammar rule 4: <after noun>::= DESTINATION <verb> <tense> PERIOD | <be> PERIOD | OBJECT <after object>
//Done by: Devin Ferre
void after_noun()
{
  cout << "Processing <after noun>" << endl;
  switch (next_token())
    {

    case DESTINATION:
      match(DESTINATION);
      verb();
      tense();
      match(PERIOD);
      break;

    case IS:
    case WAS:
      be();
      match(PERIOD);
      break;

    case OBJECT:
      match(OBJECT);
      after_object();
      break;

    default:
      //syntax error2
      syntaxerror2(saved_lexeme, saved_token);
      break;
    }
}
//Grammar rule 3: <after subject>::= <verb><tense> PERIOD |<noun><after noun>
//Done by: Devin Ferre
void after_subject()
{
  cout << "Processing <after subject>" << endl;
  switch (next_token())
    {
    case WORD2:
      verb();
      tense();
      match(PERIOD);
      break;
    case WORD1:
      noun();
      after_noun();
      break;
    case PRONOUN:
      noun();
      after_noun();
      break;
    default:
      syntaxerror2(saved_lexeme, saved_token);
      break;//syntax error2
    }
}
//Grammar rule 2:  <s>::= [CONNECTOR]<noun> SUBJECT <after subject>
//Done by: Eduardo Mariscal
void s()
{
 
  cout << "Processing <s>" << endl;
  
  switch (next_token())
    {
    cout << "Scanner called using word: " << saved_lexeme << endl;
    case CONNECTOR:
      match(CONNECTOR);
      noun();
      match(SUBJECT);
      after_subject();
      break;

    case WORD1:
      noun();
      match(SUBJECT);
      after_subject();
      break;

    case PRONOUN:
      noun();
      match(SUBJECT);
      after_subject();
      break;

    default:
      syntaxerror2(saved_lexeme, saved_token);
      break;
      //syntaxerror1();//syntax error????????????????is it syntaxerror2()?
    }
  //  match(PERIOD);
  cout << endl;
  cout << endl;
}
//Grammar rule 1:  <story>::= <s>{<s>}
// Done by: Eduardo Mariscal 
void story()
{
  cout << "Processing <story>" << endl;
  cout << " " << endl;
  s();//process at least first token
  
 while (token_available == false)
 {
  
   switch (next_token())
     {
  
     case CONNECTOR:
     case WORD1:
     case PRONOUN:
      s();
       break;
     
     default:
       return;
       //syntaxerror1();//syntax error????????????????is it syntaxerror2()?
     }
 }



}



//------------- Driver ---------------------------

// The new test driver to start the parser
// Done by: JuiYu Huang
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



