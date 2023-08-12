package vm

import "fmt"

const (
	Load  = 0x01
	Store = 0x02
	Add   = 0x03
	Sub   = 0x04
	Halt  = 0xff
)

// Stretch goals
const (
	Addi = 0x05
	Subi = 0x06
	Jump = 0x07
	Beqz = 0x08
)

func increment(b byte) byte {
	if b == 255 {
		b = 0
	} else {
		b++
	}
	return b
}

// Given a 256 byte array of "memory", run the stored program
// to completion, modifying the data in place to reflect the result
//
// The memory format is:
//
// 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f ... ff
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ ... __
// ^==DATA===============^ ^==INSTRUCTIONS==============^
func compute(memory []byte) {

	registers := [3]byte{8, 0, 0} // PC, R1 and R2

	// Keep looping, like a physical computer's clock
	for {
		// registers[0]: address of next memory address to execute on
		op := memory[registers[0]] // fetch the opcode using program counter
		if op == Halt {
			return
		}

		// param1 := memory[registers[0]+1]
		// param2 := memory[registers[0]+2]

		registers[0]++
		fmt.Printf("Calling op %d\n", op)
		switch op {
		case Load: // store memory value to register
			// registers[param1] = memory[param2]
			// registers[0] += 3
			fmt.Println(registers)
			var registerNum = memory[registers[0]]
			registers[0]++
			var byteToLoad = memory[registers[0]]
			registers[0]++
			registers[registerNum] = byteToLoad
			fmt.Println(registers)
		case Store: // store register value to memory
			// memory[param2] = registers[param1]
			// registers[0] += 3
			fmt.Println(registers)
			fmt.Println(memory[:16])

			registerNum := memory[registers[0]]
			registerVal := registers[registerNum]

			registers[0]++

			memoryAddress := memory[registers[0]]
			memory[memoryAddress] = registerVal

			registers[0]++

			fmt.Println(registers)
			fmt.Println(memory[:16])
		case Add: // add register values and store in register one
			// registers[param1] += registers[param2]
			// registers[0] += 3
			registerOne := memory[registers[0]]
			registers[0]++
			registerTwo := memory[registers[0]]
			registers[0]++
			registers[registerOne] = registers[registerOne] + registers[registerTwo]
		case Sub: // subract register values and store in register one
			// registers[param1] -= registers[param2]
			// registers[0] += 3
			registerOne := memory[registers[0]]
			registers[0]++
			registerTwo := memory[registers[0]]
			registers[0]++
			registers[registerOne] = registers[registerOne] - registers[registerTwo]
		default:
			panic("Invalid operation: ")
		}
	}
}
