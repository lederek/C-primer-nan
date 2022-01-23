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
> + Update the condition in each loop cycle before the condition is tested again.
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

### Type Aliases

1. C++ has two ways to establish a new name as an alias for a type. One is to use the pre-processor:
   
   ```C++
   #define BYTE char // preprocessor replaces BYTE with char
   ```

2. The preprocessor then replaces all  occurrences of  *BYTE* wiht **char**  when you complie a program, thus making  *BYTE*  an alias for **char** .

3. The second method is to use the C++ (and C) keyword **typedef** to create an alias. For example, to make *byte* an  alias for **char** , you use this:
   
   ```C++
   typedef char byte;        // makes byte an alias for char
   ```

4.  In other words, if you want *aliasName* to be an alias for a particular type, you declare *aliasName* as if were a variable of that  type  and then prefix the declaration with the **typedef** keyword. 
   
   ```C++
   typedef typeName aliasName；
   ```

5. For example, to make *byte_pointer* an alias for pointer-to-**char** , you could declare *byte_pointer* as a pointer-to-**char** and then stick **typedef** in front:
   
   ```C++
   typedef char * byte_pointer;       // pointer to char type
   ```

6. you could tyr something similar with **#define**, but that wouldn't work if you declared a list of variable. For example, consider the following:
   
   ```C++
   #define FLOAT_POINTER float *
   FLOAT_POINTER pa, pb;
   ```

7. Preprocessor substitution converts the declaration to this:
   
   ```C++
   float * pa, pb;    // pa a pointer to float, pb just a float
   ```

8. The typedef approach doesn’t have that problem. Its ability to handle more complex type aliases makes using typedef a better choice than #define—and sometimes it is the only choice.

9. Notice that typedef doesn’t create a new type. It just creates a new name for an old type. If you make word an alias for int, cout treats a type word value as the int it really is.

## The do while loop

1. The third C++ loop is the **do while**. It's a different from the other  two because it's an *exit-condition* loop. That means this devil-may-care loop  first executes the body of the loop and only then evaluates the test expression to see whether it should continue looping.

2. If the condition evaltes to **false**, the loop terminates; otherwise, a new cycle of execution and testing begins.

3. Such as a loop always executes at least once because its program flow must pass through the body of the loop before reaching the test. Here's the syntax for the **do while** loop:
   
   ```C++
   do 
       body
   while (test-expression);
   
   // The body portion can be a single statement 
   // or a brace-delimited statement block
   ```

4. Usually, an entry-condition loop is a better choice  than an exit-condition loop because the entry-condition loop checks before looping.

> Strange for loops
> 
> It's not terribly common, but you may occasionally see code that resembles the followingL
> 
> ```C++
> int I = 0;
> for (;;)    // sometimes called a "forever loop"
> {
>     I++;
>     // do something ...
>     if (30 >= I) break;
> }
> 
> // Or here is another variation
> 
> int I = 0;
> for (;;I++)
> {
>     if (30 >= I)break;
>     // do something ...
> }
> 
> // The code relies on the fact that an empty test condition in a for loop is treated as being
> true.
> ```

## The Range-Based for Loop (C++11)

1. The C++11 adds a new form of loop called the **range-based for** loop. It simplifies one common loop task —— that of doing something with each element of an array, or, more generally, of one of the container classes, such as **vector** or **array**. 
   
   ```C++
   double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
   for (double x: prices)
       cout << x << std::endl;
   // this loop displays every value included in the range of the array.
   ```

2. To modify array values, you need a different syntax for the loop variable:
   
   ```C++
   for (double &x : prices)
       x = x * 0.80;        // 20% off sale
   ```
   
   The & symbol identifies x as a reference variable

3. The range-based **for**  loop also can be used with initialization lists:
   
   ```C++
   for (int x : {3, 5, 2,, 8, 6})
       cout << x << " ";
   cout << '\n';
   ```

## Loops and Text Input

1. one of the most common and important tasks assigned to loops: reading text character-by-character from a file or from the keyboard.

2. In fact, the cin object supports three distinct modes of single-character
   input, each with a different user interface. Let’s look at how to use these choices with **while** loops.

### Using Unadorned cin for Input

1. it has to have some way of knowing when to stop. How can it know when to stop? One way is to choose some special character, sometimes called a *sentinel character*, to act as a stop sign.
   
   ```C++
   // textin.cpp -- reading chars with a while loop
   #include<iostream>
   int main()
   {
       using namespace std;
       char ch;
       int count = 0;      // use basic input
       cout << "Enter characters; enter # to quit:\n";
       cin >> ch;          // get a character
       while (ch != '#')
       {
           cout << ch;     // echo the character
           ++count;        // count the character
           cin >> ch;      // get the next character
       }
       cout << endl << count << " characters read\n";
       return 0;
   }
   ```

2. When reading type **char** values, just as when reading other basic types, **cin** skips over spaces and newline characters.The spaces in the input are not echoed, so they are not counted.

### cin.get(char) to the Rescue

1. Usually, programs that read input character-by-charcter need to examine every character, including spaces, tabs, and newlines.    

2. The istream class (defined in iostream), to which
   cin belongs, includes member functions that meet this need. In particular, the member function **cin.get(ch)** reads the next character, even if it is a space, from the input and  assigns it to the variable **ch**. 

### Which *cin.get()* Should You Use?

