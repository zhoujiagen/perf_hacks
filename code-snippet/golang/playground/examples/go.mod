module github.com/zhoujiagen/examples

go 1.14

require (
	github.com/Microsoft/hcsshim v0.8.10 // indirect
	github.com/Microsoft/hcsshim/test v0.0.0-20201030212021-6e6b6ce98037 // indirect
	github.com/containerd/cgroups v0.0.0-20200824123100-0b889c03f102 // indirect
	github.com/containerd/containerd v1.4.1
	github.com/containerd/continuity v0.0.0-20200928162600-f2cc35102c2a // indirect
	github.com/containerd/fifo v0.0.0-20201026212402-0724c46b320c // indirect
	github.com/containerd/go-runc v0.0.0-20201020171139-16b287bc67d0 // indirect
	github.com/containerd/ttrpc v1.0.2 // indirect
	github.com/containerd/typeurl v1.0.1 // indirect
	github.com/docker/distribution v2.7.1+incompatible // indirect
	github.com/docker/docker v1.13.1
	github.com/docker/go-connections v0.4.0 // indirect
	github.com/go-sql-driver/mysql v1.5.0
	github.com/gogo/googleapis v1.4.0 // indirect
	github.com/golang/protobuf v1.3.3
	github.com/imdario/mergo v0.3.11 // indirect
	github.com/mitchellh/go-homedir v1.1.0
	github.com/opencontainers/image-spec v1.0.1 // indirect
	github.com/opencontainers/runc v0.1.1 // indirect
	github.com/opencontainers/selinux v1.6.0 // indirect
	github.com/spf13/cobra v1.1.1
	github.com/spf13/viper v1.7.1
	github.com/syndtr/gocapability v0.0.0-20200815063812-42c35b437635 // indirect
	google.golang.org/grpc v1.33.1
	gopkg.in/yaml.v2 v2.3.0
	gotest.tools/v3 v3.0.3 // indirect
)

// 将项目引用本地文件
replace github.com/zhoujiagen/examples => ./
