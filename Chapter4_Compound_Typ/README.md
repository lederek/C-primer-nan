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
   +  The type of value to be stored in each element
   +  The name of the array
   +  The number of elements in the array
3. Accomplish this in C++ by modifying the declaration for a simple variable and adding brackets that contain the number of elements.
   ``` C++
   short months[12]; // creates array of 12 short elements,each of which can hold a type **short** value
   ```
4. This ia the general form for declaring an array:
   ``` C++
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
   ``` C++
   int cards[4] = {3, 6, 8, 10};    // okay
   int hand[4];                     // okay
   hand[4] = {5, 6, 7,  9};         // not allowed
   hand = cards;                    // not allowed
   ```
2. When initializing an array, you can provide fewer values than array elements.
   ``` C++
   float hotelTips[5] = {5.0, 2.5};
   ```
3. If you partially initialize an array, the compiler sets the remaining elements to **zero**.
4. Initialize all the elements of an array to **zero** —— just explicitly initialize the first element to **zero** and then let the compiler initialize the remaining elements to zero.
   ``` C++ 
   float totals[500] = {0};
   ```
5. If you leave the square brackets([]) empty when you initialize an array, the C++ compiler counts the elements for you.
   ```C++
   short things[] = {1, 5, 3, 8};
   // The compiler makes things an array of four elements
   ```
6. NOTE: Often , letting the comiler count the number of elements is poor practice because its count can be different from what you think it should be. And if your main concern is that the program, not you, knows how large an array is, you can do something like this:
      ``` C++
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