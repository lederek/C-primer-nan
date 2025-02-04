# Chapter4 Compound Types

## In this chapter you'll learn about the following

+ Creating and using arrays
+ Creating and using C-style strings
+ Creating and using **string-calss** strings
+ Using the **getline()** and **get()** methods for reading strings
+ Mixing string and numeric input
+ Creating and using structures
+ Creating and using unions
+ Creating and using enumerations
+ Creating and using pointers
+ Managing dynamic memory with **new** and **delete**
+ creating dynamic arrays
+ Creating dynamic structures
+ Automatic, static, and dynamic storage
+ The **vector** and **array** classes (an introduction)

## Arrays

1. An **array** is a data form that can hold several values, all of one type.

2. To create an array, you use a declaration statement. An array declaration should indicate three things:
   
   + The type of value to be stored in each element
   + The name of the array
   + The number of elements in the array

3. Accomplish this in C++ by modifying the declaration for a simple variable and adding brackets that contain the number of elements.
   
   ```C++
   short months[12]; // creates array of 12 short elements,each of which can hold a type **short** value
   ```

4. This ia the general form for declaring an array:
   
   ```C++
   typeName arrayName[arraySize];
   ```
   
   The expression *arraySize*, which is the number of elements, must be an integer constant, such as 10 or a **const** value, or a constant expression,for which all values are known at the time compilation takes place.
   In particular, *arraySize* can't be a variable whose value is set while the program is running.

5. You can access **array** elements individually. The way to do this is to use a *subscrpit*, or an *index*, to number the elements.C++ array numbering starts with zero. C++ use a bracket notation with the index to specify an array element. Note that the index of the last element is one less than the size of the array.

6. Thus, an array declaration enables you to create a lot of variables with a single declaration, and you can then use an index to identify and access individual elements.

7. It simly provides a comma-separated list of values(the initialization list) enclosed in braces. 
   
   1. The space in the list are optional. 
   2. If you don't initialize an array that's defined inside a function, the element values remain undefined.
   3. That means the element takes on whatever value previouly resided at that location in memory.     
   4. Note that if you use the **sizeof** operator with an array name, you get the number of bytes in the whole array. But if you use **sizeof** with an array element, you get the size, in bytes, of the element. 

### initialization Rules for Arrays

1. You can use the initialization form only when defining the array . You cannot use it later, and you cannot assign one array wholesale to another.
   
   ```C++
   int cards[4] = {3, 6, 8, 10};    // okay
   int hand[4];                     // okay
   hand[4] = {5, 6, 7,  9};         // not allowed
   hand = cards;                    // not allowed
   ```

2. When initializing an array, you can provide fewer values than array elements.
   
   ```C++
   float hotelTips[5] = {5.0, 2.5};
   ```

3. If you partially initialize an array, the compiler sets the remaining elements to **zero**.

4. Initialize all the elements of an array to **zero** —— just explicitly initialize the first element to **zero** and then let the compiler initialize the remaining elements to zero.
   
   ```C++
   float totals[500] = {0};
   ```

5. If you leave the square brackets([]) empty when you initialize an array, the C++ compiler counts the elements for you.
   
   ```C++
   short things[] = {1, 5, 3, 8};
   // The compiler makes things an array of four elements
   ```

6. NOTE: Often , letting the comiler count the number of elements is poor practice because its count can be different from what you think it should be. And if your main concern is that the program, not you, knows how large an array is, you can do something like this:
   
   ```C++
   short things[] = {1, 5, 3, 8};
   int num_elements = sizeof things / sizeof(short);
   ```

### C++11 Array Initialization

1. C++11 makes the brace form of initialization(list-initialization) a universal form for all types.

2. Drop the **=** sign when initializing an array:
   
   ```C++
   double earnings[4] {1.23e4, 1.6e4, 1.1e4, 1.7e4}; // okay with C++11
   ```

3. Use empty braces to set all the elements to **0**:
   
   ```C++
   unsigned int counts[10] = {};    // all elements set to 0
   float balances[100] {};          // all elements set to 0
   ```

4. list-initialization protects against narrowing:
   
   ```C++
   long plifs[] = {25, 92, 3.0};       // not allowed
   char slifs[4] {'h', 'i', 1122011, '\0'};  // not allowed
   char tlifs[4] {'h', 'i', 112, '\0'};      // allowed
   ```

5. The C++ Standard Template Liberary (STL) provides an alternative to arrays called the **vector** template class, and C++11 adds an **array** template class.

## Strings

#### introduce of string

1. A **string** is a series of characters stored in consecutive bytes of memory. 

2. Taken from C and often called a *C-style string*, is the first one this chapter examines.

3. The last character of every string is the *null character*. This character, written \0, is the character with ASCII code 0, and it serves to mark the string's end.
   
   ```C++
   char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};   // not a string!
   char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'};   // a string
   ```

4. C++ has many functions that handle strings, including those used by **cout**. They all work by processing a string character-by-character until they reach the null character. If you ask **cout** to display a nice string like *cat* in the preceding example, it displays the first seven characters, detects the null character, and stops.

5. If you are ungracious enough to tell **cout** to display the *dog* array from the precefing example, which is not a string, **cout** prints the eight letters in the array and then keeps marching through memory byte-to-byte, interpreting each byte as a character to print, until it reaches a null character.

6. Use a quoted string, called a **string constant** or **string literal**, as in the following:
   
   ```C++
   char bird[11] = "Mr. Cheeps";       // the \0 is understood
   char fish[] = "Bubbles";            // let the compiler count
   ```

7. Quoted strings always include the terminating null character implicitly, so you don't have to spell it out. The various C++ input facilities for reading a string from keyboard input into a **char** array automatically add the terminating null for you.

8. you should make sure the array is large enough to hold all the characters of the string, including the null character. Initializing a character array with a string constant is one case where it may be safer to let the compiler count the number of elements for you.

9. CAUTION: when determining the minimum array size necessary to hold a string, remember to include the terminating null character in your count.

10. Note that a string constant (with double quotes) is not interchangeable with a character constant (with single quotes). 

11. A character constant, such as 'S', is a shorthand notation for the code for a character. On an ASCII system, 'S' is just another way of writing 83.
    
    ```C++
    char shirt_size = 'S';     // this is fine
    ```

