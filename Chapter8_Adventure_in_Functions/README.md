# 第八章 函数探幽

## 本章内容：

+ 内联函数

+ 引用变量

+ 如何按引用传递函数参数

+ 默认参数

+ 函数重载

+ 函数模板

+ 函数模板具体化

## C++内联函数

1. 内联函数是C++为提高程序运行速度所做的一项改进。

2. 常规函数和内联函数的主要区别：C++编译器如何将它们组合到程序中

3. 编译过程的最终产品是可执行程序——由一组机器语言指令组成。运行程序时，操作系统将这些指令载入到计算机内存中，因此每条指令都有特定的内存地址。计算机随后将逐步执行这些指令。有时(如有循环或分支语句时)，将跳过一些指令，向前或向后跳到特定地址。常规函数调用也使程序跳到另一个地址（函数地址），并在函数结束时返回。

4. 执行到函数调用指令时，程序将在函数调用后立即存储该指令的内存地址，并将函数参数复制到堆栈(为此保留的内存块)，跳到标记函数起点的内存单元，执行函数代码（也许还需将返回值放入到寄存器中），然后跳回到地址被保存的指令处。来回跳跃并记录跳跃位置意味着以前使用函数时，需要一定的开销。

5. 内联函数的编译代码与其他程序代码“内联”起来，即编译器将使用相应的函数代码替换函数调用。程序无需跳到另一个位置处执行代码，再跳回来。因此内联函数的运行速度比常规函数稍快，代价是占用更多的内存。

6. 如果程序在10个不同的地方调用同一个内联函数，则该程序将包含该函数代码的10个副本。

7. 应有选择地使用内联函数。
   
   + 若函数代码的时间比处理函数调用机制的时间长，则节省的时间将只占整个过程的很小一部分。
   
   + 若代码执行时间很短，则内联调用就可以节省非内联调用使用的大部分时间。另一方面，由于这个过程相当快，因此尽管节省了该过程的大部分时间，但节省的时间绝对值并不大，除非该函数经常被调用。

8. 要使用这项特性，必须采取下述措施之一：
   
   + 在函数声明钱加上关键字**inline**
   
   + 在函数定义前加上关键字**inline**

9. 通常做法是省略原型，将整个定义（即函数头和所有函数代码）放在本应提供原型的地方

10. 程序员请求将函数作为内联函数时，编译器并不一定会满足这种要求。它可能认为该函数过大或注意到函数调用了自己(内联函数不能递归)

11. 注意整个函数定义都放在一行中，但并不一定非得这样做。然而，如果函数定义占用多行（假定没有使用冗长的标识符）,则将其作为内联函数就不太合适

12. 内联函数和常规函数一样，也是按值传递参数的。

> 内联和宏
> 
> C语言使用预处理器语句#define 来提供宏——内联代码的原始实现。而是通过文本替换来实现的。
> 
> 例如下面是一个计算平方的宏：
> 
> #define SQUARE(X） X*X
> 
> a = SQUARE(5.0); is replaced by a = 5.0 * 5.0;
> 
> b = SQUARE(4.5 + 7.5); is replaced by b = 4.5 + 7.5 *  4.5 + 7.5;
> 
> d = SQUARE(c++); is replaced by d = c++ * c++;
> 
> 上述示例只有第一个能正常工作。可以通常使用括号来改进：
> 
> #define SQUARE(X)  ((X)*(X)) 
> 
> 但仍存在这样的问题，即宏不能按值传递

## 引用变量

### 创建引用变量

2. C和C++使用&符号来指示变量的地址。C++给&符号赋予了另一个含义，将其用来声明引用。&不是地址运算符，而是类型标识符的一部分。

