// 示例: 包go-sql-driver/mysql
package examples

import (
	"database/sql"
	"log"
	"math/rand"
	"strconv"
	"testing"
	"time"

	_ "github.com/go-sql-driver/mysql"
)

/** 数据准备
CREATE TABLE `Movies` (
  `title` varchar(100) NOT NULL,
  `year` int(11) NOT NULL,
  `length` int(11) DEFAULT NULL,
  `genre` varchar(10) DEFAULT NULL,
  `studioName` varchar(30) DEFAULT NULL,
  `producerC#` int(11) DEFAULT NULL,
  PRIMARY KEY (`title`,`year`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4;


*/

type RMovie struct {
	Title      string
	Year       int
	Length     int    // nullable
	Genre      string // nullable
	StudioName string // nullable
	ProducerC  int    // nullable
}

// 解析行
func (movie *RMovie) Scan(rows *sql.Rows) error {
	// 处理NULL
	var length sql.NullInt64
	var genre sql.NullString
	var studioName sql.NullString
	var producerC sql.NullInt64
	err := rows.Scan(&movie.Title, &movie.Year, &length, &genre, &studioName, &producerC)
	if err != nil {
		return err
	}

	if length.Valid {
		movie.Length = int(length.Int64)
	}
	if genre.Valid {
		movie.Genre = genre.String
	}
	if studioName.Valid {
		movie.StudioName = studioName.String
	}
	if producerC.Valid {
		movie.ProducerC = int(producerC.Int64)
	}

	return nil
}

// 配置连接
func Configure(db *sql.DB) {
	db.SetMaxOpenConns(10)
	db.SetMaxIdleConns(10)
	db.SetConnMaxLifetime(time.Minute * 5)
}

// 保存
func Save(db *sql.DB, movie *RMovie) {
	tx, err := db.Begin()
	if err != nil {
		log.Fatalf("error: %v", err)
	}

	stmt, err := db.Prepare("INSERT INTO Movies(title, year, length, genre, studioName, `producerC#`) " +
		"VALUES (?,?,?,?,?,?)")
	if err != nil {
		log.Fatalf("error: %v", err)
	}

	res, err := stmt.Exec(movie.Title, movie.Year, movie.Length, movie.Genre, movie.StudioName, movie.ProducerC)
	if err != nil {
		log.Fatalf("error: %v", err)
	}

	rowCnt, err := res.RowsAffected()
	if err != nil {
		log.Fatalf("error: %v", err)
	}
	log.Printf("RowsAffected=%d\n", rowCnt)

	tx.Commit()
}

// 查询
func Query(db *sql.DB) {
	rows, err := db.Query("SELECT * FROM Movies")
	defer rows.Close()

	for rows.Next() {
		var movie RMovie
		err := movie.Scan(rows)

		if err != nil {
			log.Fatalf("error: %v", err)
		}
		log.Printf("%v\n", movie)
	}

	err = rows.Err()
	if err != nil {
		log.Fatalf("error: %v", err)
	}
}

func TestMySQL(t *testing.T) {
	// 建立连接
	db, err := sql.Open("mysql", "root:admin@tcp(127.0.0.1:3306)/movies")
	if err != nil {
		t.Errorf("error: %v", err)
	}
	// 配置连接
	Configure(db)
	// 最后关闭连接
	defer db.Close()

	// 执行插入
	randSeed := time.Now().UnixNano()
	r := rand.New(rand.NewSource(randSeed))
	movie := RMovie{
		Title:      "title" + strconv.Itoa(r.Int()),
		Year:       2000,
		Length:     120,
		Genre:      "genre1",
		StudioName: "studioName1",
		ProducerC:  1,
	}
	Save(db, &movie)

	// 执行查询
	Query(db)
}
