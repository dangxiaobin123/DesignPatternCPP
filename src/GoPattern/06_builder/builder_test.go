package builder

import "testing"
import "fmt"

func TestBuilder1(t *testing.T) {
	builder := &Builder1{}
	director := NewDirector(builder)
	director.Construct()
	res := builder.GetResult()
	if res != "123" {
		t.Fatalf("Builder1 fail expect 123 acture %s", res)
	}
}

func TestBuilder2(t *testing.T) {
	builder := &Builder2{}
	director := NewDirector(builder)
	director.Construct()
	res := builder.GetResult()
	if res != 6 {
		t.Fatalf("Builder2 fail expect 6 acture %d", res)
	}
}

func TestTextBuilder(t *testing.T) {
	builder := &TextBuilder{text: ""}
	director := NewDirectors(builder)
	director.Construct()
	fmt.Println(builder.Get_Result())
}