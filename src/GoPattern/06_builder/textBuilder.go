package builder

type IBuilder interface {
	make_title(title string)
	make_string(str string)
	make_items(items []string)
	make_close()
}

type Directors struct {
	builder IBuilder
}

func NewDirectors(builder IBuilder) *Directors {
	return &Directors{
		builder: builder,
	}
}

func (d *Directors) Construct() {
	d.builder.make_title("Greeting")
	d.builder.make_string("白天")
	d.builder.make_items([]string{"语文", "英语", "数学", "物理"})
	d.builder.make_string("晚上")
	d.builder.make_items([]string{"生物", "化学", "数学"})
	d.builder.make_close()
}

type TextBuilder struct {
	// IBuilder
	text string
}

func (t *TextBuilder) make_title(title string) {
	t.text += "============================\n"
	t.text += "[" + title + "]\n"
	t.text += "\n"
}

func (t *TextBuilder) make_string(str string) {
	t.text += " * " + str + "\n"
	t.text += "\n"
}

func (t *TextBuilder) make_items(items []string) {
	for _, item := range items {
		t.text += " .  " + item + "\n"
	}
	t.text += "\n"
}

func (t *TextBuilder) make_close() {
	t.text += "============================\n"
}

func (t *TextBuilder) Get_Result() string {
	return t.text
}