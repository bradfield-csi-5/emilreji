package metrics

import (
	"math"
	"testing"
)

func BenchmarkMetrics(b *testing.B) {
	users := LoadData()

	b.Run("Average age orig", func(b *testing.B) {
		actual := 0.0
		for n := 0; n < b.N; n++ {
			actual = AverageAge(users)
		}
		expected := 59.62
		if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
			b.Fatalf("Expected average age to be around %.2f, not %.3f", expected, actual)
		}
	})

	b.Run("Average age V2", func(b *testing.B) {
		actual := 0.0
		for n := 0; n < b.N; n++ {
			actual = AverageAgeV2(users)
		}
		expected := 59.62
		if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
			b.Fatalf("Expected average age to be around %.2f, not %.3f", expected, actual)
		}
	})

	b.Run("Average age V3", func(b *testing.B) {
		actual := 0.0
		for n := 0; n < b.N; n++ {
			actual = AverageAgeV3(users)
		}
		expected := 59.62
		if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
			b.Fatalf("Expected average age to be around %.2f, not %.3f", expected, actual)
		}
	})

	b.Run("Average age V4", func(b *testing.B) {
		actual := 0.0
		for n := 0; n < b.N; n++ {
			actual = AverageAgeV4(users)
		}
		expected := 59.62
		if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
			b.Fatalf("Expected average age to be around %.2f, not %.3f", expected, actual)
		}
	})

	b.Run("Average age V5", func(b *testing.B) {
		actual := 0.0
		for n := 0; n < b.N; n++ {
			actual = AverageAgeV5(users)
		}
		expected := 59.62
		if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
			b.Fatalf("Expected average age to be around %.2f, not %.3f", expected, actual)
		}
	})

	// b.Run("Average payment", func(b *testing.B) {
	// 	actual := 0.0
	// 	for n := 0; n < b.N; n++ {
	// 		actual = AveragePaymentAmount(users)
	// 	}

	// 	expected := 499850.559
	// 	if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
	// 		b.Fatalf("Expected average payment amount to be around %.2f, not %.3f", expected, actual)
	// 	}
	// })

	// b.Run("Payment stddev", func(b *testing.B) {
	// 	actual := 0.0
	// 	for n := 0; n < b.N; n++ {
	// 		actual = StdDevPaymentAmount(users)
	// 	}
	// 	expected := 288684.850
	// 	if math.IsNaN(actual) || math.Abs(actual-expected) > 0.01 {
	// 		b.Fatalf("Expected standard deviation to be around %.2f, not %.3f", expected, actual)
	// 	}
	// })

}
