//! 向量的示例.

#[allow(dead_code)]
pub fn example_main() {
    let mut v = vec![2, 3, 5, 7];
    assert_eq!(v.iter().fold(1, |a, b| a * b), 210);
    v.push(11);
    v.push(13);
    assert_eq!(v.iter().fold(1, |a, b| a * b), 30030);

    let mut v2 = Vec::new();
    v2.push("step");    // 插入
    v2.push("on");
    v2.push("no");
    v2.push("pets");
    assert_eq!(v2, vec!["step", "on", "no", "pets"]);

    let v3: Vec<i32> = (0..5).collect();
    assert_eq!(v3, [0, 1, 2, 3, 4]);


    // 使用切片方法
    let mut v4 = vec!["a man", "a plan", "a canal", "panama"];
    v4.reverse(); // 转换为&mut [&str]
    assert_eq!(v4, vec!["panama", "a canal", "a plan", "a man"]);

    let v5: Vec<i32> = Vec::with_capacity(2);
    assert_eq!(v5.len(), 0);
    assert_eq!(v5.capacity(), 2);


    // 插入和删除
    let mut v6 = vec![10, 20, 30, 40, 50];
    v6.insert(3, 35);
    assert_eq!(v6, [10, 20, 30, 35, 40, 50]);
    v6.remove(1);
    assert_eq!(v6, [10, 30, 35, 40, 50]);
    assert_eq!(v6.pop(), Some(50));
    assert_eq!(v6, [10, 30, 35, 40]);

    // 循环
    let languages = vec!["Lisp", "Schema", "C", "C++", "Fortran"];
    for l in languages {
        println!("{}: {}", l,
                 if l.len() % 2 == 0 {
                     "functional"
                 } else {
                     "imperative"
                 })
    }
}
