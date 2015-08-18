use std::io;
extern crate euler;
use euler::ReadValue;
use euler::multiples_under;

fn main() {
  let p: u32 = std::io::stdin().read_value().unwrap();
  let r: u32 = solve(p);
  println!("{}", r);
}

fn solve(p: u32) -> u32 {
  let mut sum = 0;
  sum += multiples_under(p, 3);
  sum += multiples_under(p, 5);
  sum += multiples_under(p, 15);
  sum
}
