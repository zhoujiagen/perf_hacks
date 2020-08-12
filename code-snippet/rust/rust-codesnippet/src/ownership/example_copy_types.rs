//! Copy类型的示例.

#[allow(dead_code)]
pub fn example_main() {
    let str1 = "somnambulance".to_string();
    let _str2 = str1;   // 移动

    let num1: i32 = 36;
    let _num2 = num1;   // 拷贝

    // struct, enum默认不是Copy
    #[derive(Copy, Clone)]
    struct Label { number: u32 }

    fn print(l: Label) {
        println!("STAMP: {}", l.number);
    }

    let l = Label { number: 3 };
    print(l);
    println!("My label number is : {}", l.number);
}