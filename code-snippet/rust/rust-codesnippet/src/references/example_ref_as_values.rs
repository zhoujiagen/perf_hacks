//! 引用作为值的示例.

pub fn example_main() {
    // create_and_dereference();
    // dot_operator_with_ref();
    assign_to_ref();
}

/// 创建共享引用和解引用
#[allow(dead_code)]
fn create_and_dereference() {
    let x = 10;             // Copy
    let r = &x;            // 共享引用: Copy
    assert_eq!(*r, 10);           // 显式解引用

    let mut y = 32;
    let m = &mut y;   // 可变引用: not Copy
    *m += 32;                     // 显式解引用
    assert_eq!(*m, 64);
}

/// .操作符与其左操作数: 自动解引用, 自动借左操作符的引用
#[allow(dead_code)]
fn dot_operator_with_ref() {
    struct Anime { name: &'static str, bechdel_pass: bool }
    ;
    let aria = Anime { name: "Aria: The Animation", bechdel_pass: true };

    let anime_ref = &aria;
    assert_eq!(anime_ref.name, "Aria: The Animation");
    assert_eq!((*anime_ref).name, "Aria: The Animation");

    let mut v = vec![1973, 1968];
    v.sort();
    (&mut v).sort();
}

/// 给引用赋值
#[allow(dead_code)]
fn assign_to_ref() {
    let x = 10;
    let y = 20;
    let mut r = &x;

    use rand::random;
    if random() {
        r = &y;
    }
    assert!(*r == 10 || *r == 20);
}
