use std::{
    cmp,
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

fn solve_col(w: usize, c: usize) -> usize {
    if c == 0 {
        return w - 1;
    }
    return w - 1 - c + w - 1;
}

fn solve(h: usize, w: usize, r: usize, c: usize) -> usize {
    if r == 0 {
        return cmp::min(h - 1, solve_col(w, c));
    }
    return cmp::min(h - 1 - r + h - 1, solve_col(w, c));
}

fn main() {
    let mut input = Scanner::new();
    let t: usize = input.next();
    for _ in 0..t {
        let h: usize = input.next();
        let w: usize = input.next();
        let r: usize = input.next();
        let c: usize = input.next();
        println!("{}", solve(h, w, r - 1, c - 1));
    }
}
