package command

import "fmt"

type Command interface {
	Execute()
}

type StartCommand struct {
	mb *MotherBoard
}

func NewStartCommand(mb *MotherBoard) *StartCommand {
	return &StartCommand{
		mb: mb,
	}
}

func (sc *StartCommand) Execute() {
	sc.mb.start()
}

type RebootCommand struct {
	mb *MotherBoard
}

func NewRebootCommand(mb *MotherBoard) *RebootCommand {
	return &RebootCommand{
		mb: mb,
	}
}

func (c *RebootCommand) Execute() {
	c.mb.reboot()
}

type MotherBoard struct {
	
}

func (*MotherBoard) start() {
	fmt.Printf("system starting\n")
}

func (*MotherBoard) reboot() {
	fmt.Printf("system rebooting\n")
}

type Box struct {
	button1 Command
	button2 Command
}

func NewBox(b1, b2 Command) *Box {
	return &Box{
		button1: b1,
		button2: b2,
	}
}

func (b *Box) PressButton1() {
	b.button1.Execute()
}

func (b *Box) PressButton2() {
	b.button2.Execute()
}