# 第十章 对象和类

## 本章内容：

+ 过程性编程和面向对象编程

+ 类概念

+ 如何定义和实现类

+ 公有类访问和私有类访问

+ 类的数据成员

+ 类方法（类函数成员）

+ 创建和使用类对象

+ 类的构造函数和析构函数

+ const 成员函数

+ 创建对象数组

+ 类作用域

+ 抽象数据类型

面向数据编程（OOP)是一种特殊的、设计程序的概念性方法。下面试最重要的OOP特性：

+ 抽象

+ 封装和数据隐藏

+ 多态

+ 继承

+ 代码的可重用性

## 过程性编程和面向对象编程

1. 采用过程性编程方法时，首先考虑要遵循的步骤，然后考虑如何表示这些数据（并不需要程序一直允许，用户可能希望能够将数据存储在一个文件中，然后从这个文件中读取数据）。

2. 采用OOP方法时，首先从用户的角度考虑对象——描述对象所需的数据以及描述用户与数据交互所需的操作。完成对接口的 描述后，需要确定如何实现接口和数据存储。最后，使用新的设计方案创建出程序。

## 抽象和类

1.抽象是通往用户定义类型的捷径，在C++中，用户定义类型指的是实现抽象接口的类设计。

### 类型是什么?

1. 指定基本类型完成了三项工作：
   
   + 决定数据对象需要的内存数量
   
   + 决定如何解释内存中的位（long和float在内存中占用的位数相同，但将它们转换为数值的方法不同）；
   
   + 决定可使用数据对象执行的操作或方法

2. 对于内置类型来说，有关操作的信息被内置到编译器中。但在C++中定义用户自定义的类型时，必须自己提供这些信息。

### C++中的类

1. 类是一种将抽象转换为用户定义类型的C++工具，它将数据表示和操纵数据的方法组合成一个整洁的包。

2. 定义类。一般来说，类规范由两个部分组成：
   
   + 类声明：以数据成员的方式描述数据部分，以成员函数(被称为方法)的方式描述公有接口。（）
   
   + 类方法定义：描述如何实现类成员函数

> ### 什么是接口
> 
> 接口是一个共享框架，供两个系统交互时使用；
> 
> 对于类，我们说公共接口。在这里，公众（public）是使用类的程序，交互系统由类对象组成，而接口由编写类的人提供的方法组成。接口让程序员能够编写与类对象交互的代码，从而让程序能够使用类对象。
> 
> 如果希望更人性化，不要将使用类的程序视为公共用户，而将编写程序的人视为公共用户。

3. 通常，C++程序员将接口（类定义）放在头文件中，并将实现（类方法的代码）放在源代码文件中。
   
   ```cpp
   // stock00.h -- Stock class interface
   // version 00
   #ifndef STOCK00_H_
   #define STOCK00_H_
   
   #include<string>
   
   class Stock // class declaration
   {
   private:
       std::string company;
       long shares;
       double share_val;
       double total_val;
       void set_tot() { total_val = shares * share_val;}
   public:
       void acquire(const std::string & co, long n, double pr);
       void buy(long num, double price);
       void sell(long num， double price);
       void update(double price);
       void show();
   };   // note semicolon at the end
   
   #endif
   ```

4. C++关键字class指出这些代码定义了一个类设计（不同于模板参数中，这里关键字class和typename不是同义词，不能使用typename代替class）。这种语法指出，Stock是这个新类的类型吗。该声明让我们能够声明Stock类型的变量——称为对象或实例
   
   ```cpp
   Stock sally;
   Stock solly;
   // 创建两个Stock对象，分别是Sally和solly
   ```

5. 要存储的数据以类数据成员的形式；要执行的操作以类函数成员的形式；

6. 成员函数可以就地定义，也可以用原型表示。

7. 访问控制
   
   + 关键字private和public也是新的，它们描述了对类成员的访问控制。
   
   + 使用类对象的程序都可以直接访问公有部分，但只能通过公有成员函数（或友元函数）来访问对象的私有成员。
   
   + 公有成员函数是程序和对象的私有成员之间的桥梁，提供了对象和程序之间的接口。
   
   + 防止程序直接访问数据被称为数据隐藏。C++还提供了第三个访问控制关键字protected

