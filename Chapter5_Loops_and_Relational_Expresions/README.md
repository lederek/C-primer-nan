# Chapter 5 Loops and Relational Expressions

## In this chapter you'll learn about the following:

+ The **for** loop

+ Expressions and statements

+ The increment and decrement operators: ++ and --

+ Combination assignment operators

+ Compound statements (blocks)

+ The comma operator

+ Relational operators: **>, >=, ==，<=, <, and !=**

+ The **while** loop

+ The **typedef**  facility

+ The **do while** loop

+ The **get()** character input method

+ The end-of-file condition

+ Nested loops and two-dimensional arrays

## Introducing for Loops

1. Circumstances often call on a program to perform repetitive tasks

```C++
// forloop.cpp -- introducing the for loop
#include<iostream>
int main()
{
    using namespace std;
    int i;          // create  a counter
    // initialize; test; update
    for(i = 0; i < 5; i++)
        cout << "C++ knows loops.\n";
    cout << "C++ knows when to stop.\n";
    return 0;
}
```

This loop begins by setting the integer i to 0:**i = 0**;

This is the *loop initialization* part of the loop. Then in the *loop test*, the program tests whether i is less than 5:   **i <5**

If it is , the program executes the following statement, which is termed the *loop body*: **cout << "C++ knows loops.\n"**;

Then the program uses the *loop update* part of the loop to increase i by 1: i ++;

2. The *loop update* part of the loop uses the ++ operator , called the *increment  operator*. It increments the value of its operand by 1. （The increment operator is not restricted to **for** loops）

### parts of a for Loop

1. A **for**  loop provides a step-by-step recipe for performing repeated actions.The usual parts of a **for** loo handle these steps:
   
   1. Setting a value initially
   
   2. Performing a test to see whether the loop should continue
   
   3. Executing the loop actions
   
   4. Updating value(s) used for the test

2. The statement following the control section is called the body of the loop, and it is executed as long as the test expression remains true:
   
   ```C++
   for(initializationl; test-expression; update-expression)
       body
   ```
   
   1. C++ syntax counts a complete **for** statement as a single statement, even thought it can incorporate one or more statements in the body portion.
   
   2. The loop performs initialization just once. Typically , programs use this expression to set a variable to a starting value and then use the variable to count loop cycles.

3. *test-expression*  determines whether the loop body gets executed. Typically, this expression is a relational expression ——  that is， one that compares two values.If the comparison is true, the program executes the loop body.Actually, C++ doesn't limit *test-expression* to  true/false comparisons.You can use any expression, and C++ will type cast it to type **bool**.  If the expression evaluates to nonzero, it is type cast to the **bool**  value **true** , and the loop continues (In the update section, i-- is similar to i++ except that it decreases the value of i by 1 each time it’s used.)
   
   1. Because a C++ program converts **true**  and **false**  to **1**  and **0**  where integer values are expected, and it converts 0 to false and nonzero to true where bool values are expected.
   
   2. The **for**  loop is an *entey-condition*  loop.This means the test expression is evaluated *before* each loop cycle. The loop never executes the loop body when  the test expression is false. But give 0 as a starting value, because the test condition fails th very first time it's evaluated, the  loop body never gets executed.
   
   3. This look-before-you-loop attitude can help keep a program out of trouble.

4. *update-expression* is evaluated at the end of the loop, after the body has been executed. Typically, it's used to increase or decrease the value of the variable keeping track of  the number of loop cycles. However , it can be any valid C++  expression, as can the other control expressions.
   
   1. The **for**  loop body consists of a single statement
   
   2. **for** 's status as a C++ keyword prevents the compiler from thinking **for** is a function. It also prevents you from naming a function **for**.

### Expressions and Statements

1.  The << operator has higher precedence than the operators used in the
   expressions, so the code uses parentheses to enforce the correct order.

2. **cout** converts **bool**values to **int** before displaying them, but the **cout.setf(ios::boolalpha)** function call sets a flag that instructs cout to display the words true and false instead of 1 and 0.

