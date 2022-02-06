# 第七章    函数——C++的编程模块

## 本章内容：

+ 函数基本知识

+ 函数原型

+ 按值传递函数参数

+ 设计处理数组的函数

+ 使用const指针参数

+ 设计处理文本字符串的函数

+ 设计处理结构的函数

+ 设计处理string对象的函数

+ 调用自身的函数（递归）

+ 指向函数的指针

## 复习函数的基本知识

1. 要使用C++函数，必须完成如下工作：
   
   + 提供函数定义
   
   + 提供函数原型
   
   + 调用函数

2. 库函数是已经定义和编译好的函数，同时可以使用标准头文件提供其原型， 只需正确地调用这种函数即可。

### 定义函数

1. 分成两类：没有返回值的函数和有返回值的函数。
   
   1. 没有返回值的函数被称为**void**函数，其通用格式如下：
      
      ```C++
      void functionName(parameterList)
      {
          statements(s)
          return;        // optional
      }
      ```
      
      *parameterList* 指定了传递给函数的参数类型和数量，可选的返回语句标记了函数的结尾；否则，函数将在右花括号处结束。
   
   2. 有返回值的函数将生成一个值，并将它返回给调用函数。函数的类型被声明为返回值得类型，其通用格式如下：
      
      ```C++
      typeName functionName(parameterList)
      {
          statement(s)
          return value;    // value is type cast to type typeName
      }
      ```
      
      + 对于有返回值的函数，必须使用返回语句，以便将值返回给调用函数。值本身可以是常量、变量、表达式， 只是其结果的类型必须为typeName类型或可以被转换为typeName, 然后，函数将最终的值返回给调用函数。
      
      + C++对于返回值类型的限制：不能是数组，但可以是其他任何类型——整数、浮点数、指针、结构和对象
      
      + 函数将在执行返回语句后结束。若函数包含多条返回语句，则函数在执行遇到的第一条返回语句后结束

### 函数原型和函数调用

1. 为什么需要原型
   
   + 原型描述了函数到编译器的借口，即将函数返回值的类型以及参数的类型和数量告诉编译器。
   
   + C++允许将一个程序放在多个文件中，单独编译这些文件，然后再将它们组合起来。在这种情况下，编译器在编译main()时，可能无权访问函数代码
   
   + 避免使用函数原型的唯一方法：在首次使用函数之前定义它

2. 原型的语法
   
   + 函数原型是一条语句，因此必须以分号结束。
   
   + 获取原型最简单的方法：复制函数定义中的函数头，并添加分号。函数原型不要求参数列表，可以包括变量名，也可以不包括。
   
   + 原型中的变量名相当于占位符，因此不必与函数定义中的变量名相同。
   
   > C++原型与ANSI原型
   > 
   > ANSI C借鉴了C++中的原型，区别如下：
   > 
   > + ANSI C中的原型是可选的，但在C++ 中，原型必不可少
   > 
   > + 在C++ 中，括号为空与在括号中使用关键字**void** 是等效的——意味着函数没有函数
   > 
   > + 在ANSI C中，括号为空意味着不指出参数——这意味着将在后面定义参数列表
   > 
   > + 在C++ 中，不指定参数列表时应使用省略号：
   >   
   >   通常，仅当与接受可变参数的C函数（如printf()）交互时才需要这样做
   >   
   >   ```C++
   >   void say_bye(...);      // C++ abdication of responsibility
   >   ```

3. 原型的功能
   
   它们可以极大地降低程序出错的几率。具体来说，
   
   + 编译器正确处理函数返回值；
   
   + 编译器检查使用的参数数目是否正确；
   
   + 编译器检查使用的参数类型是否正确。不正确则转换为正确的类型
   
   在编译阶段进行的原型化被称为静态类型检查（static type checking)。可以看出，静态类型检查可捕获许多在运行阶段非常难以捕获的错误。

## 函数参数和按值传递

1. C++ 通常按值传递参数，这意味着将数值参数传递给函数，而后者将其付给一个新的变量。

2. 用于接受传递值的变量被称为形参。传递给函数的值被称为实参。

