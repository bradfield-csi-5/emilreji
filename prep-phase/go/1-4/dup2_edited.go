package main

import (
	"bufio" 
	"fmt" 
	"os"
)

func main() {
	counts := make(map[string]int)
	// file_counts := make(map[string][string]int)
	file_counts := map[string]map[string]int{}
	files := os.Args[1:]
	if len(files) == 0 {
		// countLines(os.Stdin, counts);
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, counts, file_counts, arg);
			f.Close()
		} 
	}
	for line, n := range counts {
		if (n > 1) {
			// var filesWithLine string = file_counts[line];
			// fmt.Printf("%d\t%s\t%s\n", n, line, filesWithLine)
			fmt.Printf("%d\t%s", n, line)
			for fileName, _ := range file_counts[line] {
				fmt.Printf("\t%s", fileName)
			}
			fmt.Printf("\n")
		}
	}
	fmt.Printf("%v", file_counts)
}

func countLines(f *os.File, counts map[string]int, file_counts map[string]map[string]int, fileName string) {
	input := bufio.NewScanner(f);
	for input.Scan() {
		var line string = input.Text();
		counts[line]++
		if (file_counts[line] == nil) {
			file_counts[line] = map[string]int{};
		}
		file_counts[line][fileName]++
	}
}

/*
Question: Modify dup2 to print the names of all files in which each duplicate line occurs

Option 1:
For each file, create a seperate counts variable for that specific file (keep total counts as well)
Populate it via countLines
Then when iterating over total counts, for each duplicate value, check across all
specific counts; if any present, print out corresponding file

Option 1 has the issue of increasing space requirements by approximately N
Instead of one map, have N + 1 maps with N being number of files

Option 2: Consider using a nested map with key being filename and value being map
However that would use same amount of extra space and make program more complex

Option 3: two maps; one for line to count and another for line to files array/string
Start with two empty maps
Then for each call to countLines for a given file and line,
increment counts map
Add the current file name to the end of the value in file_counts map for that line
Then during printing, for each line that is duplicated, check in file_counts for the files
Split them on space and then output them with count

Option 3 is better than option 1 form a space utilization standpoint
Option 3 uses another extra map so more space is used that dup2 but increase is constant space
While option 1 increases space by N

Post coding issues:
Failed to consider that when appending strings, doesn't remove duplicates
Will have to try to make it a nested object
*/