package main

import (
	"fmt"

	"rsc.io/quote"
)

// Hello to greetings.
func Hello() string {
	return quote.Hello()
}

func main() {
	fmt.Println(Hello())
}