3. 引用声明允许将他们互换——它们指向相同的值和内存单元 
   
   ```cpp
   // firstref.cpp -- defining and using a reference
   #include<iostream>
   int main()
   {
       using namespace std;
       int rats = 101;
       int & rodents = rats;   // rodents is a reference
       cout << "rats = " << rats;
       cout << ", rodents = " << rodents << endl;
       rodents++;
       cout << "rats = " << rats;
       cout << ", rodents = " << rodents << endl;
   
       // some implementations require type casting the following
       // addresses to type unsigned
       cout << "rats addresses = " << &rats;
       cout << ", rodents addresses = " << &rodents << endl;
       return 0;
   }
   ```
   
   ```cpp
   输出：
   rats = 101, rodents = 101
   rats = 102, rodents = 102
   rats addresses = 0x61fe14, rodents addresses = 0x61fe14
   ```

4. 可以创建指向rats的引用和指针。 表达式rodents和*prats 都可以同rats互换。而表达式&rodents和prats都可以同&rats 互换。
   
   ```cpp
   int rats = 101;
   int & rodents = rats;    // rodents a reference
   int * prats = &rats;     // prats a pointer
   ```

5. 指针和引用的差别：
   
   + 表示法不同
   
   + 必须在引用时将其初始化，而不能像指针那样，先声明，再赋值
     
     ```cpp
     int rat;
     int & rodent;
     rodent = rats;    // No, you can't do this
     ```

6. 引用更接近const指针，必须在创建时进行初始化，一旦与某个变量关联起来，就将一直效忠于它。
   
   ```cpp
   int & rodents = rats;
   // 实际是以下代码的伪装表示
   int * const pr = &rats;
   ```

7. 可以通过初始化声明来设置引用，但不能通过赋值来设置
   
   ```cpp
   int rats = 101;
   int * pt = &rats;
   int & rodents = *pt;
   int bunnies = 50;
   pt = &bunnies;
   // 将rodents初始化为*pt使得rodents指向rats.
   // 接下来将pt改为指向bunnies，并不能改变这样的事实
   // 即rodents引用的是rats
   ```

### 将引用用作函数参数

1. 按引用传递：使用引用作函数参数，使得函数中的变量名成为调用程序中的变量的别名

2. 按引用传递允许被调用的函数能够访问调用函数中的变量。

3. 按引用传递和按值传递比较
   
   + 调用形式看起来相同。但声明函数参数的方式不同
   
   + 按引用传递，参数变量是函数中变量的别名；而按值传递，参数变量是函数变量的复制后的新变量

4. 传递引用和传递指针
   
   + 声明函数参数的方式不同
   
   + 指针需要在函数使用参数变量的整个过程中使用解除引用运算符*  

### 引用的属性和特别之处

```cpp
// cubes.cpp -- regular and reference arguments
#include<iostream>
double cube(double a);
double refcube(double &ra);

int main()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double reference(double &ra)
{
    ra *= ra * ra;
    return ra;
}
```

1. 下面是该程序的输出
   
   ```cpp
   27 = cube of 3
   27 = cube of 27
   ```

2. refcube()函数修改了main()中的x值，而cube()没有。

3. 如果让函数使用传递给它的信息，而不对这些信息进行修改，同时又想使用引用，则应使用常量引用。即，在函数原型和函数头中使用const

4. 按值传递，下面调用都是合法的：
   
   ```cpp
   double z = cube(x + 2.0);  // evaluate x+2.0, pass value
   z = cube(8.0);             // pass the value 8.0
   int k = 0;
   z = cube(k);               // convert value of k to double, pass value
   double yo[3]={2.2,3.3,4.4};
   z = cube(yo[2]);           // pass the value 4.4
   ```

5. 下面的代码不合理，因为表达式x+3.0并不是变量：
   
   ```cpp
   double z = refcube(x + 3.0);// should not compile
   
   // 不能将值赋给该表达式
   x + 3.0 = 5.0;//nonsensical
   ```

