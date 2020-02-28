package adapter

import "fmt"

type Painter interface {
	print_strong()
	print_weak()
}

type BannerI interface {
	show_with_paren()
	show_with_aster()
}

func NewBanner(str string) BannerI {
	return &Banner{
		str: str,
	}
}

type Banner struct {
	str string
}

func (b *Banner) show_with_paren() {
	fmt.Println("("+b.str+")")
}

func (b *Banner) show_with_aster() {
	fmt.Println("*"+b.str+"*")
}

type BannerPrinter struct {
	Painter
	banner BannerI
}

func NewBannerPrinter(banner BannerI) Painter {
	return &BannerPrinter{
		banner: banner,
	}
}

func (b *BannerPrinter) print_strong() {
	b.banner.show_with_paren()
}

func (b *BannerPrinter) print_weak() {
	b.banner.show_with_aster()
}