3. C++标准使用argument来表示实参，使用parameter 来表示形参。

4. 在函数中声明的1变量（包括参数）是该函数私有的。在函数被调用时，计算机将为这些变量分配内存；在函数结束时，计算机将释放这些变量使用的内存。这样的变量被称为局部变量，因为它们被限制在函数中。有助于确保数据的完整性。这样的变量也被称为自动变量，因为它们是在程序执行过程中自动被分配和释放的。

### 多个参数

1. 函数可以有多个参数。在调用函数时，只需使用逗号将这些参数分开即可
   
   ```C++
   n_char('R'， 25)；
   ```

2. 同样在定义函数时，也在函数头中使用逗号分隔得参数声明列表
   
   ```C++
   void n_chars(char c, int n)        // two arguments
   ```

3. 如果函数的两个参数的类型相同，必须分别指定每个参数的类型，不能像声明常规变量将声明组合在一起
   
   ```C++
   void fifi(float a, float b)    // declare each variable separately
   void fufu(float a, b)          // NOT acceptable
   ```

4. 和其他函数一样 ，只需添加分号就可以得到该函数的原型：
   
   ```C++
   void n_chars(char c, int n);    // prototype , style 1
   ```

5. 和一个参数一样，原型中的变量名不必与定义中的变量名相同，且可省略
   
   ```C++
   void n_chars(char, int);        // prototype,style 2
   ```

6. 然而，提供变量名将使原型更容易丽姐，尤其是两个参数的类型相同时，变量名就可以提醒参数和参数间的对应关系
   
   ```C++
   double melon_density(double weight, double volume);
   ```

### 另外一个接受两个参数的函数

```C++
// lotto.cpp -- probability of winning
#include<iostream>
// Note: some implementations require double instead of long double
 long double probability(unsigned numbers, unsigned picks);
 int main()
 {
     using namespace std;
     double total, choices;
     cout << "Enter the total number of choices on the game card and\n"
             "the number of picks allowed:\n";
     while ((cin >> total >> choices) && choices <= total)
     {
         cout << "You have one chance in ";
         cout << probability(total, choices);     // compute the odds
         cout << " of winning.\n ";
         cout << "Next two numbers (q to quit): ";
     }
     cout << "bye\n";
     return 0;
 }

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0; // here come some local variable
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    return result;
}
```

## 函数和数组

### 函数如何使用指针来处理数组

1. C++将数组名解释为其第一个元素的地址：
   
   **cookies == &cookies[0]  // array name is address of first element**

2. 上述规则的例外：
   
   + 数组声明使用数组名来标记存储位置
   
   + 对数组名使用**sizeof** 将得到整个数组的长度（以字节为单位）
   
   + 将地址运算符&用于数组名时，将返回整个数组的地址，例如&cookies 将返回一个32字节内存块的地址（如果int长4字节）

3. 在C++中，当且仅当用于函数头或函数原型中，int *arr 和 int  arr[ ]的含义才是相同的。都意味着arr是一个int指针

4. 将指针（包括数组名）加1，实际上是加上了一个与指针指向的类型的长度（以字节为单位）相等的值。对于遍历数组而言，使用指针加法和数组下标时等效的
   
   ```C++
   arr[i] = *(ar + i)        // value in two notation
   &arr[i] = ar + i          // addresses in two notation
   ```

### 将数组作为参数意味着什么

1. 并没有将数组内容传递给函数，而是将数组的位置（地址）、包含的元素种类（类型）以及元素数目（n变量）提交给函数

2. 传递常规变量时，函数将使用该变量的拷贝；但传递数组时，函数将使用原来的数组

3. 将数组类型和元素数量告诉数组处理函数，请通过两个不同的额参数来传递它们：
   
   ```C++
   void fillArray(int arr[], int size);    // prototype
   ```
   
   而不要试图使用方括号表示法来传递数组长度：
   
   ```C++
   void fillArray(int arr[size]);        // NO --- bad prototype
   ```

### 更多数组函数示例

