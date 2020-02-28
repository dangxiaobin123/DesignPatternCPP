package simple_factory

import "fmt"

type API interface {
	Say(name string) string
}

type hiAPI struct {
	
}

type helloAPI struct {
	
}

func (hi *hiAPI) Say(name string) string {
	return fmt.Sprintf("Hi, %s", name)
}

func (hello *helloAPI) Say(name	string) string {
	return fmt.Sprintf("Hello, %s", name)
}

func NewAPI(t int) API {
	switch t {
	case 1:
		return &hiAPI{}
	case 2:
		return &helloAPI{}
	default:
		return nil
	}
}