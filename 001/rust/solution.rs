use std::io;
extern crate euler;
use euler::ReadValue;

fn main() {
  let p: u32 = std::io::stdin().read_value().unwrap();
  let r: u32 = solve(p);
  println!("{}", r);
}

fn solve(p: u32) -> u32 {
  let mut sum = 0;
  for x in 0..p {
    if x % 5 == 0 || x % 3 == 0 {
      sum += x
    }
  }
  sum
}
