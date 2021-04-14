#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .
       and then append the two files into one:
          cat scanner.cpp parser.cpp > myparser.cpp
          // WORD DFA
// Done by: *JuiYu Huang *
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
int scanner(tokentype& tt, string& w)
{

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
                            tt = PRONOUN;
                            flag = 1;
                            break;
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                            tt = CONNECTOR;
                            flag = 1;
                            break;
                        case 14:
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
                    if (w[j] == 'a' || w[j] == 'e' || w[j] == 'i' || w[j] == 'o' || w[j] == 'u')
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
}

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

}
// end





//=================================================
// File parser.cpp written by Group Number: 13
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: default switch statement
// if a word isn't a valid token cout error
// Done by: Devin Ferre
void syntaxerror1(tokentype expected, /*something here*/)
{
    cout << "Error: " << expected << " expected, got:"/*<<something here*/;
}
// Type of error: **
// Done by: ** 
void syntaxerror2() { cout << ""; }

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: **
// Done by: **
tokentype next_token()
{

}

// Purpose: **
// Done by: **
bool match(tokentype expected) {}

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

// Done by: Devin Ferre

//Grammar rule 1:  <story>::= <s>{<s>}
void story()
{
    s();//process at least first token
    while (true)
    {
        s();//continue processing while there is something in s()
    }
}
//Grammar rule 2:  <s>::= [CONNECTOR]<noun> SUBJECT <after subject>
void s()
{
    switch (next_token())
    {
    case CONNECTOR:
        match(CONNECTOR);
        noun();
        match(SUBJECT);
        after_subject();
        break;

    case WORD1:
    case PRONOUN:
        noun();
        match(SUBJECT);
        after_subject();
        break;
    default:
        syntaxerror1();//syntax error
    }
}
//Grammar rule 3: <after subject>::= <verb><tense> PERIOD |<noun><after noun>
void after_subject()
{
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
        after_noun();
        break;
    default:
        break;//syntax error
    }
}
//Grammar rule 4: <after noun>::= DESTINATION <verb> <tense> PERIOD | <be> PERIOD | OBJECT <after object>
void after_noun()
{
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
            break;

        case OBJECT:
            match(OBJECT);
            after_object();
            break;
        default:
            //syntax error
            break;
    }
}
//Grammar rule 5: <after object>::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
void after_object()
{
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
        break;//syntax erro
    }
}
//Grammar rule 6: <noun> ::= WORD1 | PRONOUN
void noun()
{
    switch (next_token())
    {
    case WORD1:
        match(WORD1);
        break;
    case PRONOUN:
        match(PRONOUN);
        break;
    default:
        //syntax error
        break;
    }
}
//Grammar rule 7: <verb> ::= WORD2
void verb()
{
    switch (next_token())
    {
    case WORD2:
        match(WORD2);
        break;
    default:
        break;
        //syntax error
    }
}
//Grammar rule 8: <be> ::=   IS | WAS
void be()
{
    switch (next_token())
    {
    case IS:
        match(IS);
        break;
    case WAS:
        match(WAS);
        break;
    default:
        break;//syntax error
    }
}

//Grammar rule 9: <tense> := VERBPAST  | VERBPASTNEG | VERB | VERBNEG
void tense()
{
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
    default:
        break;
        //syntax error
    }
}
//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{

    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());

    //** calls the <story> to start parsing
    //** closes the input file 

/*
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


    */





}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
