package main

import "fmt"
import "pe"

func main() {
  var p int
  fmt.Scanln(&p)
  fmt.Println(solve(p));
}

func solve(p int) int {
  return pe.MultiplesUnder(p, 3) + pe.MultiplesUnder(p, 5) - pe.MultiplesUnder(p, 15)
}
