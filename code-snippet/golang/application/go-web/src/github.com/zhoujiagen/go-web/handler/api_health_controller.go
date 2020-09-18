package handler

import (
	"encoding/json"
	"net/http"

	"github.com/gorilla/mux"
	"github.com/zhoujiagen/go-web/metric"
)

func GetApiHealth(w http.ResponseWriter, r *http.Request) {
	json.NewEncoder(w).Encode(metric.MetricValue)
}

func registerApiHealth(router *mux.Router) {
	router.Handle("/api/health",
		JsonResponseMiddleWare(http.HandlerFunc(GetApiHealth))).Methods("GET")
}