6. **临时变量、引用参数和const**
   
   1. 如果实参与引用参数不匹配，C++将生成临时变量。
   
   2. 什么时候创建临时变量？如果引用参数是const，则编译器将在下面两情况下生成临时变量
      
      + 实参的类型正确，但不是左值；
      
      + 实参的类型不正确，但可以转换为正确的类型
   
   3. 左值：可被引用的数据对象，例如，变量、数组元素、结构成员、引用和解除引用的指针
   
   4. 非左值：字面常量（用引号括起的字符串除外，它们由其地址表示）和包含多项的表达式
   
   5. 常规变量是可修改的左值，const变量属于不可修改的左值
   
   6. 现在考虑下面的代码：
      
      ```cpp
      double side = 3.0;
      double * pd = &side;
      double & rd = side;
      long edge = 5L;
      double lens[4] = {2.0,5.0,10.0,12.0};
      double c1 = refcube(side);    // ra is side
      double c2 = refcube(len[2]);  // ra is lens[2]
      double c3 = refcube(rd);      // ra is rd is side
      double c4 = refcube(*pd);     // ra is *pd is side
      double c5 = refcube(edge);    // ra is temporary variable
      double c6 = refcube(7.0);     // ra is temporary variable
      double c7 = refcube(side + 10.0);// ra is temporary variable
      ```

7. 参数side、lens[2]、rd和*pd 都是有名称的、double类型的数据对象，因此可以为其创建引用，而不需要临时变量

8. edge虽然是变量，类型却不正确，double引用不能指向long。

9. 参数7.0 和side+ 10.0 的类型都正确，但没有名称，在这些情况下，编译器都将生成一个临时匿名变量，并让ra指向它。这些临时变量只在函数调用期间存在，此后编译器便可以随意将其删除。

10. 简而言之，如果接受引用参数的函数的意图是修改作为参数传递的变量，则创建临时变量将阻止这种意图的实现。解决办法是，禁止创建临时变量，现在C++标准正是这样做的。

11. 如果声明将引用指定为const ，C++ 将在必要时生成临时变量。实际上，对于形参为const引用的C++函数，如果实参不匹配，则其行为类似于按值传递，为确保原始数据不被修改，将使用临时变量来存储值。

> **应尽可能使用const**
> 
> 将引用参数声明为常量数据的引用的理由有三个：
> 
> + 使用const 可以避免无意中修改数据的变成错误；
> 
> + 使用const 使函数能够处理const和非const实参，否则将只能接受非const数据；
> 
> + 使用const 引用使函数能够正确生成并使用临时变量
> 
> C++11 新增——右值引用（rvalue reference)。这种引用可指向右值，是使用&&声明：
> 
> ```cpp
> double && rref = std::sqrt(36.00);  // not allowed for double &
> double j = 15.0;
> double && jref = 2.0 * j + 18.5;    // not allowed for double &
> std::cout << rref << '\n';          // display 6.0
> std::cout << jref << '\n';          // display 48.5;
> ```

### 将引用用于结构

1. 使用结构引用参数的方式与使用基本变量引用相同，只需在声明结构参数时使用引用运算符&即可。

2. 假设有如下结构定义：
   
   ```cpp
   struct free_throws
   {
       std::string name;
       int made;
       int attempts;
       float percent;
   }
   ```