1. 为防止函数无意中修改数组的内容，可在声明形参时使用关键字const
   
   ```C++
   void show_array(const double ar[], int n);
   // 该声明表明，指针ar指向的是常量数据，意味着不能使用ar修改该数据
   // 并不意味着原始数组必须是常量，而只是不能再show_array()中使用ar修改数据
   // 即show_array()将数组视为只读数据
   
   ar[0] += 10;     // error
   ```

```C++
// arrfun3.cpp -- array functions and const
#include<iostream>
const int Max = 5;
// function prototype
int fill_array(double arr[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value # "<< (i + 1) << ": ";
        cin >>temp;
        if (!cin)       // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;

        }
        else if (temp < 0)
             break;
        ar[i] = temp;
    }
    return i;
}

// the following function can use, but not alter
// the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property # "<< (i + 1) << ": $";
        cout << ar[i] <<endl;
    }
}

// multipies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}
```

### 使用数组区间的函数

1.对于处理数组的C++ 函数，必须将数组中的数据种类、数组的起始位置和数组中元素数量提交给它：

+ 传统的C/C++ 方法是： 将指向数组起始处的指针作为一个参数，将数组长度作为第二个参数(指针指出数组的位置和数据类型), 

+ 另一种给函数提供所需信息的方法：指定元素区间（range）,可以通过传递两个指针来完成：一个指针标识数组的开头，另一个指针标识数组的尾部。

+ 对于数组而言，标识数组结尾的参数将是指向最后一个元素后面的指针

### 指针和const

1. 让指针指向一个常量对象，防止使用该指针来修改所指向的值
   
   ```C++
   // 声明一个指向常量的指针pt:
   int age = 39;
   const int * pt = &age;
   ```
   
   该声明指出，pt指向一个const int，因此不能使用pt来修改这个值，即*pt的值是const,不能被修改。
   
   ```C++
   *pt += 1;   // INVALID because pt points to a const int
   cin >> *pt; // INVALID for the same reason
   ```
   
   pt的声明并不意味它指向的值实际上就是一个常量，而是对pt而言，这个值是常量，即是指针指向的值被“锁死”
   
   ```C++
   *pt = 20;    // INVALID because pt points to a const int
   age = 20;    // VALID because age is not declared to be const
   ```
   
   + 将const变量的地址赋给指向const的指针 (√)
   
   + 将const的地址赋给常规指针 （x）
     
     ```C++
     const float g_earth = 9.80;
     const float * pe = &g_earth;  // VALID
     // 既不能用g_earth来修改值9.80, 也不能使用pe来修改
     
     const float g_moon = 1.63;
     float * pm = &g_moon;        // INVALID
     // 禁止的原因是将g_moon的地址赋给pm，则可以使用pm来修改g_moon的值，这使得
     // g_moon的const状态很荒谬
     ```

2. 指针指向指针
   
   1. 一级间接关系，则将非const指针赋给const指针是可以的：
      
      ```C++
      int age = 30;   // age++ is a valid operation
      int *pd = &age; // *pd = 41 is a valid oepration
      const int * pt = pd;// *pt = 42 is an invalid operation
      ```
   
   2. 进入两级间接关系时，与一级间接关系一样将const和非const混合的指针赋值方式将不再安全。
      
      ```C++
      const int **pp2;
      int *p1;
      pp2 = &p1;    // not allowed ,but suppose it were
      *pp2 = &n;    // valid, both const, but sets p1 to point at n
      *p1 = 10;    // valid, but changes const n
      
      // 上述代码将非const地址(&p1)赋给const指针，因此可以使用p1来修修改const数据。
      ```
   
   3. 综上，仅当只有一层间接关系（如指针指向基本数据类型）时，才可以将非const地址或指针赋给const指针。
      
      > 注意：如果数据类型本身并不是指针，则可以将const数据或非const数据的地址赋给指向const的指针，但只能将非const数据的地址赋给非const指针

> **尽可能使用const**
> 
> 将指针参数声明为指向常量数据的指针有两条理由：
> 
> + 避免由于无意间修改数据而导致的编程错误；
> 
> + 使用const使得函数能够处理const和非const实参，否则将只能接受非const数据
> 
> 如果条件允许，则应将指针形参声明为指向const的指针

