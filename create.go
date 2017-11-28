package main

import (
	"crypto/hmac"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/sha512"
	"encoding/hex"
	"flag"
	"fmt"
	"hash"
)

func generate(alg, key, msg string) string {
	var h hash.Hash

	switch alg {
	case "sha1":
		h = hmac.New(sha1.New, []byte(key))
	case "sha224":
		h = hmac.New(sha256.New224, []byte(key))
	case "sha256":
		h = hmac.New(sha256.New, []byte(key))
	case "sha384":
		h = hmac.New(sha512.New384, []byte(key))
	case "sha512":
		h = hmac.New(sha512.New, []byte(key))
	}

	h.Write([]byte(msg))
	return hex.EncodeToString(h.Sum(nil))
}

func main() {
	var (
		alg string
		key string
		msg string
	)

	flag.StringVar(&alg, "alg", "sha1", "hash algorithm to be used")
	flag.StringVar(&key, "key", "key", "key for hmac function")
	flag.StringVar(&msg, "msg", "quick brown fox jumps over the lazy dog", "message for hmac function")

	flag.Parse()

	h := generate(alg, key, msg)
	fmt.Println(h)
}