3. A C++ expression is a value or a combination of values and operators, and every C++ expression has a value.

4. Any expression can become a statement if you add a semicolon.

### Nonexpressions and Statements

1. Although it is true that adding a semicolon to any expression makes it a statement, the reverse is not true.

2. you can’t assign a for loop to a variable

Bending the Reles

   1. you can declare a variable in the initialization area of a **for**  loop —— *declaration-statement expression*, which was a declaration stripped of the semicolon, and which could appear only in a **for** statement.

```C++
for (int i = 0; i < 5; i++)

for (for-init-statment condition; expression)
    statement
```

2. Such a variable exists only within the for statement.That is, after the program leaves the loop, the variable is eliminated.

### Back to the for Loop

```C++
// formore.cpp -- more looping with for
#include<iostream>
const int ArSize = 16;          // example of external declaration
int main()
{
    long long factorials[ArSize];
    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < ArSize; i++)
        std::cout << i << " ! = " << factorials[i] << std::endl;
    return 0;
}
```

### Changing the Step Size

So far the loop examples in this chapter have increased or decreased the loop counter by one in each cycle.You can change that by changing the update expression

```C++
// bigstep.cpp -- count as directed
#include<iostream>
int main()
{
    using std::cout;        // a using declaration
    using std::cin;
    using std::endl;
    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Couting by " << by << "s:\n";
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    return 0;
}
```

The main point here is that the update expression can be any valid expression.

Another point to note is that it often is a better idea to test for inequality than equality.

### Inside String with the for Loop

1. The **for** loop provides a direct way to access each character in a string in turn. You could use either a **string** class object or an **array** of **char** because both allow you to use array notation to access individual characters in a string.
2. The **string** class *size()* method yield the number of characters in the string 

### The Increment(++) and Decrement(--) Operator

1. The *prefix* version comes before the operand, as in ++x,  the notation ++b means “first increment the value of b and then use the new value in evaluating the expression”

2. The *postfix* version comes after the operand, as in x++， the notation a++ means “use the current value of a in evaluating an expression, and then increment the value of a.”

3. for example"
   
   ```C++
   int x = 5;
   int y = ++x;     // change x, then assign to y
                    // y is 6, x is 6
   
    int z = 5;
    int y = z++;    // assign to y, then change z
                    // y is 5, z is 6
   ```

### Side Effects and Sequence Points

1. a *side effect* is an effect that occurs when evaluating an expression modifies somthing , such as a value stored in a variable.
2. A *sequence point* is a point in program execution at which all side effects are guaranteed to be evaluated before going on to the next step. In C++ the semicolon in a statement marks a sequence point.That means all changes made by assignment operators, increment operators, and decrement operators in a statement must take place before a program proceeds to the next statement.
3. the end of any full expression is a sequence point.
4. It’s an expression that’s not a subexpression of a larger expression. Examples of full expressions include an expression portion of an expression statement and an expression that serves as a test condition for a while loop.
5. Sequence points help clarify when postfix incrementation takes place.

### The Increment/Decrement Operators and Pointers

1. You can use increment operators with pointers as well as with basic variable. Recall that adding an increment operator to a pointer increases its value by the number of bytes in the type it points to. The same rule holds for incrementing and decrementing pointers
   
   ```C++
   double arr[5] = {21.1, 32.8, 23.4, 45.2, 37.4};
   double *pt = arr;           // pt points to arr[0], i.e. to  21.1
   ++pt;                       // pt points to arr[1], i.e. to 32.8
   ```

2. You can also use these operators to change the quantity a pointer points to by using them in conjunction with the * operator.Those actions are determined by the placement and precedence of the operators.

3. The prefix increment, prefix decrement, and dereferencing operators all have the  *same* precedence and associate from right to left.The postfix increment and decrement operators both have the same precedence, which is higher than the prefix precedence

