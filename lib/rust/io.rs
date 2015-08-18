use std::str::FromStr;
use std::io::Stdin;
use std::io::BufRead;

pub trait ReadValue {
  fn read_value<F>(&self) -> Result<F, F::Err> where F: FromStr;
}

impl ReadValue for Stdin {
  fn read_value<F>(&self) -> Result<F, F::Err> where F: FromStr {
    let mut s: String = String::new();
    self.lock().read_line(&mut s).unwrap();
    s.trim().parse()
  }
}
