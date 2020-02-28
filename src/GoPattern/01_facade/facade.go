package facade

import "fmt"

func NewAPI() API {
	return &apiImpl{
		a: NewAModuleAPI(),
		b: NewBModuleAPI(),
	}
}

type API interface {
	Test() string
}

type apiImpl struct {
	a AModuleAPI
	b BModuleAPI
}

func (a *apiImpl) Test() string {
	aret := a.a.TestA()
	bret := a.b.TestB()
	return fmt.Sprintf("%s\n%s", aret, bret)
}

type AModuleAPI interface {
	TestA() string
}

type aModuleImpl struct {
	
}

func NewAModuleAPI() AModuleAPI {
	return &aModuleImpl{}
}

func (*aModuleImpl) TestA() string {
	return "A module running"
}

type BModuleAPI interface {
	TestB() string
}

type bModuleImpl struct {
	
}

func NewBModuleAPI() BModuleAPI {
	return &bModuleImpl{}
}

func (*bModuleImpl) TestB() string {
	return "B module running"
}

