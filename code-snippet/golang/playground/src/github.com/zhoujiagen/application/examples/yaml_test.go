package examples

import (
	"testing"

	"gopkg.in/yaml.v2"
)

// 注意: 两个空格, 而不是TAB
var data = `
a: Easy!
b:
  c: 2
  d: [3,4]
`

type T struct {
	A string
	B struct {
		RenamedC int   `yaml:"c"`
		D        []int `yaml:",flow"`
	}
}

func TestYaml(test *testing.T) {
	// 反序列化
	t := T{}
	err := yaml.Unmarshal([]byte(data), &t)
	if err != nil {
		test.Errorf("error: %v", err)
	}
	test.Logf("=== t:\n%v\n\n", t)

	// 序列化
	d, err := yaml.Marshal(&t)
	if err != nil {
		test.Errorf("error: %v", err)
	}
	test.Logf("=== t dump:\n%v\n\n", string(d))
}

func TestYamlMap(t *testing.T) {
	// 使用字典
	m := make(map[interface{}]interface{})

	err := yaml.Unmarshal([]byte(data), &m)
	if err != nil {
		t.Errorf("error: %v", err)
	}
	t.Logf("=== m:\n%v\n\n", m)
	d, err := yaml.Marshal(&m)
	if err != nil {
		t.Errorf("error: %v", err)
	}
	t.Logf("=== m dump:\n%v\n", string(d))
}
