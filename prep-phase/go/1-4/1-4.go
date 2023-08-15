package main

import (
	"bufio"
	"fmt"
	"os"
)

/*
Current process:
takes file names in cli args
for each file name
	for each line in file
		scans it in, references it in count map, and increments count value
for each key in count
	outputs the key and value aka line and count if the count is greater than 1

Want to output names of files where duplicate keys found
so in current test, temp and temp2 should be outputted but not temp3
temp3 has no crossover lines within itself or with other 2 files

One way is to have the map contain the same key of the line and have the value hold
the count and the file(s) it is from
Or could remove count and simply have value be array of strings with total
file names stored inside be the count

*/

func main() {
	counts := make(map[string][]string)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, counts)
			f.Close()
		}
	}
	validFiles := make(map[string]int)

	for line, arr := range counts {
		if len(arr) > 1 {
			fmt.Printf("%d\t%s\n", len(arr), line)
			for _, fileName := range arr {
				validFiles[fileName] = 1
			}
		}
	}

	fmt.Println("Files where dups show up:")
	for fileName := range validFiles {
		fmt.Println(fileName)
	}
}

func countLines(f *os.File, counts map[string][]string) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		str := input.Text()
		counts[str] = append(counts[str], f.Name())
	}
	// NOTE: ignoring potential errors from input.Err()
}

//!-
