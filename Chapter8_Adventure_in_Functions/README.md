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

1.  内联函数是C++为提高程序运行速度所做的一项改进。

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
   
   则可以这样编写函数原型，在函数中将指向该结构的引用作为参数：
   
   ```cpp
   void set_pc(free_throws & ft);  // use a reference to a structure
   ```
   
   如果不希望函数修改传入的结构，可使用const：
   
   ```cpp
   void display(const free_throws & ft);// don't allow changes to structure
   ```

## 默认参数

## 函数重载

## 函数模板

## <mark></mark>
