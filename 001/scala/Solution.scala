import projecteuler.Multiple.multiplesUnder

object Solution {
  def main(args: Array[String]) {
    val p : Int = readInt()
    println(solve(p))
  }

  def solve(p: Int): Int = {
    multiplesUnder(p, 3) + multiplesUnder(p, 5) - multiplesUnder(p, 15)
  }
}