12. "S is not a character constant; it represents the string consisting of two characters, the S and the \0 characters.

13. "S" actually represents the memory address at which the string is stored. So a statement like the following attempts to assign a memory address to *shirt_size*:
    
    ```C++
    char shirt_size = "s";     // illegal type mismatch
    ```

### Concatenating String Literals

1. C++ enables you to concatenate srtring literals——that is, to combine two quoted string into one.
2. Indeed， any two string constants separated only by whitespace(space, tabs, and newlines) are automatically joined into one. Thus, all the following output statements are equivalent to each other.
   ```C++
   cout << "I'd give my right arm to be" " a great violinits.\n";
   cout << "I'd give my right arm to be a great violinist.\n";
   cout <<"I'd give my right ar"
   "m to be a great violinist.\n";
3. Note that the join doesn't add any space to the joined strings. The first character of the second string immediately follows the last character, not counting \0., of the first string. The \0 character from the first string is replaced by the first character of the second string.

### Using  Strings in an Array

1. The two most common ways of getting a string into an array are initializae an array to a string constant and to read keyboard or file input into an array.
2. Initialize one array to quoted string and using **cin** to place an input string into a second array.
3. Uses the standard C liberary function **strlen()** to get the length of a string.
4. Note that the **sizeof** operator gives the size of the entire array.
5. The **strlen()** function returns the size of the string  stored in the array and not the size of the array itself. Also **strlen()** counts just visible characters and not the null character.The minimum array size for holding that string is **strlen(data)** + 1.

### Adventures in String Input

1. The **cin** technique is to use whitespace —— spaces, tabs, and newlines —— to delineate a string. This means **cin** reads just one word when it gets input for a character array. 
2. After it reads this word, **cin** automatically adds the terminating null character when it place the string into the array.

### Reading String Input a Line at a Time

For the **istream** class, has some line-oriented class member functions: **getline()** and **get()**. Both read an entire input line —— that is, up until a newline character. However, **getline()** then discards the newline characters, whereas **get** leave it in the input queue. 

#### line-Oriented Input with **getline()**

1. The **getline()** function reads a whole line, using the newline character transmitted by the Enter key to mark the end of input.                                            

2. You invoke this method by using **cin.getline()** as a function call.

3. The function takes two arguments.
   
   1. The first argument is the name of the target (that is, the array destined to hold the line of input),
   
   2. The second argument is a limit on the number of characters to be read. If this limits is, say, 20, the function reds no more than 19 characters, leaving room to be automatically add the null character at the end.

4. The **getline()** member function stops reading input when it reaches this numeric limit or when it reads a newline character, whichever comes first. 

#### Line-Oriented Input with **get()**

1. **get()** , which comes in several variations. It takes the same argumenrs, interprets them the same way, and reads to the end of a line.

2. But rather than read and discard the newline character, **get()** leaves that character in the input queue.
   
   ```C++
   cin.get(name, ArSize);
   cin.get(dessert, ArSize);     // A problem
   ```

3. Because the first call leaves the newline character in the input queue, that newline character is the first character the second call sees. Thus, get() concludes that it's reached the end of line without having found anything to read. Without help, get() just can't get past that newline character.

4. **cin.get()**(with no arguments) reads the single next character, even if it is a newline, so you can use it to dispose of the newline character and prepare for the next line of input.
   
   ```C++
   cin.get(name, ArSize);        // read first line
   cin.get();                    // read newline
   cin.get(deseert, ArSize);     // read second line
   ```

5. Another way to use **get()** is to *concatenate*, or join, the two class member functions, as follows:
   
   ```C++
   cin.get(name, ArSize).get();    // concatenate member functions
   ```
   
   What makes this possible is that **cin.get(name, ArSize)** return the **cin** object, which is then used as the object that invokes the **get()** function.

6. Similarly, the following statement reads two consecutive input lines into the arrays *name1* and *name2*; it's equivalent to making two separate calls to **cin.getline()**:
   
   ```C++
   cin.getline(name1,ArSize).getline(name2, ArSize);
   ```

7. Why use **get()** instead of **getline()** at all? 
   
   1. older implementations may not have **getline()** .
   2. **get()** lets you be a bit more careful.

8. How can you tell if it read the whole line rather than stopped because the array was filled? Look at the next input character.
   
   1. If it is a newline character, then the whole line was read.
   2. If it is not a newline character, then there is still more input on that line.

#### Empty Lines and Other Problems

1. The original practice was that the next input statement picked up where the last **getline()** or **get()** left off.

2. The current practice is that after **get()** (but not **getline()**) reads an empty line, it sets something called the *failbit*. The implications of this act are that further input is blocked, but you can restore input with the following command:
   
   ```C++
   cin.clear();
   ```

3. Another potential problem is that the input string could be longer than the allocated space. 

4. If the input line is longer than the number of characters specified, both **getline()** and **get()** leave the remaining characters in the input queue.

5. **getline()** additionally sets the failbit and turns off further input.

### Mixing String and Numeric Input

Mixing numeric input with line-oriented string input can cause problems.

```C++
// numstr.cpp -- following number input with line input
#include<iostream>
int main()
{
 using namespace std;
 cout << "What year was your house built?\n";
 int year;
 cin >> year;
 cout << "What is lts street address?\n";
 char address[80];
 cin.getline(address, 80);
 cout << "Year built: " << year << endl;
 cout << "Address: " << address << endl;
 cout << "Done!\n";
 return 0;

}
```

1. The problem is that when **cin** reads the year, it leaves the newline generated by the Enter Key in the input queue.

2. Then **cin.getline()** reads the newline as an empty line and assigns a null string to the address array.

3. The fix is to read and discard the newline before reading the address.

4. This can be done several ways, including by using **get()** with a **char** argument or with no argument, as described in the preceding example.
   
   ```C++
   cin >> year;
   cin.get();     // or cin.get(ch)
   ```
   
   Or you can concatenate the calls, making use of the fact that the expression **cin** >> year returns the **cin** object:
   
   ```C++
   (cin >> year).get();    // or (cin >> year).get(ch);
   ```
   
   C++ programs frequently use pointers instead of arrays to handle strings.

### Introducing the **string** Class

 The ISO/ANSI C++98 Standard expanded the C++ library by adding a string class. So now, instead of using a character array to hold a string, you can use a type **string**  variable（or object, to use C++ terminology）.

1. To use the **string** class, a program has to include the **string** header file.

2. The **string** class is part of the **std** namespace, so you have to provide a **using** directive or declaration or else refer to the class as **std::string**.

3. The class definition hides the array nature of a string and lets you treat a string much like an ordinary variable.

4. The main difference between **string** objects and character arrays  is that you declare a **string** object as a simple variable ,not as an array:
   
   ```C++
   String str1;        // create an empty string object 
   string str2 = "panther";        // create an initialized string 
   ```

5. The class design allows the program to handle the sizing automatically.

6. This mkes using a **string** object both more convenient and safer than using an array.

### C++11 String Initialization

C++11 enable list-initialization for C-style strings and **string** objects:

```C++
char first_date[] = {"Le Chapon Dodu"};
char seconde_data[] = {"The Elegant Plate"};
string third_date = { "The Bread Bowl"};
string fourth_date {“Han's Fine Eats"};
```

### Assignment, Concatenation, and Appending

1. The **string** class makes some operations simpler than is the case for arrays.For example, you can't simply assign one array to another. But you can assign one string object  to another:

```C++
char charr1[20];                // create an empty array
char charr2[20] = "jaguar";     // create an initialized array
string str1;                    // create an empty string object 
string str2 = "panther";        // create an initialized string
charr1 = charr2;                // INVALID, no array assignment
str1 = str2;                    // VAILD, object assignment ok
```

2. The **string** class simplifies combining strings. You can use the **+** operator to add two **string** objects together and the += operator to tack on a string to the end of an existing **string** objecct.
   
   ```C++
   string str3;
   str3 = str1 + str2;        // assign str3 the joined strings
   str1 += str2;              // add str2 to the end of str1
   ```

3. Recall that the escape sequence \" represents a double quotation mark that is used as a literal character rather than as marking the limits of a string.

### More **string** Class Operations

1. Even before the **string** class was added to C++, programmers needed to do things like assign strings. For C_style strings, they used functions from the C liberary for these tasks.

2. The **cstring** header file(formerly **string.h**) supports these functions.

3. For example, you can use the **strcpy()** function to copy a string to a character array, and use the **strcat()** function to append a string to character array:
   
   ```C++
   strcpy(charr1, charr2);            // copy charr2 to charr1
   strcat(charr1, charr2);            // append contents of charr2 
                                      // to charr1_
   ```

4. Furthermore, with arrays, there is always the danger of the destination array being too small to hold the information, as in this example:
   
   ```C++
   char site[10] = "house";
   strcat(site, " of pancakes");       // memory problem
   ```

5. The **strcat()** function would attempt to copy all 12 characters into the **site** array, thus overrunning adjacent memory. This might cause the program to abort, or the program might continue running but with corrupted data. The **string** class ,with its automatic resizing as necessary, avoids this sort of problem.

6. The C library does provide cousins to **strcat()** and **strcpy**, called **strncat()** and **strncpy** , that work more safely  by taking a third argument to indicate the maximum allowed size of the target arrays ,  but using them adds another layer of complexity in writing programs.

7. Notice the different syntax used to obtain the number of characters in string:
   
   ```C++
   int len1 = str1.size();        // obtain length of str1
   int len2 = strlen(charr1);     // obtain length of charr1
   ```
   
   The **strlen()** function is a regular function that takes a C-stylr string as its argument and that returns the number of characters in the string.
   
   The **size()**  function basically does the same thing, but the syntax for it is  different. Intead of appearing as a function argument, **str1* precedes the function name and is connected to it with a dot.

### Other Forms of String Literals

1. C++11 adds the **char16_t** and **char32_t**  types.

2. C++ uses the **L** , **u** and **U** prefixes,  respectivily, for string literals of these types.
   
   ```C++
   wchar_t title[] = L"Chief Astrogator";       // w_char string
   char16_t name[] = u"Felonia Ripova";        // char_16 string
   char32_t car[] = U"Humber Super Snipe";      // char_32 string
   ```

3. C++11 also supports an encoding scheme for Unicode characters called UTF-8.

4. C++11 addition is the raw string. In a raw string, characters simply stand for themselves. Raw string use "( and )" as delimiters, and they use an **R** prefix to identify them as raw strings:
   
   ```C++
   cout << R"(Jim "King" Tutt uses "\n" instead of endl.)" << '\n';
   ```
   
   This would display the following:
   
   ```C++
   Jim "King" Tutt uses "\n" instead of endl.
   ```

5. The raw string syntax allows you to place additional characters between the opening " and （. This implies that the same additional characters  must appear between the final ）and ". So a raw string beginning with R"+* (must terminate with )+*".
   
   ```C++
   cout << R"+*("(Who wouldn't?)", she whispered.)+*" << endl;
   ```
   
   would display the following:
   
   ```C++
   "(Who wouldn't?)", she whispered.
   ```

6. In short, the default delimiters of "( and )" have been replaced with "+*(   and   )+\*".

7. You can use any of the members of the basic character set as part of the delimiter other than the space, the left parenthesis, the right parenthesis, the backslash, and control chracters such as a tab or a newline.

## Structures

### Introducing Structures

A **structure** is a more versatile data form than an array because a single structure can hold itens of moere than one data.

A structure is a user-definable type, with a structure declaration serving to define the type's data properties. After you define the type , you can create variables of that type.

Creating a structure is a two-part process

        1. you define a structure description that describes and labels the different types of data that can be stored in a structure.

        2. you can create structure variables,  or, more generally, structure data objects, that follow the description's plan.

```C++
struct tag
{
    type name;   // structure members
    ...
};                // terminates the structuew declaration


// For example, suppose taht Bloataire,Inc.,wants to create a type to 
// describe  members of its product line of designer inflatable.

struct inflatable        // structure declaration
{
    char name[20];
    float volume;
    double price;
}
```

3. After you have defined the structure, you can create variables of that type: i
   
   ```C++
   inflatable hat;            // hat is a structure variable of type inflatable
   inflatable woopie_cushion; // type inflatable variable
   inflatable mainframe;      // type inflatable variable          
   ```

  4.  C++ allows you to drop the keyword **struct** when you declare structure variables:

```C++
struct inflatable goose;       // keyword struct rerquired in C
inflatable vincent;            // keyword struct not required in C++
```

5. In C++, the structure tag is used just like a fundamental type name. This change emphasizes that a structure declaration defines a new type. It also removes omitting **struct** from the list of curse-inducing errors.

6. You use the membership operator (.) to access individual members.

#### C++11 Structure Initialization

As with arrays, C++11 extends the features of list-initialization.The = sign is optional:

```C++
inflatable duck {"Daphne", 0.12, 9.98};        // can omit the = in C++11
```

Empty braces result in the individual members being set to 0.

Narrowing is not allowed.

### Structure Use a **string** Class Member

 Make sure the structure definition has access to the **std** namespace. You can do this by moving the **using** directive so that it is above the structure definition.

### Other Structure Properties

C++ makes user-defined types as similar as possible to built-in types. 

    1. You can pass structures as arguments to a function, and you can have a function use a structure as a return value.

2. You can use the assignment operator  (=) to assign one structure to  another of the same type. Doing so causes each member of one structure to be set to the value of the corresponding member in the other structure, even if the member is an array. This kind of assignment is called **memberwise assignment**

3. You can combine the definition of a structure form with the creation of structure variable. To fo so, you follow the closing brace with the variable name or names:

```C++
struct Perks
{
    int key_number;
    char car[12];   
}mr_smith, ms_jones;            // two Perks variables
```

4. You even can initialize a variable you create in this fashion:

```C++
struct Perks
{
    int key_number;
    char car[12];
}mr_glitz = 
{
    7,        // value for mr_glitz.key_number member
    "Packard" // value for mr_glitz.car m
};
```

5. Another thing you can do with structures is create a structure with no tyoe name. You do this by omitting a tag name while simulataneously defining a structure form and a variable,but you can't subsequently create other variables of the same type:
   
   ```C++
   struct    // no tag
   {
       int x;        // 2 members
       int y
   }position;        // a structure variable
   ```
   
   #### Arrays of Structures
   
   The *inflatable* structure contains an array (the *name* array). It's also possible to create arrays whose elements are structures. The technique is exactly the same as for creating arrays of the fundamental types.
   
   ```C++
   inflatable gifts[100];        // array of 100 inflatable structures
   ```
   
   This makes *gifts* an array of *inflatables*. Hence each element of the array , such as *gifts[0]* or *gifts[99]*, is an *inflatable* object and can be used with the membership operator:
   
   ```C++
   cin >> gifts[0].volume;        // use volume member of first struct
   cout << gifts[99].price << endl;// display price member of last struct
   ```
   
   Keep in mind that *gifts* itself is an array, not a structure, so constructions such as *gifts.price* are not valid.

       To initialize an array of structures, you combine the rule for initializing arrays (a brace-enclosed, comma-separated list of values for each element)  with the rule for structures(a brace-enclosed, comma-separated list of values for each member)

```C++
inflatable guest[2] =         // initializing an array of structs
{
    {"Bambi", 0.5, 21.99},    // first structure in array
    {"Godzilla", 2000, 565.99}// next structure in array
};
```

### Bit Field in Structures

1. C++ enable you to specify structure members that occupy a particular number of bits. This can  be handy for creating  a data structure that correponds,  say , to  a register on some hardware device.

2. The field type should be an integral or enumeration type , and a colon followed by a number indicates the actual number of bits to be used. 

3. You can use unnamed field to provide spacing. Each member is  termed  *a bit field*.
   
   ```C++
   struct torgle_register
   {
       unsigned int SN : 4;        // 4 bits for SN value
       unsigned int : 4;           // 4 bits unused
       bool goodIn  : 1;           // valid input (1 bit)
       bool goodTorgle : 1;        // successful torgling
   }
   ```
   
   4. You can initialize the fields in the usual manner, and you use standard structure notation to access bit fields:
      
      ```C++
      torgle_register tr = { 14, true, false };
      ...
      if(tr.goodIn)        
      ```
      
      Bit fields are typically used in low-level programming.

# Unions

1. A **Union**is a data format that can hold different data types but only one type at a time.

```C++
union one4all
{
    int int_val;
    liong long_val;
    double doule_val;
};
```

you can use a *one4all* variable to hold an **int** , a **long**, or a **double**, just as long ad you do  so at different times:

```C++
one4all pail;
pail.int_val = 15;        // store an int
cout << pail.int_val;
pail.double_val = 1.38;   // store a double, int value is lost
cout << pail.double_val;  
```

2. The member name identifies  the capacity in which the variable is acting. Because a union holds only one value at a time, it has to have space enough to hold its largest member. Hence, the size of the union  is the size of its largest  member.

3. One use of a union is to save space  when a data item can use two or more formats but never simultaneously.

```C++
struct widget
{
    char brand[20];
    int type;
    union id                 // format depends on widget type
    {
        long id_num;        // type 1 widgets
        char id_char[20];   // other widgets
    }id_val;
};
...
widget prize;
...
if(price.type == 1)                    
    cin >> prize.id_val.id_num;        // use member name to indicate mode
else
    cin >> prize.id_val.id_char;
```

4. An *anonymous union* has no name; in essence,  its members become variable that share the same address. Naturally, only one member can be current at a time:
   
   ```C++
   struct widget
   {
       char brand[20];
       int type;
       union                    // anonymous union
       {
           long id_num;        // type 1 widgets
           char id_char[20];   // other widgets  
       };
   };
   ...
   widget prize;
   ...
   if(prize.type == 1)
       cin >> prize.id_num;
   else
       cin >> prize.id_char;
   ```

Because the union is anonymous, *id_num* and *id_char_*are treated as two members of prize* that  share the same address.  The need for an intermediate identifier *id_val_*  is  eliminated. It is up to the programmer to keep track of which choice is active.

6. Unions often (but not exclusively) are used to save memory space.

# Enumerations

1. The C++ **enum** facility provides an alternative to **const** for creating symbolic constants.

2. It also lets you define new types but in a fairly restricted fashion
   
   ```C++
   enum spectrum{red, orange, yellow, green, blue, violet, indigo, ultraviolet);
   ```
   
   1. It makes *spectrum* the name of a new type; *spectrum* is termed an *enumeration* much as a **struct** variable is called a structure.
   
   2. It establishes *red*, *orange*, and so on, as symbolic constants for the integer values 0-7. These constants are called *enumerators*

3. By default, enumerators are assigned integer values starting with 0 for the first enumarator.

4. You can use an enumeration name to declare a variable of the enumeration type:
   
   ```cpp
   spectrum band;        // band a variable of type spectrum
   ```
   
   5. The only valid values that you can assign to an enumeration variable without a type cast are the enumerator values used in defining the type.
      
      ```CPP
      band = blue;      // valid, blue is an enumerator
      band = 2000;      // invalid, 2000 not an enumerator 
      ```

5. Only the assignment operator is defined for enumerations. In particular, arithmetic operations are not defined:
   
   ```C++
   band = orange;          // valid
   ++band;                 // not valid 
   band = orange + red;    // not valid, but a little tricky
   ```

6. Enumerators are of integer type and can be promoted to type **int**, but **int** types are not converted automatically to the enumeration type.

7. You can assign an **int** value to an **enum**, provided that the value is valid and that you use an explicit type cast:
   
   ```C++
   band = spectrum(3);              // typecast 3 to type spectrum
   ```
   
   ## Setting Enumerator Values

8. You can set enumerator values explicitly by using the assignment operator:
   
   ```C++
   enum bits{one = 1, two = 2, four = 4, eight = 8};
   ```

9. The assigned values must be integers. You also can define just some of the enumerators explicitly:
   
   ```C++
   enum bigstep{fiest, second == 100, third};
   ```
   
   In this case, *first* is 0 by default. Subsequent uninitialized enumerators are larger by one than their predecessors. So, *third* would have the value 101.

10. You can create more than one enumerator with the same value:
    
    ```C++
    enum{zero, null = 0, one, numero_uno = 1};
    // both zero and null are 0, and both one and numero_uno are 1/
    ```

11. In earlier version of C++ , you could assign only **int** values (or values that promote to **int**) to enumerators, but now you can use type **long** and **long long** values.   

## Value Ranges for Enumerations

C++ has expanded the list of valid values that can be assigned to an enumeration variable through the use of a type cast.Each enumeration has a range, and you can
assign any integer value in the range, even if it’s not an enumerator value, by using a type cast to an enumeration variable.

# Pointers and the Free Store

1. **Pointer**——holds the address of a value. 
   1. the name of the pointer represents the location
   2. applying the * operator, called the **indirect value** or the **dereferencing** operator, yields the value at the location.

## Declaring and Initializing Pointers

1. A computer needs to keep track of the type of value to which a pointer refers. For example, the address of a char typically looks the same as the address of a double, but char and double use different numbers of bytes and different internal formats for storing values。

2. This states that the combination *\*p_updates* is type **int**. Because you use the * operator by applying it to a pointer, the  *p_uodates* variable itself must be a pointer.     
   
   ```C++
   int* updates;
   ```
   
   1. *p_updates* points to type **int**;
   2. the type for *p_updates* is pointer-to-int, or, more concisely,**int \***;
   3. *p_updates* is a pointer (an address)， and *\*p_updates* is an **int** and not a pointer 

3. The following declaration creates one pointer （p1) and one ordinary **int**(p2):
   
   ```C++
   int* p1, p2;
   ```
   
   YOu need an * for each pointer variable name.

4. You can use a declaration statement to initialize a pointer. In that case, the pointer, not the pointed-to value, is initialized .

## Pointer Danger

When you create a pointer in C++, the computer allocates memory to hold an address, but it does not allocate memory to hold the data to which the address points.     

```C++
long* fellow;        // create a pointer-to-long
*fellow = 223323;    // place a value in never-never land
```

Because *fellow* wasn't initialized, it could have any value. Whatever that value is, the program interprets it as the address at which to store 223323

**Caution**
Pointer Golden Rule: Always initialize a pointer to a definite and appropriate address before you apply the dereferencing operator (*) to it.

## Pointers and Numbers

1. Pointers are not integer types, even though computers typically handle addresses as integers. 
2. Pointers are distinct types from integers.        
   1. Integers are numbers you can add, subtract, divide, and so on.
   2. A pointer describes a location, and it doesn't make sense.
3. you can't simply assign an integer to a pointer.
   1. the left side is a pointer to **int**, but the right side is just an integer, nothing in the statement tells the program that this number is an address:
      
      ```C++
      int* pt;
      pt = 0xB8000000;     // type mismatch
      ```
   2. IF you want to use a numeric value as an address, you should use a type cast to convert the number to the appropriate address type:
      
      ```C++
      int* pt;
      pt = (int* )0xB8000000;    // type now match 
      ```
   3. Now both sides of the assignment statement  represent address of integers, so the assignment is valid. Note that just because it is the address of a type **int** value doesn't mean that pt itself is type **int**. For example, one might have a platform for which type **int** is a 2-byte value and the addresses are 4-byte values.

## Allocating Memory with new

1. The variables are named memory allocated during compile time, and each pointer merely provides an alias for memory you could access directly by name anyway.

2. The true worth of pointers comes into play when you allocate unnamed memory during runtime to hold values.

3. In C, you can allocate memory with the library function **malloc()**. You can still do so in C++, but C++ also has a better way: the **new** operator.

4. this **new** technique by creating unnamed runtime storage for a type **int** value and accessing the value with a pointer.The key is the C++ **new** operator.You tell **new** for what data type you want memory; **new** finds a block of the correct size and returns the address of the block.You assign this address to a pointer, and you’re in business.
   
   ```C++
   int* pn = new int;
   ```

5. The **new int** part tells the program you want some new storage suitable for holding an **int**. The **new** operator uses the type to figure out how many bytes are needed. Then it finds the memory and return the address. Next, you assign the address to *pn*, which is declared to be of type pointer-to-int. 

6. Compare with assigning the address of a variable to a pointer:
   
   ```C++
   int higgens;
   int* pt = &higgens;
   ```
   
   In both cases(*pn* and *pt*), you assign the address of an **int** to pointer. We say that *pn* points to *a data object*, it means any block of memory allocated for a data item.

7. The general form for obtaining and assigning memory for a single data object, which can be a struct as well as a fundamental type
   
   ```C++
   typeName* pointer_name = new typeName;
   ```

8. You use the data type twice: once to specify the kind of memory requested and once to declare a suitable pointer. Of course, if you’ve already declared a pointer of the correct type, you can use it rather than declare a new one .

9. Program Notes
   
   ```C++
     // use_new.cpp -- using the new operator
     #include<iostream>
     int main()
     {
        using namespace std;
        int nights = 1001;
        int* pt = new int;              // allocate space for an int
        *pt = 1001;                     // store a value there
   
        cout << "nighs value = ";
        cout << nights << ": location " << &nights << endl;
        cout << "int ";
        cout << "value = " << *pt << ": location = " << pt << endl;
   
        double* pd = new double;        // allocate space for a double
        *pd = 10000001.0;               // store a double there
   
        cout << "double ";
        cout << "value = " << *pd << ": location = " << pd << endl;
        cout << "location of pointer pd: " << &pd << endl;
        cout << "size of pt = " << sizeof(pt);
        cout << ": size of *pt = " << sizeof(*pt) << endl;
        cout << "size of pd = " << sizeof pd;
        cout << ": size of *pd = " << sizeof(*pd) << endl;
        return 0;
     }
   ```
   
   1. The program uses **new** to allocate memory for the type **int** and type **double** data object. 
   2. This occurs while the program is running.
   3. The pointers *pt* and *pd* point to these two data objects.
   4. Without them, you cannot access those memory locations.
   5. With them, you can use *\*pt* and *\*pd* just as you would use variables.
   6. You  assign values to *\*pt* and *\*pd*  to assign values to the **new** data object.Similarly, you print *\*pt* and *\*pd* to display those values.
   7. Demonstrates one of the reasons you have to declare the type a pointer points to. An address in itself reveals only the beginning address of the object stored, not its type or the number of bytes used.
   8. Look at the addresses of the two values.They are just numbers with no type or size information.
   9. Also note that the size of a pointer-to-**int** is the same as the size of a pointer-to-**double**,both are just addresses.
   10. *use_new.cpp* declares the pointer type, the program knows that *\*pd* is a **double** value of 8 bytes, whereas *\*pt* is an **int** value of 4 bytes.
   11. The ordinary variables have their values stored in a memory region called the **stack**, whereas the memory allocated by **new** is in a region called the **heap** or **free store**. 
       
       > **Out of Memory**     
       > It's possible that a computer might not have sufficient memory available to satisfy a **new** request. When that is the case , **new** normally responds by throwing an exception, an error-handing technique.    
       > In older implementation **new** return the value 0. In C++, a pointer with the value 0 is called the *null* pointer.    
       > C++ guarantees that the *null* pointer never points to valid data, so it is often used to indicate failure for operators or functions that otherwise return usable pointers.

## Freeing Memory with delete

1. The **delete** operator, which enables you to return memory to the memory pool when you are finished with it.Memory that you return, or **free**, can then be reused by other parts of the program.You use **delete** by following it with a pointer to a block  of memory originally allocated with **new**:
   
   ```C++
   int *ps = new int;         // allocate memory with new
   ...
   delete ps;                // free memory with delete when done
   ```
   
   This removes the memory to which *ps* points; it doesn't remove the pointer *ps* itself.You can reuse *ps* , for example ,to point to another **new** allocation.  
2. You should always balance a use of **new** with a use of **delete**;Otherwise, you can wind up with a *memory leak* —— memory has been allocated but can no longer be used .If a memory leak grows too large, it can bring a program seeking more memory to a halt.
3. You should not attempt to free a block of memory that you have previously freed.The C++ Standard says the result of such an attempt is undefined , meaning that the consequences could be anything.
4. You cannot use **delete** to free memory created by declaring ordinary variable
   
   ```C++
   int *ps = new int;      // ok
   delete ps;              // ok
   delete ps;              // not ok now
   int jugs = 5;           // ok
   int *pi  = &jugs;       // ok
   delete pi;              // not allowed, memory not allocated by new
   ```
   
   > Caution
   > You should use **delete** only to free memory allocated with **new**. However, it is safe to apply >**delete** to a null pointer. 
5. Note that the critical requirement for using **delete** is to use it with memory allocated by **new**.This doesn't mean you have to use the same pointer you used with **new**; instead, you have to use the same address:
   
   ```C++
   int *ps = new int;            // allocate memory
   int *pq = ps;                 // set second pointer to same block
   delete pq;                    // delete with second pointer
   ```
   
   Ordinarily, you won't create two pointers to the same block of memory because that raises the possibility that you will mistakenly try to delete the same block twice.

## Using new to Create Dynamic Arrays

1. Allocating the array during compile time is called *static binding* , meaning that the array is built in to the program at compile time. 
2. With **new** ,you can create an array during runtime if you need it and skip creating the array if you don't need it. Or you can select an array size after the program is running.This is called *dynamic binding*, meaning that the array is created while the program is running.Such an array is called a *dynamic array*.
3. With static binding, you must specify the array size when you write the program/
4. With dynamic binding, the program can decide on an array size while the program runs.

### Creating a Dynamic Array with new

1. you tell **new** the type of array element and number of elements you want.The syntax requires that you follow the type name with the number of elements, in brackets.
   
   ```C++
   int *psome = new int[10];           // get a block of 10 ints
   ```
   
   The **new** operator returns the address of the first element of the block.
2. When freeing the array:
   
   ```C++
   delete [] psome;                    // free a dynamic array
   ```
   
   The presence of the brackets tells the program that it should free the whole array, not just the element pointed to by the pointer.
3. Note that the brackets are between **delete** and the pointer. If you use **new** without brackets, you should use **delete** without brackets.If you use **new** with brackets, you should use **delete** with bracket.
   
   ```C++
   int *pt = new int;
   short *ps = new short[500];
   delete [] pt;      // effect is undefined, don't do it
   delete ps;         // effect is undefined, don't do it
   ```
4. Note that *psome* is a pointer to a single int, the first element of the block. It's your responsibility to keep track of how many elements are in the block. That is, because the compiler doesn't keep track of the fact that *psome* points to the first of 10 integers, you have to write your program so that it keeps track of the number of elements.
5. Actually, the program does keep track of the amount of memory allocated so that it can be correctly freed at a later time when you use the **delete []** operator. But that information isn't publicly avaiable; you can't use the **sizeof** operator , for example, to find the number of bytes in a dynamically allocated array.
6. The general form for allocating and assigning memory for an array is this:      
   **type_name *pointer_name = new type_name [num_elements];**
7. Invoking the **new** operator secures a block of memory large enough to hold *num_elements* elements of type *type_name*, with *pointer_name* pointing to the first elements.

### Using a Dynamic Array

1. you can use *pointer_name* in many of the same ways you can use an array name.
   ```C++
   int *psome = new int[10];     // get a block of 10 ints
2. Because psome points to the first element of the array, *psome is the value of the first element.That leaves nine more elements to access.
3. you can use psome[0] instead of *psome for the first element, psome[1] for the second element, and so on.

## Pointer, Arrays, and Pointer Arithmetic

1. The near equivalence of pointers and array names stems from *pointer arithmetic* and how C++ handles arrays internally.

2. Adding one to an integer variable increases its value by one, but adding one to a pointer variable increases its value by the number of bytes of the type to which it points.
   Adding one to a pointer to double adds 8 to the numeric value on systems with 8-byte double
   Adding one to a pointer-to-short adds two to the pointer value if short is 2 bytes.

3. In most contexts, C++ interprets the name of an array as the address of its first element.

4. In general, wherever you use array notation,C++ makes the following conversion:               
   **arrayname[i] becomes *(arrayname + i)**
   And if you use a pointer instead of an array name, C++ makes the same conversion:
   **pointername[i] becomes *(pointername + i)**

5. Thus, in many respects you can use pointer names and array names in the same way. You can use the array brackets notation with either. You can apply the dereferencing operator (*) to either. In most expressions, each represents an address.
   One difference is that you can change the value of a pointer, whereas an array name is a constant:
   
   ```C++
   pointername = pointername + 1;     // valid
   arrayname = arrayname + 1;         // not allowed
   ```
   
   A second difference is that applying the **sizeof** operator to an array name yield the size of the array, but applying **sizeof** to a pointer yield the size of the pointer, even if the pointer points to the array.
   
   ```C++
   24 = size of wages array << displaying sizeof pw
   4 = size of pw pointer << displaying sizeof pw
   ```
   
   This is one case in which C++ doesn't interpret the array name as an address.
   
   > The Address of an Array
   > Taking the address of an array is another case in which the name of an array is not interpreted as its address. 
   > The name of the array is interpreted as the address of the first element of an array, whereas applying the address operator yields the address of the whole array:
   > 
   > ```C++
   > short tell[10];          // tell an array of 20 bytes
   > cout << tell << endl;    // display &tell[0]
   > cout << &tell << endl;   // display address of whole array
   > ```
   > 
   > Numerically, these two addresses are the same, but conceptually *&tell[0]*, and hence *tell*, is the address of a 2-bytes block of memory, whereas *&tell* is the address of a 20-byte block of memory.    
   > The expression *tell + 1* adds 2 to the address value, whereas *&tell + 1* adds 20 to the address value.
   > Another way of expressing this  is to say that *tell* is type pointer-to-*short*, or *short \**, and *&tell* is type pointer-to-array-of-20-*short*s, or *short (\*)[20]*

### Using new to Create Dynamic Structures

1. You need to allocate space for only as many structures as a program needs during a particular run. Again, the **new** operator is the tool to use. With it , you can create dynamic structures.Again, *dynamic* means the memory is allocated during runtime, not at compile time.
2. Incidentally, because classes are much like structures, you are able to use the techniques you'll learn in this section for structures with classes,too.
3. Using **new** with structures has two parts:
   1. creating the structure 
   2. accessing its members.
4. To create a structure, you use the structure type with **new** .For example, to create an unnamed structure of the *inflatable* type and assign its address to a suitable pointer.
   
   ```C++
   inflatable *ps = new inflatable;
   ```
   
   This assign to *ps* the address of a chunk of free memory large enough to hold a structure of the *inflatable* type.
5. The tricky part is accessing members. When you create a dynamic structure, you can't use the dot membership operator with the structure name because the structurehas no name. C++ provide an operator just for this situation: the arrow membership operator (->).This operator, formed by typing a hyphen and then a greater-than symbol, does for pointers to structures what the dot operator does for structure names.
   
   > **Tip**                         
   >  If the structure identifier is the name of a structure, use the dot operator. If the identifier is a pointer to the structure, use the arrow operator.
6. A second, uglier approach to accessing structure members is to realize that if ps is a pointer to a structure, then *\*ps* represents the pointed-to value—the structure itself.Then, because *\*ps* is a structure, *\*(\*ps).price* is the price member of the structure. C++’s operator precedence rules require that you use parentheses in this construction.
7. This function reads the input into a large temporary array and then uses **new []** with an appropriate size to create a chunk of memory sized to fit to the input string.Then the function returns the pointer to the block.This approach could conserve a lot of memory for programs that read in a large number of strings. (In real life, where many of us live, it would be easier to use the string class, which has the use of **new** and **delete** built in to its design.)

# Automatic Storage, Static Storage, and Dynamic Storage

1. C++ has three ways of managing memory for data, depending on the method used to allocated memory: automatic storage, static storage, and dynamic storage, sometimes called the *free store* or *heap*. C++11 adds a fourth form called *thread storage*

## Automatic Storage

1. Ordinary variable defined inside a function use *automatic storage* and are called *automatic variable*.These terms mean that the variable come into existence automatically when the function containing them is invoked, and they expire when the function terminates.
2. Actually，automatic values are local to the block that contains them. A *block* is a section of code enclosed between braces. If you define a variable inside one of those blocks, it exists only while the program is executing statements inside the block.
3. Automatic variable typically are stored on a *stack*. This means that when program execution enters a block of code, its variables are added consecutively to the stack in memory and then are freed in reverse order when execution leaves the block.(This is called a *last-in, first-out*, or *LIFO*, process.) So the stack grows and shrinks as execution proceeds.

## Static Storage

1. Static storage is storage that exists throughout the execution of an entire program. There are two ways to make a  variable static.

2. One is to define it externally , outside a function. The other is to use the keyword **static** when  declaring a variable:
   
   ```C++
   static double fee = 56.50;
   ```
   
   Under K&R C, you can initialize only static arrays and structures,  whereas C++ Release 2.0 (and later) and ANSI C allow you to initialize automatic arrays and structures, too. But some C++ implementations do not yet implement initialization for automatic arrays and structures.

3. The main point you should note now about automatic and static storage is  that these methods rigidly define the lifetime of a variable. Either the variable exists for the entire duration of a program (a static variable ) or it exists only while a particular function is being executed (an automatic variable)

## Dynamic storage

1. The **new** and **delete** operatore provide a more flexible approach than automatic and static variable.They manage a pool of memory , which C++ refers to as the **free store** or **heap**. 

2. This pool is separate from the memory used for static and automatic variable. 

3. **new** and **delete** enable you to allocate memory in one function and free it in another. Thus, the lifetime of the data is not tied arbitrarily to the lift of the program or the life of a function.

4. Using **new** and **delete** together gives you much more control over how a program uses memory than does using ordinary variables.However , memory management becomes more complex. In a stack, the automatic addition and removal  mechanism result in the part of memory in use always being contiguous. But the interplay between **new** and **delete** can leave holes in the free store, making keeping track of where to allocate new memory requests more difficult.
   
   > **Stacks, Heaps, and Memory Leaks**
   > 
   > If you don't call **delete** after creating a  variable on the free store (or heap).The variable or construct dynamically allocated on the free store continues to persist if **delete** is not called, even though the memory that contains the pointer has been freed due to rules of scope and object lifetime.
   > 
   > In essence, you have no way to access the construct on the free store becauese the pointer to the memory that contains it is gone.You have now created a *memory leak*. Memory that has been leaked remains unusable  through the life of the program;it’s been allocated but can’t be deallocated.
   > In extreme (though not uncommon) cases, memory leaks can be so severe that they use up all the memory available to the application, causing it to crash with an out-of-memory error. In addition, these leaks may negatively affect some operating systems or other applications running in the same memory space, causing them, in turn, to fail.



# Combinations of Types

This chapter has introduced arrays, structures, and pointers. These can be combined in various ways.

## starting with a structure:

```C++
struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc.*/
};
```

1. We can create variable of this type:
   
   ```C++
   antarctica_year_end s01, s02, s03;    // s01, s02, s03 are structures
   ```

2. We can then access members using the membership operator:
   
   ```C++
   s01.year = 1998;
   ```

3. We can create a pointer to such a structure:
   
   ```C++
   antarctica_years_end *pa = &s02;
   ```
   
   Provide the pointer has been set to a valid address, we then can use the indirect membership operator to acceess membership:
   
   ```C++
   pa->year = 1999;
   ```

4. We can create arrays of structures:
   
   ```C++
   antarctica_years_end trio[3];     // array of 3 strutctures
   ```
   
   We then can use the membership operator to access members of an element:
   
   ```C++
   trio[0].year = 2003;       // array of 3 structure
   ```
   
   Because an array name is a pointer, we also can use the indirect membership operator:
   
   ```C++
   (trio+1)->year = 2004;      // same as trio[1].year =2004
   ```

5. We can create an array of pointers:
   
   ```C++
   const antarctica_years_end *arp[3] ={&s1, &s2, &s3};
   ```
   
   If *arp* is an array of pointers, then *arp[1]* must be a pointer, and we can use the indirect membership operator with it to access a member:
   
   ```C++
   std::cout << arp[1]->year << std::endl;
   ```

6. We can create a pointer to such an array:
   
   ```C++
   const antarctica_years_end **pa = arp;
   ```
   
   Here, *arp* is the name of an array; hence, it is the address of its first element. But its first element is a pointer, so *ppa* has to be a pointer to a pointer 

# Array Alternatives

## The **vector** Template Class

1. The **vector** template class is similar to the **string** class in that it is a dynamic array.You can set the size of  a **vector** object during runtime, and you can append new data to the end or insert new data in the middle.

2. Basically, it's an alternative to using **new** to create a dynamic array. Actually , the **vector** class does use **new** and **delete** to manage memory, but it does so automatically.

3. A few basic practical matters
   
   1. first, to use a **vector** object, you need to include the **vector** header file.
   
   2. The **vector** identifier is part of the **std** namespace, so you can use a **using** directive, a **using** declaration, or **std::vector**
   
   3.  templates use a different syntax to indicate the type of data stored.
   
   4. the **vector** class uses a different syntax to indicate the number of elements.
      
      ```C++
      #include<vector>
      ...
      using namespace std;
      vector<int> vi;        // create a zero-size array of int
      int n;
      cin >> n;
      vector<double> vd(n);  // create an array of n doubles
      ```

4. In general, the following declaration creates a **vector** object *vt* that can hold *n_elem_* elements of type *typeName*:

5. The parameter *n_elem* can be an integer constant or an integer variable.



## The array Template Class (C++11)

1. The **vector** class has more capabilities than the built-in array type, but this comes at a cost of slightly less efficiency.

2. If you need is a fixed -size array, it could be advantageous to use the built-in type.However, that has its own costs of lessened convenience and safety.

3. C++11 responded to this  situation by adding the **array**  template class, which is part of the **std** namespace.Like the built-in type, an **array** object has a fixed size and uses the stack (or else static memory allocation) instead of the free store, so it shares the efficiency of built-in arrays.To this it adds convenience and additional safety.To create an **array** object, you need to include the **array** header file.The syntax is a bit different from that for a vector:

```C++
#include<array>
...
using namespace std;
array<int, 5> ai;        // create array object of 5 ints
array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
```

4. More general， the following declaration creates an **array** object *arr* with *n_elem* elements of *typeName*:
   
   ```C++
   array<typeName, n_elem> arr;
   ```
   
   Unlike the case for **vector**, *n_elem* can't  be a variable/
   
   With C++11, you can use list-initialization with **vector** and **array** object. 

5. if you use **at()**, an invalid index is caught during runtime and the program, by default, aborts.This added checking does come at the cost of increased run time, which is why C++ gives you the option of using either notation.More than that, these classes offer ways of using objects that reduce the chances of accidental range errors