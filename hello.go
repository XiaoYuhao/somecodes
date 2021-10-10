package main
import "fmt"
func main() {
	a := [...]string{"I", "am", "yuhao", "xiao"}
	for i := range a {
		fmt.Println("Array item", i, "is", a[i])
	}
}