package metrics

import (
	"encoding/csv"
	"log"
	"math"
	"os"
	"strconv"
	"time"
)

type UserId int
type UserMap map[UserId]*User

type Address struct {
	fullAddress string
	zip         int
}

type DollarAmount struct {
	dollars, cents uint64
}

type Payment struct {
	amount DollarAmount
	time   time.Time
}

type User struct {
	id       UserId
	name     string
	age      int
	address  Address
	payments []Payment
}

func AverageAge(users UserMap) float64 {
	// original code
	average, count := 0.0, 0.0
	for _, u := range users {
		count += 1
		average += (float64(u.age) - average) / count
	}

	return average
}

func AverageAgeV2(users UserMap) float64 {
	count, sum := 0.0, 0.0
	for _, u := range users {
		count += 1
		sum += float64(u.age)
	}

	return sum / count
}

func AverageAgeV3(users UserMap) float64 {
	count, sum := 0, 0
	for _, u := range users {
		count += 1
		sum += u.age
	}

	return float64(sum) / float64(count)
}

func AverageAgeV4(users UserMap) float64 {
	count, sum := 0, 0
	var i UserId
	for i = 0; i < 100000; i++ {
		count += 1
		sum += users[i].age
	}

	return float64(sum) / float64(count)
}

func AverageAgeV5(users UserMap) float64 {
	average, count := 0.0, 0.0
	var i UserId
	for i = 0; i < 100000; i++ {
		count += 1
		average += (float64(users[i].age) - average) / count
	}

	return average
}

func AveragePaymentAmount(users UserMap) float64 {
	average, count := 0.0, 0.0
	for _, u := range users {
		for _, p := range u.payments {
			count += 1
			amount := float64(p.amount.dollars) + float64(p.amount.cents)/100
			average += (amount - average) / count
		}
	}
	return average
}

// Compute the standard deviation of payment amounts
func StdDevPaymentAmount(users UserMap) float64 {
	mean := AveragePaymentAmount(users)
	squaredDiffs, count := 0.0, 0.0
	for _, u := range users {
		for _, p := range u.payments {
			count += 1
			amount := float64(p.amount.dollars) + float64(p.amount.cents)/100
			diff := amount - mean
			squaredDiffs += diff * diff
		}
	}
	return math.Sqrt(squaredDiffs / count)
}

func LoadData() UserMap {
	f, err := os.Open("users.csv")
	if err != nil {
		log.Fatalln("Unable to read users.csv", err)
	}
	reader := csv.NewReader(f)
	userLines, err := reader.ReadAll()
	if err != nil {
		log.Fatalln("Unable to parse users.csv as csv", err)
	}

	users := make(UserMap, len(userLines))
	for _, line := range userLines {
		id, _ := strconv.Atoi(line[0])
		name := line[1]
		age, _ := strconv.Atoi(line[2])
		address := line[3]
		zip, _ := strconv.Atoi(line[3])
		users[UserId(id)] = &User{UserId(id), name, age, Address{address, zip}, []Payment{}}
	}
	// id serves as key in users obj and rest including id is part of value obj
	f, err = os.Open("payments.csv")
	if err != nil {
		log.Fatalln("Unable to read payments.csv", err)
	}
	reader = csv.NewReader(f)
	paymentLines, err := reader.ReadAll()
	if err != nil {
		log.Fatalln("Unable to parse payments.csv as csv", err)
	}

	for _, line := range paymentLines {
		userId, _ := strconv.Atoi(line[2]) // used to find user obj value in users map using userId as key
		paymentCents, _ := strconv.Atoi(line[0])
		datetime, _ := time.Parse(time.RFC3339, line[1])
		users[UserId(userId)].payments = append(users[UserId(userId)].payments, Payment{
			DollarAmount{uint64(paymentCents / 100), uint64(paymentCents % 100)},
			datetime,
		})
		// sets up sub field of payments on each user in users map
		// each payments field is an array of payment objects and each obj has amount and time
	}

	return users
}
