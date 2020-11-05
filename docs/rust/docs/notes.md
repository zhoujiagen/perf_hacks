# Notes of Rust

## 1 资源

- Jim Blandy, Jason Orendorff. Programming Rust: Fast, Safe Systems Development. O’Reilly Media: 2018.
- [Evcxr](https://github.com/google/evcxr): An evaluation context for Rust.


### [Learn Rust](https://www.rust-lang.org/learn)

- [the Book](https://doc.rust-lang.org/book/): The Rust Programming Language
- [the Rust standard library](https://doc.rust-lang.org/std/index.html): Comprehensive guide to the Rust standard library APIs.
- [The Rust Reference](https://doc.rust-lang.org/reference/index.html): The Reference is not a formal spec, but is more detailed and comprehensive than the book.
- [The Rustonomicon](https://doc.rust-lang.org/nomicon/index.html): The Rustonomicon is your guidebook to the dark arts of unsafe Rust. It’s also sometimes called “the ’nomicon.”
- [The Rust Unstable Book](https://doc.rust-lang.org/nightly/unstable-book/index.html): The Unstable Book has documentation for unstable features that you can only use with nightly Rust.
- [Command Line Book](https://rust-cli.github.io/book/index.html): Learn how to build effective command line applications in Rust.
- [WebAssembly Book](https://rustwasm.github.io/docs/book/): Use Rust to build browser-native libraries through WebAssembly.
- [Embedded Book](https://doc.rust-lang.org/embedded-book): Become proficient with Rust for Microcontrollers and other embedded systems.

## 2 介绍

### Vocabulary

- ownership: 属主关系, 所有者关系
- move: 移动
- borrow: 借
- reference: 引用
- deref coercion: 解引用转换
- crate: 柳条箱
- module: 模块
- struct: 结构
- enum: 枚举
- pattern: 模式
- traits: 特质
- generics: 泛型
- block: 语句块
- closure: 闭包
- concurrency: 并发
- macros: 宏
- unsafe code: 不安全的代码
- raw pointers: 裸指针
- item: 项, 可以出现在程序或模块中的声明, 例如`fn`、`struct`、`use`等

## 3 数据类型

### 标量类型

整数类型:

- `i8`,`i16`,`i32`,`i64`, `u8`,`u16`,`u32`,`u64`: 有符号与无符号整数
- `isize`, `usize`: 有符号与无符号整数, 机器地址位数

浮点数类型:

- `f32`, `f64`: 浮点数

布尔类型:

- `bool`: 布尔型

字符类型:

- `char`: Unicode字符, 32位

### 复合类型

元组:

- `(char, u8, i32)`: 元组, 允许混合类型
- `()`: 单位/空元组

数组, 向量, 切片:

- `[T; N]`: `N`个类型为`T`的值的数组. 大小为编译时常量. 例: `[f64; 4]`, `[u8; 256]`
- `Vec<T>`: `T`的向量. 动态分配, 大小可变. 例: `Vec<f64>`<br>
`Vec<T>`由三个值构成: 指向堆中存放元素的缓冲区的指针, 缓冲区的容量, 缓冲区的当前长度.
- `&[T]`、`&mut [T]`: `T`的共享切片、`T`的可变切片. 数组或向量中部分值的引用. 例: `&[u8]`, `&mut [u8]`<br>
切片总是按引用传递. <br>
切片的引用是胖指针: 两个字的值, 指向切片首元素的指针和切片中元素的数量.<br>
- 搜索方法时, 自动将数组、向量转换为切片, 以使用切片上定义的方法.


字符串:

- `String`: UTF-8字符串, 动态大小
- `&str`: `str`的引用, 不拥有UTF-8文本的指针

结构体:

- `struct S { x: f32, y: f32 }`: 命名字段的结构
- `struct T(i32, char)`: 类元组的结构
- `struct E`: 类单位的结构, 没有字段

枚举:

- ```enum Attend { OnTime, Late(u32) }```: 枚举, 代数数据类型

特质对象:

- `&Any`, `&mut Read`: 特质对象(实现了一组给定方法的任意值的引用)

函数指针:

- ```fn(&str, usize) -> isize```: 函数指针
- ```|a, b| a*a + b*b```: 闭包示例

### 指针类型

#### 引用

- `&T`: 不可变引用, 类似于C中`const T*`
- `&mut T`: 可变引用, 类似于C中`T*`
- 表达式`&x`: 借一个对`x`的引用
- 给定引用`r`, 解引用`*r`表示`r`指向的值
- 引用在离开作用域时, 不自动释放资源
- Rust的引用从不为null
- 可以引用栈或堆中的值

#### 智能指针

- `Rc<T>`允许一份数据多个所有者, 而`Box<T>`、`RefCell<T>`都只有一个所有者.
- `Box<T>`允许在编译时检查的可变或不可变借用; <br>`Rc<T>`仅允许编译时检查的不可变借用; <br>`RefCell<T>`允许运行时检查的可变或不可变借用.
- `RefCell<T>`本身是不可变的, 但允许在运行时检查可变借用, 所以能够改变其中存储的值.


(1) 箱(Boxes): `Box<T>`

``` rust
let t = (12, "eggs");
let b = Box::new(t);  // 在堆中分配元组
```

- `b`的类型: `Box<i32, &str>`
- 当`b`离开作用域时, 其内存立即释放, 处理已被移动(例如在函数中返回)

(2) 引用计数: `Rc<T>`, `Arc<T>`

(3) 内部可变模式: `RefCell<T>`, ``

#### 裸指针

- `*mut T`
- `*const T`
- 使用原始指针是不安全的
- 只能在`unsafe`块中借引用原始指针

裸指针与引用、智能指针的区别:

- 允许忽略借用规则, 可以同时拥有指向同一个内存地址的可变和不可变指针, 或者拥有指向同一个地址的多个可变指针;
- 不能保证自己总是指向了有效的内存地址;
- 允许为空;
- 没有实现任何自动清理机制.


## 4 属主关系(Ownership)

### 所有权规则

- Rust的每个值都有一个对应的变量作为它的所有者;
- 在同一时间内, 值有且仅有一个所有者;
- 当所有者离开他自己的作用域时, 它持有的值就会被释放掉.

## 5 引用(References)

### 引用的规则

- 在任何一段给定的时间内, 要么只能拥有一个可变引用, 要么只能拥有任意数量的不可变引用;
- 引用总是有效的.

### 自动引用和解引用

当使用`object.something()`调用方法时, Rust会自动为调用者`object`添加`&`、`& mut`或`*`, 以使其能够符合方法的签名.

例如:

``` rust
p1.distance(&p1);   // 等价于:
(&p1).distance(&p2);
```

### 解引用转换(deref coercion)

当某个类型`T`实现了`Deref` trait时, Rust能够将`T`的引用转换为`T`经过`Deref`操作后生成的引用. 当将某个类型的值引用作为参数传递给函数或方法, 但传入的类型与参数类型不一致时, 解引用转换自动发生: 编译器或插入一些列的`deref()`将提供的类型转换为参数所需的类型.

Rust会在类型与trait满足下面情形时, 执行解引用转换:

- 当`T: Deref<Target=U>`时, 运行`&T`转换为`&U`;
- 当`T: DerefMut<Target=U>`时, 允许`&mut T`转换为`&mut U`;
- 当`T: Deref<Target=U>`时, 允许`&mut T`转换为`&U`.


例:

``` rust
struct MyBox<T>(T);

impl<T> MyBox<T> {
  fn new(x: T) -> MyBox<T> {
    MyBox(x)
  }
}

use std::ops::Deref;
impl<T> Deref for MyBox<T> {
  type Target = T;

  // 返回一个指向值的引用, 允许调用者通过*运算符访问值
  fn deref(&self) -> &T {
    &self.0
  }
}


fn hello(name: &str) {
  println!("Hello, {}", name);
}

fn main() {
  let m = MyBox::new(String::from("Rust"));

  // 解引用转换: &MyBox<String> => &String => &str
  hello(&m); // 等价于:
  hello(&(*m)[..]);
}
```


## 6 表达式

### 语句块

- 语句块是表达式
- 语句块的最后一行行尾有分号(`;`)时, 返回值为`()`; 没有分号时, 返回值是最后一个表达式的值

### 声明

``` rust
let name: type = expr;
```

- `let`声明变量时可以不初始化

``` rust
let name;
if user.has_nickname() {
  name = user.nickname();
} else {
  name = generate_unique_name();
  user.register(&name);
}
```

- 覆盖声明

``` rust
for line in file.lines() {  // 变量line: Result<String, io::Error>
  let line = line?;         // 变量line: String
  ...
}
```

- 语句块中可以包含项声明.

### `if`、`match`、`if let`

``` rust
if condition1 {
  block1
} else if confition2 {
  block2
} else {
  blockn
}
```

``` rust
match value {
  pattern => expr,
  ...
}
```

``` rust
if let pattern = expr {
  block1
} else {
  block2
}
```

### 循环

- `while`、`while let`

``` rust
while condition {
  block
}

while let pattern = expr {

}
```

- `loop`

``` rust
loop {
  block
}
```

- `for`

``` rust
for pattern in collection {
  block
}
```

- `break`表达式退出包裹的循环
- `continue`表达式跳到下一迭代

- 循环可以用生命周期标记, 例:

``` rust
'search:
for room in apartment {
  for spot in room.hiding_spots() {
    if spot.contains(keys) {
      println!("your keys are {} in the {}.", spot, room);
      break 'earch;       // 退出外部循环
    }
  }
}
```

- `!`: 不会正常结束的表达式的类型

例:

``` rust
fn serve_forever(socket: ServerSocket, handler: ServerHandler) -> ! {
  socket.listen();
  loop {
    let s = socket.accept();
    handler.handle(s);
  }
}
```

### `return`表达式

- `return`表达式退出当前函数, 返回值给调用者

`?`操作符:

``` rust
let output = File::create(filename)?; // 等价于

let output = match File::create(filename) {
  Ok(f) => f,
  Err(err) => return Err(err)
}
```

### 函数和方法调用

- 函数调用

``` rust
let x = gcd(1302, 462);
```

- 方法调用

``` rust
let room = player.location();
```

- 静态方法调用

``` rust
let mut numbers = Vec::new();

// ::<T>, turbofish
return Vec::<i32>::with_capacity(1000);
let ramp = (0 .. n).colllect::<Vec<i32>>();
```

### 字段和元素

``` rust
game.black_pawns      // 结构体字段
coords.1              // 元组元素
pieces[i]             // 数组元素

// 作为左值(lvalues)
game.black_pawns = 0x00ff0000_00000000_u64;
coords.1 = 0;
pieces[2] = Some(Piece::new(Black, knight, coords));
```

- `..`操作符

``` rust
let second_half = &game_moves[midpoint .. end];   // 提取切片

..            // RangeFull
a ..          // RangeFrom {start: a}
.. b          // RangeTo {end: b}
a .. b        // Range {start: a, end: b}

0 .. 4        // 0, 1, 2, 3
```

### 引用操作符

- `*`操作符: 访问引用指向的值

``` rust
let padovan: Vec<u64> = ...
for elem in &padovan {          // elem: &u64
  draw_triangle(turtle, *elem); // *elem: u64
}
```

### 算术、位、比较、逻辑操作符

- 算术操作符

``` rust
+, wrapping_add()
-, wrapping_sub()
*, wrapping_mul()
/, wrapping_div()
%, wrapping_rem()
```

- 位操作符: `&`、`|`、`^`、`!`、`<<`、`>>`

- 比较操作符: `==`、`!=`、`<`、`<=`、`>`、`>=`

- 逻辑操作符: `&&`、`||`

### 赋值

- `=`赋值移动不可拷贝类型的值
- 支持复合赋值: `+=`、`*=`等

### 类型转换

- `as`关键字

``` rust
let x = 17;
let index = x as usize;
```

- 内置数值类型可以互相转换
- `bool`、`char`、类C的`enum`类型, 可以转换为整数类型
- `mut`引用可以直接转换为非`mut`引用

解引用转换:

- `&String`类型的值直接转换为`&str`类型
- `&Vec<i32>`类型的值直接转换为`&[i32]`
- `&Box<Chessboard>`类型的值直接转换为`&Chessboard`

### 优先级和结合性

- [表达式的优先级](https://doc.rust-lang.org/reference/expressions.html#expression-precedence)

按优先级从高到底:

|表达式类型|示例|相关特质|
|:---|:---------------------------------------------------|:---|
|数组字面量|`[1,2,3]`||
|重复的数组字面量|`[0; 50]`||
|元组|`(6, "crullers")`||
|分组|`(2 + 2)`||
|语句块|`{ f(); g() }`||
|控制流表达式|`if ok { f() }`<br>`if ok { 1 } else {0}`<br>`if let some(x) = f() { x } else { 0 }`<br>`match x { None => 0, _ => 1 }`<br>`for v in e { f(v); }`<br>`while ok { ok = f(); }`<br>`while let Some(x) = it.next() { f(x); }`<br>`loop { next_event(); }`<br>`break`<br>`continue`<br>`return 0`|<br><br><br><br>`std::iter::IntoIterator`|
|宏调用|`println!("ok")`||
|路径|`std::f64::consts::PI`||
|结构体字面量|`Point {x: 0, y: 0}`||
|元组字段访问|`pair.0`|`Deref`、`DerefMut`|
|结构体字段访问|`point.x`|`Deref`、`DerefMut|
|方法调用|`point.translate(50, 50)`|`Deref`、`DerefMut|
|函数调用|`stdin()`|`Fn(Arg0, ...) -> T`<br>`FnMut(Arg0, ...) -> T`<br>`FnOnce(Arg0, ...) -> T`|
|索引`arr[0]`|`Index`、`IndexMut`、`Deref`、`DerefMut`|
|错误检测|`create_dir("tmp")?`||
|逻辑/位的非|`!ok`|`Not`|
|补|`-num`|`Neg`|
|解引用|`*ptr`|`Deref`、`DerefMut`|
|借|`&val`||
|类型转换|`x as u32`||
|乘|`n * 2`|`Mul`|
|除|`n / 2`|`Div`|
|取模|`n % 2`|`Rem`|
|加|`n + 1`|`Add`|
|减|`n - 1`|`Sub`|
|左移位|`n << 1`|`Shl`|
|右移位|`n >> 1`|`Shr`|
|位与|`n & 1`|`BitAnd`|
|位异或|`n ^ 1`|`BitXor`|
|位或|`n | 1`|`BitOr`|
|小于|`n < 1`|`std::com::PartialOrd`|
|小于等于|`n <= 1`|`std::com::PartialOrd`|
|大于|`n > 1`|`std::com::PartialOrd`|
|大于等于|`n >= 1`|`std::com::PartialOrd`|
|等于|`n == 1`|`std::com::PartialEq`|
|不等于|`n != 1`|`std::com::PartialEq`|
|逻辑与|`x.ok && y.ok`||
|逻辑或|`x.ok || y.ok`||
|范围|`start .. stop`||
|赋值|`x = val`||
|复合赋值|`x *= 1`<br>`x /= 1`<br>`x %= 1`<br>`x += 1`<br>`x -= 1`<br>`x <<= 1`<br>`x >>= 1`<br>`x &= 1`<br>`x ^= 1`<br>`x |= 1`| `MulAssign`<br>`DivAssign`<br>`RemAssign`<br>`AddAssign`<br>`SubAssign`<br>`ShlAssign`<br>`ShrAssign`<br>`BitAndAssign`<br>`BitXorAssign`<br>`BitOrAssign`|
|闭包|`|x, y| x + y`||

- 可被链在一起的操作符是左结合的: `*`、`/`、`%`、`+`、`-`、`<<`、`>>`、`&`、`^`、`|`、`&&`、`||`、`as`
- 不可被链在一起的操作符: 比较操作符、赋值操作符、范围操作符

## 7 错误处理

`?`操作符:

``` rust
use std::error:Error;
use std::fs::File;

fn main() -> Result<(), Box<dyn Error>> {
  let f = File::open("hello.txt")?;
  Ok(())
}
```

## 8 柳条箱(Crates)和模块(Modules)

## 9 结构体



## 10 枚举和模式

### 模式匹配

可以使用模式的场景:

- `match`分支
- `if let`条件表达式
- `while let`条件循环
- `for`循环
- `let`语句
- 函数的参数


模式:

|模式类型|示例|说明|
|:---|:---|:---|
|字面量|`100`, `"name"`|匹配精确值, `const`值也允许|
|范围|`0 ... 100`, `'a' ... 'k'`|匹配在范围中的值: `[0, 100]`|
|通配符|`_`|匹配任何值, 并忽略它|
|变量|`name`, `mut count`|类似于`_`, 但移动或拷贝值到新的本地变量中|
|ref变量|`ref field`, `ref mut field`|借匹配的值的引用, 而不是移动或拷贝它|
|与子模式绑定|`val @ 0 ... 99`, `ref circle @ Shape::Circle{..}`|匹配`@`右侧的模式, 将匹配值绑定到`@`左侧的变量上|
|枚举模式|`Some(value)`, `None`, `Pet::Orca`||
|元组模式|`(key, value)`, `(r, g, b)`||
|结构体模式|`Color(r,g,b)`, `Point{x,y}`, `Card{suit:Clubs, rank: n}`, `Account {id, name, ..}`||
|引用|`&value`, `&(k,v)`|只匹配引用值|
|多个模式|`'a'|'A'`|只在`match`中有效|
|护卫表达式|`x if x * x <= r2`|只在`match`中有效|


## 11 特质(Traits)和泛型(Generics)

### trait对象

trait对象被专门用于抽象某些共有行为.

trait对象能够指向实现了指定trait的类型实例, 以及一个在运行时查找trait方法的表.

创建trait对象: 选用一种指针(例如`&`引用或`Box<T>`智能指针等), 并添加`dyn`关键字与指定相关trait. 例:

``` rust
pub trait Draw {
  fn draw(&self);
}

pub struct Screen {
  pub components: Vec<Box<dyn Draw>>,
}

// 使用带有trait约束的泛型参数
//pub struct Screen<T: Draw> {
//  pub components: Vec<T>,
//}
```

## 12 操作符重载

## 13 工具特质

- `Write`: `write_fmt()`
- `FromStr`: `from_str()`


### `Drop`

### `Sized`

### `Clone`

### `Copy`

### `Deref`, `DerefMut`

### `Default`

### `AsRef`, `AsMut`

### `Borrow`, `BorrowMut`

### `From`, `Into`

### `ToOwned`

### `Cow`


## 14 闭包(Closure)

- 闭包由参数列表(`||`之间)、表达式构成; 调用闭包与调用函数语法相同

``` rust
let is_even = |x| x % 2 == 0;
let is_even = |x: u64| -> bool { x % 2 == 0 };
assert_eq!(is_even(14), true);
```

## 15 迭代器(Iterators)

## 16 集合

## 17 字符串和文本

## 18 输入输出

## 19 并发

## 20 宏(Macros)

### 声明宏: `macro_rules!`

### 过程宏

#### 自定义派生宏: `#[proc_macro_derive(Xxx)`
#### 属性宏: `#[proc_macro_attribute]`
#### 函数宏: `#[proc_macro]`

## 21 不安全的代码(Unsafe Code)

不安全超能力(unsafe superpower):

- 解引用裸指针
- 调用不安全的函数或方法
- 访问或修改可变的静态变量
- 实现不安全trait
