package weixin

import (
	"testing"
)

func TestSendRobotMessage(t *testing.T) {
	robotUrl := "https://qyapi.weixin.qq.com/cgi-bin/webhook/send?key=a11d5ec3-ea16-4821-86d4-6c82328f60b0"
	text := "我是robot"
	SendRobotMessage(robotUrl, text)
}
