package adapter

import "testing"

var expect = "adaptee method"

func TestAdapter(t *testing.T) {
	adaptee := NewAdaptee()
	target := NewAdapter(adaptee)
	res := target.Request()
	if res != expect {
		t.Fatalf("expect: %s, actual: %s", expect, res)
	}
}

func TestBanner(t *testing.T) {
	banner := NewBanner("hello, world")
	painter := NewBannerPrinter(banner)
	painter.print_strong()
	painter.print_weak()
}
