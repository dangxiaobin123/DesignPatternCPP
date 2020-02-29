package bridge

import "fmt"

type AbstractMessage interface {
	SendMessage(text, to string)
}

type MessageImpl interface {
	Send(text, to string)
}

type MessageSMS struct {
	
}

func ViaSMS() MessageImpl {
	return &MessageSMS{}
}

func (m *MessageSMS) Send(text, to string) {
	fmt.Printf("send %s to %s via SMS", text, to)
}

type MessageEmail struct {
	
}

func ViaEmail() MessageImpl {
	return &MessageEmail{}
}

func (m *MessageEmail) Send(text, to string) {
	fmt.Printf("send %s to %s via Email", text, to)
}

type CommonMsg struct {
	method MessageImpl
}

func NewComMsg(method MessageImpl) *CommonMsg {
	return &CommonMsg{
		method: method,
	}
}

func (c *CommonMsg) SendMessage(text, to string) {
	c.method.Send(text, to)
}

type UrgencyMsg struct {
	method MessageImpl
}

func NewUrgencyMsg(md MessageImpl) *UrgencyMsg {
	return &UrgencyMsg{
		method: md,
	}
}

func (c *UrgencyMsg) SendMessage(text, to string) {
	c.method.Send(fmt.Sprintf("[Urgency] %s", text), to)
}