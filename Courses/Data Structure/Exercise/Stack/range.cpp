#include<iostream>
#include<stack>
#define TOP stk.top()
using namespace std;

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



string infix_to_PostFix (stack <char> stk , string exp)
{
    string temp;

    for(char c: exp)
    {

        if(( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
            temp += c;
        }

        else if ( c == '(')
            stk.push(c);

        else if ( c == ')'){

            if (stk.empty()){
                cout << "Syntax error!";
                return NULL;

            }

            else {

                while((stk.top() != '(') && (!stk.empty())) {
                    temp +=  stk.top();
                    stk.pop();
                }

            }
        }

        else if(is_Operator(c)){

            if( stk.empty() )
                {
                    stk.push(c);
                }

            else
               {
                   if( precendence( c) >  precendence ( stk.top())){
                       stk.push(c );
                   }
                   else if ( precendence( c ) == precendence(stk.top()) ){
                       stk.push( c );
                   }
                   else {
                       while((! stk.empty()) && ( precendence(c) <= precendence( stk.top()) ) ){
                           temp +=  stk.top();
                           stk.pop();
                       }
                       stk.push( c);
                   }
              }
        }
    }
    while(!stk.empty()) {
        temp += stk.top();
        stk.pop();
    }
    return temp;
}




string infix_to_Prefix(stack <char> stk, string exp)
{
    string temp;
    exp = reverse_array(exp);

    for( int i=0; i < exp.length() ; i++){
        if( exp[i] == '('){
            exp[i] = ')';
        }
        else if( exp[i] == ')')
            exp[i] = '(';
    }



    for( char c : exp){


        if ( ( c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z') ) {
            temp += c;
        }

        else if( c == '(' )
            stk.push(c);

        else if( c == ')'){

            if( stk.empty() ){
                cout << "parenthesis error";
                return NULL;
            }

            else {

                while( ( stk.top() != '(' ) && ( !stk.empty() ) ){
                    temp += stk.top();
                    stk.pop();
                }

                if( stk.top() == '(')
                    stk.pop();
            }
        }

        else if( is_Operator(c) ){

            if ( stk.empty())
                stk.push(c);


            else {
                if( precendence(c) > precendence(stk.top()) ) {
                    stk.push(c);
                }
                else if( precendence(c) == precendence( stk.top() )){
                    while((precendence(c) == precendence(stk.top())) ){
                        temp += stk.top();
                        stk.pop();
                    }
                    stk.push(c);
                }

                else {
                    while(!stk.empty() && precendence(c) < precendence(TOP)){
                        temp +=  TOP;
                        stk.pop();
                    }
                    stk.push( c );
                }
            }
        }
    }

    while( !stk.empty() ){
        temp += TOP;
        stk.pop();
    }

    return temp= reverse_array(temp);
}