```
则可以这样编写函数原型，在函数中将指向该结构的引用作为参数：

```cpp
void set_pc(free_throws & ft);  // use a reference to a structure
```

   如果不希望函数修改传入的结构，可使用const：

```cpp
void display(const free_throws & ft);// don't allow changes to structure
```

3. 返回引用
   
   ```cpp
   accumulate(dup, five) = four;
   // 这条语句将值赋给函数调用，这是可行的，因为函数的返回值是一个引用。
   // 如果函数accumulate()按值返回，将不能通过编译
   // 上述代码与下面的代码等效：
   accumulate(dup,five);  // add five's data to dup
   dup = four; // overwrite the contents of dunps 
               // with the contents of four
   ```
   
   在返回值为引用时，将直接把team复制到dup,其效率更高；
   
   返回引用的函数实际上是被引用的变量的别名；
   
   返回引用时应避免返回函数终止时不再存在的内存单元引用（如指向临时变量的引用，函数运行完毕后它将不再存在）
   
   同样应避免返回指向临时变量的指针
   
   为避免这种问题，应返回一个作为参数传递给函数的引用。作为参数的引用将指向调用函数的数据，因此返回的引用也将指向这些数据

4. 另一个方法是用**new**来分配新的存储空间。前面见过这样的做法，它使用new为字符串分配内存空间，并返回指向该内存空间的指针。下面是使用引用来完成类似的工作：
   
   ```Cpp
   const free_throws & clone(free_throws & ft)
   {
       free_thorws * pt;
       *pt = ft;     // copy info
       return ft;    // return reference to copy
   }
   ```
   
   第一条语句创建一个无名的free_throws结构，并让指针pt指向该结构，因此*pt就是该结构。上述代码似乎会返回该结构，但函数声明表明，该函数实际上将返回这个结构的引用。
   
   ```cpp
   free_throws & jolly = clone(three);
   // 这使得jolly成为新结构的引用
   ```

5. 这种方法存在一个问题：在不需要new分配的内存时，应使用delete来释放它们。调用clone()隐藏了对new的调用，这使得很容易忘记使用delete来释放内存

6. 假如要使用引用返回值，但又不允许执行像给accumulate()赋值这样的操作，只需将返回类型声明为const引用：
   
   ```cpp
   const free_throws & accumulate(free_throws & target, const free_throws & source);
   ```
   
   现在返回类型是const，是不可修改的左值

### 将引用用于类对象

1. 将类对象传递给函数时，C++通常的做法是使用引用
   
   ```cpp
   // strquote.cpp -- different design
   #include<iostream>
   #include<string>
   using namespace std;
   string version1(const string & s1, const string & s2);
   const string & version2(string & s1, const string & s2);// has side effect
   const string & version3(string & s1, const string & s2);// bad design
   
   int main()
   {
       string input;
       string copy;
       string result;
   ```
   
       cout << "Enter a string: ";
       getline(cin,input);
       copy = input;
       cout << "Your string as entered: " << input << endl;
       
       result = version1(input, "***");
       cout << "Your string enhanced: " << result << endl;
       cout << "Your original string: " << input << endl;
       
       result = version2(input, "***");
       cout << "Your string enhanced: " << result << endl;
       cout << "Your original string: " << input << endl;
       
       cout << "Resetting original string.\n";
       input = copy;
       result = version3(input, "@@@");
       cout << "Your string enhanced: " << result << endl;
       cout << "Your origianl string: " << input << endl;
       
       return 0;
   
   }
   
   string version1(const string & s1, const string & s2)
   {
   
       string temp;
       
       temp = s2 + s1 + s2;
       return temp;
   
   }
   
   const string & version2(string & s1, const string & s2) // has side effect
   {
   
       s1 = s2 + s1 + s2;
       // safe to return reference passed to function
       return s1;
   
   }
   
   const string & version3(string & s1, const string & s2) // bad design
   {
   
       string temp;
       
       temp = s2 + s1 + s2;
       // unsafe to return reference to local variable
       return temp;
   
   }

```
2. s1是指向main()中一个对象（input)的引用，因此将s1作为引用返回是安全的。由于s1是指向input的引用，调用该函数将带来修改input的副作用。如果要保留原来的字符串不变，这将是一种错误设计。

3. version3存在一个致命缺陷：返回一个指向version3()中声明的变量的引用。这个函数能够通过编译（但编译器会发出警告），但当程序试图执行该函数时将崩溃。具体地说，程序试图引用已经释放的内存temp。

### 对象、继承和引用

1. ostream 和ofstream类凸显了引用的一个有趣属性。ofstream对象可以使用ostream类的方法，这使得文件输入/输出的格式与控制台输入/输出相同。**使得能够将特性从一个类传递给另一个类的语言特性被称为继承**。派生类继承了基类的方法，这意味着派生类对象可以使用基类的特性。

