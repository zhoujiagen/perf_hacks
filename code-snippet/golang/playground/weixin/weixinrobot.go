package weixin

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

/*
   data = {
       'msgtype': 'text',
       "text": {
           "content": text,
           "mentioned_list": memtion_users
       }
   }
*/
type WeixinRobotMessage struct {
	Msgtype string                 `json:"msgtype"`
	Text    WeixinRobotMessageText `json:"text"`
}
type WeixinRobotMessageText struct {
	Content string `json:"content"`
}

func SendRobotMessage(robotUrl, message string) {
	msg := WeixinRobotMessage{
		Msgtype: "text",
		Text:    WeixinRobotMessageText{Content: message},
	}

	data, err := json.Marshal(msg)
	if err != nil {
		fmt.Printf("send robot message failed: %v", err)
		os.Exit(1)
	}

	resp, err := http.Post(robotUrl, "application/json", bytes.NewBuffer(data))
	if err != nil {
		fmt.Printf("send robot message failed: %v", err)
		os.Exit(1)
	}
	fmt.Println(resp.Status)
	// if resp.StatusCode != http.StatusOK {
	// }
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Printf("send robot message failed: %v", err)
		os.Exit(1)
	}
	fmt.Println(string(body))
	resp.Body.Close()
}
