use std::io::{self, Read};

fn order(
    inorder: &[i32],
    postorder: &[i32],
    in_l: usize,
    in_r: usize,
    post_l: usize,
    post_r: usize,
) {
    if post_l <= post_r {
        let head = postorder[post_r];
        println!("{}", head);

        let mut i = in_l;
        while i <= in_r && inorder[i] != head {
            i += 1;
        }
        
        let l_num = i - in_l;
        let r_num = in_r - i;

        if l_num > 0 {
            order(inorder, postorder, in_l, i - 1, post_l, post_l + l_num - 1);
        }
        if r_num > 0 {
            order(inorder, postorder, i + 1, in_r, post_l + l_num, post_r - 1);
        }
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut tokens = input.split_whitespace();

    let n: usize = tokens.next().unwrap().parse().unwrap();

    let inorder: Vec<i32> = (0..n)
        .map(|_| tokens.next().unwrap().parse().unwrap())
        .collect();

    let postorder: Vec<i32> = (0..n)
        .map(|_| tokens.next().unwrap().parse().unwrap())
        .collect();

    order(&inorder, &postorder, 0, n - 1, 0, n - 1);
}