package ft_printf

import ("io"
	"os"
)

type container struct {
	kind int
	fd *os.File
	str []byte
}

type browser struct {
	buffer []byte
	cpt int
}

type data struct {
	width int
	length int
	mod string
}

func newBrowserFromLength(length int) browser {
	var buf browser
	buf.buffer = make([]byte, length)
	buf.cpt = 0
	return buf
}

func newBrowserFromString(str string) browser {
	var buf browser
	buf.buffer = []byte(str)
	buf.cpt = 0
	return buf
}

func (buf browser) full() bool {
	if len(buf.buffer) == buf.cpt {
		return true
	}
	return false
}

func flush(buf browser, what container) int {
	buf.buffer[buf.cpt] = 0
	nb := 0
	var err error

	buf.buffer[buf.cpt] = 0
	if what.kind == 0 {
		nb, err = io.Writer.Write(buf.buffer)
	} else if what.kind == 1 {
		what.str = append(what.str, buf.buffer...)
	} else {
		nb, err = what.fd.Write(buf.buffer)
	}

	if err != nil {
		return -1
	}

	buf.cpt = 0
	return nb
}

func treatPercent(fmt browser, buf browser, ret *int, vaArg []interface{}, argCpt *int) {
	flags := make([]byte, 0, 10)
	for isFlag(fmt.buffer[fmt.cpt]) {
		flags = append(flags, fmt.buffer[fmt.cpt])
		fmt.cpt++
	}
	width := 0
	for isDigit(fmt.buffer[fmt.cpt]) {
		width = width * 10 + (int(fmt.buffer[fmt.cpt]) - 48)
		fmt.cpt++
	}
	length := 0
	if fmt.buffer[fmt.cpt] == '.' {
		fmt.cpt++
		for isDigit(fmt.buffer[fmt.cpt]) {
			length = length * 10 + (int(fmt.buffer[fmt.cpt]) - 48)
			fmt.cpt++
		}
	}
	mod := string(nil)
	isModifier(&mod, fmt.buffer[fmt.cpt:fmt.cpt + 1])
	isModifier(&mod, fmt.buffer[fmt.cpt:fmt.cpt + 2])
	parseArgFromFormat(fmt, buf, ret, vaArg, argCpt, data{width, length, mod})
}

func ft_print(what container, format string, vaArg ...interface{}) int {

	buf := newBrowserFromLength(2048)
	fmt := newBrowserFromString(format)
	ret := 0
	argCpt := 0

	for cpt := 0 ; cpt < len(format) ; {
		if format[cpt] != '%' {
			buf.buffer[buf.cpt] = format[cpt]
			buf.cpt++
			cpt++
			ret++
		} else {
			treatPercent(fmt, buf, &ret, vaArg, &argCpt)
		}
		if (buf.buffer[buf.cpt] == '\n' || buf.full() == false) && flush(buf, what) == -1{
			return 0
		}
	}
	return ret
}