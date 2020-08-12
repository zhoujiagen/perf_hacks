//! 数组的示例.

#[allow(dead_code)]
pub fn example_main() {
    let lazy_caterer: [u32; 6] = [1, 2, 4, 7, 11, 16];
    let taxonomy = ["Animalia", "Arthropoda", "Insecta"];

    assert_eq!(lazy_caterer[3], 7);     // 访问元素
    assert_eq!(taxonomy.len(), 3);      // 长度

    let mut sieve = [true; 10000];
    for i in 2..100 {
        if sieve[i] {
            let mut j = i * i;
            while j < 10000 {
                sieve[j] = false;
                j += i;
            }
        }
    }
    assert!(sieve[211]);
    assert!(!sieve[9876]);

    // 使用切片方法
    let mut chaos = [3, 5, 4, 1, 2];
    chaos.sort();   // 转换为 &mut [i32]
    assert_eq!(chaos, [1, 2, 3, 4, 5]);
}