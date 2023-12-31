// Implement C++ program for expression conversion as infix to postfix and its
// evaluation using stack based on given conditions: 1. Operands and operator, both
// must be single character. 2. Input Postfix expression must be in a desired format.
// 3. Only '+', '-', '*' and '/ ' operators are expected.

#include<iostream>
using namespace std;
#define MAX 20
class stack
{
int top,topeval;
char infix[MAX], postfix[MAX],stk[MAX];
float stkeval[MAX];
public:
stack();
void push(char);
void pusheval(float);
void read();
int IsEmpty ();
int IsEmptyeval ();
char pop();
float popeval();
void covert_infix_postfix();
int priority(char x);
float evaluatepostfix();
};
stack :: stack ()
{
top=-1;
topeval=-1;
}
int stack :: IsEmpty ()
{
//top is always at last added element
if (top == -1) //check if elements were added
return (-1);
else
return (1);
}
int stack :: IsEmptyeval ()
{
//top is always at last added element
if (topeval == -1) //check if elements were added
return (-1);
else
return (1);
}
void stack :: push(char temp)
{
//top is always at last added element (earlier element).
top ++; //take it to empty position
if (top == MAX) //check if there is any space
cout<<"Stack is Full";
else
{
stk [top] = temp; //add Â‘valueÂ’ at topth position
 // cout<<"New element pushed on the stack";
}
}
void stack :: pusheval(float temp)
{
//top is always at last added element (earlier element).
topeval ++; //take it to empty position
if (topeval == MAX) //check if there is any space
cout<<"Stack is Full";
else
{
stkeval [topeval] = temp; //add Â‘valueÂ’ at topth position
 // cout<<"New element pushed on the stack";
}
}
char stack :: pop()
{
int status;
char temp;
status = IsEmpty ();
if (status == -1) {
//cout<<"Stack is Empty";
return ('@');
}
else {
temp = stk [top--]; //fetch topth position in temp
return (temp);
}
}
float stack :: popeval()
{
int status;
float temp;
status = IsEmptyeval ();
if (status == -1) {
//cout<<"Stack is Empty";
return (-999);
}
else {
temp = stkeval [topeval--]; //fetch topth position in temp
return (temp);
}
}
void stack :: read()
{
cout<<"Enter infix expression ";
cin>>infix;
}
void stack :: covert_infix_postfix()
{
int i,k=0;
char sop;
for(i=0;infix[i]!='\0';i++)
{
if(infix[i]>='0' && infix[i]<='9')
{
postfix[k++] = infix[i];
}
else if(infix[i]=='(')
{
push(infix[i]);
}
else if(infix[i]==')')
{
while((sop=pop())!='(')
//pop all operators till “(” doesn’t come
postfix[k++]=sop;
}
else //if any operators
{
while(priority(infix[i]) <= priority(sop=pop()))
{
//till all higher priority operators are not popped, continue & write them in answer
postfix[k++] = sop;
if(top==-1)
break;
}
//when all higher operators are done,
if(priority(infix[i]) > priority(sop))
{
push(sop); //re-push the oper taken for comparison
}
push(infix[i]); //push the operator from i/p to stack
}
}//for
while(top!=-1)
{
//pop all remaining operators from stack
sop = pop();
postfix[k++] = sop;
}
postfix[k-1]='\0';
cout<<endl<<"The postfix is : "<<postfix;
}
int stack :: priority(char x)
{
switch(x)
{
case '@':
return -1;
case '(':
return 0;
case '+':
return 1;
case '-':
return 1;
case '*':
return 2;
case '/':
return 2;
}
}
float stack :: evaluatepostfix()
{
float value,operand1,operand2,result;
for(int i=0;postfix[i]!='\0';i++)
{
// Push operands onto the stack
if(postfix[i]>='0' && postfix[i]<='9')
{
value = postfix[i] - 48;
pusheval(value);
}
// If its an operator, pop 2 operands from the stack
else
{
operand2=popeval();
operand1=popeval();
switch(postfix[i])
{
case '+':
result=operand1+operand2;
break;
case '*':
result=operand1*operand2;
break;
case '-':
result=operand1-operand2;
break;
case '/':
result=operand1/operand2;
break;
}
pusheval(result);
}
}
result=popeval();
return result;
}
int main()
{
stack s;
float answer;
s.read();
s.covert_infix_postfix();
answer=s.evaluatepostfix();
cout<<endl<<"The answer is : "<<answer;
return 0;
}
