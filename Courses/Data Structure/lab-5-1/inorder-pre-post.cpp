#include<iostream>
#include<stack>
using namespace std;

#define TOP stk.top()
#define PUSH stk.push
#define EMPTY stk.empty()
#define POP stk.pop()


bool is_Operator(char ch);

int precendence(char ch);

string reverse_array(string arr);

string infix_to_PostFix (stack <char> stk , string exp);

string infix_to_Prefix(stack <char> stk, string exp);

int main()
{
    string exp ;
    cout << "Enter a Infix expression: " ; getline(cin, exp);
    stack <char> stk ;
    cout << "\nPost-fix expression: " << infix_to_PostFix(stk, exp) <<endl;
    cout << "\nPre-fix expression: " << infix_to_Prefix(stk,exp) << endl;

}



string reverse_array(string str){
      string temp;
      for(int i=str.length()-1; i>=0; i--)
        temp += str[i];
     return temp;
}

bool is_Operator(char ch){
    if( ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return true;
}

int precendence(char ch){
    if(ch =='*'  || ch == '/' )
        return 2;
    else if ( ch == '+' || ch == '-' )
        return 1;
    return -1;
}
bool is_text(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}


string infix_to_PostFix (stack <char> stk , string exp) {
    string postfix;
    for( char ch : exp)
    {
        if(is_text(ch))
            postfix += ch;

        else if( ch == '(')
            PUSH(ch);

        else if( ch == ')')
        {
            while((!EMPTY) && TOP != '(')
            {
                postfix += TOP;
                POP;
            }
            if(TOP == '(')
                POP;
        }

        else if ( is_Operator(ch) )
        {
            if(EMPTY) PUSH(ch);

            else if (!EMPTY)
            {
                if( precendence(ch) > precendence(TOP) )
                {
                    PUSH(ch);
                }

                else
                {
                    while( (!EMPTY) && precendence(ch) <= precendence(TOP))
                    {
                        postfix += TOP;
                        POP;
                    }
                    PUSH(ch);
                }
            }
        }
    }
    while(!EMPTY)
    {
        postfix += TOP;
        POP;
    }
    return postfix;
}



string infix_to_Prefix(stack <char> stk, string exp)
{
    string prefix;
    exp = reverse_array(exp);
    for( int i = 0; i < exp.length() ; i++)
      {
          if(exp[i] == '(')
            exp[i] = ')';
         else if( exp[i] == ')')
            exp[i] = '(';
      }

    for(char ch: exp)
    {
        if(is_text(ch))
            prefix += ch;

        else if(ch == '(')
            PUSH(ch);

        else if( ch == ')')
        {
            while((!EMPTY) && TOP != '(')
            {
                prefix +=  TOP;
                POP;
            }
            if (TOP == '(')
               POP;
        }

        else if( is_Operator(ch))
        {
            if(EMPTY) PUSH(ch);

            else if(precendence(ch) > precendence(TOP))
                PUSH(ch);

            else{
                while(!EMPTY)
                {
                    prefix += TOP;
                    POP;
                }
                PUSH(ch);
            }
        }
    }

    while (!EMPTY)
    {
        prefix += TOP;
        POP;
    }
    return prefix = reverse_array(prefix);
}
