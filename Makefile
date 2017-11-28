.PHONY: all
all: ./bin/create ./bin/verify

.PHONY: clean
clean:
	rm -rf ./bin/* || true

./bin:
	mkdir -p ./bin

./bin/create: ./bin
	go build -o ./bin/create create.go

./bin/verify: ./bin
	go build -o ./bin/verify verify.go

.PHONY: docker-build
docker-build:
	docker build --rm --force-rm -t umayr/hmac:gcs .

.PHONY: binaries
binaries: docker-build
	docker run -v $(pwd)/bin:/go/src/github.com/umayr/hmac/bin --rm -it umayr/hmac:gcs make all

.PHONY: shell
shell: docker-build
	docker run -v $(pwd)/bin:/go/src/github.com/umayr/hmac/bin --rm -it umayr/hmac:gcs /bin/bash
