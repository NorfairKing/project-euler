use std::io;

fn main() {
  let p: u32 = getUInt();
  let r: u32 = solve(p);
  println!("{}", r);
}

fn getUInt() -> u32 {
  let mut guess = String::new();
  io::stdin().read_line(&mut guess).ok().expect("failed to read line");
  let p: u32 = guess.trim().parse().ok().expect("Please type a number!");
  p
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
