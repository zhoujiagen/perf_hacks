//! 字符串的示例.

#[allow(dead_code)]
pub fn example_main() {
    // 字符串字面量
    let speech = "\"Ouch!\", said the well.\n";
    println!("{}", speech);
    println!("In the room the womain com and go,\
     Sining of Mount Abora");
    println!("It was a bright, cold day in April, and \
    there wer four of us-\
    more or less.");
    // 原始字符串
    println!(r"C:\Program Files\Gorillas");
    println!(r###"
        This raw string started with 'r###"'
        Therefore it does not end until we reach a quote mark ('"')
        followed immediately by three pound signs ('###'):
        "###);

    // 字节字符串
    let method = b"GET";
    assert_eq!(method, &[b'G', b'E', b'T']);

    // 内存中字符串
    let noodles = "noodles".to_string(); // String
    let oodles = &noodles[1..];            // &str
    let poodles = "ಠ_ಠ";                  // &str
    assert_eq!(oodles.len(), noodles.len() - 1);
    assert_eq!(poodles.len(), 7);                   // 字节数
    assert_eq!(poodles.chars().count(), 3);         // 字符数


    // 创建字符串
    println!("{}", "to many pets".to_string());
    println!("{}", format!("{}°{:02}{:02}″N", 24, 5, 23));
    let bits = vec!["veni", "vidi", "vici"];
    assert_eq!(bits.concat(), "venividivici");
    assert_eq!(bits.join(", "), "veni, vidi, vici");

    // 字符串比较
    assert_eq!("ONE".to_lowercase(), "one");
    assert!("peanut".contains("nut"));
    assert_eq!("ಠ_ಠ".replace("ಠ", "■"), "■_■");
    assert_eq!("   clean\n".trim(), "clean");
    for word in "veni, vidi, vici".split(", ") {
        assert!(word.starts_with("v"));
    }
}