3. 将指针本身声明为常量，防止改变指针指向的位置
   
   ```C++
   int age = 39;
   const int * pt = &age;
   // 第二个声明中的const只能防止修改pt指向的值（这里是39），而不能防止修改pt的值
   // 即可以将一个新地址赋给pt:
   int sage = 80;
   pt = &sage;        // okay to point to another location
   ```
   
   使用如下方式使得无法修改指针的值：
   
   ```C++
   int sloth = 3;
   const int * ps = &sloth;    // a pointer to const int
   int * const finger = &sloth;// a const pointer to int
   // 这种声明格式使得finger只能指向sloth, 但允许使用finger来修改sloth的值
   // 中间的声明不允许使用ps来修改sloth,但允许将ps指向另一个位置
   ```

4. 声明指向const对象的const指针：
   
   ```C++
   double trouble = 2.0E30;
   const double * const stick = &trouble;
   // 其中stick只能指向trouble， 而stick不能用来修改trouble
   ```

5. 通常，将指针作为函数参数来传递时，可以使用指向const的指针来保护数据。
   
   ```C++
   void show_array(const double ar[], int n);
   // 在该声明中使用const意味着show_array()不能修改传递给它的数组中的值。
   // 只要只有一层间接关系，就可以使用这种技术。
   ```

## 函数和二维数组

1. 将二维数组作为参数的函数，必须牢记，数组名被视为其地址，即相应的形参是一个指针：
   
   ```C++
   int data[3][4] = {{1,2,3,4}, {9,8,7,6}.{2,4,6,8}};
   int total = sum(data, 3);
   // data是一个数组名，该数组有3个元素。
   // 第一个元素本身是一个数组，有4个int值组成
   // 因此data的类型是指向由(4个int组成的数组的)指针
   // 正确的原型是
   int sum(int (*ar2)[4], int size)
   // 一个由4个指向int的指针组成的数组
   // 函数参数不能是数组
   int *ar2[4]
   // 与原型含义完全相同，但可读性更强
   int sum(int ar2[][4], int size);
   // 上面两个原型都指出，ar2是指针不是数组。
   // 由于参数ar2 是指向数组的指针，在函数定义中使用它最简单的方法是将ar2看作一个
   // 二维数组的名称
   int sum(int ar2[][4], int size)
   {
       int total = 0;
       for (int r = 0; r < size; r++)
           for (int c = 0; c < 4; c++)
               total += ar2[r][c];
       return total[;]
   }
   ```

2. 可以使用数组表示法的原因如下：由于ar2指向数组(它的元素是由4个int组成的数组) 的第一个元素(元素0)，因此表达式 ar2 + r 指向编号为 r 的元素。因此ar2[r]是编号为r的元素。

3. 由于该元素本身就是一个由4个int组成的数组，因此ar2[r] 是由4个int组成的数组的名称。将下标用于数组名将得到一个数组元素，因此ar2[r][c] 是由4个int组成的数组中的一个元素， 是一个int值。

4. 必须对指针ar2执行两次解除引用，才能得到数据。最简单的方法是使用方括号两次: ar2[r][c]。 然而不考虑难看，也可以使用运算符*两次：
   
   ```C++
   ar2[r][c] == *(*(ar2 + r) + c) // same thing
   ```
   
   为理解这一点，读者可以从内向外解析各个表达式的含义
   
   ```C++
   ar2            // pointer to first row of an array of 4 int
   ar2 + r        // pointer to row r (an array of 4 int)
   *(ar2 + r)     // row r (an array of 4 int, hence the name of an array)
            // thus a pointer to the first int in the row, i.e., ar2[r]
   *(ar2 + r) + c // pointer int number c in row r, i.e., ar2[r]+c
   *(*(ar2+r)+c)  // value of int number c in row r, i.e. ar2[r][c] 
                   
   ```

5. sum()的代码在声明参数ar2时，没有使用const，因为这种技术只能用于指向基本类型的指针，而ar2是指向指针的指针。

