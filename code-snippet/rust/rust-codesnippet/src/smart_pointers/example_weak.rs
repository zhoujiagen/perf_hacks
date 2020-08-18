//! `Weak<T>`的示例.


use std::cell::RefCell;
use std::rc::{Rc, Weak};

/// 节点定义.
#[derive(Debug)]
struct Node {
    /// 节点值
    value: i32,
    /// 父节点
    parent: RefCell<Weak<Node>>,
    /// 子节点
    children: RefCell<Vec<Rc<Node>>>,
}


#[allow(dead_code)]
pub fn example_main() {
    let leaf = Rc::new(Node {
        value: 3,
        parent: RefCell::new(Weak::new()),
        children: RefCell::new(vec![]),
    });

    println!("leaf parent = {:?}", leaf.parent.borrow().upgrade());     // 读取值

    let branch = Rc::new(Node {
        value: 5,
        parent: RefCell::new(Weak::new()),
        children: RefCell::new(vec![Rc::clone(&leaf)]),
    });

    *leaf.parent.borrow_mut() = Rc::downgrade(&branch);         // *: 修改值

    println!("leaf parent = {:?}", leaf.parent.borrow().upgrade());
}