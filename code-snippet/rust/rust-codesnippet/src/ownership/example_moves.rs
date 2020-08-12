//! 移动值的示例.

use std::string::ToString;

#[allow(dead_code)]
pub fn example_main() {
    initialization();
    assignment();
    more_operations();
    indexed_content();
}


/// 初始化
#[allow(dead_code)]
fn initialization() {
    let s = vec!["unon".to_string(), "ramen".to_string(), "soba".to_string()];
    let _t = s;
    // let u = s; // use of moved value
}

/// 赋值
#[allow(dead_code)]
fn assignment() {
    #[allow(unused_assignments)]
        let mut s = "Govinda".to_string(); // 初始化
    s = "Siddhartha".to_string();   // 变量赋值

    let _t = s;                     // 移动
    s = "Siddhartha".to_string();   // 给未初始化的变量赋值
    println!("{}", s);
}

/// 从函数返回值, 向函数传递值, 结构中构造新值
#[allow(dead_code)]
fn more_operations() {
    struct Person { name: String, birth: i32 }

    let mut composers = Vec::new(); // 从函数返回值
    composers.push(Person {                 // 向函数传递值
        name: "Palestrina".to_string(),            // 结构中构造新值
        birth: 1525,
    });
}

/// 带索引的值
#[allow(dead_code)]
fn indexed_content() {
    let mut v = Vec::new();
    for i in 101..106 {
        v.push(i.to_string());
    }

    // let third = v[2]; // cannot move

    // 移出元素

    let fifth = v.pop().unwrap();           // 弹出元素
    assert_eq!(fifth, "105");
    println!("{}", fifth);

    let second = v.swap_remove(1);  // 交换移除
    assert_eq!(second, "102");
    println!("{}", second);

    let third = std::mem::replace(&mut v[2], "substitute".to_string()); // 内存替换
    assert_eq!(third, "103");
    println!("{}", third);

    assert_eq!(v, vec!["101", "104", "substitute"]);


    // 在循环中消费集合中元素

    let vs = vec!["liberte".to_string(), "egalite".to_string(), "fraternite".to_string()];
    for mut s in vs {    // 移动向量, 每个迭代中移动元素
        s.push('!');
        println!("{}", s);
    }

    // 移动结构序列中某一结构的字段
    struct Person { name: Option<String>, birth: i32 }
    let mut composers = Vec::new();
    composers.push(Person {
        name: Some("Palestrina".to_string()),
        birth: 1525,
    });

    // let first_name = composers[0].name // cannot move
    let first_name = std::mem::replace(&mut composers[0].name, None);
    assert_eq!(first_name, Some("Palestrina".to_string()));
    assert_eq!(composers[0].name, None);

    let _none = std::mem::replace(&mut composers[0].name, Some("aaa".to_string()));
    let now_name = composers[0].name.take();
    assert_eq!(now_name, Some("aaa".to_string()));
    assert_eq!(composers[0].name, None);
}
