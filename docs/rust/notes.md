# Notes of Rust

## 1 资源

- Jim Blandy, Jason Orendorff. Programming Rust: Fast, Safe Systems Development. O’Reilly Media: 2018.

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
- crate: 柳条箱
- module: 模块
- struct: 结构
- enum: 枚举
- pattern: 模式
- traits: 热值
- generics: 泛型
- closure: 闭包
- concurrency: 并发
- macros: 宏
- unsafe code: 不安全的代码
- raw pointers: 裸指针

## 3 基本类型

- `i8`,`i16`,`i32`,`i64`, `u8`,`u16`,`u32`,`u64`: 有符号与无符号整数
- `isize`, `usize`: 有符号与无符号整数, 机器地址位数
- `f32`, `f64`: 浮点数
- `bool`: 布尔型
- `char`: Unicode字符, 32位
- `(char, u8, i32)`: 元组, 允许混合类型
- `()`: 单位/空元组
- `struct S { x: f32, y: f32 }`: 命名字段的结构
- `struct T(i32, char)`: 类元组的结构
- `struct E`: 类单位的结构, 没有字段
- ```enum Attend { OnTime, Late(u32) }```: 枚举, 代数数据类型
- `Box<Attend>`: 拥有堆中值的指针
- `&i32`, `&mut i32`: 共享与可变引用
- `String`: UTF-8字符串, 动态大小
- `&str`: `str`的引用, 不拥有UTF-8文本的指针
- `[f64; 4]`, `[u8; 256]`: 数组, 固定长度, 元素类型相同
- `Vec<f64>`: 向量, 变长, 元素类型相同
- `&[u8]`, `&mut [u8]`: 切片的引用, 数组或向量中部分的引用, 由指针和长度构成
- `&Any`, `&mut Read`: 特质对象(实现了一组给定方法的任意值的引用)
- ```fn(&str, usize) -> isize```: 函数指针
- ```|a, b| a*a + b*b```: 闭包示例

### 指针类型

#### 引用(References)

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


##### 箱(Boxes): `Box<T>`

``` rust
let t = (12, "eggs");
let b = Box::new(t);  // 在堆中分配元组
```

- `b`的类型: `Box<i32, &str>`
- 当`b`离开作用域时, 其内存立即释放, 处理已被移动(例如在函数中返回)

##### 引用计数: `Rc<T>`, `Arc<T>`


##### 内部可变模式: `RefCell<T>`, ``

#### 裸指针(Raw Pointers)

- `*mut T`
- `*const T`
- 使用原始指针是不安全的
- 只能在`unsafe`块中借引用原始指针

裸指针与引用、智能指针的区别:

- 允许忽略借用规则, 可以同时拥有指向同一个内存地址的可变和不可变指针, 或者拥有指向同一个地址的多个可变指针;
- 不能保证自己总是指向了有效的内存地址;
- 允许为空;
- 没有实现任何自动清理机制.


### 数组, 向量, 切片

- `[T; N]`: `N`个类型为`T`的值的数组. 大小为编译时常量.
- `Vec<T>`: `T`的向量. 动态分配, 大小可变. <br>
`Vec<T>`由三个值构成: 指向堆中存放元素的缓冲区的指针, 缓冲区的容量, 缓冲区的当前长度.
- `&[T]`、`&mut [T]`: `T`的共享切片、`T`的可变切片. 数组或向量中部分值的引用. <br>
切片总是按引用传递. <br>
切片的引用是胖指针: 两个字的值, 指向切片首元素的指针和切片中元素的数量.<br>
- 搜索方法时, 自动将数组、向量转换为切片, 以使用切片上定义的方法.

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

- [表达式的优先级](https://doc.rust-lang.org/reference/expressions.html#expression-precedence)

## 7 错误处理

## 8 柳条箱(Crates)和模块(Modules)

## 9 结构

## 10 枚举和模式

### 模式匹配

可以使用模式的场景:

- `match`分支
- `if let`条件表达式
- `while let`条件循环
- `for`循环
- `let`语句
- 函数的参数

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