8. 类设计尽可能将公有接口与实现细节分开。公有接口表示设计的抽象组件。

9. 将实现细节放在一起并将它们与抽象分开被称为封装。
   
   + 数据隐藏（将数据放在类的私有部分中）是一种封装
   
   + 将实现的细节隐藏在私有部分中是一种封装
   
   + 将类函数定义和类声明放在不同的文件中也是一种封装

10. 数据隐藏不仅可以防止直接访问数据，还让开发者（类的用户）无需了解数据是如何被表示的）

11. 无论类成员是数据成员还是成员函数，都可以在类的公有部分或私有部分中声明它。但由于隐藏数据是OOP主要的目标之一，因此数据项通常放在私有部分，组成类接口的成员函数放在公有部分；否则无法从程序中调用这些函数。

12. 通常，程序员使用私有成员函数来处理不属于公有接口的实现细节

13. 不必在类声明中使用关键字private，这是类对象的默认访问控制

> ### 类和结构
> 
> 唯一的区别，结构的默认访问类型是public，而类是private
> 
> C++程序员通常使用类来实现；类描述，而把结构限制为只表示纯粹的数据对象（常背称为普调老实数据（POD，Plain Old Data）结构

### 实现类成员函数

1. 成员函数定义与常规函数定义非常相似，它们有函数头和函数体，也可以有返回类型和参数。但有两个特殊的特征：
   
   + 定义成员函数时，使用作用域解析符（::)来标识函数所属的类；
     
     ```cpp
     void Stock::update(double price)
     // 意味update()是Stock类的成员
     // 也可以将另一个类的成员函数命名为update()
     void Buffoon::update()
     // 作用域解析运算符确定了方法定义对应的类的身份。
     // 标识符update()具有类作用域（class scope)
     // Stock类的其他成员函数不必使用作用域解析运算符，就可以使用update()
     // 因为它们属于同一个类，update()是可见的。
     // 在类声明和方法定义之外使用update()时，需要采取特殊的措施
     // 类方法的完整名称中包括类名。
     Stock::update() // 函数的限定名（qualified name)
     update()        // 全名的缩写(非限定名，unqualified name)
                     // 只能在类作用域中使用
     ```
   
   + 类方法可以访问类的private组件；如果试图使用非成员函数访问这些数据成员，编译器禁止这样做

2. 内联方法：定义位于类声明中的函数都将自动称为内联函数。类声明常将短小的成员函数作为内联函数。

3. 也可以在类声明外定义成员函数，并使其称为内联函数。只需在类实现部分中定义函数时使用inline限定符即可：
   
   ```cpp
   class Stock
   {
   private:
       ...
       void set_tot();    // definition kept separate
   public:
       ...
   };
   
   inline void Stock::set_tot()    // use inline in definition
   {
       total_val = shares * share_val;
   }
   ```

4. 内联函数的特殊规则要求在每个使用它们的文件中都对其进行定义。确保内敛定义对多文件程序中的所有文件都是可用的、最简便的方法是：将内联定义放在定义类的头文件中。根据改写规则，在类声明中定义方法 == 用原型替换方法定义。

5. 使用对象的成员函数，通过成员运算符

6. ostream类包含一些可用于控制格式的成员函数
   
   ```cpp
   std::cout.setf(std::ios_base::fixed, std::ios_base::floatfiled);
   // 设置了cout对象的一个标记，命令cout 使用定点表示法。避免科学计数法
   // 下面语句导致cout在使用定点表示法时，显示三位小数：
   std::cout.precision(3);
   // 修改将一直有效，直到再次修改
   std::cout.precision(prec);  // reset to old value
   // store original flags
   std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);
   
   // reset to stored values
   std::cout.setf(orig, std::ios_base::floatfield);
   ```

## 类的构造函数和析构函数

1. C++ 的目标之一是让使用类对象就像使用标准类型一样。数据部分的访问状态是私有的，这意味着程序不能直接访问数据成员。程序只有通过成员函数来访问数据成员，因此需要设计合适的成员函数，才能成功将对象初始化。

