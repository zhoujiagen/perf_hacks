package examples

import (
	"encoding/json"
	"testing"
)

type Movie struct {
	Title  string
	Year   int  `json:"released"`
	Color  bool `json:"color,omitempty"`
	Actors []string
}

var movies = []Movie{
	{Title: "mivie1", Year: 1942, Color: false, Actors: []string{"H1", "I1"}},
	{Title: "mivie2", Year: 1967, Color: true, Actors: []string{"S2", "J2"}},
}

func TestJSON(t *testing.T) {
	// 序列化
	//data, err := json.Marshal(movies)
	data, err := json.MarshalIndent(movies, "", "  ")
	if err != nil {
		t.Errorf("JSON marshaling failed: %s", err)
	}
	t.Logf("%s\n", data)

	// 反序列化
	var titles []struct{ Title string }
	if err := json.Unmarshal(data, &titles); err != nil {
		t.Errorf("JSON Unmarshal failed: %s", err)
	}
	t.Log(titles)
}