2. 继承的另一个特征是，基类引用可以指向派生类对象，而无需进行强制类型转换。这种特征的一个实际结果，可以定义一个接受基类引用作为参数的函数，调用该函数时，可以将基类对象作为参数，也可以将派生类对象作为参数。

```cpp

// filefunc.cpp -- function with ostream & parameter
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char* fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Byte.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your "
            "telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
         << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // save initial formatting state
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);   // restore initial formatting state
}
```

3. 方法setf()能够设置各种格式化状态，
   
   + setf(ios_base::fixed)将对象置于使用定点表示法的模式；
   
   + setf(ios_base::showpoint)将对象置于显示小数点的模式，即使小数部分为零
   
   + 方法precision() 指定显示多少位小数(假定对象处于定点模式下)

4. 所有这些设置将一直保持不变，直到再次调用相应的方法重新设置他们

5. 方法width()设置下一次输出操作使用的字段宽度，这种设置只在显示下一个值时有效，然后将恢复到默认设置。默认字段宽度为零，这意味刚好能容纳下要显示的内容。

6. ```cpp
   ios_base::fmtflags initial;
   initial = os.setf(ios_base::fixed); // save initial formatting state
   ...
   os.setf(initial);   // restore initial formatting state
   ```
   
   方法setf()返回调用它之前有效的所有格式化设置。ios_baseL::fmtflags是存储这种信息所需的数据类型的名称。因此，将返回值赋给initial将存储调用file_it()之前的格式化设置，然后便可以使用变量initial作为参数来调用setf(), 将所有的格式化设置恢复到原来的值。因此，该函数将对象回到传递给file_it()之前的状态。

### 何时使用引用参数

1. 使用引用参数的主要原因有两个：
   
   + 程序员能够修改调用函数中的数据对象
   
   + 通过传递引用而不是整个数据对象，可以提高程序的运行速度（尤其当数据对象较大时）

2. 何时使用引用或指针：
   
   + 如果数据对象很小，如内置数据类型或小型结构，则按值传递
   
   + 如果数据对象是数组，则使用指针，并将指针声明为指向const的指针
   
   + 如果数据对象是较大的结构，则使用const指针或const引用，以提高程序的效率，可以节省复制结构所需的时间和空间
   
   + 如果数据对象是类对象，则使用const引用。类设计的语义常常要求使用引用，传递类对象参数的标准方式是按引用传递

3. 对于修改调用函数中数据的函数：
   
   + 如果数据对象是内置数据类型，则使用指针。
   
   + 如果数据对象是数组，则只能使用指针
   
   + 如果数据对象是结构，则使用引用或指针
   
   + 如果数据对象是类对象，则使用引用

## 默认参数

1. 默认参数指的是当函数调用中省略了实参时自动使用的一个值。
   
   + 假设有一个名为left()的函数，它将字符串和n作为参数，并返回该字符串的前n个字符。更准确的说，该函数返回一个指针，该指针指向由原始字符串中被选中的部分组成的字符串
   
   + 必须通过函数原型来设置默认值。由于编译器通过查看原型来了解函数所使用的参数数目，因此函数原型也必须将可能的默认参数告知程序。
   
   + 方法时是将值赋给原型中的参数
   
   + 例如，left()的原型如下
     
     ```cpp
     char * left(const char * str, int n = 1);
     ```
   
   + 该函数返回一个新的字符串，因此将其类型设置为char*(指向char的指针)；原始字符串保持不变，对第一个参数使用了const限定符；n的默认值为1，将这个值付给n。默认参数值是初始化值，上面的原型将n初始化为1。如果省略参数n，则它的值将为1,否则，传递的值将覆盖1.

2. 对于带参数列表的函数，必须从右向左添加默认值。也就是说，要为某个参数设置默认值，则必须为它右边的所有参数提供默认值
   
   ```cpp
   int harpo(int n, int m = 4, int j = 5);    //VALID
   int chico(int n, int m = 6, int j);        // INVALID
   int groucho(int k = 1, int m = 2, int n = 3);   // VALID
   ```

