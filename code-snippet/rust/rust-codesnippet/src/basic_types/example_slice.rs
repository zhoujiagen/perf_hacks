//! 切片的示例.

#[allow(dead_code)]
pub fn example_main() {
    let v: Vec<f64> = vec![0.0, 0.707, 1.0, 0.707];
    let a: [f64; 4] = [0.0, -0.707, -1.0, -0.707];

    let sv = &v;
    let sa = &a;

    /// 输出切片引用内容
    fn print(n: &[f64]) {
        for e in n {
            print!("{}\t", e);
        }
        println!()
    }
    print(sv);
    print(sa);

    print(&v);
    print(&a);

    print(&v[0..2]);
    print(&a[2..]);
    print(&sv[1..3]);
}