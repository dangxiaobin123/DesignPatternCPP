package proxy

type Subject interface {
	Do() string
}

type RealSubject struct {
	
}

func (*RealSubject) Do() string {
	return "real"
}

type Proxy struct {
	real *RealSubject
}

func (p *Proxy) Do() string {
	var str string

	str += "pre:"

	str += p.real.Do()

	str += ":after"

	return str
}