3. 例如，harpo()原型允许调用该函数时提供1个、2个或3个参数：
   
   ```cpp
   beeps = harpo(2);    // same as harpo(2,4,5)
   beeps = harpo(1,8);  // same as harpo(1,8,5)
   beeps = harpo(8,7,6);// no default arguments used
   ```

4. 实参按从左到右的顺序依次被赋给相应的形参，而不能跳过任何参数。因此，下面的调用是不允许的：
   
   ```cpp
   beeps = harpo(3,,8);    // invaild, doesn't set m to 4
   ```

5. 默认参数并非编程方面的重大突破，而只是提供了一种便捷的方式。通过使用默认参数，可以减少要定义的析构参数、方法以及方法重载的数量
   
   ```cpp
   // left.cpp -- string function with a default argument
   #include<iostream>
   const int ArSize = 80;
   char * left(const char * str, int n = 1);
   int main()
   {
       using namespace std;
       char sample[ArSize];
       cout << "Enter a string:\n";
       cin.get(sample, ArSize);
       char *ps = left(sample, 4);
       cout << ps << endl;
       delete []ps;        // free old string
       ps = left(sample);
       cout << ps << endl;
       delete []ps;        // free new string
       return 0;
   }
   
   // This function returns a pointer to a new string
   // consisting of the first n characters in the str string
   char * left(const char * str, int n)
   {
       if (n < 0)
           n = 0;
       char * p = new char[n+1];
       int i;
       for (i = 0; i < n && str[i]; i++)
           p[i] = str[i];  // copy characters
       while (i <= n)
           p[i++] = '\0';  // set rest of string to '\0'
       return p;  
   }
   ```

## 函数重载

1. 函数多态是C++在C语言的基础上新增的功能。默认参数能够使用不同数目的参数调用同一个函数，而函数多态（函数重载）能够使用多个同名的函数。

2. 术语“**多态**”指的是有多种形式，因此函数多态允许函数可以有多重形式

3. 术语“**函数重载**”指的是可以有多个同名的函数，因此对名称进行了重载。

4. 这两个术语指的是同一回事，但通常使用函数重载

5. 函数重载来设计一系列函数——完成相同的工作，但是用不同的参数列表

6. 重载函数就像是有多重含义的动词。

7. 函数重载的关键是函数的参数列表——也称为函数特征标（function signature）

8. 若两个函数的参数数目和类型相同，同时参数的排列顺序也相同，则它们的特征标相同，而变量名是无关紧要的。

9. C++允许定义名称相同的函数，条件是它们征标不同

10. 如果参数数目或参数类型不同，则特征标也不同 
    
    ```cpp
    // 定义一组原型如下的print()函数
    void print(const char * str, int width);    // #1
    void print(double d, int width);            // #2
    void print(long l, int width);              // #3
    void print(int i, int width);               // #4
    void print(const char * str);               // #5
    ```
    
    + 使用print()函数时，编译器将根据所采取的用法使用有相应特征标的原型：
    
    ```cpp
    print("Pancakes", 15);    // use #1
    print("Syrup");           // use #5
    print(1999.0, 10);        // use #2
    print(1999, 12);          // use #4
    print(1999L ,15);         // use #3
    ```
    
    + 没有匹配的原型并不会自动停止使用其中的某个该函数，C++将尝试使用标准类型转换强制进行匹配。
    
    + 但是若转换的方式不止一种，C++将拒绝这种函数调用，并视其为错误

11. - 一些看起来彼此不同的特征标是不能共存的。
      
      ```cpp
      double cube(double x);
      double cube(double & x);
      ```
    
    - 从编译器角度考虑，假设
      
      ```cpp
      cout << cube(x);
      ```
    
    - 参数x与doubl x 原型和 double &x原型都匹配，因此编译器无法确定究竟该使用哪个原型。为避免这种混乱，编译器在检查函数特征时，将把类型引用和类型本身视为同一个特征标

