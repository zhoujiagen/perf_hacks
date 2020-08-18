extern crate crossbeam;
extern crate iron;
#[macro_use]
extern crate mime;
extern crate rand;
extern crate router;
extern crate urlencoded;

mod tour;
mod tests;
mod basic_types;
mod ownership;
mod references;
mod smart_pointers;

fn main() {
    // tour();
    // basic_types();
    // ownership();
    // references();
    smart_pointers();
    // expressions();
    // error_handling();
    // structs();
    // patterns();
    // traits();
    // generics();
    // operators();
    // closures();
    // collections();
    // texts();
    // io();
    // concurrency();
    // macros();
    // unsafes();

    println!("done!");
}

/// a tour of Rust
#[allow(dead_code)]
fn tour() {
    tour::example_gcd();
    tour::example_cmd_arg();
    tour::example_mandelbrot();
    tour::example_server();
}

/// 基本类型
#[allow(dead_code)]
fn basic_types() {
    use crate::basic_types::*;
    example_array::example_main();
    example_vec::example_main();
    example_slice::example_main();
    example_string::example_main();
}

/// 属主关系
#[allow(dead_code)]
fn ownership() {
    use crate::ownership::*;
    example_moves::example_main();
    example_copy_types::example_main();
    example_rc_arc::example_main();
}

/// 引用
#[allow(dead_code)]
fn references() {
    use crate::references::*;
    // example_reference::example_main();
    example_ref_as_values::example_main();
}

/// 智能指针
#[allow(dead_code)]
fn smart_pointers() {
    use crate::smart_pointers::*;
    example_weak::example_main();
}


/// 表达式
#[allow(dead_code)]
fn expressions() {}

/// 错误处理
#[allow(dead_code)]
fn error_handling() {}

/// 结构体
#[allow(dead_code)]
fn structs() {}

/// 枚举和模式
#[allow(dead_code)]
fn patterns() {}

/// 特质
#[allow(dead_code)]
fn traits() {}

/// 泛型
#[allow(dead_code)]
fn generics() {}

/// 操作符重载
#[allow(dead_code)]
fn operators() {}

/// 闭包
#[allow(dead_code)]
fn closures() {}

/// 迭代器与集合
#[allow(dead_code)]
fn collections() {}

/// 字符串与文本
#[allow(dead_code)]
fn texts() {}

/// 输入与输出
#[allow(dead_code)]
fn io() {}

/// 并发
#[allow(dead_code)]
fn concurrency() {}

/// 宏
#[allow(dead_code)]
fn macros() {}

/// 不安全的代码
#[allow(dead_code)]
fn unsafes() {}
