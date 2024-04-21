// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 4.
//!+

// Echo1 prints its command-line arguments.
package main

import (
	// "fmt"
	"os"
	"strings"
	"testing"
)

func efficient() {
	// var s string = strings.Join(os.Args[1:], " ");
	strings.Join(os.Args[1:], " ");
	// fmt.Println(s)
}

func inefficient() {
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		// creates new string from sep +  os.Args[i] and points s to it
		// old string that s used to point to is garbage collected
		sep = " "
	}
	// fmt.Println(s)
}

func BenchmarkEfficient(b *testing.B) {
	for i := 0; i < b.N; i++ {
		efficient()
	}
}

func BenchmarkInefficient(b *testing.B) {
	for i := 0; i < b.N; i++ {
		inefficient()
	}
}

/*
BenchmarkEfficient-8       23666             67148 ns/op             144 B/op           2 allocs/op
PASS
ok      prep-phase-go/1-3       2.140s

BenchmarkInefficient-8             30883             56095 ns/op             432 B/op           6 allocs/op
PASS
ok      prep-phase-go/1-3       2.154s

-8 means GOMAXPROCS
next value is times ran respectively
next value is average runtime of one iteration
last line end also has total time taken for all iterations
*/

// func main() {
// 	start1 := time.Now()
// 	inefficient()
// 	fmt.Printf("Inefficient: %d nanoseconds elapsed\n", time.Since(start1).Nanoseconds())

// 	start2 := time.Now()
// 	efficient() // seems to be 2 to 5 times faster
// 	fmt.Printf("Efficient: %d nanoseconds elapsed\n", time.Since(start2).Nanoseconds())
// }

//!-



// run example:
// ubuntu@ubuntu-Inspiron-7773:~/Documents/emilreji/prep-phase/go/1-3$ go test -bench=.
// goos: linux
// goarch: amd64
// pkg: vm/Documents/emilreji/prep-phase/go/1-3
// cpu: Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz
// BenchmarkEfficient-8            19064372                68.07 ns/op
// BenchmarkInefficient-8          11019427               133.0 ns/op
// PASS
// ok      vm/Documents/emilreji/prep-phase/go/1-3 3.925s
// ubuntu@ubuntu-Inspiron-7773:~/Documents/emilreji/prep-phase/go/1-3$ 