## 函数和C-风格字符串

1. C-风格字符串由一系列字符组成，以空字符结尾。

### 将C-风格字符串作为参数的函数

1. 假设要将字符串作为参数传递给函数，则表示字符串的方式有三种：
   
   + char数组
   
   + 用引号括起的字符串常量( 也称字符串字面值 )
   
   + 被设置为字符串的地址的char指针

2. 将字符串作为参数来传递，实际传递的是字符串第一个字符的地址。这意味着字符串函数原型应将其表示字符串的形参声明为**char** 类型

3. C- 风格字符串与常规char 数组之间的一个重要区别：字符串有内置的结束字符。意味着不必将字符串长度作为参数传递给函数，而函数可以使用循环一次检查字符串中的每个字符，知道遇到结尾的空字符为止

### 返回C-风格字符串的函数

1. 函数无法返回一个字符串，但可以返回字符串的地址。           
   
   ```C++
   // strgback.cpp -- a function that return a pointer to char
   #include<iostream>
   char * buildstr(char c, int  n);    // prototype
   int main()
   {
       using namespace std;
       int times;
       char ch;
   
       cout << "Enter a character: ";
       cin >> ch;
       cout << "Enter a integer: ";
       cin >> times;
       char * ps = buildstr(ch, times);
       cout << ps << endl;
       delete []ps;                  // free memory
       ps = buildstr('+', 20);       // reuse pointer
       cout << ps << "-DONE-" << ps << endl;
       delete []ps;                  // free memory
       return 0;
   }
   
   // builds string made of n c characters
   char * buildstr(char c, int n)
   {
       char * pstr = new char[n + 1];
       pstr[n] = '\0';         // terminate string
       while (n-- > 0)
           pstr[n] = c;        // fill rest of string
       return pstr;
   } 
   ```

2. 要创建包含n个字符的字符串，需要能够存储n+1个字符的空间，以便能够存储空值字符。循环将循环n次，直到n减少到0

3. 在最后一轮循环开始时，n的值为1。由于n--意味着先使用这个值，然后将其递减，因此while循环测试条件将对1和0进行比较，发现测试为TRUE，循环继续。测试后，函数将n减为0，因此**pstr[0]** 是最后一个被设置为c的元素。

4. 之所以从后向前（而不是从前往后）t填充字符串，是为了避免使用额外的变量，从前向后填充的代码将与下面类似：
   
   ```C++
   int i = 0;
   while (i < n)
       pstr[i++] = c;
   ```

5. 注意，变量pstr的作用域为buildstr函数内，因此该函数结束时，pstr(而不是字符串) 使用的内存将被释放

6. 当该字符串不再需要时，使用delete释放该字符串占用的内存，然后，将ps指向为下一个字符串分配的内存块，然后释放它们

7. 这种设计的缺点是，程序员必须记住使用delete

## 函数和结构

1. 使用结构编程时，最直接的方式是像处理基本类型那样来处理结构，即将结构作为参数传递，并在需要时将结构用作返回值使用。

2. 按值传递结构有一个缺点: 若结构非常大，则复制结构将增加内存要求，降低系统运行的速度。故倾向于传递结构的地址，然后使用指针来访问结构的内容

3. C++提供了第三种选择：按引用传递

### 传递和返回结构

1. 当结构比较小时，按值传递结构最合理

2. cin是istream类的一个对象，类运算符是使用函数实现的。

### 传递结构的地址

假设要传递结构的地址而不是整个结构以节省时间和空间

```cpp
// strctptr.cpp -- functions with pointer to structure arguments
#include<iostream>
#include<cmath>

// structure templates
struct polar
{
    double distance;    // distance from origin
    double angel;       // direction from origin
};

struct rect
{
    double x;           // horizontal diatance from origin
    double y;           // vertical distance from origin
};

// prototypes
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);   // pass addresses
        show_polar(&pplace);               // pass address
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

// show polar coordinates, converting angle to degrees
void show_polar(const polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angel * Rad_to_deg;
    cout << " degrees\n";
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect * pxy,polar * pda)
{
    using namespace std;
    pda->distance =
        sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angel = atan2(pxy->y, pxy->x);
}
```

