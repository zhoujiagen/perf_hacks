// 示例: 简单的HTTP服务器
package examples

import (
	"fmt"
	"log"
	"net/http"
	"sync"
	"testing"
)

var mu sync.Mutex // 信号量, 控制count
var count int     // 访问次数

func init() {
	// log.SetFlags(log.Ldate | log.Ltime | log.Llongfile)
	log.SetFlags(log.Ldate | log.Ltime | log.Lshortfile)
}

func handler(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	count++
	mu.Unlock()

	fmt.Fprintf(w, "URL.Path=%q\n", r.URL.Path)
	debugHandler(w, r)
}

func debugHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "\n\n=== DEBUG === \n\n")
	// method, url, protocol
	fmt.Fprintf(w, "%s %s %s\n", r.Method, r.URL, r.Proto)
	// headers
	for k, v := range r.Header {
		fmt.Fprintf(w, "Header[%q]=%q\n", k, v)
	}
	// host
	fmt.Fprintf(w, "Host=%q\n", r.Host)
	// remote address
	fmt.Fprintf(w, "RemoteAddr=%q\n", r.RemoteAddr)
	// form
	if err := r.ParseForm(); err != nil {
		log.Print(err)
	}
	for k, v := range r.Form {
		fmt.Fprintf(w, "Form[%q]=%q", k, v)
	}
}

func counterHandler(w http.ResponseWriter, r *http.Request) {
	mu.Lock()
	fmt.Fprintf(w, "Count %d\n", count)
	mu.Unlock()

	debugHandler(w, r)
}

func TestHTTP(t *testing.T) {
	http.HandleFunc("/", handler)
	http.HandleFunc("/count", counterHandler)
	log.Fatal(http.ListenAndServe("localhost:9999", nil))
}
