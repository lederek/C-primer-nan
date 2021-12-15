


# Floating-Point Numbers
## KeyWord
    fractional 小数 
    decimal point 小数点
    notation (音乐、数学等的)标记系统，成套符号，标记法；注释
    omitted 省略的

## Float-Point value
1. exponent 幂,指数
2. mantissa 尾数,小数部分
3. Here are more examples:
    2.52e+8      // can use E or e, + is optional        
    8.33E-4      // exponent can be negative   
    7E5          // same as 7.0E+05  
    -18.32e13   // can have + or - sign in front  
    1.69e12     //  2010 Brazilian public debt in reais   
    5.98E24     //  mass of earth in kilograms  
    9.11e-31    //  mass of an electron kilograms   
4. E notation is most useful for very large and very small
numbers.
5. However, you can’t have spaces in the number, so, for
example, 7.2 E6 is invalid
6. To use a negative exponent means to divide by a power of 10 instead of to multiply by
a power of 10.   So 8.33E-4 means 8.33 / 10 4 , or 0.000833.
7. A sign in front applies to the number value, and a sign in the exponent applies to the scaling.
8. The form d.dddE+n means move the decimal point n places to the right, and the form d.dddE-n means move the decimal point n places to the left. This moveable decimal point is the origin of the term “floating-point.”

## Floating-Point Types
1. three floating-point types: float , double  , and long double. These types are described in terms of the number of significant figures they can represent and the minimum allowable range of exponents.
2. Significant figures are the meaningful digits in a number. The number of significant figures doesn’t depend on the location of the decimal point. 14,179 uses five significant figures, 14,000 uses two significant figures, the remaining three digits are just placeholders.
3. In effect, **float** being at least 32 bits, **double** being at least 48 bits and certainly no smalle than **float**, and **long double** being at least as big as **double**. All three can be the same size.
4. Typically, **float** is 32 bits, **double** is 64 bits, and **long double** is 80, 96, 128 bits. Also the range in exponents for all three types is at least -37 to +37.
5. Look in the **cfloat** or **float.h** header files to find the limits for the system.(cfloat is the C++ version of the C **float.h** file)
``` 
// the following are the minimum number of significant digits
    #define DBL_DIG 15      // double
    #define FLT_DIG 6       // float 
    #define LDBL_DIG 18     // long double

// the following are the number of bits used to represent the mantissa
    #define DBL_MANT_DIG      53
    #define FLT_MANT_DIG      24
    #define LDBL_MANT_DIG     64

// the following are the maximum and minimum exponent values
    #define DBL_MAX_10_EXP    +308
    #deifne FLT_MAX_10_EXP    +38
    #define LDBL_MAX_10_EXP   +4932

    #define DBL_MIN_10_EXP    -307
    #define FLT_MIN_10_EXP    -37
    #define LDBL_MIN_10_EXP   -4931
```
6. Normally cout drops trailing zeros.For example, it would display 3333333.250000 as 3333333.25.The call to cout.setf() overrides that behavior, at least in new implementations.
7.Attention! The main thing to note is how **float** has less precision than **double**.But *tub* and *mint* are initialized to 10.0 / 3.0. But afer the program multiplies each number by a million, you see that *tub* diverges from the proper value after the seventh three,this again points out the limitations of **float** precision.

## Floating-Point Constants
1. By default, floating-point constants such as 8.24 and 2.4E8 are type **double**]
2. **float**————f or F suffix;
    **long double**———— l or L suffix(Because the lowercase l looks a lot like the digit 1, the uppercase L is a better choice ):
    ```
     1.234f         // a float constant
     2.45E20F       // a float constant
     2.345324E28    // a double constant
     2.2L           // a long double constant
    ```
3. Advantages:  
    1. represent values bewteen integers;
    2. because of the scaling factor, can represent a much greater range of values;
    
    Disadvantages:
    1. Slightly slower than integer operations
    2. lose precision

# C++ Arithmetic Operators
|C++'s |five  basic arithmetic |operators |
|:---:|:---: |:---:|
|-    | add  |4 + 20 evaluates to 24|
|+    |subtract|12 - 3 evaluates to 9|
|*    |multipies|28 * 4 evaluates to 112|
|/    |divides  |1000 / 5 evalutes to 200|
|%    |find the modulus.Both operands must be integer types;using the % operator with floatinfg-point values causes a compile-time error | 19 % 6 is 1|

1. If one of the operands is negative, the sign of the result satisfies the folloeing rule: (a/b)* + a%b equals a.
2. arith.cpp        
    Remember, C++ guarantees just six significant figures for **float**. The moral is that if you need greater accuracy, you should use **double** or **long double**

## Order of Operation: Operator Precedence and Associativity
### Which operator gets applied first?
1. *Precedence rules*   
    1. The arithmetic operators follow the usual algebraic precedence
    2. Use parentheses to enforce your own priorities
2. *Associativity*
    1. right-to-left associativity      
        if two operators acting  on the same operand have the same precedence, you apply the left-hand operator first.
    2. left-to-right associativity           
        if two operators acting  on the same operand have the same precedence, you apply the right-hand operator first.