## 函数和string对象

1. 虽然C-风格字符串和string对象的用途几乎相同，但与数组相比，string对象与结构更相似。

2. 可以将一个结构赋给另一个结构，也可以将一个对象赋给另一个对象。

3. 可以将结构作为完整的实体传递给函数，也可以将对象作为完整的实体进行传递

4. 如果需要多个字符串，可以声明一个string对象数组，而不是二维char数组

5. ```C++
   getline(cin, inputLine);
   // 其中cin是正在读取的输入流，而inputLine是接受输入字符串的string变量的名称
   ```

## 函数与array对象

1. CPP中，类对象是基于结构的，因此结构编程方面有些考虑因素也适用于类。
   
   + 可按值将对象传递给函数，在这种情况下，函数处理的是原始对象的副本
   
   + 可传递指向对象的指针，这让函数能够操作原始对象

2. 假设要使用一个array对象来存储一年四季的开支：
   
   ```C++
   std::array<double, 4> expenses;
   // 要使用array类，必须包含头文件array，而名称array位于名称空间std中。
   // 如果函数来显示expenses内容，可按值传递expenses
   show(expenses)
   // 如果函数要修改对象expenses，则需将该对象的地址传递给函数
   fill(&expenses)
   ```

3. 注意，模板array并非只能存储基本数据类型，还可以存储类对象

4. 程序没有使用编译指令using, 必须使用std::限定array和string.

## 递归

1. 递归——调用自己（与C语言不同的是，C++不允许main()调用自己）

### 包含一个递归调用的递归

1. 如果递归函数调用自己，则被调用的函数也将调用自己，这将无限循环下去吗，直到代码中包含终止调用链的内容

2. 通常的方法将递归调用放在if语句中。如，void类型的递归函数recurs()：
   
   ```C++
   void recurs(argumentlist)
   {
       statements1
       if(test)
           recurs(arguments)
       statements2
   }
   // test 最终将为false，调用链将断开
   ```

3. 递归的本质是中断调用
   
   ```cpp
   // recur.cpp -- using recursion
    #include<iostream>
   void countdown(int n);
   
   int main()
   {
       countdown(4);       // call the recursive function
       return 0;
   }
   
   void countdown(int n)
   {
       using namespace std;
       cout << "couting down ... " << n << endl;
       if(n > 0)
           countdown(n-1); //function calls itself
       cout << n << ": Kaboom!\n";
   }
   ```
   
   实际输出：
   
   ```cpp
   couting down ... 4
   couting down ... 3
   couting down ... 2
   couting down ... 1
   couting down ... 0
   0: Kaboom!
   1: Kaboom!
   2: Kaboom!
   3: Kaboom!
   4: Kaboom!
   ```
   
   

### 包含多个递归调用的递归

1. 需要将一项工作不断分为两项较小的、类似的工作时，递归非常有用。递归又称为分而治之策略（divide-and-conquer strategy）

```cpp
// ruler.cpp -- using recursion to subdivide a ruler
#include<iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);

int main()
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    std::cout << ruler << std::endl;
    for (i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;
        for(int j = 1; j < Len - 2; j++)
            ruler[j] = 'd'; // reset to blank ruler
    }
    return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0)
        return;
    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdi
vide(ar, mid, high, level - 1);

}
// subdivide()函数使用变量level来控制递归层。
// 函数调用自身时，将把level减1，当level为0时，该函数将不再调用自己
// 注意，subdivide()调用自己两次，一次针对左半部分，另一次针对右半部分
// 最初的中点被用作一次调用的右端点和另一次调用的左端点
// 调用次数将呈几何级数增长
```



## 函数指针

与数据项相似，函数也有地址。函数的地址是存储其机器语言代码的内存的开始地址

### 函数指针的基础知识

将程序员要使用的算法函数的地址传送给函数，必须完成以下工作：

+ 获取函数的地址

+ 声明一个函数指针