2. 一般来说，最好是在创建对象时对它进行初始化
   
   ```cpp
   Stock gift;
   gift.buy(10, 24.75);
   ```

3. C++提供一个特殊的成员函数——类构造函数，专门用于构造新对象、将值赋给它们的数据成员。

4. 构造函数的名称与类名相同。构造函数的原型和函数头——没有返回值，没有背声明void类型，没有声明类型。

### 声明和定义构造函数

1. 创建Stock的构造函数。需为Stock对象提供3个值，应为构造函数提供3个参数。程序员可能只想设置company成员，而将其他值设置为0；这可以使用默认参数来完成
   
   ```cpp
   // 原型如下
   // constructor prototype with some default arguments
   Stock(const string & co, long n = 0, double pr = 0.0);
   // 第一个参数是指向字符串的指针，该字符串用于初始化成员company。
   // n和pr参数为shares和shre_val成员提供值
   // 注意，没有返回类型。原型位于类声明的公有部分
   // constructor definition
   Stock::stock(const string & co, long n, double pr)
   {
       company = co;
       if (n < 0)
       {
           std::cerr << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
           shares = 0;
       }
       else
           shares = n;
       share_val = pr;
       set_tot();
   }            
   ```

> ### 成员名和参数名
> 
> 不熟悉构造函数会试图将类成员名称用作构造函数的参数名
> 
> ```cpp
> // No!
> Stock::Stock(const string & company, long shares, double share_val)
> {
>     ...
> }
> // 这是错误的。
> // 构造函数的参数表示的不是类成员，而是赋给类成员的值
> // 因此，参数名不能与类成员相同，否则最终代码是
> Shares = shares
> // 为避免这种混乱，一种常见的做法是在数据成员名中使用m_前缀：
> class Stock
> {
> private:
>     string m_company;
>     long m_shares;
> }
> 
> // 另一种常见做法是，在成员名中使用后缀_:
> class Stock
> {
> private:
>     string company_;
>     long shares_;
>     ...
> };
> 
> // 无论采用哪种做法，都可在公有接口中在参数名中包含company和shares
> ```

### 使用构造函数

1.两种使用构造函数来初始化对象的方式

+ 第一种方式是显式地调用构造函数：
  
  ```Cpp
  Stock food = Stock("World Cabbage", 250, 1.25);
  // 这将food对象的company成员设置为字符串“World Cabbage”
  // 将shares成员设置为250，以此类推
  ```

+ 另一种方式是隐式地调用构造函数
  
  ```Cpp
  Stock garmer("Furry Mason", 50, 2.5);
  // 这种格式更紧凑，它与下面的显示调用等价：
  Stock garmer = Stock("Furry Mason", 50, 2.5);
  ```
2. 每次创建类对象（甚至使用new动态分配内存）时，C++都使用类构造函数
   
   ```cpp
   Stock *pstock = new Stock("Electroshock Games", 18, 19.0);
   // 这条语句创建一个Stock对象，将其初始化为参数提供的值
   // 并将该对象的地址赋给pstock指针
   // 在这种情况下，对象没有名称，但可以使用指针来管理该对象
   ```

3. 构造函数的使用方式不同于其他类方法。一般来说，使用对象来调用方法
   
   ```Cpp
   stock1.show();    // stock1 object invokes show() method
   // 但无法使用对象来调用构造函数
   // 因为在构造函数构造出对象之前，对象是不存在的
   // 构造函数被用来创建对象，而不能通过对象来调用
   ```

### 默认构造函数

1. 默认构造函数是在未提供显式初始值时，用来创建对象的构造函数。
   
   ```cpp
   Stock fluffy_the_cat;    // uses the default constructor
   // 如果没有提供任何构造函数，则C++将自动提供默认构造函数。
   // 它是默认构造函数的隐式版本，不做任何工作。
   // 默认构造函数可能如下：
   Stock::Stock() { }
   // 因此将创建fluffy_the_cat对象，但不初始化其成员，这和下面的语句创建x
   int x;
   // 默认构造函数没有参数，因为声明中不包含值
   ```

