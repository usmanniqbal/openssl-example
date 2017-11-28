FROM 10pdev/gcs:1.8.3-jessie

MAINTAINER "Umayr Shahid <umayr.shahid@gmail.com>"

ADD . /go/src/github.com/umayr/hmac
WORKDIR /go/src/github.com/umayr/hmac

