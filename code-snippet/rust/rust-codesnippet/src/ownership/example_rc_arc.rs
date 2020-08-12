//! Rc和Arc的示例.

#[allow(dead_code)]
pub fn example_main() {
    use std::rc::Rc;

    let s = Rc::new("shirataki".to_string());
    let t = s.clone();
    let _u = s.clone();

    // Rc<T>可以使用T上方法
    assert!(s.contains("shira"));
    assert_eq!(t.find("taki"), Some(5));

    // s.push_str(" noodles"); // cannot borrow data in an `Rc` as mutable
}