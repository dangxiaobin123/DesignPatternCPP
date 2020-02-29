package proxy

import "testing"
import "fmt"

func TestProxy(t *testing.T) {
	var sub Subject
	sub = &Proxy{}

	res := sub.Do()

	fmt.Println(res)

	if res != "pre:real:after" {
		t.Fail()
	}
}