+ 使用函数指针来调用函数
1. 获取函数的地址
   
   获取函数的地址：只要使用函数名（后面不跟参数）即可。
   
   ```cpp
   process(think);   // passes address of think() to process()
   thought(think());  // passes return value of think() to thought()
   ```

        process()调用使得process()函数能够在其内部调用think()函数。thought()调用首先调用think()函数，然后将think()函数的返回值传递给thought()函数。

2. 声明函数指针
   
   声明指向某种数据类型的指针时，必须指定指针指向的类型。同样，声明指向函数的指针时，也必须指定指针指向的函数类型。这意味着声明应指定函数的返回类型以及函数的特征标（参数列表）。即声明应像函数原型那样指出有关函数的信息。
   
   ```cpp
   double pam（int);    // prototype,编写了一个估算时间的函数
   // 正确的指针类型声明
   double (*pf)(int);    // pf points to a function that takes
                         // one int argument and that 
                         // returns type double
   ```

> 提示：通常，要声明指向特定类型的函数的指针，可以首先编写这种函数的原型，然后用（*pf）替换函数名。这样pf就是这类函数的指针。
> 
> 括号的优先级比*高，必须在声明中使用括号将\*pf括起来。
> 
> ```cpp
> double (*pf)(int);  // pf points to a function that return double
> double *pf(int);// pf() a function that returns a pointer-to-double
> ```

正确地声明pf后，便可以将相应函数的地址赋给它：

```cpp
double pam(int);
double (*pf)(int);
pf = pm;        // pf now points to the pam() function
// 注意，pam()的特征标和返回类型必须与pf相同。如果不相同，编译器将拒绝这种复制。
double ned(double);
int ted(int);
double (*pf)(int); 
pf = ned;       // invalid -- mismatched signature
pf = ted;       // invalid -- mismatched return types
```

3. 使用指针来调用函数
   
   使用(\*pf) 时，只需将它看作函数名即可。
   
   ```cpp
   double pam(int);
   double (*pf)(int);
   pf = pam;            // pf now points to the pam() function
   double x = pam(4);   // call pam() using the function name
   double y = (*pf)(5); // call pam() using the pointer pf
   
   // C++也允许像使用函数名那样使用pf:
   double y = pf(5);    // also call pam() using the pointer pf
   ```

4. 函数指针示例
   
   ```cpp
   // fun_ptr.cpp -- pointers to functions
   #include<iostream>
   double betsy(int);
   double pam(int);
   
   // second argument is pointer to a type double function
   // takes a type int argument
   
   void estimate(int lines, double (*pf)(int));
   
   int main()
   {
       using namespace std;
       int code;
       cout << "How many lines of code do you need? ";
       cin >> code;
       cout << "Here's Betsy's estimate: \n";
       estimate(code, betsy);
       cout << "Here's Pam's estimate: \n";
       estimate(code, pam);
       return 0;
   }
   
   double betsy(int lns)
   {
       return 0.05 * lns;
   }
   
   double pam(int lns)
   {
       return 0.03 * lns + 0.0004 * lns * lns;
   }
   
   void estimate(int lines, double (*pf)(int))
   {
       using namespace std;
       cout << lines << " lines will take ";
       cout << (*pf)(lines) << " hour(s)\n";
   }
   ```

### 深入探讨函数指针

1. 下面是一些函数的原型，它们的特征标和返回类型相同：
   
   ```cpp
   const double * f1(const double ar[], int n);
   const double * f1(const double [], int);
   const double * f1(const double *, int);
   // 这些函数的特征标看似不同，实际相同。
   // 在函数原型中，参数列表const double ar[] 与 const double * 的含义完全相同、
   // 在函数原型中，可以省略标识符
   // 函数定义必须提供标识符
   ```

2. 要声明一个指针，它可指向这三个函数之一。假定该指针名为pa, 则只需将目标函数原型中的函数名替换为(\*pa):
   
   ```cpp
   const double * (*p1)(const double *, int);
   // 可在声明的同时进行初始化：
   const double * (*p1)(const double *, int) = f1;
   
   // 使用C++11的自动类型推断功能时，代码要简单得多：
   auto p2 = f2; // C++11 automatic type deduction
   
   // 
   cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
   cout << p2(av, 3) << ": "<< *p2(av,3) << endl;
   ```

