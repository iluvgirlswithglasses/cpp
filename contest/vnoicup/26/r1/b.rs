use std::{
    collections::VecDeque,
    fmt,
    io::{self, BufRead},
    str::FromStr,
};

struct Scanner {
    tokens: VecDeque<String>,
}

impl Scanner {
    pub fn new() -> Self {
        let stdin = io::stdin();
        let mut tokens = VecDeque::new();

        for line in stdin.lock().lines() {
            for token in line.unwrap().split_ascii_whitespace() {
                tokens.push_back(token.to_owned());
            }
        }
        Self { tokens }
    }

    pub fn next<T: FromStr>(&mut self) -> T
    where
        <T as FromStr>::Err: fmt::Debug,
    {
        T::from_str(&self.tokens.pop_front().unwrap()).unwrap()
    }
}

fn solve(n: usize, k: i32, mut a: Vec<i32>, mut b: Vec<i32>) -> bool {
    let pair_id = |x: i32| std::cmp::min(x, k - x);

    for i in 0..n {
        if pair_id(a[i]) != pair_id(b[i]) {
            return false;
        }
    }

    let mut i = 0;
    while i < n {
        let mut j = i;

        while j < n && pair_id(a[j]) == pair_id(a[i]) {
            j += 1;
        }

        // cool ass sort trick
        a[i..j].sort_unstable();
        b[i..j].sort_unstable();

        if a[i..j] != b[i..j] {
            return false;
        }

        i = j;
    }

    true
}

fn main() {
    let mut input = Scanner::new();
    let t: usize = input.next();
    for _ in 0..t {
        let n: usize = input.next();
        let k: i32 = input.next();
        let a: Vec<i32> = (0..n).map(|_| input.next()).collect();
        let b: Vec<i32> = (0..n).map(|_| input.next()).collect();
        if solve(n, k, a, b) {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
