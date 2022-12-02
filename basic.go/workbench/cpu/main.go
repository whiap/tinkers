package main

import (
	"fmt"
	"runtime"

	_ "go.uber.org/automaxprocs"
)

func main() {
	fmt.Println("NumCPU=", runtime.NumCPU())
}
