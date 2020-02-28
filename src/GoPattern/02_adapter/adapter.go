package adapter

type Target interface {
	Request() string
}

type Adaptee interface {
	SpecificRequest() string
}

func NewAdaptee() Adaptee {
	return &adapteeImpl{}
}

type adapteeImpl struct {
	
}

func (*adapteeImpl) SpecificRequest() string {
	return "adaptee method"
}

type adaper struct {
	Adaptee
}

func NewAdapter(adaptee Adaptee) Target {
	return &adaper{
		Adaptee: adaptee,
	}
} 

func (a *adaper) Request() string {
	return a.SpecificRequest()
}