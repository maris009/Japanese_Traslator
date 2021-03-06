#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//=================================================
// File scanner.cpp
//=================================================


/* 

// --------- Two DFAs ---------------------------------

// WORD DFA

// RE:   * (vowel | vowel n | consonant vowel | consonant vowel n |consonant-pair vowel | consonant-pair vowel n)^+ *
bool word (string s)
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
      if (state == 0 &&s[charpos] == 's')
	{
	  state = 1;
	}
      else if(state == 0 && s[charpos] == 't')
	{
	  state = 2;
	}
      else if(state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 0 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'n' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
	{
	  state = 5;
	}
      else if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      // state = 1
      else if(state == 1 && s[charpos] == 'h')
	{
	  state = 3;
	}
      else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      
      
      // state = 2
      else if (state == 2 && s[charpos] == 's')
	{
	  state = 3;
	}
      else if (state == 2 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      
      else if(state == 3 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}

      // state = 4
      else if (state == 4 && s[charpos] == 'h')
	{
	  state = 3;
	}
      
      // state = 5
      else if(state == 5 && s[charpos] == 'y')
	{
	  state = 3;
	}
      else if(state == 5 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
	{
	  state = 6;
	}
      // state = 6
      else if (state == 6 &&s[charpos] == 's')
	{
	  state = 1;
	}
      else if (state == 6 && s[charpos] == 't')
	{
	  state = 2;
	}
      else if (state == 6 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 6 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 6 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g'))
	{
	  state = 5;
	}
      else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
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
      else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
	{
	  state = 3;
	}
      else if (state == 7 && s[charpos] == 'c')
	{
	  state = 4;
	}
      else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'm' || s[charpos] == 'k' || s[charpos] == 'h' || s[charpos] == 'p' || s[charpos] == 'r' || s[charpos] == 'g' || s[charpos] == 'n'))
	{
	  state = 5;
	}
      else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'e' || s[charpos] == 'i' || s[charpos] == 'o' ||s[charpos] == 'u' || s[charpos] == 'I' || s[charpos] == 'E'))
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

bool period (string s)
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
enum tokentype {ERROR, WORD1, WORD2, PERIOD, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"ERROR", "WORD1", "WORD2", "PERIOD", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR" };

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
				      {"eofm", "EOFM"}};



// ------------ Scanner and Driver -----------------------

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself


int scanner(tokentype& tt, string& w)
{
    
  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.

  while (fin){
    // read the word to w
    fin >> w;
    
    if(w == "eofm")
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

       
	if(result1 == false && result2 == false)
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
		    switch(i)
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
	    if(flag == 1)
	      {
		break;
	      }
	    // it the word is not a reserved word
	    else
	      {
		int j = 0;
		// check the last charactor
		while(w[j+1] != '\0')
		  {
		    j++;
		  }
		// word1
		if(w[j] == 'a' || w[j] == 'e' || w[j] == 'i' || w[j] == 'o' || w[j] == 'u' || w[j]=='n')
		  {
		    tt = WORD1;
		    break;
		  }
		// word2
		else if(w[j] == 'I' || w[j] == 'E')
		  {
		    tt = WORD2;
		    break;
		  }
	      }
	  }

      }
    
  } // end of the while
    
  /*  **
     2. Call the token functions (word and period)
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.
     
     3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.
     
     4. Return the token type & string  (pass by reference)
  */

}//the end of scanner



// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!

int main()
{
  tokentype thetype;
  string theword;
  string filename;
    
  cout << "Enter the input file name: ";
  cin >> filename;
    
  fin.open(filename.c_str());
    
  // the loop continues until eofm is returned.
  while (true)
    {
      scanner(thetype, theword);  // call the scanner which sets
      // the arguments
      if (theword == "eofm") break;  // stop now
        
      cout << "Type is:" << tokenName[thetype] << endl;
      cout << "Word is:" << theword << endl;
    }
    
  cout << "End of file is encountered." << endl;
  fin.close();
    
}// end
