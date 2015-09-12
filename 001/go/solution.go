package main

import "fmt"

func main() {
  var p int
  fmt.Scanln(&p)
  fmt.Println(solve(p));
}

func solve(p int) int {
  sum := 0;
  for i := 1; i < p; i++ {
    if i % 3 == 0 || i % 5 == 0 {
      sum += i
    }
  }
  return sum
}
