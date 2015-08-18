extern crate num;

use self::num::{Num, Zero, One};

pub fn multiples_under<Int: Num + Copy>(pp: Int, nn: Int) -> Int {
  let p = pp.clone(); let n = nn.clone();
  let pdn = p / n + if p % n == Int::zero() { Int::one() } else { Int::zero() };
  return (n * pdn * (pdn + Int::one())) / (Int::one() + Int::one());
}