2. 当且仅当没有定义任何构造函数时，编译器才会提供默认构造函数。为类定义了构造函数后，程序员就必须为它提供默认构造函数。

3. 如果提供了非默认构造函数(如Stock(const char * co, int n, double pr))，但没有提供默认构造函数，则下面的声明将出错
   
   ```Cpp
   Stock stock1;    // not possible with current constructor
   // 原因是想禁止创建未初始化的对象
   ```

4. 如果要创建对象，而不显式地初始化，则必须定义一个不接受任何参数的默认构造函数。

5. 定义默认构造函数的方式有两种：
   
   + 给已有构造函数的所有参数提供默认值
     
     ```cpp
     Stock(const string & co = "Error", int n = 0, double pr = 0.0);
     ```
   
   + 通过函数重载来定义另一个构造函数——一个没有参数的构造函数；
     
     ```cpp
     Stock();
     // 由于只能有一个默认构造函数，因此不要同时采用这两种方式
     ```

6. 通常应初始化所有的对象，以确保所有成员一开始就有已知的合理值。因此用户定义的默认构造函数通常给所有成员提供隐式初始值。
   
   ```Cpp
   Stock::Stock()    // default constructor
   {
       company = "no name";
       shares = 0;
       share_val = 0.0;
       total_val = 0.0;
   }
   // 在设计类时，通常应提供对所有类成员做隐式初始化的默认构造函数
   ```

7. 使用上述任何一种方式（没有参数或所有参数都有默认值）创建了默认构造函数后，便可以声明对象变量，而不对它们进行显式初始化：
   
   ```CPP
   Stock first;                   // calls default constructor      
   Stock first = Stock();         // calls it explicitly
   Stock *prelief = new Stock;    // calls it implicitly    
   // 然而，不要被非默认构造函数的隐式形式所误导:
   Stock first("Concrete Conglomerate");    // calls constructor
   Stock second();                          // declares a function
   Stock third;                             // calls default constructor
   // 第一个声明调用非默认构造函数，即接受参数的构造函数
   // 第二个声明指出，second()是一个返回Stock对象的函数
   // 隐式地调用默认构造函数时，不要使用圆括号
   ```

### 析构函数

1. 用构造函数创建对象后，程序负责跟踪该对象，直到其过期为止。对象过期时，程序将自动调用一个特殊的成员函数，该函数叫做——析构函数。析构函数完成清理工作。

2. 如果构造函数使用**new** 来分配内存，则析构函数将使用**delete** 来释放这些内存。

3. 析构函数没有需要完成的任务，在这种情况下，只需让编译器生成一个什么要不做的隐式析构函数即可

4. 在类名前加上~。如Stock类的析构函数为~Stock()

5. 和构造函数一样，析构函数也可以没有返回值和声明类型。

6. 与构造函数不同的是，西沟函数没有参数，因此Stock析构函数的原型必须是
   
   ```cpp
   ~Stock();
   // 由于Stock的析构函数不承担任何重要的工作，因此可以将它编写为不执行任何操作的函数：
   Stock::~Stock()
   {
       
   }
   ```

7. 什么时候应调用析构函数呢？由编译器决定，通常不应在代码中显式地调用析构函数。
   
   + 如果创建的是静态存储类对象，则其析构函数将在程序结束时自动被调用。
   
   + 如果创建的是自动存储类对象，则其析构函数将在程序执行完代码块时(该对象是在其中定义的)自动被调用。
   
   + 如果对象是通过**new**创建的，则它将驻留在栈内存或自由存储区中，当使用delete来释放内存时，其析构函数将自动被调用。
   
   + 程序可以创建临时对象来完成特定的操作，在这种情况下，程序将在结束对该对象的使用时自动调用其析构函数。

8. 由于在类对象过期时析构函数将自动被调用，因此必须有一个析构函数。如果 没有提供析构函数，编译器将隐式地声明一个默认析构函数，并在发现导致对象被删除的代码后，提供默认析构函数的定义
