use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let numbers: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().expect("Please enter valid integers"))
        .collect();

    if numbers.len() >= 2 {
        let a = numbers[0];
        let b = numbers[1];
        println!("{}", a + b);
    } else {
        println!("Please provide exactly two integers separated by space.");
    }
}