1. ```C++
   char name[ArSize];
   ...
   cout << "Enter your name: \n";
   cin.get(name, ArSize).get();
   
   // The last line is equivalent to two consecutive function calls:
   cin.get(name, ArSize);
   cin.get();
   ```

2. One version of **cin.get()** takes two arguments: the array *name*, which is the address of the string (technically, type **char*** )， and *ArSize*, which is an integer of type **int**(). Then the program uses cin.get() with no arguments.

3. you can do so in C++ because the language supports an OOP feature called function overloading. Function overloading allows you to create different functions that have the same name, provided that they have different argument lists.

### The End-of-File Condition

1. If the input comes from a file, you can employ a much more powerful technique—detecting the end-of-file (**EOF**).

2. First, many operating systems, including Unix, Linux, and the Windows Command Prompt mode, support redirection, which enables you to substitute a file for keyboard input.

3. Second, many operating systems allow you to simulate the EOF condition from the keyboard.

4. When **cin**  detects the **EOF**, it sets two bits (the **eofbit** and the **failbit**) to *1*.You can use a member function named **eof()** to see whether the **eofbit** has been set; the call **cin.eof()** returns the **bool** value true if the **EOF** has been detected and false otherwise. Similarly, the **fail()** member function returns true if either the eofbit or the failbit has been set to 1 and false otherwise. Note that the eof() and fail() methods report the result of the most recent attempt to read; that is, they report on the past rather than look ahead. So a cin.eof() or cin.fail() test should always follow an attempt to read.

5. Some systems do not support simulated EOF from the keyboard.

6. ran the program on a Windows  system,  pressed Ctrl+Z and then Enter to
   simulate the EOF condition. Unix and Linux users would press Ctrl+D instead. Note that in Unix and Unix-like systems, including Linux and Cygwin, Ctrl+Z suspends execution of the program; the fg command lets execution resume.
+ EOF Ends Input
  
  1. Remember that when a cin method detects the EOF, it sets a flag in the cin object, indicating the EOF condition.When this flag is set, cin does not read anymore input, and further calls to cin have no effect.
  
  2. For file input, this makes sense because you shouldn’t read past the end of a file. For keyboard input, however, you might use a simulated EOF to terminate a loop but then want to read more input later.The cin.clear() method clears the EOF flag and lets input proceed again.
  
  3. Keep in mind, however, that in some systems, typing Ctrl+Z effectively
     terminates both input and output beyond the powers of cin.clear() to restore them

+ Common Idioms for Character Input
  
  the **istream** class provides a function that can convert an **istream** object such as **cin** to a bool value; this conversion function is called when cin occurs in a location where a bool is expected, such as in the test condition of a while loop.
  
  
  
  



### Yet Another Version of cin.get()

1. **getchar()** and **putchar()** ,they are available in C++ if you want them. You just use the **Stdio.h** header file as you would in C (or use the more current **cstdio** ). Or you can use member functions from the **istream** and **ostream** that work in much the same way.

2. The **cin.get()** member function with  no arguments  returns the next character from the input. 
   
   ```C++
   ch = cin.get();
   ```

3. Recall that **cin.get(ch)** returns an object, not the character read. This function works much the same as C's **getchar()** , returnning the character code as a type **int** value. 

4. Similarly, you can use the **cout.put()**  function to display the character::
   
   ```C++
   cout.put(ch);
   ```

5. Like C’s **putchar()**, except that its argument should be type **char** instead of type **int**.

6. To use **cin.get()** successfully, you need to know how it handles the EOF condition. When the function reaches the EOF, there are no more characters to be returned. Instead , **cin.get()** return a special  value, represented by the symbolic constant EOF. EOF.This constant is defined in the iostream header file.The EOF value must be different from any valid character value so that the program won’t confuse EOF with a regular character.Typically, EOF is defined as the value -1 because no character has an ASCII code of -1, but you don’t need to know the actual value

> Tip
> 
> You should realize that EOF does not represent a character in the input . Insted , it's a signal that there are no more characters.

| Property                                  | cin.get()                                            | ch = cin.get()                            |
| ----------------------------------------- | ---------------------------------------------------- | ----------------------------------------- |
| Method for conveying input character      | Assign to argument ch                                | Use function return value to assign to ch |
| Function return value for character input | A class istream object (true after bool conversion)  | Code for character as type int value      |
| Function return value at EOF              | A class istream object (false after bool conversion) | EOF                                       |



## Nested Loops and Two-Dimensional  Arrays

1. You can visualize a two-dimensional array as being more like a table, having both rows and columns of data.

2. Instead, you create an array for which each element is itself an array.

3. you need to use two subscripts to access the **int** elements.You can think of the first subscript as representing the row and the second subscript as epresenting the column

### Initializing a Two-Dimensional Array

1. When you create a two-dimensional array, you have the option of initializing each element. The technique is based on that for initializing a one-dimensional array. Remember that you do this by providing a comma-separated list of values enclosed in braces.

2. the initialization consists of a comma-separated series of one-dimensional initializations, all enclosed in a set of braces.
   
   ```C++
   int maxtemps[4][5] = // 2-D array
   {                                        
       {96, 100, 87, 101, 105}, // values for maxtemps[0]
       {96, 98, 91, 107, 104}, // values for maxtemps[1]
       {97, 101, 93, 108, 107}, // values for maxtemps[2]
       {98, 103, 95, 109, 108} // values for maxtemps[3]
   };
   ```

### Using a Two-Dimensional Array