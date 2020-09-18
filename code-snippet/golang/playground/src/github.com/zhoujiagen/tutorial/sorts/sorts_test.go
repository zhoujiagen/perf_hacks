// 示例: 排序
package sorts

import (
	"fmt"
	"os"
	"sort"
	"text/tabwriter"
	"time"

	"testing"
)

type Track struct {
	Title  string
	Artist string
	Album  string
	Year   int
	Length time.Duration
}

var tracks = []*Track{
	{"Go", "Delilah", "From the Roots Up", 2012, length("3m38s")},
	{"Go", "Moby", "Moby", 1992, length("3m37s")},
	{"Go Ahead", "Alicia Keys", "As I Am", 2007, length("4m36s")},
	{"Ready 2 Go", "Martin Solveig", "Smash", 2011, length("4m24s")},
}

func length(s string) time.Duration {
	d, err := time.ParseDuration(s)
	if err != nil {
		panic(s)
	}
	return d
}

func printTrack(tracks []*Track) {
	const format = "%v\t%v\t%v\t%v\t%v\t\n"
	tw := tabwriter.NewWriter(os.Stdout, 0, 8, 2, ' ', 0)

	fmt.Fprintf(tw, format, "Title", "Artist", "Album", "Year", "Length")
	fmt.Fprintf(tw, format, "-----", "------", "-----", "----", "------")
	for _, t := range tracks {
		fmt.Fprintf(tw, format, t.Title, t.Artist, t.Album, t.Year, t.Length)
	}
	tw.Flush()
}

// byArtist有sort.Interface接口方法
type byArtist []*Track

func (x byArtist) Len() int {
	return len(x)
}
func (x byArtist) Less(i, j int) bool {
	return x[i].Artist < x[j].Artist
}
func (x byArtist) Swap(i, j int) {
	x[i], x[j] = x[j], x[i]
}

type playlistSort struct {
	t    []*Track
	less func(x, y *Track) bool
}

func (x playlistSort) Len() int {
	return len(x.t)
}
func (x playlistSort) Less(i, j int) bool {
	return x.less(x.t[i], x.t[j])
}
func (x playlistSort) Swap(i, j int) {
	x.t[i], x.t[j] = x.t[j], x.t[i]
}

//	按Artist排序
func TestByArtist(t *testing.T) {
	printTrack(tracks)
	fmt.Println()
	sort.Sort(byArtist(tracks))
	printTrack(tracks)
	fmt.Println(sort.IsSorted(byArtist(tracks)))
}

// 自定义排序
func TestPlaylistSort(t *testing.T) {
	printTrack(tracks)
	fmt.Println()
	sort.Sort(playlistSort{
		t: tracks,
		less: func(x, y *Track) bool {
			if x.Title != y.Title {
				return x.Title < y.Title
			}
			if x.Year != y.Year {
				return x.Year < y.Year
			}
			if x.Length != y.Length {
				return x.Length < y.Length
			}
			return false
		},
	})
	printTrack(tracks)
}