12. 匹配函数时，并不区分const和非const变量
    
    ```cpp
    void dribble(char * bits);       // overload
    void dribble(const char *cbits); // overload
    void dabble(char * bits);       // overload
    void drivel(const char * bits); // overload
    ```
    
    下面列出了各种函数调用对应的原型：
    
    ```cpp
    const char p1[20] = "How's the weather?";
    char p2[20] = "How's business?";
    dribble(p1);        // dribble (const char *);
    dribble(p2);        // dribble (char *);
    dabble(p1);         // no match
    dabble(p2);         // dabble(char *);
    drivel(p1);         // drivel(const char *);
    drivel(p2);         // drivel(const char *)
    ```

13. 将非const值赋给const变量是合法的，但反之则是非法的

14. Attention！！！是特征标，而不是函数类型使得可以对函数进行重载
    
    ```cpp
    // 下面两个声明是互斥的
    long gronk(int n, float m);    // same signatures.
    double gronk(int n, float m);  // hence not allowed
    ```
    
    因此，C++不允许以这种方式重载gronk()。返回类型可以不同，但特征标也必须不同
    
    ```cpp
    long gronk(int n, float m);    // different signature,
    double gronk(float n,float m); // hence allowed
    ```

> ## 重载引用参数
> 
> 类设计和STL经常使用引用参数，因此知道不同引用类型的重载很有用
> 
> + 左值引用参数r1与可修改的左值参数（如double变量）匹配；
> 
> + const 左值引用参数r2与可修改的左值参数、const左值参数和右值参数(如两个double值的和)匹配；
> 
> + 左值引用参数r3与左值匹配
> 
> + 注意到与r1或r3匹配的参数都与r2匹配。如果重载使用这三种参数的函数，结果将调用最匹配的版本
> 
> ```cpp
> void sink(double & r1);      // matches modifiable lvalue
> void sank(const double & r2);// matches modifiable or const lvalue
>                              // rvalue
> void sunk(double && r3);     // matches rvalue   
> ```

> 根据参数是左值、const还是右值来定制函数
> 
> 如果没有定义函数stove(double &&),stove(x+y)将调用函数stove(const double &)
> 
> ```cpp
> double x = 55.5;
> const double y = 32.0;
> stove(x);                // calls stove(double &)
> stove(y);                // calls stove(const double &)
> stove(x+y);              // calls stove(double &&)
> ```

### 重载示例

1. 本章前面创建了一个left()函数，它返回一个指针，指向字符串的前n个字符。

2. 下面添加另一个left()函数，它返回整数的前n位。
   
   ```cpp
   // leftover.cpp -- overloading the left() function
   #include<iostream>
   unsigned long left(unsigned long num, unsigned ct);
   char * left(const char * str, int n = 1);
   
   int main()
   {
       using namespace std;
       char * trip = "Hawaii!!";   // test value
       unsigned long n = 12345678; // test value
       int i;
       char * temp;
   
       for (i = 1; i < 10; i++)
       {
           cout << left(n, i) << endl;
           temp = left(trip, i);
           cout << temp << endl;
           delete[] temp; // point to temporary storage
       }
       return 0;
   
   }
   // This function return the first ct digits of the number num.
   unsigned long left(unsigned long num, unsigned ct)
   {
       unsigned digits = 1;
       unsigned long n = num;
   
       if (ct == 0 || num == 0)
           return 0;       // return 0 if no digits
       while (n /= 10)
           digits++;
       if (digits > ct)
       {
           ct = digits - ct;
           while (ct--)
               num /= 10;
           return num;     // return left ct digits
       }
       else                // if ct >= number of digits
           return num;     // return the whole number
   }
   
   // This function returns pointer to a new string
   // consisting of the first n charaters in the str string
   char * left(const char * str, int n)
   {
       if (n < 0)
           n = 0;
       char * p = new char[n+1];
       int i;
       for (i = 0; i < n && str[i]; i++)
           p[i] = str[i];  //copy characters
       while (i <= n)
           p[i++] = '\0';  // set rest of string to '\0'
       return p;
   
   }
   ```



