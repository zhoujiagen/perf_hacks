// 示例: 包flag, 命令行参数解析, 测试工具
package main

import (
	"flag"
	"fmt"
	"io"
	"os"
	"strings"
)

var out io.Writer = os.Stdout

// 命令行选项: 返回的是指针
var n = flag.Bool("n", false, "omit trailing newline")
var sep = flag.String("s", " ", "seperator")

func main() {
	flag.Parse()
	if err := echo(!*n, *sep, flag.Args()); err != nil {
		fmt.Fprintf(os.Stderr, "echo :%v\n", err)
		os.Exit(1)
	}
}

func echo(newline bool, sep string, args []string) error {
	fmt.Fprintf(out, strings.Join(args, sep))
	if newline {
		fmt.Fprintln(out)
	}
	return nil
}
