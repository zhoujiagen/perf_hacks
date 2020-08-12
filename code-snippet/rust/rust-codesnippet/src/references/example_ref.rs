//! 示例: 传值, 传共享引用, 传可变引用.
use std::collections::HashMap;

/// `HashMap<String, Vec<String>>`的类型别名
type Table = HashMap<String, Vec<String>>;

#[allow(dead_code)]
pub fn example_main() {
    let mut table = Table::new();
    table.insert("Gesualldo".to_string(),
                 vec!["many madrigals".to_string(),
                      "Tenebra Responsoria".to_string()]);
    table.insert("Caravaggio".to_string(),
                 vec!["The Musicians".to_string(),
                      "The Calling of St. Matthew".to_string()]);
    table.insert("Cellini".to_string(),
                 vec!["Perseus with the head of Medusa".to_string(),
                      "a salt cellar".to_string()]);
    // 传值
    // show(table);
    // ERROR: not found in this scope
    // assert!(table[Gesualldo][0], "many madrigals");

    // 传共享引用
    show_ref(&table);
    assert_eq!(table["Gesualldo"][0], "many madrigals");

    // 传可变引用
    sort_works(&mut table);
    println!("after sort:");
    show_ref(&table);
}

/// HashMap不是Copy, 传递值表示移动属主关系
#[allow(dead_code)]
fn show(table: Table) {
    for (artist, works) in table {
        println!("works by {}:", artist);
        for work in works {
            println!(" {}", work);
        }
    }
}

/// 传递共享引用参数: 是Copy
fn show_ref(table: &Table) {
    for (artist, works) in table {
        println!("works by {}:", artist);
        for work in works {
            println!(" {}", work);
        }
    }
}

/// 传递可变引用参数: 不是Copy
fn sort_works(table: &mut Table) {
    for (_artist, works) in table {
        works.sort();
    }
}