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
   3. That means the element takes on takes on 