3. 函数指针数组
   
   ```cpp
   const double * (*pa[3])(const double *, int) = {f1, f2, f3};
   ```
   
   pa是一个包含三个元素的数组，需使用pa[3]。该声明的其他部分指出来数组包含的元素是什么样的。运算符[] 的优先级高于 *, 因此\*pa[3]表明pa是一个包含三个指针的数组。上述声明的其他部分指出了每个指针指向什么：特征标为const double *， int, 且返回类型为const double \* 的函数。因此，pa是一个包含三个指针的数组，其中每个指针都指向这样的函数，即将const double * 和 int 作为参数，并返回一个const double  \* 

4. **auto** 自动类型推断只能用于单值初始化，而不能用于初始化列表。但声明数组pa后，声明同样类型的数组就简单了：
   
   ```cpp
   auto pb = pa;
   // 数组名是指向第一个元素的指针，因此pa和pb都是指向函数指针的指针
   ```

5. pa[i] 和pb[i] 都表示数组中的指针，因此可将任何一种函数调用表示法用于它们：
   
   ```cpp
   const double * px = pa[0](av, 3);
   const double * py = (*pb[1])(av, 3);
   ```

6. 要获得指向的double值，可使用运算符\*:
   
   ```cpp
   double x = (*pa)(av, 3);
   double y = *(*pb[1])(av,3);
   ```

7. 创建指向整个数组的指针。由于数组名pa是指向函数指针的指针，因此指向数组的指针将是这样，即它指向指针的指针。由于可使用单个值对其进行初始化，因此可使用auto：
   
   ```cpp
   auto pc = &pa;    // C++11 automatic type deduction
   ```

8. 如果这个指针名为pd，则需指出它是一个指针，而不是数组。这意味着声明的核心部分应为(\*pd)[3]，其中的括号让标识符pd与\* 先结合：
   
   ```cpp
   *pd[3]       // an array of 3 pointers
   (*pd)[3]     // a pointer to an array of 3 elements
   ```

9. 换句话说，pd是一个指针，它指向一个包含三个元素的数组。
   
   ```cpp
   const double *(*(*pd)[3])(const double *, int) = &pa;
   ```
   
   要调用函数，需要认识：既然pd指向数组，那么\*pd就是数组，而(\*pd)[i]是数组中的元素，即函数指针。较简单的函数调用是(\*pd)\[i](av, 3)，而*(\*pd)\[i](av, 3)是返回的指针指向的值。；
   
   第二种使用指针调用函数的语法：使用(\*(\*pd)[i])(av,3)来调用函数，而*(*(*pd)[i])(av,3) 是指向的double值

10. 请注意，大多数情况下，pa都表示数组第一个元素的地址，即&pa[0]。因此它是单个指针的地址。但&pa是整个数组（即三个指针块）的地址。
    
    从数字来说，pa和&pa的值相同，但类型不同。一种差别是，pa+1为数组中下一个元素的地址，而&pa+1为数组pa后面一个12字节内存块的地址（这里假设地址为4个字节）。另一个差别是，要得到第一个元素的值，只需对pa解除一次引用，但需要对&pa解除两次
    
    ```cpp
    **&pa == *pa == pa[0]
    ```

### 使用typedef进行缉拿话

关键字**typedef** 能够创建类型别名：

```cpp
typedef double real;    // makes real another name for double
```

这里采用的方法是，将别名当作标识符进行声明，并在开头使用关键字typedef。

将p_fun声明为函数指针类型的别名：

```cpp
typedef const double *(*p_fun)(const double *, int); // p_fun now a type name
p_fun p1 = f1;// p1 points to f1() function
```

然后使用这个别名来简化代码：

```cpp
p_fun pa[3] = {f1, f2, f3}; // pa an array of 3 function pointers
p_fun （*pd)[3] = &pa; // pd points to an array of 3 function pointers
```
