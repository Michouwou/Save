package main

import ("reflect"
		"fmt"
		"strings")

func isConcrete(xKind string) bool {
	if xKind == "bool" || xKind == "int" ||
		xKind == "int8" || xKind == "int16" ||
		xKind == "int32" || xKind == "int64" ||
		xKind == "uint" || xKind == "uint8" ||
		xKind == "uint16" || xKind == "uint32" ||
		xKind == "uint64" || xKind == "uintptr" ||
		xKind == "float32" || xKind == "float64" ||
		xKind == "complex64" || xKind == "complex128" ||
		xKind == "string" || xKind == "interface" {
			return true
		}
	return false
}

func isIndexed(xKind string) bool {
	if xKind == "array" || xKind == "slice" ||
		xKind == "map" {
			return true
		}
	return false
}

func isChan(xKind string) bool {
	if xKind == "chan" {
		return true
	}
	return false
}

func isPtr(xKind string) bool {
	if xKind == "ptr" || xKind == "unsafePointer" {
		return true
	}
	return false
}

func isStruct(xKind string) bool {
	if xKind == "struct" {
		return true
	}
	return false
}

type mystruct struct {
	Names []string
	Ages []int
	Sizes []float32
	Num int
}

type myotherstruct struct {
	First mystruct
	Second mystruct
}

var depth = 0
var nested = false

func deepPrint(elem interface{}) {
	depth += 1
	tabs := strings.Repeat("\t", depth - 1)
	xKind := reflect.TypeOf(elem).Kind().String()
	xValue := reflect.ValueOf(elem)
	if isConcrete(xKind) {
		if nested {
			fmt.Print(tabs)
		}
		fmt.Print(xValue)
	} else if isIndexed(xKind) {
		tmp := nested
		nested = false
		fmt.Print(tabs, "[")
		for cpt := 0 ; cpt < xValue.Len() ; cpt++ {
			if cpt != 0 {
				fmt.Print(", ")
			}
			deepPrint(xValue.Index(cpt).Interface())
		}
		fmt.Print("]\n")
		nested = tmp		
	} else if isChan(xKind) {
		opened := true
		var value reflect.Value
		fmt.Print(tabs, "-> ")
		for opened == true {
			value, opened = xValue.Recv()
			if opened {
				deepPrint(value.Interface())
			}
			if xValue.Len() != 0 {
				fmt.Print(", ")
			}
		}
		fmt.Print("\n")
	} else if isPtr(xKind) {
		fmt.Print(tabs, "*(")
		deepPrint(xValue.Elem().Interface())
		fmt.Println(")")
	} else if isStruct(xKind) {
		fmt.Println(tabs, "struct {")
		nested = true
		for cpt := 0 ; cpt < xValue.NumField() ; cpt++ {
			if cpt != 0 {
				fmt.Print("\n")
			}
			fmt.Print(tabs, "\t")
			deepPrint(xValue.Field(cpt).Interface())
		}
		fmt.Print("\n", tabs, "\t}\n")
	} else {
		fmt.Print("Invalid value for printing.")
	}
	depth -= 1
}