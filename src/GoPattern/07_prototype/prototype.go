package prototype

type Clonable interface {
	Clone() Clonable
}

type PrototypeManager struct {
	prototypes map[string]Clonable
}

func NewPrototypeManager() *PrototypeManager {
	return &PrototypeManager{
		prototypes: make(map[string]Clonable),
	}
}

func (p *PrototypeManager) Get(name string) Clonable {
	if pro, ok := p.prototypes[name]; ok{
		return pro
	}
	return nil
}

func (p *PrototypeManager) Set(name string, proto Clonable) {
	p.prototypes[name] = proto
}