### Combination Assignment Operators

     C++ has a combined addition and assignment operator that accomplishes the same result more concisely,The += operator adds the values of its two operands and assigns the result to the operand on the left.This implies that the left operand must be something to which you can assign a value, such as a variable, an array element, a structure member, or data you identify by dereferencing a pointer.



### Compound Statements, or Blocks

1. The body of the loop must be a single statement。 C++ provides a syntax loophole through which you may stuff as many statements as you like into a loop body.The trick is to use paired braces to construct a compound statement, or block.The block consists of paired braces and the statements they enclose and, for the purposes of syntax, counts as a single statement.

2. Suppose you leave in the indentation but omit the braces.The compiler ignores indentation, so only the first statement would be in the loop.
   Thus, the loop would print the five prompts and do nothing more.After the loop completes,the program moves to the following lines, reading and summing just one number.

3. If you define a new variable inside a block, the variable persists only as long as the program is executing statements within the block.When execution leaves the block, the variable is deallocated.That means the variable is known only within the block.

4. if you declare a variable in a block that has the same name as one outside
   the block. The new variable hides the old one from its point of appearance until the end of the block.Then the old one becomes visible again, as in this example:
   
   ```C++
   #include <iostream>
   int main()
   {
     using std::cout;
     using std::endl;
     int x = 20; // original x
     { // block starts
        cout << x << endl; // use original x
        int x = 100; // new x
        cout << x << endl; // use new x
     } // block ends
     cout << x << endl; // use original x
     return 0;
   }
   ```
   
   ### More Syntax Tricks—— The Comma Operator
   
   1. A block enables you to sneak two or more statements into a place where C++ syntx allows just one statement.The comma operator does the same for expressions enabling you to sneak two expressions into a place where C++ syntax allows only one expression.
   
   2. The comma is not always a comma operator. The comma in this declaration serves to separate adjacent names in a list of variables.
      
      ```C++
      int i, j; // comma is a separator here, not an operator
      ```
   
   3. C++ does provide the operator with two additional properties. 
      
      + First, it guarantees that the first expression is evaluated before the second Table 5.2 Relational Operators Operator Meaning
      
      + Second, C++ states that the value of a comma expression is the value of the second part of the expression
      
      + The comma operator has the lowest precedence of any operator.



### Relational Expressions

1. C++ provides six relational operators to compare numbers.Because characters are represented by their ASCII codes, you can use these operators with characters, too.They don’t work with C-style strings, but they do work with string class objects.

2. Each relational expression reduces to the bool value true if the comparison is true and to the bool value false if the comparison is false, so these operators are well suited for use in a loop test expression.
   
   | Relational      Operators |                             |
   | ------------------------- | --------------------------- |
   | <<                        | Is less than                |
   | <=                        | Is less than or equal to    |
   | ==                        | Is equal to                 |
   | >                         | Is greater than             |
   | >=                        | Is greater than or equal to |
   | !=                        | Is not equal to             |

3. The relational operators have a lower precedence than the arithmetic operators

### Assignment, Comparison, and a Mistake You'll Probaby Make

1. Don’t confuse testing the is-equal-to operator (==) with the assignment operator (=).
   
   + This expression asks the musical question “Is musicians equal to 4?”:
     
     ```C++
     musicians == 4 // comparison
     ```
   
   + The expression has the value true or false.This expression assigns the value 4 to  musicians:
     
     ```C++
     musicians = 4 // assignment
     ```
     
     > **Caution**
     > Don’t use = to compare for equality; use ==.

   

### Comparing C-Style Strings

1. Because C++ handles C-style strings as addresses, you get little satisfaction if you try to use the relational operators to compare strings.

2. Instead, you can go to the C-style string library and use the **strcmp()** function to compare strings.This function takes two string addresses as arguments.That means the arguments can be pointers, string constants, or
   character array names.
   
   + If the two strings are identical, the function returns the value 0. 
   
   + If the first string precedes the second alphabetically, strcmp() returns a negative value.
   
   + if the first string follows the second alphabetically, strcmp() returns a positive value.
   
   + The fact that comparisons are based on code values also means that
     uppercase and lowercase letters differ, so the string "FOO" is different from the string "foo".