### 何时使用函数重载

1. 仅当函数基本上执行相同的任务，但使用不同形式的数据时，才应采用函数重载。

2. 使用默认参数是否可以实现同样的目的？
   
   ```cpp
   // 可以用两个重载函数来代替面向字符串的left()函数
   char * left(const char * str, unsigned n);    // two arguments
   char * left(const char * str);
   ```
   
   使用一个带默认参数的函数要简单些，只需编写一个函数(而不是两个函数)，程序也只需为一个函数（而不是两个）请求内存；需要修改函数时，只需修改一个。然而，如果需要使用不同类型的参数，则默认参数便不管用了，在这种情况下，应该使用函数重载。

> ## 名称修饰
> 
> 使用C++开发工具中的编译器编写和编译程序时，C++编译器将执行一些操作—名称修饰（name decoration)或名称矫正（name mangling)，它根据函数原型中指定的形参类型对每个函数名进行加密。
> 
> 下述未经修饰的函数原型：
> 
> ```cpp
> long MyFunctionFoo(int, float);
> ```
> 
> 这种格式对于人类来说很适合；我们知道函数接受两个参数（一个为int类型，另一个为float类型），并返回一个long值。而编译器将名称转换为不太好看的内部表示，来描述该接口，如下所示：
> 
> ```cpp
> ?MyFunctionFoo@@YAXH
> ```
> 
> 对原始名称进行的表面看来无意义的修饰（或矫正，因人而异）将对参数数目和类型进行编码。添加的一组符号随函数特征标而异，而修饰时使用的约定随编译器而异



## 函数模板

1. 函数模板是通用的函数描述，它们使用泛型来定义函数，其中的泛型可用具体的类型（如int或double）替换。

2. 通过将类型作为参数传递给模板，可使编译器生成该类型的函数。

3. 由于模板允许以泛型（而不是具体类型）的方法编写程序，因此有时也被称为通用编程；由于类型是用参数表示的，因此模板特性有时也被称为参数化类型（parameterized type)

4. THINK: 定义了一个交换两个int值的函数后，假设要交换两个double值，再交换两个char值，如何实现？以前就只能复制原来的代码，再替换类型。而C++的函数模板功能能自动完成这一过程，可以节省时间，而且更可靠

5. 函数模板允许以任意类型的方式来定义函数，例如，建立一个交换模板：
   
   ```cpp
   template <typename AnyType>
   void Swap(AnyType &a, AnyType &b)
   {
       AnyType temp;
       temp = a;
       a = b;
       b = temp;
   }
   // 第一行指出，要建立一个模板，并将类型命名为AnyType。 
   // 关键字template和typename是必需的，除非可以使用关键字class代替typename
   // 另外，必须使用尖括号。
   // 类型名可以任意选择(这里为AnyType),只要遵守C++命名规则即可。常用T
   // 余下的代码描述了交换两个AnyType值的算法
   // 模板并不创建任何函数，而只是告诉编译器如何定义函数。
   // 需要交换int/double/char的函数时，编译器将按模板模式创建这样的函数，
   // 并用int/double/char代替AnyType
   ```

6. 在C++98添加关键字typename之前，C++使用关键字class来创建模板
   
   ```cpp
   template <class AnyType>
   void Swap(AnyType &a, AnyType &b)
   {
       AnyType temp;
       temp = a;
       a = b;
       b = temp;
   }
   ```

> **提示**： 如果需要多个将同一种算法用于不同类型的函数，请使用模板。
> 
> 如果不考虑向后兼容的问题，并愿意键入较长的单词，则声明类型参数时，应使用关键字typename而不使用class

7. 注意，函数模板不能缩短可执行程序。最终的代码不包含任何模板，而只包含了为程序生成的实际函数。使用模板的好处是，它使生成多个函数定义更简单、更可靠

8. 更常见的情形是，将模板放在头文件中，并在需要使用模板的文件中包含头文件

9. 
