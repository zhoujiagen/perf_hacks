//! A Tour of Rust.

pub mod math;
pub mod tests;
pub mod mandelbrot;
pub mod web_server;

#[allow(dead_code)]
pub fn example_gcd() {
    use math::gcd;
    println!("{}", gcd(2 * 3 * 5 * 11 * 17, 3 * 7 * 11 * 13 * 19));
}

#[allow(dead_code)]
pub fn example_cmd_arg() {
    use math::gcd;
    use std::str::FromStr;
    use std::io::Write;

    let mut numbers = Vec::new();

    for arg in std::env::args().skip(1) {
        numbers.push(u64::from_str(&arg)
            .expect("error parsing argument"));
    }

    if numbers.len() == 0 {
        writeln!(std::io::stderr(), "Usage: gcd NUMBER ...").unwrap();
        std::process::exit(1);
    }

    let mut d = numbers[0];
    for m in &numbers[1..] {
        d = gcd(d, *m);
    }

    println!("The greatest common divisor of {:?} is {}",
             numbers, d);
}

#[allow(dead_code)]
pub fn example_server() {
    use iron::Iron;
    use router::Router;

    use web_server::get_form;
    use web_server::post_gcd;
    let mut router = Router::new();
    router.get("/", get_form, "root");
    router.post("/gcd", post_gcd, "gcd");
    println!("Serving on http://localhost:3000...");
    Iron::new(router).http("localhost:3000").unwrap();
}

#[allow(dead_code)]
pub fn example_mandelbrot() {
    // use mandelbrot::render;
    use mandelbrot::write_image;
    use mandelbrot::render_c;

    use num::Complex;
    let bounds = (4000, 3000);
    let upper_left = Complex {
        re: -1.20,
        im: 0.35,
    };
    let lower_right = Complex { re: -1.0, im: 0.20 };
    let mut pixels = vec![0; bounds.0 * bounds.1];

    // render(&mut pixels, bounds, upper_left, lower_right);
    render_c(&mut pixels, bounds, upper_left, lower_right);

    write_image("target/mandelbrot.png", &pixels, bounds).expect("error writing PNG file");
}