3. In some languages, such as BASIC and standard Pascal, strings stored in differently sized arrays are necessarily unequal to each other. But C-style strings are defined by the terminating null character, not by the size of the containing array.This means that two strings can be identical even if they are contained in differently sized arrays:
   
   ```C++
   char big[80] = "Daffy";    // 5 letters plus \0
   char litter[6] = "Daffy";  // 5 letters plus \0
   ```

4. This statement has the value 1 (true) if the strings are unequal and the value 0 (false) if they are equal.

> Testing for Equality or Order
> 
> You can use strcmp() to test C-style strings for equality or order. The following expression is true if str1 and str2 are identical:
> 
> **strcmp(str1,str2) == 0**
> 
> The expressions
> 
> **strcmp (str1, str2) != 0**
> 
> and
> 
> **strcmp （str1,  str2)**
> 
> are true if **str1** and **str2** are not identical. The ffollowing expressionis true if **str1** precedes **str2**:
> 
> **strcmp (str1,  str2)  < 0**
> 
> And the following exopression is true if **str1** following **str2**:
> 
> **strcmp (str1,  str2)  >  0**
> 
> Thus,  the **strcmp()**  function can play the role of the ==, !=, < and > operators, depending on how you set up a test condition.

5. you can use the relational operators with string class objects

6. The string class design allows you to use a string object as a single entity, as in the relational test expression, or as an aggregate object for which you can use array notation to extract individual characters.



## The while Loop

1. The **while** loop is a *for* loop stripped of the initialization and update parts; it has just a test condition and a body

```C++
while (test-condition)
    body
```

2. If the expression evaluates to true, the program executes the statement(s) in the body. the body consists of a single statement or a block defined by paired braces. After it finishes with the body, the program returns to the test condition and re-evaluates it. If the condition is nonzero, the program executes the body again.This cycle of testing and execution continues until the test condition evaluates to **false**.

### for Versus while

In C++ the **for** and **while** loops are essentially equivalent.

```C++
for (init-expression; test-expression; update-expression)
{
    statement(s)
}
```

could be rewritten this way:

```C++
init-expression;
while (test-expression)
{
    statement(s)
    update-expression;
}
```

Similarly, the **while** loop

```C++
while (test-expression)
    body
```

could be rewritten this way:

```C++
for (;test-expression;)
    body
```

This for loop requires three expressions, but they can be empty expressions (or statements). Only the two semicolons are mandatory. Incidentally, a missing test expression in a for loop is construed as true, so this loop runs forever:

```C++
for (;;)
    body
```

> Tip
> Keep in mind the following guidelines when you design a loop:
> 
> + Identify the condition that terminates loop execution.
> 
> + Initialize that condition before the first test.
> 
> +  Update the condition in each loop cycle before the condition is tested again.
> 
> One nice thing about for loops is that their structure provides a place to implement these three guidelines, thus helping you to remember to do so. But these guidelines apply to a while loop, too.



> Bad Punctuation
> 
> ```C++
> i = 0;
> while (name[i] != '\0' )
>     cout << name[i] << endl;
>     i++;
> cout << "Done\n";    
> ```
> 
> The absence of braces, however, tells the compiler that the body consists solely of  the first **cout** statement.  Thus, the loop keeps printing the first character of the array indefinitely. The program never reaches the **i++;**  statement because it is outside the loop
> 
> ```C++
> i = 0;
> while (name[i] != '\0');    // problem semicolon
> {
>     cout << name[i] << endl;
>     i++;
> }
> cout << "Done\n";
> ```
> 
> This time the code gets the braces right, but it also inserts an extra semicolon. Remember, a semicolon terminates a statement, so this semicolon terminate the **while** loop. In other words, the body of the loop is a *null statement* ——that is , nothing followed by a semicolon. All the material in  braces now comes *after* the loop and is never reached . Instead , the loop cycles, doing nothing forever. Beware the straggling semicolon.